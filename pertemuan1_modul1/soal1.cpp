#include <iostream>
using namespace std;

int main() {
  float bil1,bil2;

cout << "kalkulator sederhana" << endl;

cout << "masukkan bilangan pertama: ";    
cin >> bil1;
cout << "masukan bilangan ke dua: ";
cin >> bil2;

// menampilkan hasil
cout << "Hasil operasi " << endl;

cout << "penjumlahan : " << bil1 << " + " << bil2 << " = " << (bil1 + bil2) << endl;
cout << "pengurangan : " << bil1 << " - " << bil2 << " = " << (bil1 - bil2) << endl;
cout << "perkalian : " << bil1 << " * " <<bil2 << " = " << (bil1 * bil2) << endl;

if (bil2 != 0) {
    cout << "pembagian : " << bil1 << "/" << bil2 << " = " << (bil1 / bil2) << endl;
} else {
    cout << "pembagian tidak dapat dilakukan karena pembagi tidak boleh nol." << endl;
}

  return 0;
 

}
