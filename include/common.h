
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    #define TEST_DATA                           \
        'Q', 'Z', 'D', 'W', 'V', 'L', 'P',      \
        'I', 'X', 'K', 'E', 'A', 'M', 'Y',      \
        'H', 'R', 'C', 'N', 'U', 'O',           \
        'G', 'J', 'T', 'F', 'B', 'S'

    ////////// ////////// ////////// ////////// //////////

    class error_t
    {
    public:
        error_t(const std::string & message) : message(message) { }

        std::string message;
    };

    ////////// ////////// ////////// ////////// //////////

    template<typename t> t * new_array(size_t size)
    {
        t * arr = new t[size];
        if(arr == nullptr)
            throw error_t("no enouth memory");

        return arr;
    }

    template<typename t> void delete_array(t * arr)
    {
        if(arr != nullptr)
            delete [] arr;
    }

    template<typename t, size_t n>
    constexpr size_t array_size(const t (&arr)[n])
    {
        return n;
    }

    template<typename t> double log2(t value)
    {
        return std::log(value) / std::log(2);
    }

    inline size_t pow2(size_t value)
    {
        return (size_t)std::pow(2, value);
    }

    /*
                   A                    # 15
           A               A            # 7 15
       A       A       A       A        # 3 7
     A   A   A   A   A   A   A   A      # 1 3
    A A A A A A A A A A A A A A A A     # 0 1

    */

    size_t __tree_node_offset(int n);
    void   __print_spaces(int n);

    template<typename t> void print_tree(const t * tree, size_t n)
    {
        if(n == 0)
            return;

        int height = (int)(std::log(n) / std::log(2)) + 1;
        const t * tree_end = tree + n + 1;
        tree++;

        for(int h = 1, count = 1; h <= height; h++, count *= 2)
        {
            size_t offset = __tree_node_offset(height - h);
            size_t space = __tree_node_offset(height - h + 1);

            __print_spaces(offset);

            for(int c = 0, c_count = std::min(count, (int)(tree_end - tree)); c < c_count; c++)
            {
                if(c > 0)
                    __print_spaces(space);

                std::cout << *tree++;
            }

            std::cout << std::endl;
        }
    }

    namespace
    {
        template<typename _node_t>
        struct __element_t { _node_t * node; size_t index; };
    }

    template<typename _node_t> void print_tree(_node_t * node)
    {
        if(node == nullptr)
            return;

        typedef __element_t<_node_t> element_t;
        std::vector<element_t> elements;
        elements.push_back(element_t { node, 1 });

        for(size_t k = 0; k < elements.size(); k++)
        {
            element_t e = elements[k];
            if(e.node->left != nullptr)
                elements.push_back(element_t { e.node->left, e.index * 2 });

            if(e.node->right != nullptr)
                elements.push_back(element_t { e.node->right, e.index * 2 + 1 });
        }

        size_t n = elements[elements.size() - 1].index;
        int height = (int)std::log2(n) + 1;
        size_t index = 0;
        element_t e = elements[index++];

        for(int h = 1, count = 1; h <= height; h++, count *= 2)
        {
            size_t offset = __tree_node_offset(height - h);
            size_t space = __tree_node_offset(height - h + 1);

            __print_spaces(offset);

            size_t start = (size_t)std::pow(2, h - 1), end = (size_t)std::pow(2, h) - 1;
            for(size_t k = start; k <= end; k++)
            {
                if(k != start)
                    __print_spaces(space);

                if(e.index != k)
                {
                    std::cout << ' ';
                }
                else
                {
                    std::cout << *e.node;
                    if(index >= elements.size())
                        break;

                    e = elements[index++];
                }
            }

            std::cout << std::endl;
        }
_end:;
    }

    ////////// ////////// ////////// ////////// //////////
}

#endif // _COMMON_H_
