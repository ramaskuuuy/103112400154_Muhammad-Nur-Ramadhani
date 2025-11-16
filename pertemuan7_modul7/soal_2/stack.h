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