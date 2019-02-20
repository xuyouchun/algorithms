
#ifndef _MIN_HEAP_H_
#define _MIN_HEAP_H_

#include <common.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    class min_heap_t
    {
        typedef char __element_t;
        typedef min_heap_t __self_t;

    public:
        min_heap_t(size_t heap_size = 1024) : __heap_size(heap_size + 1)
        {
            __heap = new_array<__element_t>(__heap_size);
        }

        void push(__element_t element);
        __element_t pop();

        bool   empty() const { return __current_index == 0; }
        size_t size()  const { return __current_index; }

        void print();

        ~min_heap_t()
        {
            delete_array(__heap);
        }

    private:
        __element_t * __heap;
        size_t __current_index = 0;
        const size_t __heap_size;

        void __sit_down(size_t n);
    };

    ////////// ////////// ////////// ////////// //////////

    void min_heap_test();

    ////////// ////////// ////////// ////////// //////////
}

#endif // _MIN_HEAP_H_
