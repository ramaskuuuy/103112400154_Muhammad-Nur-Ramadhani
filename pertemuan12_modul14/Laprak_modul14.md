# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Muhammad Nur Ramadhani - 103112400154</p>

## Dasar Teori
Linked List adalah jenis struktur data linier di mana setiap elemen tidak disimpan di tempat yang berdekatan, melainkan dihubungkan melalui pointer. Linked List terdiri dari rangkaian node yang saling terhubung, di mana setiap node berisi data dan alamat node berikutnya [1].


### A. Graph <br/>
Graph adalah jenis struktur data umum yang data dalam graph tidak terletak secara berdekatan satu sama lain, artinya data disusun secara non-linier. Graph terdiri dari sekelompok simpul yang digunakan untuk menyimpan data, dan antara dua simpul terdapat hubungan yang saling terkait. Berdasarkan arah penjelajahan, graph dibagi menjadi dua jenis yaitu graph tak berarah dan graph berarah [2].

## Guided 

### 1. Soal guided 1
graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
  adrNode first;
};
void createGraph(Graph &G);
adrNode allocateNode(infoGraph X);
void insertNode(Graph &G, infoGraph X);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);
#endif
```
graph_edge.cpp
```C++
#include "graph.h"
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while(P != NULL){
        if(P->info == X){
            P = P -> next;
        }
        return NULL;
    }
}
void connectNode(Graph &G, infoGraph start, infoGraph end){
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);
    if(pStart != NULL && pEnd != NULL){
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;//insert first di list edge
        pStart->firstEdge = newEdge;
    }
    
}

```
graph_init.cpp
```C++
#include "graph.h"
void createGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void insertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;

    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }
}
```
graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node" << P->info << "Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

```
main.cpp
```C++
#include "graph.h"
#include <iostream>
using namespace std;
int main(){
    Graph G;
    createGraph(G);

    insertNode(G, 'A');//nambah node A,B,C,D
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    //hub8ngkan node gd edge
    connectNode(G,'A','B'); // A ke B
    connectNode(G,'A','C'); // A ke C
    connectNode(G, 'B','D'); // B ke D
    connectNode(G, 'C','D'); // C ke D

    cout << "Isi graph :" << endl;
    printGraph(G);

}
```
Program ini mengimplementasikan struktur data graph berarah (directed graph) menggunakan linked list, di mana setiap node menyimpan data berupa karakter serta daftar edge yang merepresentasikan hubungan menuju node lain. Graph dimulai dari kondisi kosong, kemudian ditambahkan node A, B, C, dan D. Selanjutnya, dibentuk hubungan satu arah dari A ke B, A ke C, B ke D, dan C ke D. Setiap node menyimpan daftar node tujuan dalam bentuk adjacency list. Struktur graph kemudian ditampilkan dengan mencetak setiap node beserta node-node yang terhubung, sehingga hubungan antar node dapat diamati secara jelas.


## Unguided 

### 1. Soal Unguided 
Buatlah ADT Graph tidak berarah file “graph.h”.Buatlah implementasi ADT Graph pada file“graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp”.

graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
using namespace std;
typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;
struct ElmNode{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};
struct ElmEdge{
    adrNode node;
    adrEdge next;
};
struct Graph{
    adrNode first;
};
void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
adrNode findNode(Graph G, infoGraph X);
adrNode allocateNode(infoGraph X);
//prosedur untuk menampilkanhasil penelusuran DFS
void printDFS(Graph G, adrNode N);    
//prosedur untuk menampilkanhasil penelusuran BFS
void printBFS(Graph G, adrNode N);                     
void Visited(Graph &G);
#endif           
```

graph.cpp
```C++
#include "graph.h"
#include<queue>

void CreateGraph(Graph &G){
    G.first = NULL;
}
adrNode allocateNode(infoGraph X){
    adrNode P = new ElmNode; //milik parent
    P->info = X;
    P->visited = false;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}
