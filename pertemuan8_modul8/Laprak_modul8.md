# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Struktur data adalah cara untuk mengatur, menyimpan, dan mengelola data di dalam komputer agar data mudah diakses, diproses, dan diubah. 
Dengan struktur data, data bisa dikelola dengan lebih baik dan program berjalan lebih cepat dalam memproses informasi. Struktur data juga 
membantu memahami bagaimana data saling terhubung, sehingga memudahkan pencarian dan pengubahan data sesuai kebutuhan aplikasi. Menggunakan 
struktur data yang tepat akan membantu programmer meningkatkan kinerja aplikasi dan menghadapi masalah data yang rumit [1].

### A. Queue <br/>
Queue atau struktur data antrean adalah struktur data yang mengatur elemen data secara linier. Queue memiliki prinsip dasar "First In, First Out" atau FIFO yang berarti 
elemen yang pertama kali dimasukan kedalam antrean, akan dikeluarkan lebih dulu. Queue memiliki banyak peran dalam aplikasi dan algoritma. Salah satu peran utama adalah 
sistem yang bisa mengatur dan mengelola antrean tugas secara efisien, sedangkan dalam komputasi secara sistem digunakan dalam pengelolaan, penjadwalan proses, antrian pesan 
dan manajemen sumber daya. Queue juga bisa dibagi menjadi banyak jenis mendasar dari implementasi dan pengunaan :  
1. Jenis Queue berdasarkan Implementansinya  
- Simple/Linear Queue: Elemen data yang ada pada struktur antrean akan disusun secara linear dan elemen data bisa hanya ditambahkan atau dihapus dari 2 ujung barisan.  
- Circular Queue:  Hampir sama pada linear queue, tetapi ujung dari 2 baris akan saling terhubung, sehingga membentuk antrean yang berputar. 
2. Jenis Queue berdasarkan Pengunaannya  
- Prioritty Queue:  Setiap elemen pada queue  memiliki prioritas, elemen yang akan diambil adalah elemen dengan prioritas teratas.  
- Double-ended Queue (Dequeue):  Elemen pada queue bisa ditambahkan atau dihapus pada 2 ujung barisan antrean [2].


## Guided 

