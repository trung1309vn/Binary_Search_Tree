#include <iostream>

template <typename T>
class Tree
{
    public:
        Tree(): root_(nullptr){}
        ~Tree();
        void add_node(const T &data);
        bool find(const T &data);
        void traverse(const int &order);
        int height();
        bool is_full();
        void remove(const T &data);

    private:
        class TreeNode
        {
            public:
                T data;
                TreeNode *left, *right;
                TreeNode(const T &data): data(data), left(nullptr), right(nullptr){}
        };

        TreeNode *root_;
        TreeNode *& _find(const T &data, TreeNode *&current_node);
        void _traverse(TreeNode *&current_node, const int &order);
        int _height(int current_level, TreeNode *&current_node);
        bool _is_full(TreeNode *&current_node);
        void _remove(const T &data);
        
        // In-order predecessor (IOP) - Get the right most node on the left branch of current node
        TreeNode *& _IOP(TreeNode *&current_node);
};
