EXE  ?= clockwork
ARCH ?= native
PARALLEL_BUILD ?= yes
NO_PGO ?= no

ifeq ($(origin CXX), default)
	CXX = clang++
endif

ifdef MSYSTEM
	SUFFIX := .exe
	SUFFIX :=
	COPY := cp
	RM := rm -f
	RM_DIR := rm -rf
	MK_PATH = $(1)
else
	ifeq ($(OS), Windows_NT)
	    SUFFIX := .exe
	    COPY := copy
	    RM := del
	    RM_DIR := rd /s /q
	    MK_PATH = $(subst /,\,$(1))
	else
	    SUFFIX :=
	    COPY := cp
	    RM := rm -f
	    RM_DIR := rm -rf
	    MK_PATH = $(1)
	endif
endif

CMAKE_FLAGS := -DCMAKE_CXX_COMPILER=$(CXX) -DCLOCKWORK_MARCH_TARGET=$(ARCH)
ifeq ($(PARALLEL_BUILD),yes)
	CMAKE_BUILD_FLAGS := -j
endif

.PHONY: all release debug evaltune test clean format

all: release

ifeq ($(NO_PGO),yes)
release:
	cmake -DCMAKE_BUILD_TYPE=Release $(CMAKE_FLAGS) -B build-release -S . && cmake --build build-release $(CMAKE_BUILD_FLAGS)
	$(COPY) $(call MK_PATH,"build-release/clockwork$(SUFFIX)") $(EXE)$(SUFFIX)
else

LLVM_PROFDATA ?= llvm-profdata

release:
	@echo "Building with PGO (Profile-Guided Optimization)..."
	@echo "Stage 1: Building instrumented binary..."
	cmake -DCMAKE_BUILD_TYPE=Release $(CMAKE_FLAGS) -DCLOCKWORK_ENABLE_PGO_GENERATE=ON -DCLOCKWORK_PGO_DIR="$(CURDIR)/pgo-data" -B build-pgo-generate -S . && cmake --build build-pgo-generate $(CMAKE_BUILD_FLAGS)

	@echo "Stage 2: Gathering profile data..."
	@$(call MK_PATH,"build-pgo-generate/clockwork$(SUFFIX)") bench > /dev/null 2>&1

	@echo "Stage 2.5: Merging profile data..."
	$(LLVM_PROFDATA) merge -output="$(CURDIR)/pgo-data/default.profdata" $(CURDIR)/pgo-data/*.profraw

	@echo "Cleaning up raw profile data..."
	-$(RM) $(CURDIR)/pgo-data/*.profraw

	@echo "Stage 3: Building optimized binary with profile data..."
	cmake -DCMAKE_BUILD_TYPE=Release $(CMAKE_FLAGS) -DCLOCKWORK_ENABLE_PGO_USE=ON -DCLOCKWORK_PGO_DIR="$(CURDIR)/pgo-data" -B build-release -S . && cmake --build build-release $(CMAKE_BUILD_FLAGS)
	$(COPY) $(call MK_PATH,"build-release/clockwork$(SUFFIX)") $(EXE)$(SUFFIX)

	@echo "Cleaning up merged profile data..."
	-$(RM) $(CURDIR)/pgo-data/default.profdata

	@echo "PGO build complete!"

endif

debug:
	cmake -DCMAKE_BUILD_TYPE=Debug $(CMAKE_FLAGS) -B build-debug -S . && cmake --build build-debug $(CMAKE_BUILD_FLAGS)
	$(COPY) $(call MK_PATH,"build-debug/clockwork$(SUFFIX)") $(EXE)$(SUFFIX)

evaltune:
	cmake -DCMAKE_BUILD_TYPE=Release $(CMAKE_FLAGS) -DCLOCKWORK_ENABLE_EVALTUNE=ON -B build-evaltune -S . && cmake --build build-evaltune $(CMAKE_BUILD_FLAGS)
	$(COPY) $(call MK_PATH,"build-evaltune/clockwork-evaltune$(SUFFIX)") $(EXE)-evaltune$(SUFFIX)

evaltune-debug:
	cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo $(CMAKE_FLAGS) -DCLOCKWORK_ENABLE_EVALTUNE=ON -B build-evaltune-debug -S . && cmake --build build-evaltune-debug $(CMAKE_BUILD_FLAGS)
	$(COPY) $(call MK_PATH,"build-evaltune-debug/clockwork-evaltune$(SUFFIX)") $(EXE)-evaltune$(SUFFIX)

bench: release
	./$(EXE)$(SUFFIX) bench

test: release
	ctest --test-dir build-release

clean:
	-$(RM_DIR) build-debug build-release build-evaltune build-evaltune-debug build-pgo-generate
	-$(RM_DIR) $(CURDIR)/pgo-data
	-$(RM) $(EXE)$(SUFFIX)

format:
	./scripts/auto_format.sh