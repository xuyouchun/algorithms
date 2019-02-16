
#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <common.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    class min_heap_t
    {
        typedef int __element_t;
        typedef min_heap_t __self_t;

    public:
        min_heap_t(size_t heap_size) : __heap_size(heap_size)
        {
            __heap = new_array<__element_t>(heap_size);
        }

        void push(__element_t element);
        __element_t pop();

        ~min_heap_t()
        {
            delete_array(__heap);
        }

    private:
        __element_t * __heap;
        const size_t __heap_size;
    };

    ////////// ////////// ////////// ////////// //////////

    void min_heap_test();

    ////////// ////////// ////////// ////////// //////////
}

#endif // _MIN_HEAP_H_
