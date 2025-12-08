# <h1 align="center">Laporan Praktikum Modul 10 - TREE(Bagian Pertama)</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Multi Linked List yang terhubung banyak terdiri dari beberapa kelompok Linked List yang berbeda, tetapi bisa diakses sekaligus. Setiap kelompok Linked List memiliki simpul-simpul yang saling terkait dalam kelompok tersebut. Tipe Linked List ini memungkinkan penyimpanan data dalam bentuk kelompok-kelompok terpisah sekaligus menjaga struktur data yang rapi dan teratur. Dengan memahami perbedaan antara berbagai jenis Linked List, kita bisa memilih struktur data yang tepat sesuai dengan kebutuhan aplikasi [1].

### A. Tree<br/>
Tree merupakan bentuk struktur data yang membentuk hierarki melalui hubungan antar simpul (node) yang terhubung oleh jalur (edge). Dimulai dari simpul utama yang disebut root, setiap node bisa memiliki satu atau lebih node turunan (child), sedangkan node yang tidak memiliki turunan disebut sebagai daun (leaf) [2].


## Guided 

### 1. Soal guided 1
file BST1.h
```C++
#ifndef BST1_H
#define BST1_H
#include<iostream>
using namespace std;
typedef int infotype; // alias infotypen untk dta int
typedef struct Node* address; // alias adres sbgi pointer
struct Node{
    infotype info; // info data yg disimpan dismona (int)
    address left; // pointer left
    address right;// pointer right
};
bool isEmpty(address root);//
void createTree(address &root);// fungsi untuk mdmnuat  bst root do set null
address newNode(infotype x); //untuk memasukan data(infotype) ke dalam node
address insertNode(address root, infotype x);//untuk memasukan node ke dalam BST
//travesal
void preOrder(address root); // secara preorder tengan - kiri - kanan
void inOrder(address root); //kiri - tengah - kanan
void postOrder(address root); // kiri - kanan - tengah

int countNodes(address root);//untuk menghitung size jumlah node yang ada di tree
int treeDepth(address root);// 

#endif
```
file BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```
file main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Program ini mengimplementasikan struktur data Binary Search Tree (BST). Di dalamnya didefinisikan struktur Node yang menyimpan data bertipe int serta dua pointer untuk anak kiri dan kanan. Fungsi isEmpty() digunakan untuk memeriksa apakah tree kosong, createTree() untuk menginisialisasi root dengan nilai NULL, serta newNode() dan insertNode() untuk membuat node baru dan memasukkannya ke dalam BST sesuai aturan (nilai lebih kecil ditempatkan di kiri, nilai lebih besar di kanan).Program juga menyediakan tiga metode traversal—inOrder, preOrder, dan postOrder—yang menampilkan isi tree dalam urutan berbeda. Selain itu, fungsi countNodes() menghitung jumlah node dalam tree, sedangkan treeDepth() menentukan kedalaman tree. Pada fungsi main, tree dibuat, beberapa nilai dimasukkan, kemudian program menampilkan hasil traversal, total node, dan kedalaman tree.

### 2. soal guided 2

file BST2.h
```C++
#ifndef BST2_H
#define BST2_H
#include<iostream>
using namespace std;
typedef int infotype; // alias infotypen untk dta int
typedef struct Node* address; // alias adres sbgi pointer
struct Node{
    infotype info; // info data yg disimpan dismona (int)
    address left; // pointer left
    address right;// pointer right
};
bool isEmpty(address root);//
void createTree(address &root);// fungsi untuk mdmnuat  bst root do set null
address newNode(infotype x); //untuk memasukan data(infotype) ke dalam node
address insertNode(address root, infotype x);//untuk memasukan node ke dalam BST
//travesal
void preOrder(address root); // secara preorder tengan - kiri - kanan
void inOrder(address root); //kiri - tengah - kanan
void postOrder(address root); // kiri - kanan - tengah

int countNodes(address root);//untuk menghitung size jumlah node yang ada di tree
int treeDepth(address root);//

//fungsi tambahan
//search
void searchByData(address root, infotype x);

//mostleft dan righrleft
address mostLeft(address root);//menmapilkan mostleft/paling kiti
address mostRight(address root);// menmapilkan paling kanan

//delete
bool deleteNode(address &root, infotype x); // mennghapus node tertentu di dalam BST
void deleteTree(address &root);//proeedur untuk menghapus BSt(hapus seluruh node)

#endif

```
file BST2.cpp
```C++
#ifndef BST2_H
#define BST2_H
#include<iostream>
using namespace std;
typedef int infotype; // alias infotypen untk dta int
typedef struct Node* address; // alias adres sbgi pointer
struct Node{
    infotype info; // info data yg disimpan dismona (int)
    address left; // pointer left
    address right;// pointer right
};
bool isEmpty(address root);//
void createTree(address &root);// fungsi untuk mdmnuat  bst root do set null
address newNode(infotype x); //untuk memasukan data(infotype) ke dalam node
address insertNode(address root, infotype x);//untuk memasukan node ke dalam BST
//travesal
void preOrder(address root); // secara preorder tengan - kiri - kanan
void inOrder(address root); //kiri - tengah - kanan
void postOrder(address root); // kiri - kanan - tengah

