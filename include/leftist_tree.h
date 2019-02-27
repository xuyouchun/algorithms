#ifndef _LEFTIST_TREE_H_
#define _LEFTIST_TREE_H_

#include <common.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    class leftlist_tree_node_t
    {
        friend class leftist_tree_t;

        typedef char __element_t;
        typedef leftlist_tree_node_t __self_t;

    public:
        leftlist_tree_node_t() = default;
        leftlist_tree_node_t(__element_t element) : element(element) { }

        __self_t * left = nullptr, * right = nullptr;
        int shortest = 1;

        __element_t element;
    };

    template<typename _stream_t>
    _stream_t & operator << (_stream_t & stream, const leftlist_tree_node_t & node)
    {
        return stream << node.element, stream;
    }

    ////////// ////////// ////////// ////////// //////////

    class leftist_tree_t
    {
        typedef leftist_tree_t __self_t;
        typedef leftlist_tree_node_t __node_t;
        typedef leftlist_tree_node_t::__element_t __element_t;

    public:
        leftist_tree_t() { }

        void push(__element_t element);
        __element_t pop();

        bool empty() const { return __root == nullptr; }
        void combine(__self_t * tree);

        void print();

    private:
        __node_t * __root = nullptr;

        void __combine(__node_t *& a, __node_t *& b);
        void __do_combine(__node_t *& a, __node_t *& b);

        __node_t * __new_node(__element_t element);
        void __delete_node(__node_t * node);
    };

    ////////// ////////// ////////// ////////// //////////

    void leftist_tree_test();
}


#endif      // _LEFTIST_TREE_H_

