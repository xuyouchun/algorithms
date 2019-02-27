#ifndef _DOUBLE_ENDED_HEAP_H_
#define _DOUBLE_ENDED_HEAP_H_

#include <common.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    class double_ended_heap_t
    {
        typedef char __element_t;
        typedef double_ended_heap_t __self_t;

    public:
        double_ended_heap_t(size_t heap_size = 1024) : __heap_size(heap_size + 2)
        {
            __heap = new_array<__element_t>(__heap_size); 
            __heap[1] = ' ';
        }

        void push(__element_t element);
        __element_t pop_min();
        __element_t pop_max();

        bool   empty() const { return size() == 0; }
        size_t size()  const { return __current_index - 1; }

        void print();

        ~double_ended_heap_t()
        {
            delete_array(__heap);
        }

    private:
        __element_t * __heap;
        size_t __current_index = 1;
        const size_t __heap_size;

        void __min_insert(size_t i, __element_t element);
        void __max_insert(size_t i, __element_t element);

        bool __at_max_heap(size_t k);
        size_t __min_partner(size_t k);
        size_t __max_partner(size_t k);
    };

    ////////// ////////// ////////// ////////// //////////

    void double_ended_heap_test();
}

#endif  // _DOUBLE_ENDED_HEAP_H_