void InsertNode(Graph &G, infoGraph X){
    adrNode P = allocateNode(X);
    if(G.first == NULL){
        G.first = P;
    }else{
        adrNode Q = G.first;
        while(Q->next != NULL){
            Q = Q->next;
        }
        Q->next = P;
    }

}
void ConnectNode(adrNode N1, adrNode N2){
    if (N1 != NULL && N2 != NULL) {
        // Edge N1 ke N2
        adrEdge E1 = new ElmEdge;
        E1->node = N2;
        E1->next = N1->firstEdge;
        N1->firstEdge = E1;

        // Edge N2 ke N1
        adrEdge E2 = new ElmEdge;
        E2->node = N1;
        E2->next = N2->firstEdge;
        N2->firstEdge = E2;
    }
}
void PrintInfoGraph(Graph G){
    adrNode P = G.first;
    while(P != NULL){
        cout << "Node " << P->info << " Terbuhung ke :";
        adrEdge E = P->firstEdge;
        while(E != NULL){
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}
adrNode findNode(Graph G, infoGraph X){
    adrNode P = G.first;
    while (P != NULL) {
        if (P->info == X) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}
void Visited(Graph &G){
    adrNode P = G.first;
    while(P != NULL){
        P->visited = 0;
        P = P->next;
    }
}

//prosedur untuk menampilkanhasil penelusuran DFS
void printDFS(Graph G, adrNode N){
    if(N != NULL && N->visited == 0){
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while(E != NULL){
            if(E->node->visited == 0){
                printDFS(G, E->node);
            }
            E = E->next;
        }
    }
}

//prosedur untuk menampilkanhasil penelusuran BFS
void printBFS(Graph G, adrNode N) {
    if (N == NULL) return;

    queue<adrNode> Q;

    N->visited = 1;
    Q.push(N);

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();

        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                Q.push(E->node);
            }
            E = E->next;
        }
    }
}
```

main.cpp
```C++
#include "graph.h"
#include<iostream>
using namespace std;
int main(){
    Graph G;
    CreateGraph(G);
    
    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode a = findNode(G, 'A');
    adrNode b = findNode(G, 'B');
    adrNode c = findNode(G, 'C');
    adrNode d = findNode(G, 'D');
    adrNode e = findNode(G, 'E');
    adrNode f = findNode(G, 'F');
    adrNode g = findNode(G, 'G'); 
    adrNode h = findNode(G, 'H');

    ConnectNode(a, b);
    ConnectNode(a, c);
    ConnectNode(b, d);
    ConnectNode(b, e);
    ConnectNode(c, f);
    ConnectNode(c, g);
    ConnectNode(d, h);
    ConnectNode(e, h);
    ConnectNode(f, h);
    ConnectNode(g, h);
    PrintInfoGraph(G);
    cout << endl ;


    Visited(G);
    cout << "Hasil penulusuran DFS : " ;
    printDFS(G, a);
    cout << endl ;


    Visited(G);
    cout << "Hasil penulusuran BFS : " ;
    printBFS(G, a);
    cout << endl ;
    
    return 0;

}
```
### Output Unguided  :
#### a. enampilkan setiap node beserta node-node lain yang terhubung (PrintInfoGraph)
![Screenshot Output Unguided 1_1]()
#### b. Hasil penelusuran DFS.
![Screenshot Output Unguided 1_2]()
#### c.Hasil penelusuran BFS.
![Screenshot Output Unguided 1_3]()

Program ini merupakan implementasi struktur data graph tak berarah (undirected graph) menggunakan linked list dalam bahasa C++. Graph dibangun dengan menambahkan node A hingga H yang masing-masing menyimpan informasi berupa karakter serta daftar edge dalam bentuk adjacency list. Setiap hubungan antar node dibentuk secara dua arah melalui fungsi ConnectNode, sehingga memungkinkan penelusuran bolak-balik. Program ini mendukung proses penelusuran graph menggunakan algoritma Depth First Search (DFS) dan Breadth First Search (BFS), di mana setiap node memiliki penanda visited untuk mencegah kunjungan berulang. Sebelum penelusuran dilakukan, seluruh node diinisialisasi sebagai belum dikunjungi melalui fungsi Visited. Penelusuran DFS dilakukan secara mendalam mulai dari node A, sedangkan BFS dilakukan secara melebar dengan bantuan struktur data queue. Hasil penelusuran dan keterhubungan antar node ditampilkan menggunakan fungsi pencetakan, sehingga program ini menunjukkan proses membangun, menghubungkan, dan menelusuri graph tak berarah secara lengkap dan terstruktur.


## Kesimpulan
Graph merupakan struktur data non-linier yang efektif untuk merepresentasikan hubungan atau keterkaitan antar data dalam bentuk simpul (vertex) dan sisi (edge). Struktur ini memungkinkan pemodelan permasalahan yang kompleks.Berdasarkan arah hubungan antar simpulnya, graph dibedakan menjadi graph berarah dan graph tidak berarah, yang masing-masing memiliki karakteristik dan penerapan yang berbeda. Dengan kemampuannya dalam menggambarkan hubungan antar data secara fleksibel, graph menjadi struktur data yang sangat penting dalam pengembangan algoritma dan sistem komputasi modern.

## Referensi
[1]Ginting, S. H. N., Effendi, H., Kumar, S., Marsisno, W., Sitanggang, Y. R. U., Anwar, K., ... & Smrti, N. N. E. (2024). Pengantar struktur data. Penerbit Mifandi Mandiri Digital, 1(01)[text](https://jurnal.mifandimandiri.com/index.php/penerbitmmd/article/view/39).<br>
[2]Trivusi. (2022, September 16). Struktur data graph: Pengertian, jenis, dan kegunaannya. Trivusi.[text](https://share.google/xNcFPXyImy8vf9ReB)
