#include <min_max_heap.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    void min_max_heap_t::push(min_max_heap_t::__element_t element)
    {
        if(__current_index >= __heap_size - 1)
            throw error_t("heap full");

        size_t k = ++__current_index;

        if(__current_index == 1)
        {
            __heap[k] = element;
            return;
        }

        if(__at_min_layer(k))
        {
            if(element < __heap[k / 2])
            {
                std::cout << "---------- 1" << std::endl;
                __walk_min_layer(element, k);
            }
            else
            {
                std::cout << "---------- 2" << std::endl;
                __heap[k] = __heap[k / 2];
                __walk_max_layer(element, k / 2);
            }
        }
        else    // at max layer
        {
            if(element > __heap[k / 2])
            {
                std::cout << "---------- 3" << std::endl;
                __walk_max_layer(element, k);
            }
            else
            {
                std::cout << "---------- 4" << std::endl;
                __heap[k] = __heap[k / 2];
                __walk_min_layer(element, k / 2);
            }
        }
    }

    void min_max_heap_t::__walk_min_layer(__element_t element, size_t k)
    {
        for(; k >= 4 && element < __heap[k / 4]; k /= 4)
        {
            __heap[k] = __heap[k / 4];
        }

        __heap[k] = element;
    }

    void min_max_heap_t::__walk_max_layer(__element_t element, size_t k)
    {
        for(; k >= 4 && element > __heap[k / 4]; k /= 4)
        {
            __heap[k] = __heap[k / 4];
        }

        __heap[k] = element;
    }

    min_max_heap_t::__element_t min_max_heap_t::pop_min()
    {
        if(__current_index == 0)
            throw error_t("heap empty");

        __heap[0] = __heap[1];

        if(--__current_index >= 1)
        {
            __heap[1] = __heap[--__current_index + 1];
            __sit_down_min_layer(1);
        }

        return __heap[0];
    }

    min_max_heap_t::__element_t min_max_heap_t::pop_max()
    {
        if(__current_index == 0)
            throw error_t("heap empty");

        

        return 0;
    }

    void min_max_heap_t::__sit_down_min_layer(size_t k)
    {
        size_t left = k * 4;
        if(left > __current_index)
            return;

        // ?
    }

    void min_max_heap_t::__sit_down_max_layer(size_t k)
    {

    }

    bool min_max_heap_t::__at_min_layer(size_t n)
    {
        int layer = (int)(std::log(n) / std::log(2));
        return layer % 2 == 0;
    }

    void min_max_heap_t::print()
    {
        print_tree(__heap, __current_index);
    }

    ////////// ////////// ////////// ////////// //////////

    void min_max_heap_test()
    {
        std::cout << "min max heap" << std::endl;

        min_max_heap_t heap(1024);
        char arr[] = { TEST_DATA };

        for(int k = 0; k < sizeof(arr) / sizeof(arr[0]); k++)
        {
            auto value = arr[k];
            heap.push(value);
        }

        heap.print();

        while(!heap.empty())
        {
            std::cout << "-------------" << std::endl;

            heap.pop_min();
            heap.print();
        }
    }

    ////////// ////////// ////////// ////////// //////////
}

