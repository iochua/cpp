#include <iostream>//JOSHUA CONTRERAS LÓPEZ 4-2
using namespace std;

int potenciaRecursiva(int base, int exponente) {
    if (exponente == 0) {
        return 1;//devuelve el resultado de la ultima operacion
    } else {
        return base * potenciaRecursiva(base, exponente - 1);
    }
}

int main() {
    int base, exponente;
    cout << "Ingrese la base: ";
    cin >> base;
    cout << "Ingrese el exponente: ";
    cin >> exponente;
    cout << "El resultado de " << base << " elevado a " << exponente << " es: " << potenciaRecursiva(base, exponente) << endl;
    return 0;
}