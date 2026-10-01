#include <iostream>
using namespace std;

int main(){
    int var =10;
    int *ptr = &var;

    cout << "Valor de var: " << var << endl;
    cout << "Valor de var: " << &var << endl;
    cout << "Valor de var: " << ptr << endl;
    cout << "Valor de var: " << *ptr << endl;

    //wild pointer
    //int* ptr;
    
    //null pointer
    //int* ptr = nullptr;
    return 0;
}