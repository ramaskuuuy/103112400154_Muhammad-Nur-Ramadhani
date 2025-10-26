# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Linked List adalah jenis struktur data linier di mana setiap elemen tidak disimpan di tempat yang berdekatan, melainkan dihubungkan melalui pointer. Linked List terdiri dari rangkaian node yang saling terhubung, di mana setiap node berisi data dan alamat node berikutnya .[1]

### A. Linear search<br/>
Linear Search adalah algoritma yang bekerja dengan mencocokkan data satu per satu secara berurutan, mulai dari ujung awal hingga ujung akhir dari sekumpulan data. Pencarian menggunakan Linear Search tidak akan berhenti sampai data yang dicari berhasil ditemukan. Kelebihan linear search adalah datanya tidak harus terurut dan dan alhoritmanya mudah dipelajari, tetapi tidak cocok unutk data yang sangat besar dan waktu pencariannya lama .[2]

### B. Binary searcht<br/>
Binary Search adalah metode pencarian yang digunakan untuk data yang sudah terurut. Metode ini bekerja dengan membagi data menjadi dua bagian secara terus-menerus. Dengan membagi dua, proses pencarian menjadi lebih cepat karena tidak perlu mencari di bagian yang tidak relevan. Kelebihan binary search adalah pencarian nya lebih cepat dan efektif jika datanya banyak, tetapi datanya harus terurut[2].

## Guided 

### 1. Soal Guided 1
file "listbuah.h"
```C++
    #ifndef LISTBUAH_H
    #define LISTBUAH_H

    #define Nil NULL
    #include <iostream>
    using namespace std;

    struct buah {
        string nama;
        int jumlah;
        float harga;
    };

    typedef buah dataBuah;
    typedef struct node *address;

    struct node {
        dataBuah isidata;
        address next;
    };

    struct linkedlist {
        address first;
    };

    // ==== DEKLARASI / PROTOTYPE ====
    bool isEmpty(linkedlist List);
    void createList(linkedlist &List);

    address alokasi(string nama, int jumlah, float harga);
    void dealokasi(address &node);

    void insertFirst(linkedlist &List, address nodeBaru);
    void insertAfter(linkedlist &List, address nodeBaru, address Prev);
    void insertLast(linkedlist &List, address nodeBaru);

    void delFirst(linkedlist &List);
    void delLast(linkedlist &List);
    void delAfter(linkedlist &List, address nodeHapus, address nodePrev);

    void printList(linkedlist List);
    int nbList(linkedlist List);
    void deleteList(linkedlist &List);

    // === Fungsi update data ===
    void updateFirst(linkedlist List);
    void updateLast(linkedlist List);
    void updateAfter(linkedlist List, address nodePrev);

    #endif
```
file "listbuah.cpp"
```C++
#include "listbuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if (List.first == Nil) {
        return true;
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) {
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah;
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
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

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List) {
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List) {
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil) {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else {
            while (nodeHapus->next != Nil) {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) {
            cout << "Nama Buah : " << nodeBantu->isidata.nama
            << ", Jumlah : " << nodeBantu->isidata.jumlah
            << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List) {
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil) {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List berhasil terhapus!" << endl;
}

//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) {
            address nodeBantu = nodePrev->next;
            cout << "Masukkan update data node setelah node "<< nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

file "main.cpp"
```C++
#include "listBuah.h"

#include <iostream>
using namespace std;

int main() {
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout <<"--- ISI LIST SETELAH DILAKUKAN INSERT---" << endl;
    printList(List);
    cout <<"jumlah node:" << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout <<"--- ISI LIST SETELAH DILAKUKAN UPDATE---" << endl;
    printList(List);
    cout << "jumlah node:" << nbList(List) << endl;
    cout << endl;

    return 0;
}
```


penjelasan singkat guided 1
Program ini mengimplementasikan struktur data Linked List untuk menyimpan dan mengatur informasi mengenai buah. Setiap elemen dalam list berisi nama, jumlah, dan harga buah, serta dilengkapi fungsi untuk memanipulasi data tersebut (menambah, menghapus, memperbarui, dan menampilkan).

### 2. Soal Guided 2
file "binary.cpp"
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara binary
Node* binarySearch(Node* head, int key) { //Node* ini pointer (kembalian) // head ini pointer ke node pertama //key ini data yang dicari
    int size = 0; //var size disi 0
    for (Node* current = head; current;current = current->next)size++; //current adalah pointer yan digunakan untuk menyusuri linked linked list
    Node *start = head; //start adalah pointer yang menunjuk ke node pertama
    Node *end = nullptr; //end adalah pointer yang menunjuk ke node terakhir (null karena linked list tidak memiliki pointer ke node terakhir yang pasti)

    while(size > 0) { //selama masih ada elemen > 0
        int mid = size / 2; //bagi size jadi 2
        Node* midNode = start; //midNode adalah pointer yang menunjuk ke node tengah
        for (int i = 0 ; i< mid;i++)midNode = midNode->next; //pindah ke node tengah

        if(midNode->data == key)return midNode; //jika ditemukan data yang cocok, kembalikan node
        if(midNode->data < key) { //jika data midNode lebih kecil dari key, kita cari dibagian kanan
            start = midNode->next; //Mulai pencarian dari node setelah midNode
        }
        else { //jika data midNode lebih besar dari key, kita cari dibagian kiri
            end = midNode; //Akhiri pencarian di midNode
        }
        size -= mid; //kita mengurangi size dengan mid
    }
    return nullptr; //jika key tidak ditemukan
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode; // node terakhir dihubungkan ke node baru
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30);
    append(head, 40);
    append(head, 50); //menambah node

    //mencari data 40  menggunakan binarysearch
    Node* result = binarySearch(head, 40); //result ini pointer untuk mencari data 40
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}

```

