# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>


## Dasar Teori
Linked List adalah jenis struktur data linier di mana setiap elemen tidak disimpan di tempat yang berdekatan, melainkan dihubungkan melalui pointer. Linked List terdiri dari rangkaian node yang saling terhubung, di mana setiap node berisi data dan alamat node berikutnya [1].


### A. Doubly linked list<br/>
Doubly linked list adalah linked list bidirectional. Jadi, kita bisa melintasinya secara dua arah. Tidak seperti singly linked list, simpul doubly linked list berisi satu pointer tambahan yang disebut previous pointer. Pointer ini menunjuk ke simpul sebelumnya [2].
Double linked list memiliki beberapa operasi dasar pada list, misalkan penyisipan(insert first,last, after/before), penghapusan(delete first,last, node), menampilkan maju, dan menampilkan mundur [3].


## Guided 

### 1. Soal Guided 1

"file stack.h"
```C++
#ifndef STACK_H
#define STACK_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct Stack{
    address top;
};

bool isEmpty(Stack listStack);
void createStack(Stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(Stack &listStack, address nodeBaru);
void pop(Stack &listStack);
void update(Stack &listStack, int posisi);
void view(Stack listStack);
void searchData(Stack listStack, int data);

#endif
```
file "stack.cpp"
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(Stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(Stack &listStack){
    listStack.top = Nil;
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

void push(Stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(Stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(Stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(Stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(Stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```
file "main.cpp"
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    Stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Program ini mengimplementasikan doubly linked list untuk manajemen data makanan. Operasi yang didukung meliputi inisialisasi list, penyisipan node (di berbagai posisi), traversal (menampilkan isi list), dan update (pembaruan) data pada node tertentu.

### 2. soal guided 2

file "stack.h"
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20 //array unutknmenyimpan stack smpe 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // nambh elemen

infotype pop(Stack &S); // ambil elemem paling atas
void printInfo(Stack S);
void balikStack(Stack &S); // membentuk urutan stack


#endif
```
file "stack.cpp"
```C++
#ifndef STACK_H
#define STACK_H
#include <iostream>
#define MaxEl 20 //array unutknmenyimpan stack smpe 20
#define Nil -1

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};
void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x); // nambh elemen

infotype pop(Stack &S); // ambil elemem paling atas
void printInfo(Stack S);
void balikStack(Stack &S); // membentuk urutan stack


#endif
```

file "main.cpp"
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Program ini mengimplementasikan doubly linked list untuk manajemen data kendaraan (nopol, warna, tahun). Operasi yang didukung meliputi inisialisasi list, penambahan data (di akhir), pencarian (via nopol), penghapusan, dan penampilan semua data.

## Unguided 

### 1. Soal unguided 
Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”: Type infotype : integer Type Stack < info : array [20] of integer top : integer
procedure CreateStack( input/output S : Stack ) procedure push(input/output S : Stack, input x : infotype) function pop(input/output t S : Stack ) → infotype procedure printInfo( input S : Stack ) procedure balikStack(input/output S : Stack )

file "stack.h"
```C++
#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;

typedef int infotype;
struct stack{
    int info[20];
    int top;
};

void createStack(stack &S);
void push(stack &S,infotype x);
infotype pop(stack &S);
void printinfo(stack S);
void balikstack(stack &S);
#endif
```

file "stack.cpp"
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S){
    S.top = -1;
}

void push(stack &S ,infotype x){
    if (S.top < 19){
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(stack &S){
    if (S.top == -1){
        cout << "Stack kosong!" << endl;
        return -1; 
    } else {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    }
}

void printinfo(stack S){
    if (S.top == -1){
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP]";
        for(int i = S.top; i >= 0; i--){
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikstack(stack &S){
    stack temp;
    createStack(temp);

    while (S.top != -1){
       
        int nilai = S.info[S.top];
        S.top--;

       
        if (temp.top < 19){
            temp.top++;
            temp.info[temp.top] = nilai;
        }
    }

    S = temp;
}

```

file "main.cpp"
```C++
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
    cout << "Hello World!" << endl;
    stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S,2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printinfo(S);
    cout << "balik stack" << endl;
    balikstack(S);
    printinfo(S);
    cout << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan6_modul6/output_unguided1_modul6.png)

Program ini adalah implementasi doubly linked list untuk mengelola data kendaraan (nopol, warna, tahun) secara dinamis. Program ini memiliki fungsi untuk membuat list, menambah data di akhir (sambil mengecek duplikasi nopol), mencari berdasarkan nopol, dan menghapus data (baik di awal, akhir, atau tengah). Pada fungsi main, pengguna dapat menguji operasi input, display, pencarian, dan penghapusan data

### 2. Soal unguided 
Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

file "stack.h"
```C++
#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;

typedef int infotype;
struct stack{
    int info[20];
    int top;
};

void createStack(stack &S);
void push(stack &S,infotype x);
infotype pop(stack &S);
void printinfo(stack S);
void balikstack(stack &S);
void pushascanding(stack &S, int x);
#endif
```

file "stack.cpp"
```C++

#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S){
    S.top = -1;
}

void push(stack &S ,infotype x){
    if (S.top < 19){
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(stack &S){
    if (S.top == -1){
        cout << "Stack kosong!" << endl;
        return -1; // atau nilai khusus untuk menandakan stack kosong
    } else {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    }
}

void printinfo(stack S){
    if (S.top == -1){
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for(int i = S.top; i >= 0; i--){
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikstack(stack &S){
    stack temp;
    createStack(temp);

    while (S.top != -1){
        // ambil nilai dari S (pop manual)
        int nilai = S.info[S.top];
        S.top--;

        // masukkan nilai ke temp tanpa input ulang
        if (temp.top < 19){
            temp.top++;
            temp.info[temp.top] = nilai;
        }
    }

    S = temp;
}

void pushascanding(stack &S, int x){
    stack temp;
    createStack(temp);

    
    while (S.top != -1 && S.info[S.top] > x){
        int nilai = S.info[S.top];
        S.top--;

        temp.top++;
        temp.info[temp.top] = nilai;
    }

  
    S.top++;
    S.info[S.top] = x;

   
    while (temp.top != -1){
        int nilai = temp.info[temp.top];
        temp.top--;

        S.top++;
        S.info[S.top] = nilai;
    }
}

```

file "main.cpp"
```C++
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
     cout << "Hello World!" << endl;
     stack S;
    createStack(S);
    pushascanding(S, 3);
    pushascanding(S, 4);
    pushascanding(S, 8);
    pushascanding(S, 2);
    pushascanding(S, 3);
    pushascanding(S, 9);
    printinfo(S);
    cout << "balik stack" << endl;
    balikstack(S);
    printinfo(S);
    cout << endl;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan6_modul6/output_unguided1_modul6.png)

Program ini adalah implementasi doubly linked list untuk mengelola data kendaraan (nopol, warna, tahun) secara dinamis. Program ini memiliki fungsi untuk membuat list, menambah data di akhir (sambil mengecek duplikasi nopol), mencari berdasarkan nopol, dan menghapus data (baik di awal, akhir, atau tengah). Pada fungsi main, pengguna dapat menguji operasi input, display, pencarian, dan penghapusan data

### 3. Soal unguided 
Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)

file "stack.h"
```C++
#ifndef stack_h
#define stack_h
#include <iostream>
using namespace std;

typedef int infotype;
struct stack{
    int info[20];
    int top;
};

void createStack(stack &S);
void push(stack &S,infotype x);
infotype pop(stack &S);
void printinfo(stack S);
void balikstack(stack &S);
void pushascanding(stack &S, int x);
void getInputStream(stack &S);
#endif
```

file "stack.cpp"
```C++
#include "stack.h"
#include <iostream>
using namespace std;

void createStack(stack &S){
    S.top = -1;
}

void push(stack &S ,infotype x){
    if (S.top < 19){
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

infotype pop(stack &S){
    if (S.top == -1){
        cout << "Stack kosong!" << endl;
        return -1; // atau nilai khusus untuk menandakan stack kosong
    } else {
        int nilai = S.info[S.top];
        S.top--;
        return nilai;
    }
}

void printinfo(stack S){
    if (S.top == -1){
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for(int i = S.top; i >= 0; i--){
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikstack(stack &S){
    stack temp;
    createStack(temp);

    while (S.top != -1){
        // ambil nilai dari S (pop manual)
        int nilai = S.info[S.top];
        S.top--;

        // masukkan nilai ke temp tanpa input ulang
        if (temp.top < 19){
            temp.top++;
            temp.info[temp.top] = nilai;
        }
    }

    S = temp;
}

void pushascanding(stack &S, int x){
    stack temp;
    createStack(temp);

    
    while (S.top != -1 && S.info[S.top] > x){
        int nilai = S.info[S.top];
        S.top--;

        temp.top++;
        temp.info[temp.top] = nilai;
    }

  
    S.top++;
    S.info[S.top] = x;

   
    while (temp.top != -1){
        int nilai = temp.info[temp.top];
        temp.top--;

        S.top++;
        S.info[S.top] = nilai;
    }
}

void getInputStream(stack &S) {
    cout << "Masukkan deretan angka (akhiri dengan Enter): ";
    char c = getchar();
    while (c != '\n') {
        if (c >= '0' && c <= '9') {
            int digit = c - '0';
            push(S, digit);
        }
        c = getchar();
    }
}
```

file "main.cpp"
```C++
#include "stack.h"
#include <iostream>
using namespace std;
int main(){
   cout << "Hello World!" << endl;
    stack S;
    createStack(S);
    getInputStream(S);
    printinfo(S);
    cout << "balik stack" << endl;
    balikstack(S);
    printinfo(S);


    return 0;
}
```
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan6_modul6/output_unguided1_modul6.png)

Program ini adalah implementasi doubly linked list untuk mengelola data kendaraan (nopol, warna, tahun) secara dinamis. Program ini memiliki fungsi untuk membuat list, menambah data di akhir (sambil mengecek duplikasi nopol), mencari berdasarkan nopol, dan menghapus data (baik di awal, akhir, atau tengah). Pada fungsi main, pengguna dapat menguji operasi input, display, pencarian, dan penghapusan data


## Kesimpulan
Linked List adalah struktur data yang bersifat dinamis, terdiri dari sekumpulan node yang terhubung satu sama lain menggunakan pointer. Struktur ini memungkinkan pengelolaan data yang fleksibel karena tidak membutuhkan alokasi memori yang berurutan. Salah satu jenisnya adalah Doubly Linked List, yang memiliki kemampuan navigasi dua arah (ke depan dan ke belakang) melalui penggunaan pointer next dan prev. Hal ini membuat proses pencarian dan akses data menjadi lebih mudah dan efisien. Doubly Linked List mendukung berbagai operasi fundamental seperti penambahan node, penghapusan node, serta traversal data yang dapat dilakukan dari node pertama maupun node terakhir. Karakteristik ini menjadikan Doubly Linked List sangat bermanfaat untuk menangani data yang kompleks dan bersifat dinamis.

## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01).<br>
[2]Trivusi. (2022, 16 September). Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya. Diakses dari https://share.google/pozbIqzUEbmikX8fA<br>
[3]Rizkidoank. 2016. Double Linked List. Diakses pada 1 November 2025 dari https://share.google/41EjwqvTZzzn1nvmN