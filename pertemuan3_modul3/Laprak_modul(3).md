# <h1 align="center">Laporan Praktikum Modul 3 - Abstact Data Type</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Struktur data menjelaskan koleksi atau kelompok data yang dapat dibedakan oleh organisasi dan operasi yang dilakukan terhadapnya. Penggunaan struktur data yang tepat selama proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih sederhana.[1]

### A. Abstarct Data Type<br/>
Tipe data abstrak (ADT) adalah tipe data tertentu yang didefinisikan oleh pemrogram untuk kemudahan pemrograman dan untuk mengakomodasi tipe data yang tidak secara spesifik diakomodasi oleh bahasa pemrograman yang digunakan. ADT juga menyempurnakan tipe data dengan mengaitkannya dengan fungsi-fungsi yang beroprasi pada data yang bersangkutan.[2]

## Guided 

### 1. Soal Guided 1

```C++
#include <iostream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilai1, nilai2;

};

void inputMhs(mahasiswa &m){
    cout << " input nama : ";
    cin >> m.nama;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return float(m.nilai1 + m.nilai2) / 2;

}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2(mhs) << endl;

    return 0;
}

```
penjelasan singkat guided 1

Program ini dirancang untuk mengelola data mahasiswa. Data yang disimpan meliputi nama dan dua nilai, menggunakan struktur (struct) mahasiswa. Terdapat dua fungsi utama: inputMhs untuk memasukkan data, dan rata2 untuk menghitung rata-rata dari kedua nilai tersebut.

### 2. Soal Guided 2

```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H
struct mahasiswa
{
  char nim[10];
  int nilai1, nilai2;
    /* data */
};

void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif

```
```C++
#include <iostream>
#include "mahasiswa.h"
using namespace std;

void inputMhs(mahasiswa &m){
    cout << " input nim : ";
    cin >> m.nim;
    cout << " input nilai 1 : ";
    cin >> m.nilai1;
    cout << " input nilai 2 : ";
    cin >> m.nilai2;

}

float rata2(mahasiswa m){
    return (float)(m.nilai1 + m.nilai2) / 2;
}

```
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>
using namespace std;

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "rata -rata nilai adalah : " << rata2 
    (mhs) << endl;
    system("pause");
    return 0;
}

```
penjelasan singkat guided 2

Program ini dirancang untuk mengelola data mahasiswa secara modular dengan memisahkan kode ke dalam tiga file utama: file header, file implementasi, dan file utama. File header (.h) bertindak sebagai antarmuka (interface) program, di mana di dalamnya didefinisikan struktur data mahasiswa yang berisi NIM, nilai1, dan nilai2, serta deklarasi untuk fungsi inputMhs() dan rata2(). Sementara itu, file implementasi (.cpp) berisi definisi atau rincian kode dari kedua fungsi tersebut; fungsi inputMhs secara spesifik menangani proses input data dari pengguna, sedangkan fungsi rata2 melakukan kalkulasi nilai rata-rata. Terakhir, file utama (main.cpp) berfungsi sebagai titik eksekusi, di mana sebuah variabel mahasiswa dibuat, kemudian fungsi inputMhs dipanggil untuk mengisi data, dan diakhiri dengan pemanggilan fungsi rata2 untuk menghitung sekaligus menampilkan hasil akhirnya ke layar.

## Unguided 

### 1. (soal unguided 1)
Buat program yang dapat menyimpan data mahasiswa maksimal 10 ke dalam sebuah array dengan field nama, nim, uts, uas, tugas dan nilai akhir. nilai akhir yang diperoleh dengan rumus 0.3uts + 0.4uas + 0.3*tugas.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.35 * uts) + (0.4 * uas) + (0.25 * tugas);
}

int main(){
    Mahasiswa mhs[10];
    int jumlahMhs;

    cout << "=== PROGRAM DATA MAHASISWA ===" << endl;
    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> jumlahMhs;

    if (jumlahMhs <1 || jumlahMhs > 10) {
        cout << "Jumlah mahasiswa harus antara 1 sampai 10." << endl;
        return 1;
    }

    for (int i = 0; i < jumlahMhs; i++) {
        cout << "\nData Mahasiswa ke-" << (i + 1) << endl;
        cout << "Nama: ";
        getline(cin >> ws, mhs[i].nama);
        cout << "NIM: ";
        cin >> mhs[i].nim;
        cout << "Nilai UTS: ";
        cin >> mhs[i].uts;
        cout << "Nilai UAS: ";
        cin >> mhs[i].uas;
        cout << "Nilai Tugas: ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    
 for(int i = 0; i < jumlahMhs; i++) {
        cout << "\n=== DAFTAR NILAI MAHASISWA ===" << endl;
        cout << "Nama : " << mhs[i].nama << endl;
        cout << "NIM : " << mhs[i].nim << endl;
        cout << "Nilai Akhir : " << mhs[i].nilaiAkhir << endl;
    }
    
    return 0; 
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan3_modul3/output_unguided1_modul3.png)

penjelasan unguided 1 

Program ini merupakan sebuah aplikasi C++ sederhana yang dirancang untuk mengelola data nilai mahasiswa. Inti dari program ini adalah penggunaan sebuah struct bernama Mahasiswa untuk mengelompokkan informasi setiap mahasiswa, yang mencakup nama, NIM, serta nilai UTS, UAS, Tugas, dan nilai akhir. Untuk memproses nilai, terdapat fungsi terpisah bernama hitungNilaiAkhir yang bertugas mengkalkulasi nilai akhir berdasarkan rumus pembobotan 35% dari nilai UTS, 40% dari UAS, dan 25% dari Tugas. 

### 2. (soal unguided 2)
Buatlah ADT pelajaran dengan file "pelajaran.h" lalu buat implementasi ADT pelajran dalam file "pelajaran.cpp" lalu coba hasil implementasi ADT dalam file "main.cpp"

pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <string>
using namespace std;

struct pelajaran {
    string namamapel,kodemapel;
    
};

pelajaran create_pelajaran(string namamapel, string kodemapel);
void tampil_pelajaran(pelajaran pel);

#endif
```
pelajaran.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;


