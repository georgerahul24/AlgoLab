#include <iostream>

using namespace std;

//c[i,j] = 1 +  max(c[i+1,j] , c[i,j+1]); but, check if they are smaller than the current number

class Arr {
public:
    int n = 0;
    int **arr;

    Arr() {
        cout << "Enter the size of the square(n): " << endl;
        cin >> this->n;
        this->arr = new int *[n];

    }

    Arr(int n) {
        this->n = n;
        arr = new int *[n];
    }

    void fillArray() {

        for (int i = 0; i < n; i++) {
            int *_arr = new int[n];
            for (int j = 0; j < n; j++) {
                cin >> _arr[j];
            }
            this->arr[i] = _arr;
        }

    }

    void fillArrayWithZeros() {
        for (int i = 0; i < n; i++) {
            this->arr[i] = new int[n];


        }
    }


    void printArr() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

};


int main() {
    Arr arr, arr1(5);
    arr.fillArray();
    arr.printArr();
    arr1.fillArrayWithZeros();
    arr1.printArr();
    arr.printArr();
    arr.printArr();
    arr1.printArr();


    return 0;
}
