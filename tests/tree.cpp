#include <catch.hpp>
#include <sstream>
#include "tree_t.hpp"

TEST_CASE ("insert")
{
    tree_t<int> tree;
    tree.insert(8);
    tree.insert(10);
    tree.insert(7);
    std::string output
    {
        "--------10/n"
        "----8/n"
        "--------7/n"
    }
    std::ostringstream ostream;
    tree print(ostream);
    REQUIRE (ostream.str() == output);
}

TEST_CASE ("print")
{
    tree<int> tree;
    tree.insert(15);
    tree.insert(18);
    tree.insert(10);
    tree.insert(8);
    tree.insert(16);
    std::string output;
    {
        "--------18/n"
        "------------16/n"
        "----15/n"
        "--------10/n"
        "------------8/n"
    }
    std::ostringstream ostream;
    tree print(ostream);
    REQUIRE (ostream.str() == output);
}

TEST_CASE ("remove")
{
    tree_t<double> tree;
    tree.insert(8.3);
    tree.insert(10.5);
    tree.insert(7.4);
    tree.insert(9.1);
    tree.insert (12.2);
    REQUIRE (tree.remove(10.5) == true);
    std::string output;
    {
        "--------12.2/n"
        "------------9.1/n"
        "----8.3/n"
        "--------7.4/n"
    }
    std::ostringstream ostream;
    tree print(ostream);
    REQUIRE (ostream.str() == output);
}

TEST_CASE ("comparasion")
{
    tree<int> tree1, tree2;
    
    tree1.insert(8);
    tree1.insert(10);
    tree1.insert(7);
    
    tree2.insert(8);
    tree2.insert(10);
    tree2.insert(7);
    
    REQUIRE ((tree1==tree2)==true);
}

TEST_CASE ("initializer list")
{
    tree_t<int> tree {10, 20, 5, 6};
    std::string output
    {
        "--------20/n"
        "----10/n"
        "------------6/n"
        "--------5/n"
    }
    std::ostringstream ostream;
    tree print(ostream);
    REQUIRE (ostream.str() == output);
}