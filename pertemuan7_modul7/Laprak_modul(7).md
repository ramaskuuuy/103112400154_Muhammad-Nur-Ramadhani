# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>


## Dasar Teori

### A. Stack<br/>
Stack adalah struktur data linier yang mengikuti aturan tertentu untuk melakukan operasi. Data yang memiliki struktur stack, tersusun seperti tumpukan, sehingga hanya elemen yang baru dimasukkan yang dapat diakses atau dilihat. Ujung tumpukan yang digunakan untuk melakukan semua operasi disebut bagian atas tumpukan. Stack mengikuti prinsip LIFO (Last In First Out), yang berarti elemen yang dimasukkan terakhir akan menjadi elemen pertama yang keluar dari urutan data [1].

### B. Implementasi Stack<br/>
Terdapat dua implementasi umum: Array / Statis: ukuran tetap, sederhana secara implementasi namun kurang fleksibel [2]. Linked List / Dinamis: menggunakan node dan pointer, ukuran fleksibel mengikuti alokasi memori [2].

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
Program ini mengimplementasikan struktur data Stack dinamis (LIFO) menggunakan linked list. Program ini menyediakan operasi dasar seperti push, pop, dan view, serta fungsi tambahan untuk memperbarui dan mencari data. Fungsi main mendemonstrasikan alur kerja: setelah memasukkan lima data, program melakukan dua kali pop, beberapa kali update, dan pencarian. Implementasi ini dilengkapi validasi input dan notifikasi untuk setiap operasi.

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
Program ini mengimplementasikan Stack statis menggunakan array berkapasitas 20 elemen dengan penunjuk indeks top. Selain operasi dasar seperti push, pop, dan validasi kapasitas (empty/full), tersedia fungsi balikStack yang menggunakan dua stack bantu untuk membalik urutan data. Fungsi main mendemonstrasikan alur manipulasi data, pencetakan awal, proses pembalikan, dan pencetakan hasil akhir.

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
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan7_modul7/output_unguided1_modul7.png)

Fungsi main ini menguji fungsionalitas ADT Stack, terutama fungsi balikstack. Program diawali dengan createStack, lalu mengeksekusi urutan operasi: push(3), push(4), push(8), diikuti pop(). Dilanjutkan dengan push(2), push(3), pop(), dan diakhiri push(9). Stack yang dihasilkan (dari atas: 9, 2, 4, 3) ditampilkan oleh printinfo. Setelah itu, balikstack digunakan untuk membalik urutan elemen, dan hasilnya dicetak kembali untuk verifikasi.

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
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan7_modul7/output_unguided2_modul7.png)

Fungsi main ini menguji ADT Stack, berfokus pada operasi pushascanding. Program diawali dengan createStack, lalu mengeksekusi pushascanding untuk data 3, 4, 8, 2, 3, dan 9. Operasi ini menyusun Stack dalam urutan ascending (dari bawah ke atas: [2, 3, 3, 4, 8, 9]). Isi Stack ini kemudian ditampilkan oleh printinfo. Selanjutnya, balikstack digunakan untuk membalik urutan elemen, dan hasil pembalikan tersebut dicetak kembali untuk verifikasi.

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
![Screenshot Output Unguided 1_1](https://github.com/ramaskuuuy/103112400154_Muhammad-Nur-Ramadhani/blob/main/pertemuan7_modul7/output_unguided3_modul7.png)

Fungsi main ini menguji ADT Stack, berfokus pada penerimaan input dinamis dan pembalikan. Program diawali dengan createStack, lalu memanggil getInputStream(S) untuk mempopulasi Stack (kemungkinan berdasarkan runtime input pengguna). Isi Stack awal ini ditampilkan oleh printinfo. Selanjutnya, balikstack dieksekusi, dan hasil pembalikan urutan tersebut dicetak kembali untuk verifikasi.


## Kesimpulan
Stack adalah struktur data linier yang penting untuk pengelolaan data dinamis. Stack beroperasi secara ketat menggunakan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan adalah elemen pertama yang harus dikeluarkan. Karena mekanisme ini, Stack sangat efektif untuk menyelesaikan masalah yang membutuhkan urutan operasi tertentu.

## Referensi
[1]Soffya Ranti. (2022). Pengertian Stack dan Queue serta Contoh Penerapannya. Kompas.Com [text](https://tekno.kompas.com/read/2022/12/01/02150047/pengertian-stack-dan-queue-serta-contoh-penerapannya?utm_source=Various&utm_medium=Referral&utm_campaign=Top_Desktop)<br>
[2]GeeksforGeeks — Stack Data Structure [text](https://www.geeksforgeeks.org/dsa/stack-data-structure/)<br>
