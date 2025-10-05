# <h1 align="center">Laporan Praktikum Modul 2 - Array & Pointer Pengenalan Bahas C++ (Bagian Kedua)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
Struktur data menjelaskan koleksi atau kelompok data yang dapat dibedakan oleh organisasi dan operasi yang dilakukan terhadapnya. Penggunaan struktur data yang tepat selama proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih sederhana.[1]

### A. Array<br/>
Array merupakan struktur data yang menyimpan elemen dalam satu blok memori dengan akses cepat menggunakan indeks.[3]

### B. Pointer<br/>
pointer adalah variabel yang menyimpan  alamat  memori  dari  variabel  lain.[2]

### B. Prosedur<br/>
Proses dapat mengembalikan atau tidak mengembalikan nilai atau hasil; untuk melakukannya, diperlukan suatu variabel tertentu. Proses pencetakan hasil atau nilai disimpan dalam blok subrutinnya sendiri di program utama, yang kemudian diberi nama prosesnya.[4]

## Guided 

### 1. Array

```C++
#include <iostream>
using namespace std;

int main() {
    int arr[5];

    for (int i = 0; i < 5; i++) {
        cout << "Masukan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j=0;
    while (j < 5) {
        cout << "Isi indeks ke-" << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```
penjelasan singkat guided 1
Program ini membuat array dengan 5 elemen, meminta user untuk mengisi nilainya, kemudian menampilkan semua nilai yang telah diinput.

### 2. Array Pointer

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[] = {10,20,30,40,50};
    int*ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i<5; ++i){
        cout << " Elemen array ke-" << i+1 << " menggunakan pointer : " << *(ptr + i) << endl;
    }

    for (int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i + 1 << " menggunakan indeks: " << arr[i] << endl;
    }

    return 0;
}

```
penjelasan singkat guided 2
Program ini mendemonstrasikan hubungan antara array dan pointer, serta menunjukkan 2 cara mengakses elemen array: menggunakan pointer dan menggunakan indeks biasa.

### 3. Fungsi Prosedur

```C++
#include <iostream>
using namespace std;

int cariMAX (int arr[], int ukuran){
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran){
    int totaljumlah = 0;
    for(int i = 0; i < ukuran; i ++){
        totaljumlah += arr[i];
    }
    cout << " total penjumlahan : " << totaljumlah << endl;

    int totalKali = 1;
    for(int i = 0; i < ukuran; i++){
        totalKali *= arr[i];
    }

    cout << " total perkalian : " << totalKali << endl;
}
    int main (){
    const int ukuran = 5;
    int arr[ukuran];
    for (int i = 0; i < ukuran; i++){
        cout << "masukan nilai arrray ke-" << i << " : ";
        cin >> arr[i];
    }
    cout << endl;
    cout << "nilai terbesar dalam array : " << cariMAX(arr, ukuran)<< endl;

    operasiAritmatika(arr, ukuran);
    return 0;

}

```
penjelasan singkat guided 3
Program ini berfungsi untuk memasukkan data ke dalam array, kemudian mencari nilai maksimum, serta menghitung jumlah total dan hasil perkalian seluruh elemen array dengan menggunakan fungsi, perulangan, dan operasi aritmatika dalam bahasa C++.

## Unguided 

### 1. (soal unguided 1)
Diketahui 2 buah matriks 3x3 seperti dibawah ini :
matriksA = [ 7 12 22
31 6 41
15 19 36]
 MatriksB = [11 34 7
3 25 41
5 18 33]
Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian
matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan;
jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan
kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case
seperti berikut ini :
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar

```C++
#include <iostream>
#include <iomanip>
using namespace std;


void tampilkanMatriks(int matriks[3][3], string nama) {
    cout << "\n" << nama << ":\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << setw(5) << matriks[i][j] << " ";
        }
        cout << endl;
    }
}


void jumlahMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    cout << "\n=== PENJUMLAHAN MATRIKS ===";
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] + B[i][j];
        }
    }
  
}


void kurangMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    cout << "\n=== PENGURANGAN MATRIKS ===";
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = A[i][j] - B[i][j];
        }
    }
    
}

void kaliMatriks(int A[3][3], int B[3][3], int hasil[3][3]) {
    cout << "\n=== PERKALIAN MATRIKS ===";
    
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            hasil[i][j] = 0;
        }
    }
    
   
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                hasil[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    
}

int main() {
    int matriksA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    

    int matriksB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    
    int hasil[3][3];
    int pilihan;
    
    do {
       
        cout << "\n========================================";
        cout << "\n       Menu Program Matriks";
        cout << "\n========================================";
        cout << "\n1. Penjumlahan matrix";
        cout << "\n2. Pengurangan matrix";
        cout << "\n3. Perkalian Matrix";
        cout << "\n4. Keluar";
        cout << "\n========================================";
        cout << "\nPilih menu (1-4): ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                jumlahMatriks(matriksA, matriksB, hasil);
                tampilkanMatriks(hasil, "Hasil Penjumlahan");
                break;
            case 2:
                kurangMatriks(matriksA, matriksB, hasil);
                tampilkanMatriks(hasil, "Hasil Pengurangan");
                break;
            case 3:
                kaliMatriks(matriksA, matriksB, hasil);
                tampilkanMatriks(hasil, "Hasil Perkalian");
                break;
            case 4:
                cout << "\nTerima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih 1-4.\n";
        }
        
        
    } while(pilihan != 4);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan2_modul2/output_ungide1_modul2.png)


penjelasan unguided 1 
Program ini merupakan aplikasi console yang dirancang untuk melakukan berbagai operasi matematika pada dua buah matriks berukuran 3×3. Program mengimplementasikan tiga operasi dasar matriks yaitu penjumlahan, pengurangan, dan perkalian matriks. Program menggunakan sistem menu interaktif dengan struktur kontrol switch-case yang memungkinkan user untuk memilih operasi yang diinginkan secara berulang hingga memutuskan untuk keluar.

### 2. (soal unguided 2)
Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan
dan perubahan nilainya menggunakan pointer, seperti berikut:
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan
luas (beri nilai 0).
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar
yang menunjuk ke variabel lebar.
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas.
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar.
4) Cetak nilai luas ke layar.
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui
pointer ptrPanjang dan ptrLebar.
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa
nilainya telah berubah.

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan2_modul2/output_unguided2_modul2.png)


penjelasan unguided 2
Program ini merupakan aplikasi console C++ yang menghitung luas dan keliling persegi panjang menggunakan konsep pointer. Melalui pointer, program mengakses dan mengubah nilai variabel secara tidak langsung. Awalnya, perhitungan dilakukan dengan panjang 10 dan lebar 5, lalu nilai tersebut diubah melalui pointer. Setelah perubahan, program menghitung ulang untuk menunjukkan bahwa modifikasi lewat pointer memengaruhi variabel asli dan menghasilkan hasil baru.



## Kesimpulan
Praktikum Modul 2 memperkenalkan penggunaan array dan pointer dalam C++. Array digunakan untuk menyimpan sekumpulan data sejenis, sedangkan pointer berfungsi mengakses dan mengubah nilai variabel secara tidak langsung melalui alamat memori. Dengan menggabungkan keduanya serta memanfaatkan fungsi dan prosedur, program menjadi lebih efisien dan terstruktur.

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.[text](https://osf.io/preprints/vyech)
<br>[2] Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).[text](https://jurnal.mifandimandiri.com/index.php/penerbitmmd/article/view/39/33)
<br>[3]Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Menulis: Jurnal Penelitian Nusantara, 1(6), 871-877.[text](https://padangjurnal.web.id/index.php/menulis/article/view/417/433)
<br>[4]Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Umsida Press, 1-146.[text](https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4/759)