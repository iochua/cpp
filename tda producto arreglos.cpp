#include <iostream> // JOSHUA CONTRERAS LÓPEZ 4-2
#include <string>
using namespace std;

class producto {
    private:
        int codigo_pr;
        string nombre;
        int stock;
        float precio;
    public:
        void Agregar();
        void Eliminar();
        void Mostrar();
        int getCodigo() { 
            return codigo_pr; 
        } 
};

void producto::Agregar() {
    cout << "Introduce codigo del producto: ";
    cin >> codigo_pr;

    cout << "Nombre del producto: ";
    cin.ignore(); 
    getline(cin, nombre);

    cout << "Stock: ";
    cin >> stock;

    cout << "Precio: ";
    cin >> precio;
    cout << "Producto agregado\n";
}

void producto::Eliminar() {
    codigo_pr = 0;
    nombre = "";
    stock = 0;
    precio = 0.0;
    cout << "Producto eliminado\n";
}

void producto::Mostrar() {
    if (codigo_pr == 0) {
        cout << "Código de producto no válido\n";
        return;
    }
    cout << "PRODUCTO\n";
    cout << "Codigo del producto: " << codigo_pr << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Stock: " << stock << endl;
    cout << "Precio: $" << precio << endl;
}

int main() {
    producto inventario[10];
    int cantidadActual = 0;
    int opcion = 0; 

    while (opcion != 4) {
        cout << "\n MENU DE INVENTARIO\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar todos los productos\n";
        cout << "3. Eliminar producto por posicion\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (cantidadActual < 10) {
                    cout << "\nRegistrando en la posicion [" << cantidadActual + 1 << "]\n";
                    inventario[cantidadActual].Agregar();
                    cantidadActual++;
                } else {
                    cout << "El inventario esta lleno (Maximo 10 productos).\n";
                }
                break;

            case 2:
                if (cantidadActual == 0) {
                    cout << "\nNo hay productos registrados en el inventario\n";
                } else {
                    cout << "\nLISTA DE PRODUCTOS\n";
                    for (int i = 0; i < cantidadActual; i++) {
                        cout << "Posicion [" << i + 1 << "]:\n";
                        inventario[i].Mostrar();
                    }
                }
                break;

            case 3:
                if (cantidadActual == 0) {
                    cout << "\nNo hay productos para eliminar\n";
                } else {
                    int pos;
                    cout << "\nIngresa la posicion del producto a eliminar: ";
                    cin >> pos;

                    if (pos >= 1 && pos <= cantidadActual) {
                        inventario[pos - 1].Eliminar();

                        for (int i = pos - 1; i < cantidadActual - 1; i++) {
                            inventario[i] = inventario[i + 1];
                        }
                        inventario[cantidadActual - 1].Eliminar();
                        cantidadActual--;
                    } else {
                        cout << "Posicion no valida\n";
                    }
                }
                break;

            case 4:
                cout << "Saliendo del programa\n";
                break;

            default:
                cout << "Opcion invalida\n";
                break;
        }
    }

    return 0;
}