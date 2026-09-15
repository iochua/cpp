#include <iostream>
using namespace std;

int sumaRecursiva(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sumaRecursiva(n - 1);
    }
}

int main() {
    int num;
    cout << "Ingrese un número: ";
    cin >> num;
    cout << "La suma de los números del 1 al " << num << " es: " << sumaRecursiva(num) << endl;
    return 0;
}