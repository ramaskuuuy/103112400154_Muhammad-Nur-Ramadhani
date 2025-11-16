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
