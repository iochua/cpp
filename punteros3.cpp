#include <iostream>
using namespace std;

int main(){
    int var = 10;
    int* ptr1 = &var;
    int** ptr2 = &ptr1;

    cout << *ptr1 << endl;
    cout << **ptr2;
    return 0;
}