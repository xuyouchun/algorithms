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
                __walk_min_layer(element, k);
            }
            else
            {
                __heap[k] = __heap[k / 2];
                __walk_max_layer(element, k / 2);
            }
        }
        else    // at max layer
        {
            if(element > __heap[k / 2])
            {
                __walk_max_layer(element, k);
            }
            else
            {
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

        __heap[0] = std::numeric_limits<__element_t>::max();
        __element_t y = __heap[1];
        __element_t x = __heap[__current_index--];

        size_t i = 1, j = __current_index / 2;
        while(i <= j)
        {
            size_t k = __min_child(i);
            if(x <= __heap[k])
                break;

            __heap[i] = __heap[k];
            if(k <= 2 * i + 1)
            {
                i = k;
                break;
            }

            size_t p = k / 2;
            if(x > __heap[p])
            {
                std::swap(__heap[p], x);
            }

            i = k;
        }

        __heap[i] = x;

        return y;
    }

    min_max_heap_t::__element_t min_max_heap_t::pop_max()
    {
        switch(__current_index)
        {
            case 0:
                throw error_t("heap empty");

            case 1:
                __current_index = 0;
                return __heap[1];

            case 2:
                __current_index = 1;
                return __heap[2];
        }

        size_t i = __heap[2] > __heap[3] ? 2 : 3;
        __heap[0] = std::numeric_limits<__element_t>::min();
        __element_t y = __heap[i];
        __element_t x = __heap[__current_index--];

        size_t j = __current_index / 2;
        while(i <= j)
        {
            size_t k = __max_child(i);
            if(x >= __heap[k])
                break;

            __heap[i] = __heap[k];
            if(k <= 2 * i + 1)
            {
                i = k;
                break;
            }

            size_t p = k / 2;
            if(x < __heap[p])
            {
                std::swap(__heap[p], x);
            }

            i = k;
        }

        __heap[i] = x;

        return y;
    }

    size_t min_max_heap_t::__min_child(size_t k)
    {
        if(k * 4 > __current_index)
        {
            if(k * 2 > __current_index)
                return k;

            size_t left = k * 2, right = left + 1;
            return __heap[left] < __heap[right]? left : right;
        }

        size_t min_index = k * 4;
        for(size_t i = min_index + 1, i_end = std::min(min_index + 3, __current_index);
            i <= i_end; i++)
        {
            if(__heap[i] < __heap[min_index])
            {
                min_index = i;
            }
        }

        return min_index;
    }

    size_t min_max_heap_t::__max_child(size_t k)
    {
        if(k * 4 > __current_index)
        {
            if(k * 2 > __current_index)
                return k;

            size_t left = k * 2, right = left + 1;
            return __heap[left] > __heap[right]? left : right;
        }

        size_t max_index = k * 4;
        for(size_t i = max_index + 1, i_end = std::min(max_index + 3, __current_index);
            i <= i_end; i++)
        {
            if(__heap[i] > __heap[max_index])
            {
                max_index = i;
            }
        }

        return max_index;
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
            auto value1 = heap.pop_max();
            std::cout << "\n------------- " << value1 << std::endl;
            heap.print();

            auto value2 = heap.pop_min();
            std::cout << "\n------------- " << value2 << std::endl;
            heap.print();
        }
    }

    ////////// ////////// ////////// ////////// //////////
}

