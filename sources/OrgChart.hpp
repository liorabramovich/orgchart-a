#include <string>
#include <iostream>
// #include "Node.hpp"

namespace ariel
{
    class Node
    {
    private:
        std::string data;

    public:
    };

    class OrgChart
    {
    private:
    public:
        class Iterator
        {

        private:
            Node *Current;

        public:
            Iterator(Node *ptr = nullptr) : Current(ptr){};
            int size(){return 1;}
            std::string operator*(){return "test";}
            Iterator* operator->(){return this;}
            Iterator& operator++(){return *this;};
            Iterator& operator++(int){return *this;}
            bool operator==(const Iterator &lh){return true;}
            bool operator!=(const Iterator &lh){return false;}

        };
        OrgChart();
        OrgChart &add_root(const std::string &root);
        OrgChart &add_sub(const std::string &parent, const std::string &child);

        Iterator begin_level_order();
        Iterator end_level_order();

        Iterator begin_reverse_order();
        Iterator reverse_order();

        Iterator begin_preorder();
        Iterator end_preorder();

        Iterator begin();
        Iterator end();
        int size(){return 1;}
         friend std::ostream& operator<<(std::ostream& out,  const OrgChart &Chart);
    };

}