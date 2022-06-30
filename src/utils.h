#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>

/// helper functions
namespace Utility {

    template <typename T>
    void printElems(T & data_) {

        for (const auto & elem : data_) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    template <typename T>
    void swap(T & val1_, T & val2_) {

        T tmp = val1_;
        val1_ = val2_;
        val2_ = tmp;
    }
}; /// end of namespace Utility

#endif