### 1. Soal guided 1
"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL
#include <iostream>
using namespace std;
typedef struct node *address;
struct node{
   int dataAngka;
   address next;
};
struct Queue {
    address head;
    address tail;
};
bool isEmpty(Queue Q);
void createQueue(Queue &Q);
address alokasi(int angka);
void dealokasi(Queue &node);
void enqueue(Queue &Q, address nodeBaru);
int dequeue(Queue &Q);
void updateQueue(Queue &Q, int posisi);
void viewQueue(Queue Q);
void searchData(Queue Q, int data);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(Queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(Queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enqueue(Queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

int dequeue(Queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(Queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(Queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(Queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    Queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enqueue(Q, nodeA);
    enqueue(Q, nodeB);
    enqueue(Q, nodeC);
    enqueue(Q, nodeD);
    enqueue(Q, nodeE);
    cout << endl;

    cout << "queue setelah dihapus " << endl;
    viewQueue(Q);
    cout << endl;

    dequeue(Q);
    dequeue(Q);
    cout << endl;

    cout << "queue setelah deque 2 kali" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "queue setelah diupdate " << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}
```
Program ini mengimplementasikan struktur data Queue menggunakan linked list, di mana setiap node menyimpan data angka dan pointer berikutnya, diatur oleh pointer head (depan) dan tail (belakang). Fungsi utamanya meliputi inisialisasi, pengecekan kekosongan (isEmpty), enqueue (tambah belakang), dan dequeue (hapus depan).Fitur tambahan yang disediakan adalah updateQueue (ganti nilai node berdasarkan posisi), viewQueue (tampilkan isi), dan searchData (cari nilai).Pada eksekusi utama, program membuat lima node, menambahkannya, menampilkan antrian, menghapus dua node terdepan, memperbarui beberapa posisi, dan melakukan pencarian data.

### 2. Soal guided 2
"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
struct Queue
{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};
void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif

```
"queue.cpp"
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```
"main.cpp"
```C++
#include <iostream>
#include"queue.h"
using namespace std;
int main (){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueu 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    
    cout << "\n dequeue 1 elemen" << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "enqueu 1 elemen " << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n dequeue 2 elemen " << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    cout << "elemen keluar : " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}
```
Program ini mengimplementasikan Circular Queue (antrian melingkar) menggunakan array berukuran tetap ($MAX\_QUEUE = 5$). Struktur data ini menyimpan indeks head (posisi elemen depan), tail (posisi elemen belakang berikutnya), dan count (jumlah elemen tersimpan) sebagai informasi penting. Fungsi createQueue menginisialisasi queue menjadi kosong, sementara isEmpty dan isFull digunakan untuk memeriksa statusnya. Operasi enqueue menambahkan data pada posisi tail, lalu memperbarui indeksnya secara melingkar menggunakan operasi modulus. Sebaliknya, dequeue mengambil elemen dari head dan menggeser posisi kepala juga secara melingkar. Fungsi printInfo bertugas menampilkan seluruh isi queue sesuai jumlah elemen yang ada. Dalam fungsi utama, program mendemonstrasikan proses kerja circular queue: ia menambahkan beberapa elemen, menghapus elemen terdepan, menambahkan elemen kembali setelah indeks berputar, dan menampilkan kondisi queue setiap terjadi perubahan.

## Unguided 

### 1. Soal unguided 1
Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file“queue.h”.Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme
queue Alternatif 1 (head diam, tail bergerak).

"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = 0;

}
bool isEmptyQueue(Queue Q){
    return (Q.head == 0);
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE);
}
void enqueue(Queue &Q, infotype x){
    if(isFullQueue(Q)){
        cout << "queue penuh" << endl;

    }
    if (isEmptyQueue(Q)){
        Q.head = 1;
        Q.tail = 1;
        Q.info[0] = x;
    }else{
        Q.tail++;
        Q.info[Q.tail - 1] = x;
    }
    
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        cout << "queue kosong" << endl;
        return -1;
    }
    infotype hasil = Q.info[0];
    for (int i = 0; i < Q.tail - 1; i++){
        Q.info[i] = Q.info[i + 1];
    }
    Q.tail--;
    if (Q.tail == 0){
        Q.head = 0;
    }
    return hasil;
}
void printInfo(Queue Q) {
    int H, T;

    // Konversi posisi HEAD & TAIL ke format tugas (0 → -1 untuk kosong)
    if (isEmptyQueue(Q)) {
        H = -1;
        T = -1;
    } else {
        H = Q.head - 1;   // HEAD selalu = 1 → ditampilkan sebagai 0
        T = Q.tail - 1;   // TAIL = jumlah elemen → ditampilkan indeks terakhir
    }

    // Cetak HEAD - TAIL
    cout << H << "  -  " << T << "  |  ";

    // Tampilkan isi queue
    if (isEmptyQueue(Q)) {
        cout << "empty queue";
    } else {
        for (int i = 0; i < Q.tail; i++) {
            cout << Q.info[i] << " ";
        }
    }

    cout << endl;
}
```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan8_modul8/output_unguided1_modul8.png)

Program ini mengimplementasikan struktur data Queue (antrian) menggunakan array sederhana tanpa mekanisme circular. Queue terdiri dari array info[MAX_QUEUE] dengan dua penanda posisi yaitu head dan tail. Fungsi CreateQueue menginisialisasi head dan tail dengan nilai 0 sebagai penanda antrian kosong. Pemeriksaan kondisi kosong dilakukan melalui isEmptyQueue dengan mengecek apakah head bernilai 0, sedangkan isFullQueue memeriksa apakah tail telah mencapai kapasitas maksimum.
Operasi enqueue menambahkan elemen baru pada posisi tail. Ketika antrian kosong, head dan tail diatur menjadi 1 dan data ditempatkan di indeks 0. Untuk antrian yang tidak kosong, tail bertambah dan data disimpan pada posisi tail - 1. Sementara itu, operasi dequeue mengambil elemen terdepan dari indeks 0, kemudian menggeser seluruh elemen ke kiri agar posisi depan tetap berada di indeks 0. Setelah penghapusan, tail dikurangi dan jika tail menjadi 0, antrian kembali kosong dengan head diatur ke 0.
Fungsi printInfo menampilkan posisi HEAD dan TAIL sesuai format yang ditentukan beserta isi antrian saat ini. Pada fungsi main, program mendemonstrasikan cara kerja queue melalui serangkaian operasi enqueue dan dequeue dengan menampilkan isi antrian setelah setiap operasi. Program ini menunjukkan implementasi queue sederhana yang menggunakan teknik shifting (pergeseran array) pada setiap penghapusan untuk menjaga struktur data tetap teratur dengan elemen terdepan selalu berada di indeks pertama.


### 2. Soal unguided 2
Buatlah implementasi ADT Queue pada file“queue.cpp” dengan menerapkan mekanisme
queue Alternatif 2 (head bergerak, tail bergerak).

"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = 0;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return Q.tail < Q.head;
}
bool isFullQueue(Queue Q){
    return(Q.tail == MAX_QUEUE - 1);
}
void enqueue(Queue &Q, infotype x){
   
   if(!isFullQueue(Q)){
    Q.tail++;
    Q.info[Q.tail] = x;
   }else{
        cout << "queue penuh \n";
   }
    
    
}
infotype dequeue(Queue &Q){
    if (!isEmptyQueue(Q)) {
        int x = Q.info[Q.head];
        Q.head++;

        // reset ketika kosong
        if (Q.head > Q.tail) {
            Q.head = 0;
            Q.tail = -1;
        }
        return x;
    }
    cout << "Queue kosong!\n";
    return -1;
   
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue\n";
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << "\n";
}

```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan8_modul8/output_unguided2_modul8.png)

Program ini mengimplementasikan struktur data queue menggunakan array linear yang bergerak maju tanpa mekanisme circular. Queue terdiri dari array info[MAX_QUEUE] dengan dua indeks utama: head sebagai penanda posisi elemen terdepan dan tail sebagai penanda posisi elemen terakhir. Pada inisialisasi menggunakan CreateQueue, head diatur ke 0 dan tail ke -1 untuk menandakan antrian kosong. Fungsi isEmptyQueue memeriksa apakah tail berada di belakang head untuk menentukan kondisi kosong, sementara isFullQueue mengecek apakah tail telah mencapai indeks maksimum.
Dalam operasi enqueue, selama antrian belum penuh, tail akan bertambah satu dan elemen baru ditempatkan pada posisi tersebut. Untuk operasi dequeue, elemen terdepan pada posisi head diambil kemudian head ditambah satu. Jika setelah pengambilan elemen nilai head melebihi tail, maka queue direset dengan mengembalikan kedua indeks ke posisi awal. Fungsi printInfo menampilkan posisi head dan tail beserta seluruh elemen queue dari head hingga tail.
Pada fungsi main, program mendemonstrasikan cara kerja queue melalui berbagai operasi enqueue dan dequeue lengkap dengan output di setiap tahapan. Implementasi ini membuat antrian berfungsi dengan baik meskipun tanpa pergeseran elemen, namun area yang telah dilalui head menjadi tidak digunakan lagi.

### 3. Soal unguided 3
"queue.h"
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define MAX_QUEUE 5
typedef int infotype;
struct Queue{
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};
void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```
"queue.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

void CreateQueue(Queue &Q){
    Q.head = -1;
    Q.tail = -1;

}
bool isEmptyQueue(Queue Q){
    return(Q.head == -1 && Q.tail == -1);
}
bool isFullQueue(Queue Q){
    return((Q.tail + 1) % MAX_QUEUE == Q.head);
}
void enqueue(Queue &Q, infotype x){
    if (isFullQueue(Q)){
        cout << "queue penuh" << endl;
        return;
    }
    if(isEmptyQueue(Q)){
        Q.head = 0;
        Q.tail = 0;

    }else{
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    Q.info[Q.tail] = x;
}
infotype dequeue(Queue &Q){
    if (isEmptyQueue(Q)){
        return -1;
    }
    infotype temp = Q.info[Q.head];
    if(Q.head == Q.tail){
        Q.head = -1;
        Q.tail = -1;
    }else{
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }
    return temp;
}
void printInfo(Queue Q){
    cout << " " << Q.head << " - " << Q.tail << "\t | ";

    if(isEmptyQueue(Q)){
        cout << "Queue kosong" << endl;
        return;
    }

    int i = Q.head;
    while(true){
        cout << Q.info[i] << " ";
        if(i == Q.tail) break;
        i = (i + 1) % MAX_QUEUE;
    }
    cout << endl;
}
```
"main.cpp"
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
    }
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan8_modul8/output_unguided3_modul8.png)

Program ini mengimplementasikan CircularQueue menggunakan array dengan teknik pergeseran indeks berbasis modulus. Struktur queue terdiri dari array info[MAX_QUEUE] dengan dua penanda yaitu head dan tail yang menunjukkan posisi elemen pertama dan terakhir. Fungsi CreateQueue menginisialisasi kedua indeks dengan nilai -1 sebagai penanda antrian kosong. Fungsi isEmptyQueue memeriksa apakah head dan tail bernilai -1, sedangkan isFullQueue mendeteksi kondisi penuh dengan mengecek apakah posisi setelah tail yaitu (tail + 1) % MAX_QUEUE bertabrakan dengan head.
Pada operasi enqueue, jika antrian kosong maka head dan tail diatur ke 0. Jika antrian berisi elemen, tail dimajukan secara circular menggunakan formula (tail + 1) % MAX_QUEUE, kemudian data baru ditambahkan pada posisi tail tersebut. Untuk operasi dequeue, elemen pada posisi head dihapus dan head dimajukan secara circular. Apabila setelah penghapusan nilai head sama dengan tail, kedua indeks dikembalikan ke -1 menandakan antrian kembali kosong.
Fungsi printInfo menampilkan posisi head dan tail beserta seluruh isi queue dengan menelusuri array secara circular hingga mencapai tail. Pada fungsi main, program mendemonstrasikan cara kerja circular queue melalui berbagai operasi enqueue dan dequeue dengan menunjukkan pergerakan indeks tanpa perlu menggeser elemen-elemen di dalam array.


## Kesimpulan
Struktur data merupakan elemen fundamental dalam pemrograman yang berperan mengorganisasi, menyimpan, dan mengelola data supaya lebih mudah diakses serta diproses. Pemilihan struktur data yang sesuai dapat meningkatkan efisiensi kinerja program dan mempermudah penanganan pengolahan data kompleks. Queue adalah salah satu struktur data yang umum digunakan dengan menerapkan prinsip FIFO (First In, First Out).
Queue memiliki banyak kegunaan dalam berbagai aplikasi seperti penjadwalan proses, pengelolaan antrean tugas, manajemen pesan, dan sistem yang memerlukan pemrosesan data secara berurutan. Queue tersedia dalam beberapa jenis yang dapat disesuaikan dengan kebutuhan, baik dari aspek implementasi seperti Linear Queue dan Circular Queue, maupun dari aspek penggunaan seperti Priority Queue dan Double-ended Queue. Dengan memahami berbagai jenis dan fungsi queue, programmer dapat menentukan model antrean yang paling tepat untuk menyelesaikan permasalahan secara lebih efisien.

## Referensi
[1] Anaraindyah, R. (2024). Struktur data: Pengertian, fungsi, dan penerapannya. Universitas Negeri Surabaya.[text](https://share.google/kfvAZsEHXwWWO9ZVc) </br>
[2] Maulana, R. (2023). Struktur data queue: Pengertian, fungsi, dan jenisnya. Digoding.[text](https://share.google/pxu2YAgcsMBzVlprm)
