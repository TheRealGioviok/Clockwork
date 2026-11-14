#include "root_move.hpp"
#include <ostream>

namespace Clockwork::Search {

std::ostream& operator<<(std::ostream& os, const PV& pv) {
    for (const auto& entry : pv.m_pv) {
        os << entry.move << ' ';
    }
    return os;
}

}
