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