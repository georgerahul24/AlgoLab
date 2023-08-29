#include <iostream>

using namespace std;

#include <cstdlib>
#include "limits.h"


void printArray(int *arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    cout << "\n";
}


int min(int a, int b, bool *changed) {
    if (a > b) {
        *changed = true;
        return b;
    } else {
        *changed = false;
        return a;
    }
}


int sumOfArrays(int *arrSizes, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arrSizes[i];
    }
    return sum;
}


int findMin(int **array, int *arrayIndexes, int n) {
    int current_min = INT32_MAX; //initialise to the minimum
    int current_array = 0;
    bool changed = false;
    for (int i = 0; i < n; i++) {
        current_min = min(current_min, array[i][arrayIndexes[i]], &changed);
        if (changed) current_array = i;
        changed = false;
    }
    arrayIndexes[current_array] = arrayIndexes[current_array] + 1; //update the index of the array that was changed
    return current_min;

}


int *mergeNArrays(int n, int **arrays, int *arrSizes) {
    const int finalArraySize = sumOfArrays(arrSizes, n);
    int *finalArray = new int(finalArraySize);
    int finalArrayIndex = 0;
    int *arrayIndexes{new int[n]{0, 0}};
    int current_min = INT32_MIN;

    current_min = findMin(arrays, arrayIndexes, n);
    while (current_min!=INT32_MAX) {
        finalArray[finalArrayIndex++] = current_min;
        current_min = findMin(arrays, arrayIndexes, n);
    }

    return finalArray;


}


int main() {
    int arr1[] = {8, 100, 230, INT_MAX};
    int arr2[] = {1, 4, 7, 9, 10, INT_MAX};
    int **arrs = new int *[2];
    arrs[0] = arr1;
    arrs[1] = arr2;

    int *arr_size = new int[2];
    arr_size[0] = 4;
    arr_size[1] = 6;


    int *ans = mergeNArrays(2, arrs, arr_size);

    printArray(ans, 10);

}
