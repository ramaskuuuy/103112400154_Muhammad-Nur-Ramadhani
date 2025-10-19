# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Struktur data menjelaskan koleksi atau kelompok data yang dapat dibedakan oleh organisasi dan operasi yang dilakukan terhadapnya. Penggunaan struktur data yang tepat selama proses pemrograman akan menghasilkan algoritma yang lebih jelas dan tepat, sehingga menjadikan program secara keseluruhan lebih sederhana.[1]

### A. Singly Linked List<br/>
Linked list adalah sejenis struktur data yang ukurannya dapat berubah. Tidak seperti array, item dalam linked list tidak semuanya disimpan di samping satu sama lain dalam memori. Sebaliknya, setiap item, yang disebut node, memiliki tautan atau penunjuk ke item berikutnya. Pengaturan ini memudahkan untuk menambah atau menghapus item dari daftar. Daftar terkait tunggal adalah jenis spesifik dari daftar terkait di mana setiap simpul hanya menunjuk ke simpul berikutnya dalam daftar. Struktur single linked list yaitu, data dan pointer(next).[2]

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

Program ini mengimplementasikan linked list untuk menyimpan data mahasiswa (nama, NIM, umur) secara dinamis. Program menyediakan fungsi untuk membuat list kosong, menambahkan node di awal/tengah/akhir, dan menampilkan semua data. Pada fungsi main, lima data mahasiswa dimasukkan ke dalam list lalu ditampilkan, mendemonstrasikan pengelolaan data dinamis tanpa array statis.

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

Program ini mendemonstrasikan linked list untuk mengelola data mahasiswa (nama, NIM, usia) secara dinamis. Setiap node menyimpan data mahasiswa dan pointer ke node berikutnya. Program menyediakan fungsi create, insert (awal/tengah/akhir), delete (posisi tertentu/seluruh list), dan display. Fungsi main() menunjukkan operasi dasar linked list: menambahkan beberapa data mahasiswa, menampilkan isi list dengan jumlah node, menghapus node tertentu, dan menghapus seluruh list. Program ini bertujuan mengilustrasikan operasi fundamental linked list seperti insertion, deletion, dan traversal.

## Unguided 

### 1. (soal unguided 1)
Buat ADT singly linked list dalam file "Singlylist.h",Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file “Singlylist.cpp”,Kemudian buat program utama didalam file “main.cpp”.

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

typedef list List; 

void CreateList(List &L);
address alokasi(infoType X);      
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
![Screenshot Output Unguided 1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan4_modul4/output_unguided1_modul4.png)

penjelasan unguided 1 

Program ini mengimplementasikan linked list satu arah dengan fungsi-fungsi dasar: CreateList (membuat list kosong), insertFirst (menambah node di awal), printInfo (menampilkan isi list), serta alokasi dan dealokasi memori. Pada fungsi main(), beberapa node berisi angka dibuat, ditambahkan ke list, kemudian ditampilkan secara berurutan.


### 2. (soal unguided 2)
Dari soal Latihan pertama, lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

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

typedef list List; 

void CreateList(List &L);
address alokasi(infoType X);      
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
![Screenshot Output Unguided 2](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan4_modul4/output_unguided2_modul4.png)

penjelasan unguided 2

Program ini mengimplementasikan linked list satu arah secara lengkap dengan operasi insert (insertFirst), delete (deleteFirst, deleteLast, deleteAfter), serta fungsi tambahan seperti nbList (menghitung jumlah elemen) dan deleteList (menghapus seluruh list). Linked list memungkinkan pengelolaan data dinamis yang dapat bertambah atau berkurang sesuai kebutuhan. Pada fungsi main(), program mendemonstrasikan pembuatan elemen, penambahan ke list, penghapusan beberapa elemen, dan menampilkan hasil akhir.


## Kesimpulan
Praktikum ini menunjukkan bahwa Singly Linked List merupakan struktur data dinamis berbasis node yang terhubung satu arah, memungkinkan operasi penambahan, penghapusan, dan penelusuran data secara efisien tanpa realokasi memori seperti array. Implementasi C++ mendemonstrasikan operasi dasar linked list meliputi insert, delete, counting, dan penghapusan seluruh elemen list.

## Referensi
[1] Pratama, M. A. (2020). STRUKTUR DATA ARRAY DUA DIMENSI PADA PEMROGRAMAN C++.[text](https://osf.io/preprints/vyech)
<br>[2] Düzgün, M. T. (2024, June 9). Understanding and implementing singly linked lists in C++. Medium..[text](https://medium.com/@togunchan/understanding-and-implementing-singly-linked-lists-in-c-2dc7aa5df07e)
