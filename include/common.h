
#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <iostream>

namespace algorithms
{
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

    ////////// ////////// ////////// ////////// //////////
}

#endif // _COMMON_H_
