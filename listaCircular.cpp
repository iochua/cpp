#include <iostream>
#include <string>
using namespace std;

class Nodo {
public:
    string nombre;
    Nodo* siguiente;

    Nodo(string n) {
        nombre = n;
        siguiente = NULL;
    }
};

class listaCircular {
private:
    Nodo* inicio;
    Nodo* ultimo;

public:
    listaCircular() {
        inicio = NULL;
        ultimo = NULL;
    }

    ~listaCircular() {
        if (inicio != NULL) {
            Nodo* actual = inicio;
            Nodo* temp;
            do {
                temp = actual;
                actual = actual->siguiente;
                delete temp;
            } while (actual != inicio);
        }
    }

    void ingresarJugador(string n) {
        Nodo* nuevo = new Nodo(n);
        if (inicio == NULL) {
            inicio = nuevo;
            ultimo = nuevo;
            inicio->siguiente = inicio; 
        } else {
            ultimo->siguiente = nuevo;
            nuevo->siguiente = inicio; 
            ultimo = nuevo;
        }
        cout << "Jugador ingresado correctamente\n";
    }

    void mostrarJugadores() {
        if (inicio == NULL) {
            cout << "No hay jugadores en la lista.\n";
            return;
        }
        Nodo* actual = inicio;
        cout << "\nJugadores\n";
        do {
            cout << actual->nombre << " -> ";
            actual = actual->siguiente;
        } while (actual != inicio);
        cout << "vuelve a " << inicio->nombre << "\n";
    }

    void iniciarJuego(int saltos) {
        if (inicio == NULL) {
            cout << "No hay suficientes jugadores para iniciar el juego.\n";
            return;
        }
        if (inicio->siguiente == inicio) {
            cout << "Solo hay un jugador. El ganador por defecto es: " << inicio->nombre << "\n";
            return;
        }

        Nodo* actual = inicio;
        Nodo* anterior = ultimo;

        cout << "\nIniciando Juego\n";
        
        while (actual->siguiente != actual) {
            for (int i = 1; i < saltos; i++) {
                anterior = actual;
                actual = actual->siguiente;
            }

            cout << "Eliminando a: " << actual->nombre << "\n";

            anterior->siguiente = actual->siguiente;
            
            if (actual == inicio) {
                inicio = actual->siguiente;
            }
            if (actual == ultimo) {
                ultimo = anterior;
            }

            Nodo* eliminado = actual;
            actual = actual->siguiente; 
            delete eliminado;
        }

        inicio = actual;
        ultimo = actual;
        inicio->siguiente = inicio;

        cout << "\nEl ganador es: " << inicio->nombre << "\n";
    }
};

int menu() {
    int opcion;
    cout << "\nJUEGO DE ELIMINACION\n";
    cout << "1. Ingresar jugadores\n";
    cout << "2. Mostrar jugadores\n";
    cout << "3. Iniciar juego\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;
    return opcion;
}

int main() {
    listaCircular juego;
    int opcion = 0; 
    string nombre;
    int saltos;

    while (opcion != 4) {
        opcion = menu();

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre del jugador: ";
                cin >> nombre;
                juego.ingresarJugador(nombre);
                break;
            case 2:
                juego.mostrarJugadores();
                break;
            case 3:
                cout << "Ingrese de a cuantos va a eliminar: ";
                cin >> saltos;
                if (saltos > 0) {
                    juego.iniciarJuego(saltos);
                } else {
                    cout << "El numero no puede ser 0\n";
                }
                break;
            case 4:
                cout << "adeu\n";
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
    }

    return 0;
}