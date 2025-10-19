# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)Type</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Struktur data menjelaskan koleksi atau kelompok data yang dapat dibedakan oleh organisasi dan operasi yang dilakukan terhadapnya. Penggunaan struktur data yang tepat selama proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih sederhana.[1]

### A. Abstarct Data Type<br/>
Tipe data abstrak (ADT) adalah tipe data tertentu yang didefinisikan oleh pemrogram untuk kemudahan pemrograman dan untuk mengakomodasi tipe data yang tidak secara spesifik diakomodasi oleh bahasa pemrograman yang digunakan. ADT juga menyempurnakan tipe data dengan mengaitkannya dengan fungsi-fungsi yang beroprasi pada data yang bersangkutan.[2]

## Guided 

### 1. Soal Guided 1
file "list.h"
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
file "list.cpp"

```C++
#include "list.h"
#include <iostream>
using namespace std;
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}
address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}
void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}
void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}
void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

```

file "main.cpp"
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
penjelasan singkat guided 1

Program ini dirancang untuk mengelola data mahasiswa. Data yang disimpan meliputi nama dan dua nilai, menggunakan struktur (struct) mahasiswa. Terdapat dua fungsi utama: inputMhs untuk memasukkan data, dan rata2 untuk menghitung rata-rata dari kedua nilai tersebut.

### 2. Soal Guided 2
file "list.h"
```C++
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};
typedef mahasiswa dataMahasiswa;
typedef struct node *address;
struct node{ 
    dataMahasiswa isidata;
    address next;
};
struct linkedlist{ 
    address first;
};
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```
file "list.cpp"
```C++
#include "list.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
}

address alokasi(string nama, string nim, int umur) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) { 
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}

```

file "main.cpp"
```C++
#include "list.h"
#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
penjelasan singkat guided 2

Program ini dirancang untuk mengelola data mahasiswa secara modular dengan memisahkan kode ke dalam tiga file utama: file header, file implementasi, dan file utama. File header (.h) bertindak sebagai antarmuka (interface) program, di mana di dalamnya didefinisikan struktur data mahasiswa yang berisi NIM, nilai1, dan nilai2, serta deklarasi untuk fungsi inputMhs() dan rata2(). Sementara itu, file implementasi (.cpp) berisi definisi atau rincian kode dari kedua fungsi tersebut; fungsi inputMhs secara spesifik menangani proses input data dari pengguna, sedangkan fungsi rata2 melakukan kalkulasi nilai rata-rata. Terakhir, file utama (main.cpp) berfungsi sebagai titik eksekusi, di mana sebuah variabel mahasiswa dibuat, kemudian fungsi inputMhs dipanggil untuk mengisi data, dan diakhiri dengan pemanggilan fungsi rata2 untuk menghitung sekaligus menampilkan hasil akhirnya ke layar.

## Unguided 

### 1. (soal unguided 1)
Buat program yang dapat menyimpan data mahasiswa maksimal 10 ke dalam sebuah array dengan field nama, nim, uts, uas, tugas dan nilai akhir. nilai akhir yang diperoleh dengan rumus 0.3uts + 0.4uas + 0.3*tugas.

file "Singlylist.h"
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infoType;

struct Elmlist {
    infoType info;
    Elmlist* next;
};

typedef Elmlist* address;

struct list {
    address first;
};

typedef list List; // Tambahkan ini untuk konsistensi

void CreateList(List &L);
address alokasi(infoType X);      // Perbaiki: infoType (bukan infotype)
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif
```

file "Singlylist.cpp"
```C++
#include "singlylist.h"

void CreateList(List &L) {
    L.first = NULL;
}
address alokasi (infoType X) {
    address P = new Elmlist;
    P->info = X;
    P->next = NULL;
    return P;
}

void dealokasi (address &P) {
    delete P;
}
void printInfo (List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}
void insertFirst (List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}


```
file "main.cpp"
```C++
#include "singlylist.h"

int main (){
    list L;
    address p1, p2, p3, p4, p5 = NULL; 
    CreateList(L);
    p1 = alokasi(2);
    insertFirst(L, p1);
    p2 = alokasi(0);
    insertFirst(L, p2);
    p3 = alokasi(8);
    insertFirst(L, p3);
    p4 = alokasi(12);
    insertFirst(L, p4);
    p5 = alokasi(9);
    insertFirst(L, p5);\
    printInfo(L);
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

file "singlylist.h"
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#include <iostream>
using namespace std;

typedef int infoType;

struct Elmlist {
    infoType info;
    Elmlist* next;
};

typedef Elmlist* address;

struct list {
    address First;
};

typedef list List; // Tambahkan ini untuk konsistensi

void CreateList(List &L);
address alokasi(infoType X);      // Perbaiki: infoType (bukan infotype)
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(List &L, address &P, address Prec);
int nbList(List L);
void deleteList(List &L);

#endif
```
file "singlylist.cpp"
```C++
#include "singlylist.h"

void CreateList(List &L){
    L.First = NULL;
}
address alokasi (infoType X){
    address P = new Elmlist;
    if (P != NULL){
        P -> info = X;
        P -> next = NULL;
    }
    return P;
}
void dealokasi (address &P){
    delete P;
    P = NULL;
}
void printInfo(List L){
    address P = L.First;
    while(P != NULL){
        cout << P -> info << " ";
        P = P -> next;

    }
    cout << endl;
}
void insertFirst (List &L, address P){
    P -> next = L.First;
    L.First = P;
}

void deleteFirst(List &L, address &P){
    if (L.First != NULL){
        P = L.First;
        L.First = L.First -> next;
        P -> next = NULL;
    }else{
        P = NULL;
    }
}
void deleteLast(List &L, address &P){
    if (L.First != NULL){
        address Q = L.First;
        if(Q -> next == NULL){
            P = Q;
            L.First = NULL;
        }else{
            while (Q -> next -> next != NULL){
                Q = Q -> next;
            }
            P = Q -> next;
            Q -> next = NULL;


        }
    }else{
        P = NULL;
    }
}
void deleteAfter(List &L, address &P, address prec){
    if (prec != NULL && prec -> next != NULL){
        P = prec -> next;
        prec -> next = P -> next;
        P -> next = NULL;
    }else{
        P = NULL;
    }
}
int nbList(List L){
    int count = 0;
    address P = L.First;
    while (P != NULL){
        count++;
        P = P -> next;
    }
    return count;
}

void deleteList(List &L){
    address P;
    while (L.First != NULL){
        deleteFirst(L, P);
        //dealokasi(P);
    }
}
```
file "main.cpp"
```C++
#include "singlylist.h"

int main (){
    list L;
    address p1, p2, p3, p4, p5 = NULL; 
    CreateList(L);
    p1 = alokasi(2);
    insertFirst(L, p1);
    p2 = alokasi(0);
    insertFirst(L, p2);
    p3 = alokasi(8);
    insertFirst(L, p3);
    p4 = alokasi(12);
    insertFirst(L, p4);
    p5 = alokasi(9);
    insertFirst(L, p5);
 

    deleteFirst(L, p1);
    deleteLast(L, p5);

    address p;
    deleteAfter(L, p, p4);
    dealokasi(p);
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    deleteList(L);
    cout << "List berhasil terhapus " << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    
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
