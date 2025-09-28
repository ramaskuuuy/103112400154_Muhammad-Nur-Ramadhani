# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Muhammad Dhimas Hafizh Fathurrahman - 2311102151</p>

## Dasar Teori
isi dengan penjelasan dasar teori disertai referensi jurnal (gunakan kurung siku [] untuk pernyataan yang mengambil refernsi dari jurnal).
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
Program ini adalah kalkulator sederhana dua bilangan yang melakukan 4 operasi dasar matematika (penjumlahan, pengurangan, perkalian, pembagian) pada dua bilangan yang diinput oleh user.

### 2. ...

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
Program ini mengkonversi angka (0-100) menjadi kata-kata dalam bahasa Indonesia.

### 3. ...

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
Program ini membuat pola angka berbentuk piramid terbalik dengan format khusus yang menampilkan angka menurun, tanda asterisk (*), dan angka menaik.

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
![Screenshot Output Unguided 1_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 1_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 1 

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
![Screenshot Output Unguided 2_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 2_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 2

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
![Screenshot Output Unguided 3_1](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

contoh :
![Screenshot Output Unguided 3_1](https://github.com/DhimazHafizh/2311102151_Muhammad-Dhimas-Hafizh-Fathurrahman/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 3_2](https://github.com/(username github kalian)/(nama repository github kalian)/blob/main/(path folder menyimpan screenshot output)/(nama file screenshot output).png)

penjelasan unguided 3

## Kesimpulan
Algoritma membentuk dasar logika program, seperti langkah-langkah perhitungan pada kalkulator dan konversi angka ke kata. Setiap program dimulai dari fungsi main() dengan #include <iostream> untuk input-output.Variabel dideklarasikan sesuai kebutuhan seperti float untuk bilangan desimal, int untuk angka bulat, string untuk teks, dan array untuk menyimpan data koleksi seperti kata-kata angka.Input-output menggunakan cin dan cout untuk interaksi user yang mudah dan informatif. Operator aritmatika (+, -, *, /, %) digunakan untuk perhitungan dan manipulasi data.Struktur kontrol if-else memungkinkan program membuat keputusan, seperti validasi pembagian nol atau penanganan rentang angka. Perulangan for efektif untuk membuat pola berulang dengan nested loop yang mengatur format output.Dengan menggabungkan konsep-konsep ini, tercipta program yang fungsional dan user-friendly.
...

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
