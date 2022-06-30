#include "partitions.h"

namespace Sorts {

    template <typename Iterator>
    void boubleSort(Iterator begin_, Iterator end_) {

        bool flag = true;
        for (auto i = begin_; i != end_; ++i) {
            flag = true;
            for (auto j = std::prev(end_); j != i; --j) {
                if (*j < *std::prev(j)) {
                    Utility::swap(*j, *std::prev(j));
                    flag = false;
                }
            }
            if (flag) break;
        }
    }

    template <typename Iterator>
    void selectionSort(Iterator begin_, Iterator end_) {

        auto min = begin_;
        for (auto i = begin_; i != std::prev(end_); ++i) {
            min = i;
            for (auto j = std::next(i); j != end_; ++j) {
                if (*j < *min) min = j;
            }
            Utility::swap(*i, *min);
        }
    }

    template <typename Iterator>
    void insertionSort(Iterator begin_, Iterator end_) {

        for (auto j = std::next(begin_); j != end_; ++j) {
            auto i = std::prev(j);
            auto key = *j;

            while (i != std::prev(begin_) && *i > key) {
                *std::next(i) = *i;
                --i;
            }
            *std::next(i) = key;
        }
    }

    template <typename Iterator, typename Compare>
    void quickSort(Iterator begin_, Iterator end_, Compare compare_) {

        if (1 < std::distance(begin_, end_)) {
            auto bound = SortPartitions::partition(begin_, end_, compare_);
            quickSort(begin_, bound, compare_);
            quickSort(std::next(bound), end_, compare_);
        }
    }

    template <typename T>
    void mergeSort(std::vector<T> & vec_, int begin_, int end_) {

        if (begin_ >= end_) return;
        int mid = begin_ + (end_ - begin_) / 2;
        mergeSort(vec_, begin_, mid);
        mergeSort(vec_, mid + 1, end_);
        SortPartitions::merge(vec_, begin_, mid, end_);
    }

    template <typename T>
    void heapSort(std::vector<T> & vec_) {

        for (int i = vec_.size() / 2; i >= 0; --i) {
            SortPartitions::heapify(vec_, vec_.size(), i);
        }

        for (int i = vec_.size() - 1; i >= 0; --i) {
            Utility::swap(vec_[i], vec_[0]);
            SortPartitions::heapify(vec_, i, 0);
        }
    }
}; /// end of namespace Sorts
