#include <leftist_tree.h>

namespace algorithms
{
    typedef leftlist_tree_node_t __node_t;

    ////////// ////////// ////////// ////////// //////////

    void leftist_tree_t::__combine(__node_t *& a, __node_t *& b)
    {
        if(!a)
            a = b;
        else if(b)
            __do_combine(a, b);

        b = nullptr;
    }

    void leftist_tree_t::__do_combine(__node_t *& a, __node_t *& b)
    {
        if(a->element > b->element)
            std::swap(a, b);

        if(a->right == nullptr)
            a->right = b;
        else
            __do_combine(a->right, b);

        if(a->left == nullptr)
        {
            a->left = a->right;
            a->right = nullptr;
        }
        else if(a->right->shortest > a->left->shortest)
        {
            std::swap(a->left, a->right);
        }

        if(a->right == nullptr)
            a->shortest = 1;
        else
            a->shortest = a->right->shortest + 1;
    }

    __node_t * leftist_tree_t::__new_node(__element_t element)
    {
        return new __node_t(element);
    }

    void leftist_tree_t::__delete_node(__node_t * node)
    {
        if(node != nullptr)
            delete node;
    }

    void leftist_tree_t::push(__element_t element)
    {
        __node_t * node = __new_node(element);
        __combine(__root, node);
    }

    leftist_tree_t::__element_t leftist_tree_t::pop()
    {
        if(__root == nullptr)
            throw error_t("heap empty");

        __element_t element = __root->element;

        __combine(__root->left, __root->right);

        __node_t * root = __root;
        __root = __root->left;
        __delete_node(root);

        return element;
    }

    void leftist_tree_t::combine(__self_t * tree)
    {
        if(tree == nullptr)
            return;

        __combine(__root, tree->__root);
    }

    void leftist_tree_t::print()
    {
        print_tree(__root);
    }

    ////////// ////////// ////////// ////////// //////////

    void leftist_tree_test()
    {
        std::cout << "leftist tree" << std::endl;

        leftist_tree_t tree;
        char arr[] = { TEST_DATA };
        const size_t size = sizeof(arr) / sizeof(arr[0]);

        for(int k = 0; k < size / 2; k++)
        {
            auto value = arr[k];
            tree.push(value);

            std::cout << "---------- " << value << std::endl;
            tree.print();
        }

        leftist_tree_t tree2;
        for(int k = size / 2; k < size; k++)
        {
            auto value = arr[k];
            tree2.push(value);

            std::cout << "---------- " << value << std::endl;
            tree2.print();
        }

        tree.combine(&tree2);

        tree.print();

        while(!tree.empty())
        {
            std::cout << tree.pop() << std::endl;
        }
    }
}

