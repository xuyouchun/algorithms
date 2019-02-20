
#include <common.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    size_t __tree_node_offset(int n)
    {
        static size_t offsets[32];
        static int cal_pos = 0;

        while(cal_pos < n)
        {
            cal_pos++;
            offsets[cal_pos] = offsets[cal_pos - 1] * 2 + 1;
        }

        return offsets[n];
    }

    void __print_spaces(int n)
    {
        for(int k = 0; k < n; k++)
        {
            std::cout << ' ';
        }
    }

    ////////// ////////// ////////// ////////// //////////
}
