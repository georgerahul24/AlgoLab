#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

class Arr {

public:

    int n = 0;
    int **arr{};


    Arr() {
        cout << "Enter the number of items(n): " << endl;
        cin >> this->n;
        this->arr = new int *[n];

    }

    Arr(int n) {
        this->n = n;
        arr = new int *[n];
    }

    void fillArray(int m) {
        cout << "Enter the Wt and Value: " << endl;

        for (int i = 0; i < n; i++) {
            int *_arr = new int[m];
            for (int j = 0; j < m; j++) {
                cin >> _arr[j];
            }
            this->arr[i] = _arr;
        }

    }

    void fillArrayWithZeros(int m) {
        for (int i = 0; i < n; i++) {
            int *_arr = new int[m];
            this->arr[i] = _arr;
        }

    }


    void printArr(int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int *&operator[](int index) const {

        return arr[index];
    }


};


class KnapSack {
public:
    Arr arr{};
    int W{};
    int count = 0;

    KnapSack() {
        arr.fillArray(2);
        cout << "Enter the max weight(W):";
        cin >> this->W;
    }


    int calculateTopDown(int i, int W) {
        count++;
        if (i < 0) return 0;
        if (W < arr[i][0]) {
            return calculateTopDown(i - 1, W);

        } else {
            return max(calculateTopDown(i - 1, W), arr[i][1] + calculateTopDown(i - 1, W - arr[i][0]));
        }
    }

    int calculateBottomUp() {
        Arr table(arr.n);
        table.fillArrayWithZeros(arr.n);
        table.printArr(arr.n);

    }


};


int main() {
    KnapSack k;
    auto start = high_resolution_clock::now();
    cout << endl << "The max that can be added is " << k.calculateTopDown(k.arr.n - 1, k.W) << endl;
    auto stop = high_resolution_clock::now();
    cout << "The number of function calls is " << k.count<<endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;




    return 0;
}
