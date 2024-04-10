#include <iostream>
using namespace std;

void modifyArray(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        *(arr+i) *= 2; // Intentar modificar cada element de l'array
    }
}

int main() {
    int array[5] = { 1, 2, 3, 4, 5 };
    int* ptr = array;
    modifyArray(ptr, 5);

    for (int i = 0; i < 5; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}

