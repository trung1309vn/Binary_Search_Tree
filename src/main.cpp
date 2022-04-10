#include "BST.hpp"

int main()
{
    Tree<int> tree;

    tree.add_node(4);
    tree.add_node(9);
    tree.add_node(7);
    tree.add_node(12);
    tree.add_node(-5);
    tree.add_node(10);
    tree.add_node(-1);
    tree.add_node(-2);
    tree.add_node(0);
    tree.add_node(22);
    tree.add_node(-10);
    tree.add_node(-8);
    tree.add_node(13);
    // tree.add_node(19);
    tree.add_node(99);
    tree.add_node(-12);

    std::cout << "Tree height: " << tree.height() << std::endl;
    std::cout << "IS full: " << tree.is_full() << std::endl;
    std::cout << "Remove 19\n";
    tree.remove(19);
    std::cout << "IS full: " << tree.is_full() << std::endl;
    std::cout << "Remove 4\n";
    tree.remove(4);
    std::cout << "IS full: " << tree.is_full() << std::endl;
    tree.traverse(0);
    return 0;
}