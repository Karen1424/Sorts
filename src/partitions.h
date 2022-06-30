#ifndef PARTITIONS_H
#define PARTITIONS_H

#include "utils.h"

namespace SortPartitions {

    template <typename Iterator, typename Compare>
    Iterator partition(Iterator begin_, Iterator end_, Compare compare_) {

        auto pivot = std::prev(end_);
        auto i = begin_;

        for (auto j = begin_; j != pivot; ++j) {
            if (compare_(*j, *pivot)) {
                Utility::swap(*j, *i);
                ++i;
            }
        }
        Utility::swap(*i, *pivot);
        return i;
    }

    template <typename T>
    void merge(std::vector<T> & vec_, int begin_, int mid_, int end_) {

        int leftVecSize  = mid_ - begin_ + 1;
        int rightVecSize = end_ - mid_;

        /// reserve 2 vectors
        std::vector<T> leftVec(leftVecSize);
        std::vector<T> rightVec(rightVecSize);

        for (int i = 0; i < leftVecSize; ++i) {
            leftVec[i] = vec_[begin_ + i];
        }

        for (int i = 0; i < rightVecSize; ++i) {
            rightVec[i] = vec_[mid_ + i + 1];
        }

        int indexOfLeftVec = 0;
        int indexOfRightVec = 0;
        int indexOfMergedVec = begin_;

        while (indexOfLeftVec < leftVecSize && indexOfRightVec < rightVecSize) {
            if (leftVec[indexOfLeftVec] <= rightVec[indexOfRightVec]) {
                vec_[indexOfMergedVec] = leftVec[indexOfLeftVec];
                ++indexOfLeftVec;
            } else {
                vec_[indexOfMergedVec] = rightVec[indexOfRightVec];
                ++indexOfRightVec;
            }
            ++indexOfMergedVec;
        }

        while (indexOfLeftVec < leftVecSize) {
            vec_[indexOfMergedVec] = leftVec[indexOfLeftVec];
            ++indexOfLeftVec;
            ++indexOfMergedVec;
        }

        while (indexOfRightVec < rightVecSize) {
            vec_[indexOfMergedVec] = rightVec[indexOfRightVec];
            ++indexOfRightVec;
            ++indexOfMergedVec;
        }
    }

    template <typename T>
    void heapify(std::vector<T> & vec_, int size_, int index_) {

        int largest = index_;
        int left = index_ * 2 + 1;
        int right = index_ * 2 + 2;

        if (size_ > left && vec_[largest] < vec_[left]) largest = left;
        if (size_ > right && vec_[largest] < vec_[right]) largest = right;
        if (largest != index_) {
            Utility::swap(vec_[largest], vec_[index_]);
            heapify(vec_, size_, largest);
        }
    }
}; /// end of namespase SortPartitions

#endif
