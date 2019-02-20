
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

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

    ////////// ////////// ////////// ////////// //////////
}

#endif // _COMMON_H_
