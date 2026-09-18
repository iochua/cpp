#include <iostream>
#include <string>
using namespace std;

template <typename R>
class Caja {
    private: 
        R valor[5];

    public:
        void asignar(int indice, R v) {
            if (indice >= 0 && indice < 5) {
                valor[indice] = v;
            }
        }

        R obtener(int indice) {
            if (indice >= 0 && indice < 5) {
                return valor[indice];
            }
            return R();
        }

        void mostrar() {
            for (int i = 0; i < 5; i++) {
                cout << valor[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Caja<int> entero;
    Caja<float> decimal;
    Caja<string> texto;

    for (int i = 0; i < 5; i++) {
        entero.asignar(i, (i + 1) * 10);
        decimal.asignar(i, (i + 1) * 1.5);
    }

    texto.asignar(0, "Hola");
    texto.asignar(1, "Mundo");
    texto.asignar(2, "desde");
    texto.asignar(3, "un");
    texto.asignar(4, "arreglo");

    cout << "Enteros: ";
    entero.mostrar();

    cout << "Decimales: ";
    decimal.mostrar();

    cout << "Texto: ";
    texto.mostrar();

    return 0;
}