#ifndef _MIN_MAX_HEAP_H_
#define _MIN_MAX_HEAP_H_

#include <common.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    class min_max_heap_t
    {
        typedef char __element_t;
        typedef min_max_heap_t __self_t;

    public:
        min_max_heap_t(size_t heap_size = 1024) : __heap_size(heap_size + 1)
        {
            __heap = new_array<__element_t>(__heap_size);
        }

        void push(__element_t element);
        __element_t pop_min();
        __element_t pop_max();

        bool   empty() const { return __current_index == 0; }
        size_t size()  const { return __current_index; }

        void print();

        ~min_max_heap_t()
        {
            delete_array(__heap);
        }

    private:
        __element_t * __heap;
        size_t __current_index = 0;
        const size_t __heap_size;

        void __sit_down(size_t n);
        bool __at_min_layer(size_t n);

        void __walk_min_layer(__element_t element, size_t k);
        void __walk_max_layer(__element_t element, size_t k);

        void __sit_down_min_layer(size_t k);
        void __sit_down_max_layer(size_t k);
    };

    ////////// ////////// ////////// ////////// //////////

    void min_max_heap_test();
}


#endif // _MIN_MAX_HEAP_H_

