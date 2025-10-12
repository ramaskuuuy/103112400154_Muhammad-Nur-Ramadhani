#include <iostream>
using namespace std;

void tampilakanArray(int arr[3][3]) {
    cout << "Isi array 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarNilai(int array1[3][3], int array2[3][3], int nilaiA, int nilaiB) {
int *x1 = nullptr;
int *x2 = nullptr;

for (int i = 0; i < 3 ; i++) {
    for (int j = 0; j < 3; j++) {
        if (array1[i][j] == nilaiA) {
            x1 = &array1[i][j];
        }
    }
}

for (int i = 0; i < 3 ; i++) {
    for (int j = 0; j < 3; j++) {
        if (array2[i][j] == nilaiB) {
            x2 = &array2[i][j];
        }
    }
}

if (x1 != nullptr && x2 != nullptr) {
    int temp = *x1;
    *x1 = *x2;
    *x2 = temp;
} else {
    cout << "Nilai tidak ditemukan dalam array." << endl;
}
}

int main(){
    int array1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int array2[3][3] = {
        {10, 21, 22},
        {33, 34, 35},
        {46, 47, 48}
    };

    cout << "Array 1 sebelum ditukar:" << endl;
    tampilakanArray(array1);
    cout << "Array 2 sebelum ditukar:" << endl;
    tampilakanArray(array2);

    int nilaiA, nilaiB;
    cout << "Masukkan nilai dari array1 yang ingin ditukar: ";
    cin >> nilaiA;
    cout << "Masukkan nilai dari array2 yang ingin ditukar: ";
    cin >> nilaiB;

    tukarNilai(array1, array2, nilaiA, nilaiB);

    cout << "Array 1 setelah ditukar:" << endl;
    tampilakanArray(array1);
    cout << "Array 2 setelah ditukar:" << endl;
    tampilakanArray(array2);

    return 0;
}