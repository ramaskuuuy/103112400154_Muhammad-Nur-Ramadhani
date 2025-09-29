# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
Algoritma pemrograman  adalah  "langkah-langkah".  langkah  sistematis  dan logis  untuk mengembangkan  program  komputer  menggunakan  bahasa  pemrograman  untuk  memecahkan  masalah dan mencapai tujuan tertentu [1],C++ merupakan salah satu bahasa pemrograman yang populer digunakan bagi siapa saja yang baru belajar bahasa pemrograman. C++ termasuk kedalam bahasa pemrograman komputer tingkat tinggi yang mana artinya bahasa pemrograman ini mudah dimengerti dan di pelajari oleh manusia [2]
contoh :
Linked list atau yang disebut juga senarai berantai adalah Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara sekuensial, saling bersambungan, dinamis, dan terbatas[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.

### A. Dasar Pemrograman <br/>
#### 1. Struktur C++

#### 2. Tipe Data 

#### 3. Variabel

#### 4. Konstanta

### B. Input dan Output<br/>
#### 1. Fungsi cout

#### 2. Fungsin cin
#### 3. ...

### C. Operator <br/>
#### 1. Operator Aritmatika

#### 2. Operator Logika 

### D. Kondisional <br/>
#### 1. If - else

#### 2. Switch - case

### E.  Perulangan <br/>
#### 1. For loop

#### 2. While loop

## Guided 

### 1. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukan angka 1 : ";
    cin >> angka1;
    cout << "angka yang dimasukan 2 ";
    cin >> angka2;

    cout << "penjumlahan : " << angka1 + angka2 << endl;
    cout << "pengurangan : " << angka1 - angka2 << endl;
    cout << "perkalian :  " << angka1 * angka2 << endl;
    cout << "pembagian : " << angka1 / angka2 << endl;
    return 0;

}

```
Program ini adalah kalkulator sederhana dua bilangan yang melakukan 4 operasi dasar matematika (penjumlahan, pengurangan, perkalian, pembagian) pada dua bilangan yang diinput oleh user.

### 2. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "masukan angka 1 : ";
    cin >> angka1;
    cout << "masukan angka 2 : ";
    cin >> angka2;

    if (angka1 < angka2){
        cout << angka1 << " kurang dari " << angka2 << endl;
    }else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    }else if (angka1 != angka2) {
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "Menu" << endl;
    cout << "1. penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "masukan pilhan : " << endl;
    cin >> pilihan ;

    switch(pilihan){
        case 1:
        cout << "penjumlahan : " << angka1 + angka2 << endl;
        cout << endl;
        break;
        case 2 :
        cout << "pengurangan : " << angka1 - angka2 << endl;
        cout << endl;
        break;
        default :
        cout << "pilihan salah" << endl;


    }
    return 0;

}

```
Program ini membahasa percabangan dan pengkondisian untuk kasus tertentu.

### 3. ...

```C++
#include <iostream>
using namespace std;

int main() {
    int angka1;
    cout << "masukan angka 1 : ";
    cin >> angka1;

    for(int i = 0; i < angka1; i++ ){
        cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while(j > angka1){
        cout << j << " - ";
        j--;
    }
    cout << endl;

    int k = 10;
    do{
        cout << k << " - ";
    }while(k < angka1);

    return 0;

}
```
Program ini membahas tentang perulangan.

## Unguided 

### 1. (soal unguided 1)
Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
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

cout << "penjumlahan : " << bil1 << "+" << bil2 << " = " << (bil1 + bil2) << endl;
cout << "pengurangan : " << bil1 << "-" << bil2 << " = " << (bil1 - bil2) << endl;
cout << "perkalian : " << bil1 << "*" << bil2 << " = " << (bil1 * bil2) << endl;

if (bil2 != 0) {
    cout << "pembagian : " << bil1 << "/" << bil2 << " = " << (bil1 / bil2) << endl;
} else {
    cout << "pembagian tidak dapat dilakukan karena pembagi tidak boleh nol." << endl;
}

  return 0;
 

}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan1_modul1/output_unguide1_modul1.png)


