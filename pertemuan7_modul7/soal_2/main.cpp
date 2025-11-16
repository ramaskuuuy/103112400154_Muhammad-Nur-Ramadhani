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