penjelasan singkat guided 2

Program binary.cpp mengimplementasikan pencarian biner (Binary Search) pada linked list yang terurut. Setelah data dimasukkan, program akan mencari nilai tertentu (contoh: 40) dan memberikan output "found" jika data ditemukan atau "not found" jika sebaliknya.

### 3. Soal Guided 3
file "linear.cpp"
```C++
#include <iostream>
using namespace std;

//definisi node
struct Node{//memiliki 2 bagian yaitu data dan pointer
    int data;
    Node* next; //pointer ke node berikutnya
};

//fungsi untuk melakukan pencarian secara linear
Node* linearSearch(Node* head, int key) {//head adalah pointer ke node pertama, key adalah nilai yang dicari
    Node* current = head; //mulai dari node pertama
    while (current != nullptr) { //selama current tidak null
        if (current->data == key)//jika data pada node saat ini sama dengan key
        return current; //kembalikan pointer ke node yang ditemukan
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; //jika tidak ditemukan, kembalikan null
}

//prosedur untuk menambah node
void append(Node*& head, int value) { // Node* ini pointer (kembalian) //fs linear search
    Node* newNode = new Node{value, nullptr}; //new node adalag pointer yang meunjuk ke node baru yang dibuat. // value == null karena node baru berada oaling akhir
    if (!head)head = newNode; // jika head null, head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)temp = temp->next; //pindah ke node berikutnya sampai node terakhir
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr; // inisiasi head list masih kosong
    append(head, 10);
    append(head, 20); 
    append(head, 30); //menambah node

    Node* result = linearSearch(head, 20); //result ini pointer untuk mencari data 20
    cout << (result? "found": "not found") << endl; // condition ? value_if_true : value_if_false
    return 0;
}

```

penjelasan singkat guided 3
Program ini melakukan pencarian linear pada sebuah linked list, di mana setiap elemen diperiksa satu per satu. Program akan mencari nilai spesifik (misalnya 20) di dalam data yang telah ditambahkan dan melaporkan hasilnya, yaitu "found" jika ditemukan atau "not found" jika tidak.

## Unguided 

### 1. (soal unguided 1)
Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:

 1.Membuat linked list dengan menambahkan node di akhir <br>
 2.Mengimplementasikan binary search pada linked list <br>
 3.Menampilkan detail proses pencarian dan hasil akhir Petunjuk Tugas 1: • Gunakan struktur Node dengan data integer dan pointer next • Implementasikan fungsi append() untuk menambah node • Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan • Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar • Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi • Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian.