Program ini adalah kalkulator sederhana dua bilangan yang melakukan 4 operasi dasar matematika (penjumlahan, pengurangan, perkalian, pembagian) pada dua bilangan yang diinput oleh user.

### 2. (soal unguided 2)
Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
#include <string>
using namespace std;

string DigitToString (int digit) {

    string satuan [] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", 
                        "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas",
                         "tujuh belas", "delapan belas", "sembilan belas"};

    string puluhan [] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

 if (digit == 0) {
    return "nol";
    }

    else if (digit < 20) {
    return satuan[digit];
    }

    else if (digit < 100) {
    int puluhan_digit = digit / 10;
    int satuan_digit = digit % 10;
    if (satuan_digit == 0) {
        return puluhan[puluhan_digit];
    } else {
        return puluhan[puluhan_digit] + " " + satuan[satuan_digit];
    }
    }

 else if (digit == 100) {
        return "seratus";
        
    }
    return "angka di luar jangkauan";
}

int main (){
    int digit;
    cout << "Masukkan angka (0-100): ";
    cin >> digit;
    cout << "Angka dalam kata: " << DigitToString(digit) << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan1_modul1/output_unguide2_modul1.png)


Program ini mengkonversi angka (0-100) menjadi kata-kata dalam bahasa Indonesia.

### 3. (soal unguided 3)
Buatlah program yang dapat memberikan input dan output sbb
```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Masukan angka : ";
    cin >> n;
    
    cout << "Hasil : " << endl;
    

    for (int i = n; i >= 1; i--) {
     
        for (int space = 0; space < n - i; space++) {
            cout << " ";
        }
        
        for (int j = i; j >= 1; j--) {
            cout << j;
        }
        
        cout << " * ";
        
        for (int k = 1; k <= i; k++) {
            cout << k;
        }
        
        cout << endl;
    }
    
    for (int space = 0; space < n; space++) {
        cout <<" ";
    }
    cout << " * " << endl;
    
    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan1_modul1/output_unguide3_modul1.png)


Program ini membuat pola angka berbentuk piramid terbalik dengan format khusus yang menampilkan angka menurun, tanda asterisk (*), dan angka menaik.

## Kesimpulan
Algoritma membentuk dasar logika program, seperti langkah-langkah perhitungan pada kalkulator dan konversi angka ke kata. Setiap program dimulai dari fungsi main() dengan #include <iostream> untuk input-output.Variabel dideklarasikan sesuai kebutuhan seperti float untuk bilangan desimal, int untuk angka bulat, string untuk teks, dan array untuk menyimpan data koleksi seperti kata-kata angka.Input-output menggunakan cin dan cout untuk interaksi user yang mudah dan informatif. Operator aritmatika (+, -, *, /, %) digunakan untuk perhitungan dan manipulasi data.Struktur kontrol if-else memungkinkan program membuat keputusan, seperti validasi pembagian nol atau penanganan rentang angka. Perulangan for efektif untuk membuat pola berulang dengan nested loop yang mengatur format output.Dengan menggabungkan konsep-konsep ini, tercipta program yang fungsional dan user-friendly.
...

## Referensi
[1] Samsudin, dkk. (2020).  Perancangan Sistem Informasi Pembelajaran Algoritma dan Pemrograman Berbasis Web pada Program Studi Teknik Informatika STMIK ERESHA. Jurnal Informatika Universitas Pamulang, Vol. 5(4), hal. 521-528 https://www.researchgate.net/publication 357459576_Perancangan_Sistem_Informasi_Pembelajaran_Algoritma_dan_Pemrograman_Berbasis_Web_pada_Program_Studi_Teknik_Informatika_STMIK_ERESHA
<br>[2] Dasar Pemrograman Dengan C++ Materi Paling Dasar Untuk Menjadi Programmer Berbagai Platform Nugraha (2021) [text](https://books.google.co.id/books?hl=en&lr=&id=9AhREQAAQBAJ&oi=fnd&pg=PP1&dq=dasar+pemrograman+c&ots=QGHrmTjnpO&sig=kRUqQeGDZ10Em0yRctDG5uBnGoY&redir_esc=y#v=onepage&q=dasar%20pemrograman%20c&f=false)
<br>...
