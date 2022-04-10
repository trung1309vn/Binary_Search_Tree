#ifndef BST_HPP_
#define BST_HPP_

#include "BST.h"

template <typename T>
Tree<T>::~Tree()
{
    std::cout << "Clearing tree\n";
    while (root_ != nullptr)
    {
        _remove(root_->data);
    }
}

template <typename T>
int Tree<T>::height()
{
    return _height(0, root_);
}

template <typename T>
bool Tree<T>::is_full()
{
    return _is_full(root_);
}

template <typename T>
bool Tree<T>::_is_full(TreeNode *&current_node)
{
    if (current_node == nullptr)
        return true;

    if ((current_node->left == nullptr && current_node->right != nullptr)
     || (current_node->left != nullptr && current_node->right == nullptr))
    {
        return false;
    }

    return _is_full(current_node->left) && _is_full(current_node->right);
}

template <typename T>
int Tree<T>::_height(int current_level, TreeNode *&current_node)
{
    if (current_node == nullptr)
        return std::max(0, current_level - 1);
    
    int left_height = _height(current_level + 1, current_node->left);
    int right_height = _height(current_level + 1, current_node->right);

    return std::max(left_height, right_height);
}

template <typename T>
void Tree<T>::add_node(const T &data)
{
    // Check the existance of data in Tree
    TreeNode *&check_node = _find(data, root_);

    if (check_node != nullptr)
    {
        std::cout << "Data existed\n";
        return;
    }
    
    // Add new node
    check_node = new TreeNode(data);
}

template <typename T>
void Tree<T>::traverse(const int &order)
{
    _traverse(root_, order);    
}

template <typename T>
void Tree<T>::_traverse(TreeNode *&current_node, const int &order)
{
    if (current_node == nullptr)
        return;
    
    // Pre-order traversal
    if (order == -1)
    {
        std::cout << "Current value: " << current_node->data << std::endl;
        _traverse(current_node->left, order);
        _traverse(current_node->right, order);
    }
    // In-order traversal
    else if (order == 0)
    {
        _traverse(current_node->left, order);
        std::cout << "Current value: " << current_node->data << std::endl;
        _traverse(current_node->right, order);
    }
    // Post-order traversal
    else
    {
        _traverse(current_node->left, order);
        _traverse(current_node->right, order);
        std::cout << "Current value: " << current_node->data << std::endl;
    }
}

template <typename T>
bool Tree<T>::find(const T &data)
{
    TreeNode *&found_node = _find(data, root_);

    if (found_node != nullptr)
    {
        return true;
    }
    return false;
}

template <typename T>
typename Tree<T>::TreeNode *&Tree<T>::_find(const T &data, TreeNode *&current_node)
{
    if (current_node == nullptr)
        return current_node;

    if (current_node->data == data)
        return current_node;
    
    if (data > current_node->data)
        return _find(data, current_node->right);
    else
        return _find(data, current_node->left);
}

template <typename T>
void Tree<T>::remove(const T &data)
{
    _remove(data);
}

template <typename T>
void Tree<T>::_remove(const T &data)
{
    TreeNode *& to_be_removed = _find(data, root_);

    if (to_be_removed == nullptr)
    {
        std::cout << "Data doesn't exist in tree.\n";
        return;
    }

    // The removed node is the leaf
    if (to_be_removed->left == nullptr && to_be_removed->right == nullptr)
    {
        std::cout << "Leaf removed. Value: " << to_be_removed->data << "\n";
        delete to_be_removed;
        to_be_removed = nullptr;
        return;
    }

    // The removed node has one child
    if ((to_be_removed->left != nullptr && to_be_removed->right == nullptr)
     || (to_be_removed->right != nullptr && to_be_removed->left == nullptr))
    {
        std::cout << "One child node removed. Value: " << to_be_removed->data << "\n";
        
        // Left child
        if (to_be_removed->left != nullptr)
        {
            TreeNode *tmp = to_be_removed;
            to_be_removed = to_be_removed->left;
            delete tmp;
            tmp = nullptr;
        }
        // Right child
        else
        {
            TreeNode *tmp = to_be_removed;
            to_be_removed = to_be_removed->right;
            delete tmp;
            tmp = nullptr;
        }

        return;
    }

    // The removed node has two children
    if (to_be_removed->left != nullptr && to_be_removed->right != nullptr)
    {
        std::cout << "Two children node removed. Value: " << to_be_removed->data << "\n";

        // Get IOP node
        TreeNode *&iop_node = _IOP(to_be_removed->left);

        // Replace value of to_be_removed by iop_node
        to_be_removed->data = iop_node->data;

        // Remove the iop_node
        TreeNode *tmp = iop_node;
        iop_node = iop_node->left;
        delete tmp;
        tmp = nullptr;
    }
}

template <typename T>
typename Tree<T>::TreeNode *& Tree<T>::_IOP(TreeNode *&current_node)
{
    if (current_node->right != nullptr)
        return _IOP(current_node->right);
    else
        return current_node;
}

#endif