file "soal1.cpp"
```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next; 
};


void displayList(Node* head) {
    if (!head) {
        cout << "Linked list kosong\n";
        return;
    }
    
    cout << "Linked List yang dibuat: ";
    
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL\n";
}


Node* binarySearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    

    int size = 0;
    for (Node* current = head; current; current = current->next) {
        size++;
    }
    
    Node* start = head;
    int iteration = 1;
    
    while (size > 0) {
        int mid = size / 2;
        Node* midNode = start;
        
        
        for (int i = 0; i < mid; i++) {
            midNode = midNode->next;
        }
        
        if (midNode->data == key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) - DITEMUKAN!\n";
            return midNode;
        }
        
        
        if (midNode->data < key) {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kanan\n";
            
            int newSize = size - mid - 1;
            
        
            if (newSize == 1) {
                Node* lastNode = midNode->next;
                if (lastNode && lastNode->data == key) {
                    return lastNode;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            start = midNode->next;
            size = newSize;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        else {
            cout << "Iterasi " << iteration << ": Mid = " << midNode->data 
                 << " (indeks tengah) -> Cari di bagian kiri\n";
            
            
            if (mid == 1) {
                if (start->data == key) {
                    return start;
                }
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
            
            size = mid;
            
            if (size <= 0) {
                cout << "Tidak ada elemen tersisa\n";
                return nullptr;
            }
        }
        
        iteration++;
    }
    
    cout << "Tidak ada elemen tersisa\n";
    return nullptr;
}


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void deleteList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    
    cout << "BINARY SEARCH PADA LINKED LIST\n";
    
   
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);
    
    displayList(head);
    
    
    cout << "Mencari nilai: 40";
    
    Node* result = binarySearch(head, 40);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 40 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
 
    cout << "Mencari nilai: 25\n";
    
    result = binarySearch(head, 25);
    
    if (result) {
        cout << "\nHasil: Nilai " << result->data << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << "\n";
        cout << "Data node: " << result->data << "\n";
        if (result->next) {
            cout << "Node berikutnya: " << result->next->data << "\n";
        } else {
            cout << "Node berikutnya: NULL\n";
        }
    } else {
        cout << "\nHasil: Nilai 25 TIDAK DITEMUKAN dalam linked list!\n";
    }
    
  
    deleteList(head);
    
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan5_modul5/output_unguided1_modul5.png)

penjelasan unguided 1 

Program ini mendemonstrasikan pencarian data menggunakan metode binary search pada sebuah linked list. Program dilengkapi fungsi untuk menambah data secara berurutan (append()) dan menampilkannya (displayList()). Fungsi utamanya, binarySearch(), bekerja dengan memecah daftar menjadi dua bagian secara berulang untuk menemukan nilai tengah, lalu melanjutkan pencarian di separuh bagian yang relevan hingga data ditemukan. Sebagai contoh, program akan membuat list berisi angka 10 sampai 60, lalu berhasil menemukan angka 40 dan gagal menemukan angka 25.


### 2. (soal unguided 2)
Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program harus mampu: <br>
 1.Membuat linked list dengan menambahkan node di akhir <br>
 2.Mengimplementasikan linear search pada linked list <br>
 3.Menampilkan detail proses pencarian dan hasil akhir Petunjuk Tugas 2: • Gunakan struktur Node dengan data integer dan pointer next • Implementasikan fungsi append() untuk menambah node • Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan • Data dalam linked list tidak perlu terurut untuk linear search • Tampilkan setiap langkah pencarian dan node yang sedang diperiksa • Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

file "soal2.cpp"
```C++
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}


Node* linearSearch(Node* head, int key) {
    Node* current = head;
    int posisi = 1;

    cout << "\nProses Pencarian:\n";

    while (current != nullptr) {
        cout << "Memeriksa node " << posisi << ": " << current->data;
        if (current->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return current;
        } else {
            cout << " (tidak sama)\n";
        }
        current = current->next;
        posisi++;
    }

    cout << "Tidak ada node lagi yang tersisa\n";
    return nullptr;
}

void printList(Node* head) {
    cout << "Isi Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = nullptr;

    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);


    int cari1 = 30;
    cout << "Mencari nilai: " << cari1 << "\n";
    Node* hasil1 = linearSearch(head, cari1);

    if (hasil1) {
        cout << "\nHasil: Nilai " << cari1 << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil1 << "\n";
        cout << "Data node: " << hasil1->data << "\n";
        if (hasil1->next)
            cout << "Node berikutnya: " << hasil1->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari1 << " TIDAK DITEMUKAN dalam linked list!\n";
    }

   
    int cari2 = 25;
    cout << "\nMencari nilai: " << cari2 << "\n";
    Node* hasil2 = linearSearch(head, cari2);

    if (hasil2) {
        cout << "\nHasil: Nilai " << cari2 << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil2 << "\n";
        cout << "Data node: " << hasil2->data << "\n";
        if (hasil2->next)
            cout << "Node berikutnya: " << hasil2->next->data << "\n";
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << cari2 << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan5_modul5/output_unguided2_modul5.png)

penjelasan unguided 2

Program ini adalah implementasi pencarian linear pada linked list dalam bahasa C++. Program ini memiliki fungsi untuk menambah data (append), menampilkan seluruh isi list (printList), dan mencari sebuah nilai dengan memeriksa setiap elemen satu per satu (linearSearch). Sebagai contoh, program membuat list berisi 10 hingga 50, kemudian berhasil menemukan nilai 30, dan gagal menemukan nilai 25.


## Kesimpulan
Linked List adalah sebuah struktur data linier di mana setiap elemen atau node terhubung melalui pointer alih-alih disimpan di memori yang berurutan, dan untuk mencari data di dalamnya, metode Linear Search dapat digunakan dengan memeriksa setiap node satu per satu tanpa perlu data terurut, meskipun lambat untuk data besar, sementara Binary Search menawarkan solusi yang jauh lebih cepat dengan membagi data menjadi dua secara berulang, namun dengan syarat mutlak bahwa data harus sudah diurutkan terlebih dahulu.

## Referensi
[1] Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).[text](https://jurnal.mifandimandiri.com/index.php/penerbitmmd/article/view/39/33)
<br>[2] Putra, M. Naufal Adrian Pratama. 2023. Algoritma Pemrograman: Linear Search & Binary Search. Medium, 29 Juni 2023. Diakses dari [text](https://medium.com/@naufal.adrian904/algoritma-pemrograman-linear-search-binary-search-3cd4403bab88)