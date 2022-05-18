#include "doctest.h"
#include "sources/OrgChart.hpp"
#include "vector"
using namespace ariel;
using namespace std;

TEST_CASE("case 1")
{
    OrgChart Org;
    SUBCASE("Add_root")
    {
        CHECK_NOTHROW(Org.add_root("B"));
        CHECK_NOTHROW(Org.add_root("C"));
        CHECK_NOTHROW(Org.add_root("A"));
    }
    SUBCASE("Add_sub")
    {
        CHECK_NOTHROW(Org.add_sub("A", "B"));
        CHECK_NOTHROW(Org.add_sub("A", "C"));
        CHECK_NOTHROW(Org.add_sub("A", "D"));
        CHECK_NOTHROW(Org.add_sub("B", "E"));
        CHECK_NOTHROW(Org.add_sub("D", "F"));
    }
    SUBCASE("THROWS_Add_sub")
    {
        CHECK_NOTHROW(Org.add_sub("K", "Z"));
        CHECK_NOTHROW(Org.add_sub("F", "W"));
        CHECK_NOTHROW(Org.add_sub("T", "Q"));
    }
    SUBCASE("Level_order")
    {
        vector<string> Level_order_ans = {"A", "B", "C", "D", "E", "F"};
        OrgChart::Iterator myiter = Org.begin_level_order();
        for (unsigned int i = 0; i < Level_order_ans.size(); i++)
        {
            ++myiter;
            CHECK(Level_order_ans[i] == *myiter);
        }
    }
    SUBCASE("PreOrder")
    {
        vector<string> PreOrder_ans = {"A", "B", "E", "C", "D", "F"};
        OrgChart::Iterator myiter = Org.begin_level_order();
        for (unsigned int i = 0; i < PreOrder_ans.size(); i++)
        {
            ++myiter;
            CHECK(PreOrder_ans[i] == *myiter);
        }
    }
    SUBCASE("reverse_order")
    {
        vector<string> reverse_order_ans = {"E", "F", "B", "C", "D", "A"};
        OrgChart::Iterator myiter = Org.begin_level_order();
        for (unsigned int i = 0; i < reverse_order_ans.size(); i++)
        {
            ++myiter;
            CHECK(reverse_order_ans[i] == *myiter);
        }
    }
}

TEST_CASE("case 2")
{
    OrgChart Team;
    SUBCASE("Add_root")
    {
        CHECK_NOTHROW(Team.add_root("Coach"));
        CHECK_NOTHROW(Team.add_root("GK"));
        CHECK(*(Team.begin()) != "Coach");
    }
    SUBCASE("Add_sub")
    {
        CHECK_NOTHROW(Team.add_sub("GK", "LB"));
        CHECK_NOTHROW(Team.add_sub("GK", "CB"));
        CHECK_NOTHROW(Team.add_sub("GK", "RB"));
        CHECK_NOTHROW(Team.add_sub("CB", "CDM"));
        CHECK_NOTHROW(Team.add_sub("CDM", "CM1"));
        CHECK_NOTHROW(Team.add_sub("CDM", "CM2"));
        CHECK_NOTHROW(Team.add_sub("CM1", "CAM"));
        CHECK_NOTHROW(Team.add_sub("CAM", "LW"));
        CHECK_NOTHROW(Team.add_sub("CAM", "ST"));
        CHECK_NOTHROW(Team.add_sub("CAM", "RW"));
    }
    SUBCASE("Level_order")
    {
        CHECK_NE(*(Team.end()), "CAM");
        vector<string> Level_order_ans = {"GK", "LB", "CB", "RB", "CDM", "CM1", "CM2", "CAM", "LW", "RW"};
        OrgChart::Iterator myiter = Team.begin_level_order();
        for (unsigned int i = 0; i < Level_order_ans.size(); i++)
        {
            ++myiter;
            CHECK(Level_order_ans[i] == *myiter);
        }
    }
    SUBCASE("PreOrder")
    {
        CHECK_NE(*(Team.end()), "CAM");

        vector<string> PreOrder_ans = {"GK", "LB", "CB", "CDM", "CM1", "CAM", "LW", "ST", "RW", "CM2", "RB"};
        OrgChart::Iterator myiter = Team.begin_level_order();
        for (unsigned int i = 0; i < PreOrder_ans.size(); i++)
        {
            ++myiter;
            CHECK(PreOrder_ans[i] == *myiter);
        }
    }
    SUBCASE("reverse_order")
    {
        vector<string> reverse_order_ans = {"LW", "ST", "RW", "CAM", "CM1", "CM2", "CDM", "LB", "CB", "RB", "GK"};
        CHECK_NE(*(Team.end()), "CAM");

        OrgChart::Iterator myiter = Team.begin_level_order();
        for (unsigned int i = 0; i < reverse_order_ans.size(); i++)
        {
            ++myiter;
            CHECK(reverse_order_ans[i] == *myiter);
        }
    }
}