pelajaran create_pelajaran(string namapel, string kodepel) {
    pelajaran pel;
    pel.namamapel = namapel;
    pel.kodemapel = kodepel;
    return pel;
}


void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namamapel << endl;
    cout << "nilai : " << pel.kodemapel << endl;
}
```
main.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan3_modul3/output_unguided2_modul3.png)

penjelasan unguided 2

Program ini mengimplementasikan pendataan mahasiswa dan perhitungan nilai rata-rata dengan pendekatan modular yang memisahkan kode ke dalam tiga file utama. Struktur program dimulai dengan file header, yang berfungsi sebagai antarmuka (interface), tempat struct mahasiswa (berisi nim, nilai1, dan nilai2) didefinisikan serta fungsi inputMhs dan rata2 dideklarasikan. Detail atau logika dari fungsi-fungsi tersebut kemudian diimplementasikan dalam file implementasi terpisah, di mana inputMhs bertugas mengambil data dari pengguna dan rata2 melakukan perhitungan. Seluruh komponen ini dijalankan melalui file main, yang menjadi titik awal eksekusi program, di mana sebuah variabel mahasiswa dibuat, lalu fungsi inputMhs dipanggil untuk mengisi data, dan diakhiri dengan pemanggilan fungsi rata2 untuk menampilkan hasil akhir.

### 3. (soal unguided 3)
Buatlah program dengan ketentuan:
- 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
- fungsi/prosedur yang menampilkan isi sebuah array integer 2D
- fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
- fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
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
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan3_modul3/output_unguided3_modul3.png)

penjelasan unguided 3

Program C++ ini dirancang untuk menukar sebuah nilai spesifik antara dua array dua dimensi (matriks 3x3) berdasarkan input pengguna. Fungsi inti dari program ini, tukarNilai, bekerja dengan cara mencari nilai yang diinginkan di masing-masing array dan kemudian menyimpan alamat memori dari kedua nilai tersebut menggunakan pointer. Setelah kedua alamat ditemukan, nilai-nilai tersebut ditukar secara efisien. Untuk mempermudah visualisasi, sebuah fungsi terpisah bernama tampilakanArray digunakan untuk mencetak isi array ke layar dalam format matriks yang rapi. Seluruh proses ini diatur dalam fungsi main, yang pertama-tama menginisialisasi dan menampilkan kondisi awal kedua array, kemudian meminta input dari pengguna, memanggil fungsi tukarNilai untuk melakukan pertukaran, dan terakhir menampilkan kembali kedua array untuk menunjukkan hasilnya.



## Kesimpulan
Tipe data adalah klasifikasi dasar yang menentukan jenis nilai suatu variabel. Melengkapi konsep ini, Tipe Data Abstrak (ADT) adalah model data yang didefinisikan oleh pemrogram untuk membungkus sekumpulan nilai beserta operasi-operasi yang dapat dilakukan terhadapnya. ADT diciptakan untuk memenuhi kebutuhan spesifik yang tidak tercakup oleh tipe data bawaan dengan cara menyembunyikan detail implementasi yang kompleks. 
## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.[text](https://osf.io/preprints/vyech)
<br>[2] Triase, T. (2020). Struktur Data: Diktat Edisi Revisi.[text](http://repository.uinsu.ac.id/9717/2/Diktat%20Struktur%20Data.pdf)
