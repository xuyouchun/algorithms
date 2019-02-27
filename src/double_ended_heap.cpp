#include <double_ended_heap.h>

namespace algorithms
{
    ////////// ////////// ////////// ////////// //////////

    void double_ended_heap_t::push(__element_t element)
    {
        if(__current_index >= __heap_size - 2)
            throw error_t("heap full");

        __current_index++;
        if(__current_index == 2)
        {
            __heap[__current_index] = element;
            return;
        }

        if(__at_max_heap(__current_index))
        {
            size_t i = __min_partner(__current_index);
            if(element < __heap[i])
            {
                __heap[__current_index] = __heap[i];
                __min_insert(i, element);
            }
            else
            {
                __max_insert(i, element);
            }
        }
        else
        {
            size_t i = __max_partner(__current_index);
            if(element > __heap[i])
            {
                __heap[__current_index] = __heap[i];
                __max_insert(i, element);
            }
            else
            {
                __min_insert(i, element);
            }
        }
    }

    void double_ended_heap_t::__min_insert(size_t i, __element_t element)
    {
        for(size_t parent = i / 2; parent >= 1 && element < __heap[parent]; i = parent, parent /= 2)
        {
            __heap[i] = __heap[parent];
        }

        __heap[i] = element;
    }

    void double_ended_heap_t::__max_insert(size_t i, __element_t element)
    {
        for(size_t parent = i / 2; parent > 1 && element > __heap[parent]; i = parent, parent /= 2)
        {
            __heap[i] = __heap[parent];
        }

        __heap[i] = element;
    }

    double_ended_heap_t::__element_t double_ended_heap_t::pop_min()
    {
        return 'A';
    }

    double_ended_heap_t::__element_t double_ended_heap_t::pop_max()
    {
        return 'A';
    }

    bool double_ended_heap_t::__at_max_heap(size_t k)
    {
        double a = log2(k);
        double b = log2(k + pow2((size_t)a - 1));

        return (size_t)a != (size_t)b;
    }

	size_t double_ended_heap_t::__min_partner(size_t k)
	{
		double a = pow2((size_t)log2(k) - 1);
		return k - (int)a;
	}

	size_t double_ended_heap_t::__max_partner(size_t k)
	{
		double a = pow2((size_t)log2(k) - 1);
		return (k + (int)a) / 2;
	}

    void double_ended_heap_t::print()
    {
        print_tree(__heap, __current_index);
    }

    ////////// ////////// ////////// ////////// //////////

    void double_ended_heap_test()
    {
        std::cout << "double ended heap" << std::endl;

        double_ended_heap_t heap(1024);
        char arr[] = { TEST_DATA };

        for(int k = 0; k < sizeof(arr) / sizeof(arr[0]); k++)
        {
            auto value = arr[k];
            heap.push(value);
        }

        heap.print();
    }
}
