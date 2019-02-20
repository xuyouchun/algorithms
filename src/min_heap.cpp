
#include <min_heap.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    void min_heap_t::push(min_heap_t::__element_t element)
    {
        if(__current_index >= __heap_size - 1)
            throw error_t("heap full");

        size_t k = ++__current_index;

        for(; k != 1 && element < __heap[k / 2]; k /= 2)
        {
            __heap[k] = __heap[k / 2];
        }

        __heap[k] = element;
    }

    min_heap_t::__element_t min_heap_t::pop()
    {
        if(__current_index == 0)
            throw error_t("heap empty");

        __element_t min = __heap[1];

        __heap[1] = __heap[__current_index];
        __current_index--;

        __sit_down(1);

        return min;
    }

    void min_heap_t::__sit_down(size_t n)
    {
        size_t left = n * 2, right = left + 1;
        if(left > __current_index)
            return;

        size_t sub = (right <= __current_index && __heap[right] < __heap[left])? right : left;
        if(__heap[n] > __heap[sub])
        {
            std::swap(__heap[n], __heap[sub]);
            __sit_down(sub);
        }
    }

    void min_heap_t::print()
    {
        print_tree(__heap, __current_index);
    }

    ////////// ////////// ////////// ////////// //////////

    void min_heap_test()
    {
        std::cout << "min heap" << std::endl;

        min_heap_t heap(1024);
        char arr[] = { TEST_DATA };

        for(auto value : arr)
        {
            heap.push(value);
        }

        heap.print();

        while(!heap.empty())
        {
            std::cout << "-------------" << std::endl;

            heap.pop();
            heap.print();
        }
    }

    ////////// ////////// ////////// ////////// //////////
}
