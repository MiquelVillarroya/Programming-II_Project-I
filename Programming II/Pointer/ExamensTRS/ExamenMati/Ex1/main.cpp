#include <iostream>
using namespace std;

void printArray(int* arr1, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl;
}

int* combinarArraysOrdenats(int* arr1, int longitud1, int* arr2, int longitud2) {
    // aqui el vostre codi
    int fullLength = longitud1 + longitud2;
    int* res = new int[fullLength];
    int i = 0;
    for (i = 0; i < longitud1; i++) {
        res[i] = arr1[i];
    }
    for (int j = 0; j < longitud2; j++) {
        res[i] = arr2[j];
        i++;
    }
    printArray(res, fullLength);

    for (int i = 0; i < (fullLength - 1); ++i) {
        for (int j = i + 1; j < fullLength; ++j) {
            if (res[i] > res[j]) {
                int aux = res[i];
                res[i] = res[j];
                res[j] = aux;
            }
        }
    }
    return res;
}

int main() {
    int arr1[] = { 1, 3, 5, 7, 9 , 74, -2};
    int arr2[] = { 2, 4, 10 };
    // busqueu la forma de saber la mida de l'array
    int longitud1 = sizeof(arr1) / sizeof(int);
    int longitud2 = sizeof(arr2) / sizeof(int);

    cout << longitud1 << " " << longitud2 << endl;

    int* resultat = combinarArraysOrdenats(arr1, longitud1, arr2, longitud2);

    cout << "L'array combinat ordenat és: ";
    for (int i = 0; i < longitud1 + longitud2; ++i) {
        cout << resultat[i] << " ";
    }
    cout << endl;

    // Alliberar la memòria de l'array resultat
    delete[] resultat;

    return 0;
}

