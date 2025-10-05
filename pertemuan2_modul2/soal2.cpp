#include <iostream>
using namespace std;

int main(){
    int panjang = 10;
    int lebar = 5;
    int luas, keliling;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "\n--- Nilai Awal ---" << endl;
    cout << "Panjang : " << panjang << endl;
    cout << "Lebar : " << lebar << endl;

 
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas : " << luas << endl;
    cout << "Keliling : " << keliling << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

   
    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * (*ptrPanjang + *ptrLebar);

    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << *ptrPanjang << endl;
    cout << "Lebar Baru: " << *ptrLebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}