#include "sorts.hpp"

int main() {

    std::vector<int> vec {2, 3, -9, 5, -8, 12, 5, 1, 0, 81, 12};
    Utility::printElems(vec);
    //Sorts::boubleSort(vec.begin(), vec.end());
    //Sorts::selectionSort(vec.begin(), vec.end());
    //Sorts::insertionSort(vec.begin(), vec.end());
    //Sorts::quickSort(vec.begin(), vec.end(), [](int x, int y) {
    //    return x < y;
    //});
    //Sorts::mergeSort(vec, 0, vec.size() - 1);
    //Sorts::heapSort(vec);
    Utility::printElems(vec);

    return 0;
}