int countNodes(address root);//untuk menghitung size jumlah node yang ada di tree
int treeDepth(address root);//

//fungsi tambahan
//search
void searchByData(address root, infotype x);

//mostleft dan righrleft
address mostLeft(address root);//menmapilkan mostleft/paling kiti
address mostRight(address root);// menmapilkan paling kanan

//delete
bool deleteNode(address &root, infotype x); // mennghapus node tertentu di dalam BST
void deleteTree(address &root);//proeedur untuk menghapus BSt(hapus seluruh node)

#endif

```
file main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Program ini mengimplementasikan Binary Search Tree (BST) secara lengkap, mulai dari operasi dasar hingga fitur tambahan seperti pencarian, pencarian nilai minimum–maksimum, dan penghapusan node. Struktur node berisi data integer serta pointer ke anak kiri dan kanan. Fungsi createTree, isEmpty, newNode, dan insertNode digunakan untuk membangun tree dan menambah data sesuai aturan BST.Program menyediakan traversal inOrder, preOrder, dan postOrder, serta fungsi countNodes dan treeDepth untuk menghitung jumlah node dan kedalaman tree. Melalui searchByData, program dapat mencari nilai tertentu dan menampilkan parent, sibling, dan child dari node tersebut. Nilai minimum dan maksimum diperoleh dengan mostLeft dan mostRight.Penghapusan node ditangani oleh deleteNode, yang mencakup semua kasus penghapusan, sementara deleteTree digunakan untuk mengosongkan seluruh tree. Pada fungsi main, program menambahkan data awal, menampilkan hasil traversal, melakukan pencarian, menampilkan nilai ekstrem, menghapus node berdasarkan input, dan akhirnya menghapus seluruh isi tree.

### 3. guided 3

```C++
#include <iostream>
using namespace std;

int pangkat_2(int x){
    if(x == 0){
        return 1;
    }else if(x > 0) { //rekuren
        return 2 * pangkat_2(x-1);
    }
}
int main(){
    cout <<" --rekursif pangkat 2--" << endl;

    int x;
    cout << " masukan nilai x : ";
    cin >> x;
    cout << endl;
    cout << " 2 pangkat " << x << "adalah : " << pangkat_2(x);
    return 0;
}
// x=3
//pankat(2)
//2* pagkat(2)
// 2*2pangkat91
```
Program ini menghitung nilai 2 pangkat x menggunakan rekursi. Fungsi pangkat_2(int x) bekerja dengan memanggil dirinya secara berulang. Jika x == 0, fungsi mengembalikan nilai 1 karena 2⁰ = 1. Jika x > 0, fungsi memanggil dirinya dengan nilai x-1, kemudian mengalikan hasilnya dengan 2. Proses ini berulang hingga x mencapai 0.

## Unguided 

### 1. Soal unguided 1
Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file
“bstree.h”.Buatlah implementasi ADT Binary Search Tree pada file“bstree.cpp” dan cobalah hasil
implementasi ADT pada file “main.cpp”

file bst.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);



#endif
```
file bst.cpp
```C++
#include "bst.h"


address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}


void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}


address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } 
    else if (x == root->info) {
        return root;
    } 
    else if (x < root->info) {
        return findNode(x, root->left);
    } 
    else {
        return findNode(x, root->right);
    }
}


void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}


```
file main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);
    InOrder(root);

    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]()

Program tersebut mengimplementasikan struktur data Binary Search Tree (BST). Struktur Node memiliki tiga elemen, yaitu info sebagai data, serta pointer left dan right sebagai anak kiri dan kanan. Fungsi alokasi digunakan untuk membuat node baru, sedangkan insertNode berfungsi menempatkan data ke dalam BST sesuai aturan: nilai lebih kecil disimpan di sisi kiri dan nilai lebih besar di kanan. Fungsi findNode digunakan untuk mencari sebuah nilai di dalam tree dengan cara menelusuri node secara rekursif. Sementara itu, fungsi printInOrder mencetak seluruh isi BST dari nilai paling kecil ke paling besar dengan traversal in-order (left–root–right). Pada fungsi main, program membuat BST kosong, memasukkan beberapa nilai (1–7) ke dalam tree, lalu mencetak seluruh isi tree secara urut. 

### 2. Soal unguided 2
Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer

file bst.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);


#endif
```

file bst.cpp
```C++
#include "bst.h"


address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}


void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}


address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } 
    else if (x == root->info) {
        return root;
    } 
    else if (x < root->info) {
        return findNode(x, root->left);
    } 
    else {
        return findNode(x, root->right);
    }
}


