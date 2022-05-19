#include "OrgChart.hpp"
#include <string>
using namespace ariel;

OrgChart::OrgChart(){}

OrgChart& OrgChart::add_root(const std::string &root) {
    return *this;
}

OrgChart& OrgChart::add_sub(const std::string &parent, const std::string &child) {
    return *this;
}

OrgChart::Iterator OrgChart::begin_level_order() {Iterator test;return test;}
OrgChart::Iterator OrgChart::end_level_order(){Iterator test;return test;}

OrgChart::Iterator OrgChart::begin_reverse_order(){Iterator test;return test;}
OrgChart::Iterator OrgChart::reverse_order(){Iterator test;return test;}

OrgChart::Iterator OrgChart::begin_preorder(){Iterator test;return test;}
OrgChart::Iterator OrgChart::end_preorder(){Iterator test;return test;}

OrgChart::Iterator OrgChart::begin(){Iterator test;return test;}
OrgChart::Iterator OrgChart::end(){Iterator test;return test;} 

namespace ariel {

    std::ostream& operator << (std::ostream &out, const OrgChart &Chart) {
        return out;
    }

}