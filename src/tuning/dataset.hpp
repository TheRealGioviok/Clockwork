#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <optional>
#include <random>
#include <span>
#include <stdexcept>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "../position.hpp"
#include "graph.hpp"
#include "value.hpp"

namespace Clockwork::Autograd {

class PersyFormatDataset {
public:
    using index_t = std::size_t;

    PersyFormatDataset(std::vector<std::string> files) :
        m_data_files(std::move(files)) {
        if (m_data_files.empty()) {
            throw std::invalid_argument("At least one data file must be provided");
        }
    }

    template<typename... Files>
    PersyFormatDataset(Files&&... f) {
        (m_data_files.emplace_back(std::forward<Files>(f)), ...);
        if (m_data_files.empty()) {
            throw std::invalid_argument("At least one data file must be provided");
        }
    }

    void load() {
        for (const auto& filename : m_data_files) {
            std::ifstream file(filename);
            if (!file) {
                throw std::runtime_error("Error opening data file: " + filename);
            }

            std::string line;
            std::size_t line_count = 0;

            while (std::getline(file, line)) {
                ++line_count;
                auto pos = line.find(';');
                if (pos == std::string::npos) {
                    std::cout << "Warning: Invalid line format @" << filename << ':' << line_count << '\n';
                    continue;
                }

                std::string fen    = line.substr(0, pos);
                auto        parsed = Position::parse(fen);
                if (!parsed) {
                    std::cout << "Warning: Invalid FEN @" << filename << ':' << line_count << '\n';
                    continue;
                }
                positions.push_back(*parsed);

                std::string result = line.substr(pos + 1);
                result.erase(std::remove_if(result.begin(), result.end(), ::isspace), result.end());

                if (result == "w") {
                    results.push_back(1.0);
                } else if (result == "d") {
                    results.push_back(0.5);
                } else if (result == "b") {
                    results.push_back(0.0);
                } else {
                    std::cout << "Warning: Invalid result @" << filename << ':' << line_count << '\n';
                    // Remove the last position added since the result is invalid
                    positions.pop_back();
                    continue;
                }
            }
        }

        indices.resize(positions.size());
        std::iota(indices.begin(), indices.end(), 0);
    }

    void shuffle_indices(std::mt19937& rng) {
        std::shuffle(indices.begin(), indices.end(), rng);
    }

    struct BatchView {
        std::span<const Position> positions;
        std::span<const f64>      results;
    };

    class BatchIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type        = BatchView;

        BatchIterator(const PersyFormatDataset* ds, index_t start, index_t batch) :
            ds_(ds),
            index_(start),
            batch_size_(batch) {
            refresh_buffer();
        }

        bool operator==(const BatchIterator& other) const {
            return index_ == other.index_ && ds_ == other.ds_;
        }
        bool operator!=(const BatchIterator& other) const {
            return !(*this == other);
        }

        value_type operator*() const {
            return buffer_;
        }

        BatchIterator& operator++() {
            index_ = std::min(index_ + batch_size_, ds_->size());
            refresh_buffer();
            return *this;
        }

    private:
        const PersyFormatDataset* ds_;
        index_t                   index_      = 0;
        index_t                   batch_size_ = 1;

        BatchView                    buffer_{};
        std::vector<index_t>         index_window_;
        std::vector<const Position*> pos_ptrs_;
        std::vector<const f64*>      res_ptrs_;

        void refresh_buffer() {
            if (!ds_ || index_ >= ds_->size()) {
                buffer_ = {{}, {}};
                return;
            }

            size_t end = std::min(index_ + batch_size_, ds_->size());
            index_window_.assign(ds_->indices.begin() + index_, ds_->indices.begin() + end);

            pos_ptrs_.clear();
            res_ptrs_.clear();
            pos_ptrs_.reserve(index_window_.size());
            res_ptrs_.reserve(index_window_.size());

            for (auto idx : index_window_) {
                pos_ptrs_.push_back(&ds_->positions[idx]);
                res_ptrs_.push_back(&ds_->results[idx]);
            }

            buffer_.positions = std::span<const Position>(
              reinterpret_cast<const Position*>(pos_ptrs_.data()), pos_ptrs_.size());
            buffer_.results = std::span<const f64>(reinterpret_cast<const f64*>(res_ptrs_.data()),
                                                   res_ptrs_.size());
        }
    };

    class BatchRange {
    public:
        BatchRange(const PersyFormatDataset* ds, index_t batch) :
            ds_(ds),
            batch_size_(batch) {
        }

        BatchIterator begin() const {
            return {ds_, 0, batch_size_};
        }
        BatchIterator end() const {
            return {ds_, ds_->size(), batch_size_};
        }

    private:
        const PersyFormatDataset* ds_;
        index_t                   batch_size_;
    };

    BatchRange batches(index_t batch_size) const {
        return BatchRange(this, batch_size);
    }

    BatchRange batches(index_t batch_size, index_t /*prefetch_depth*/) const {
        return BatchRange(this, batch_size);
    }


    index_t size() const {
        return positions.size();
    }

    std::vector<Position> positions;
    std::vector<f64>      results;
    std::vector<index_t>  indices;

private:
    std::vector<std::string> m_data_files;
};

}  // namespace Clockwork::Autograd