void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    return max(leftDepth, rightDepth);
}


```
file main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);
    InOrder(root);

    cout << "\n";
    
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;


    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]()

Program tersebut merupakan implementasi struktur data Binary Search Tree (BST) yang menyimpan data bertipe integer. Struktur Node memiliki nilai info serta pointer left dan right untuk merepresentasikan anak kiri dan kanan. Program menyediakan beberapa fungsi penting, antara lain insertNode untuk memasukkan data ke BST sesuai aturan nilai lebih kecil ke kiri dan lebih besar ke kanan, findNode untuk mencari nilai tertentu, serta printInOrder untuk mencetak seluruh isi tree secara terurut menggunakan traversal in-order. Selain itu, terdapat fungsi tambahan seperti hitungJumlahNode yang menghitung total node dalam tree, hitungTotalInfo yang menjumlahkan seluruh nilai yang tersimpan di tree, dan hitungKedalaman yang menentukan kedalaman atau tinggi tree secara rekursif. Pada fungsi main, program membuat tree kosong, memasukkan beberapa nilai (1–7), mencetak isi tree, lalu menampilkan kedalaman tree, jumlah total node, serta jumlah keseluruhan nilai yang tersimpan.

### 3. Soal unguided 3
Print tree secara pre-order dan post-order.

file bst.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node* left;
    Node* right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(infotype x, address root);
void InOrder(address root);
void preOrder(address root);
void postOrder(address root);
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);


#endif
```

file bst.cpp
```C++
#include "bst.h"


address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = NULL;
    P->right = NULL;
    return P;
}


void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } 
    else if (x < root->info) {
        insertNode(root->left, x);
    }
    else if (x > root->info) {
        insertNode(root->right, x);
    }
}


address findNode(infotype x, address root) {
    if (root == NULL) {
        return NULL;
    } 
    else if (x == root->info) {
        return root;
    } 
    else if (x < root->info) {
        return findNode(x, root->left);
    } 
    else {
        return findNode(x, root->right);
    }
}


void InOrder(address root) {
    if (root != NULL) {
        InOrder(root->left);
        cout << root->info << " - ";
        InOrder(root->right);
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) {
        return start;
    }
    int leftDepth = hitungKedalaman(root->left, start + 1);
    int rightDepth = hitungKedalaman(root->right, start + 1);
    return max(leftDepth, rightDepth);
}

void preOrder(address root) {
    if (root != NULL) {
        cout << root->info << " - ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(address root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " - ";
    }
}
```

file main.cpp
```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main() {
    cout << "Hello World!" << endl;

    address root = NULL;

    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6); 
    insertNode(root, 7);

    cout << "In-Order   : ";
    InOrder(root);

    cout << "\nPre-Order  : ";
    preOrder(root);

    cout << "\nPost-Order : ";
    postOrder(root);

    cout << "\n";
    
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;


    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1]()

Program tersebut membuat dan menelusuri sebuah binary tree menggunakan metode traversal pre-order dan post-order. Struktur Node digunakan untuk menyimpan sebuah nilai integer serta pointer ke anak kiri dan kanan. Fungsi alokasi digunakan untuk membuat node baru yang kemudian dirangkai secara manual di fungsi main sehingga membentuk sebuah tree dengan akar bernilai 6, dan memiliki beberapa cabang seperti 4, 7, 2, 5, 1, dan 3. Fungsi preOrder menampilkan node dengan urutan Root–Left–Right, sedangkan postOrder menampilkan node dengan urutan Left–Right–Root. Pada bagian output, program mencetak hasil traversal pre-order dan post-order dari tree yang telah dibentuk.

## Kesimpulan
Multi Linked List merupakan struktur data yang terdiri dari beberapa kelompok Linked List terpisah namun tetap dapat diakses sekaligus, sehingga memudahkan pengelompokan data secara rapi dan terorganisasi; sedangkan Tree adalah struktur data hierarkis yang menghubungkan node melalui hubungan parent–child, dimulai dari root hingga leaf, sehingga cocok untuk merepresentasikan data bertingkat; dan algoritma rekursif adalah teknik pemrograman di mana suatu fungsi memanggil dirinya sendiri dengan ruang masalah yang semakin kecil, sehingga sangat efektif digunakan pada proses yang memiliki pola berulang seperti traversal pada Tree. Dengan memahami ketiga konsep ini, kita dapat memilih dan menggunakan struktur data ataupun algoritma yang tepat sesuai kebutuhan aplikasi.

## Referensi
[1] Annisa. (2025). Pengertian Linked List : Structur Data dalam Pemprograman .[text](https://share.google/ZHwf3jDuCjJnvDri3) <br>
[2] Pebrianti, E., & Abdurramadan, N. (2025). Struktur Data Tree: Konsep, Jenis, dan Aplikasinya. Direktorat Pusat Teknologi Informasi.[text](https://share.google/gNeh0RKpK3BtJ8fRK) <br>

