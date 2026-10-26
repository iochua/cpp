#include <iostream>
using namespace std;

class Nodo { //clase para crear el vagon del tren
private:
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

public:
    Nodo(int d) {
        dato = d;
        siguiente = NULL;
        anterior = NULL;
    }

    void setDato(int d) {
        dato = d;
    }

    int getDato() {
        return dato;
    }

    void setSiguiente(Nodo* s) {
        siguiente = s;
    }

    Nodo* getSiguiente() {
        return siguiente;
    }

    void setAnterior(Nodo* a) {
        anterior = a;
    }

    Nodo* getAnterior() {
        return anterior;
    }
};

class Lista {//clase para crear la lista donde se uniran los vagones del tren
private:
    Nodo* inicio;//inicio izquierda
    Nodo* cola;//inicio derecha

public:
    Lista() {
        inicio = NULL;
        cola = NULL;
    }

    ~Lista() {
        Nodo* actual = inicio;
        while (actual != NULL) {
            Nodo* siguienteNodo = actual->getSiguiente();
            delete actual;
            actual = siguienteNodo;
        }
    }
    //patadas de ahogado, columbia, roma
    void insertarInicio(int d) {
        Nodo* nuevoNodo = new Nodo(d);//agg luna
        if (inicio == NULL) {
            inicio = nuevoNodo;//luna es el inicio y la cola
            cola = nuevoNodo;
        } else {
            nuevoNodo->setSiguiente(inicio);//luna apunta a patadas de ahogado
            inicio->setAnterior(nuevoNodo);//patadas de ahogado apunta a luna
            inicio = nuevoNodo;//inicio ahora es luna
        }
        cout << "Nodo con dato " << d << " insertado al inicio correctamente.\n";
    }
    //luna, patadas de ahogado, columbia
    void insertarFinal(int d) {
        Nodo* nuevoNodo = new Nodo(d);//agg roma
        if (inicio == NULL) {
            inicio = nuevoNodo;//roma es el inicio y la cola
            cola = nuevoNodo;
        } else {
            cola->setSiguiente(nuevoNodo);//patadas de ahogado apunta a roma
            nuevoNodo->setAnterior(cola);//roma apunta a patadas de ahogado
            cola = nuevoNodo;//cola ahora es roma
        }
        cout << "Nodo con dato " << d << " insertado al final correctamente.\n";
    }
    //luna, patadas de ahogado, columbia, roma
    void mostrarAdelante() {
        if (inicio == NULL) {
            cout << "La lista esta vacia.\n";
            return;
        }
        Nodo* actual = inicio;//variable que inicia como luna
        cout << "Lista (Adelante): ";
        while (actual != NULL) {
            cout << actual->getDato() << " ";//imprime el nombre de la cancion actual (luna)
            actual = actual->getSiguiente();//actual ahora es la  cancion que sigue de luna (patadas de ahogado)
        }
        cout << "\n";
    }
    //roma, columbia, patadas de ahogado, luna
    void mostrarAtras() {
        if (cola == NULL) {
            cout << "La lista esta vacia.\n";
            return;
        }
        Nodo* actual = cola;//variable que inicia como roma
        cout << "Lista (Atras): ";
        while (actual != NULL) {
            cout << actual->getDato() << " ";//imprime el nombre de la cancion actual (roma)
            actual = actual->getAnterior();//actual ahora es la cancion que precede a roma (columbia)
        }
        cout << "\n";
    }

    void eliminar(int d) {
        if (inicio == NULL) {
            cout << "La lista esta vacia. No se puede eliminar.\n";
            return;
        }
        
        //recorre la lista hasta encontrar la cancion a eliminar
        Nodo* actual = inicio;
        while (actual != NULL && actual->getDato() != d) {
            actual = actual->getSiguiente();
        }
        //por si no encuentra la cancion a eliminar
        if (actual == NULL) {
            cout << "El dato " << d << " no se encontro en la lista.\n";
            return;
        }
        //si la cancion a eliminar es la primera
        if (actual == inicio) {
            inicio = actual->getSiguiente();
            if (inicio != NULL) {
                inicio->setAnterior(NULL);
            } else {
                cola = NULL; 
            }
        } else if (actual == cola) {//si la cancion a eliminar es la ultima
            cola = actual->getAnterior();
            if (cola != NULL) {
                cola->setSiguiente(NULL);
            }
        } else {//si la cancion a eliminar está en medio
            actual->getAnterior()->setSiguiente(actual->getSiguiente());
            actual->getSiguiente()->setAnterior(actual->getAnterior());
        }

        delete actual;
        cout << "Nodo con dato " << d << " eliminado correctamente.\n";
    }
};

void mostrarSubmenu(Lista &miLista) {
    int opcionSubmenu;
    int valor;
    
    cout << "\n--- Submenu: Insertar Nodo ---\n";
    cout << "1. Insertar al inicio\n";
    cout << "2. Insertar al final\n";
    cout << "Elige una opcion: ";
    cin >> opcionSubmenu;

    if (opcionSubmenu == 1 || opcionSubmenu == 2) {
        cout << "Ingresa el numero a insertar: ";
        cin >> valor;
        if (opcionSubmenu == 1) {
            miLista.insertarInicio(valor);
        } else {
            miLista.insertarFinal(valor);
        }
    } else {
        cout << "Opcion no valida en el submenu.\n";
    }
}

int main() {
    Lista miLista;
    int opcion = 0;
    int valor;

    while (opcion != 5) {
        cout << "\n--- Menu ---\n";
        cout << "1. Insertar\n";
        cout << "2. Mostrar adelante\n";
        cout << "3. Mostrar atras\n";
        cout << "4. Eliminar\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                mostrarSubmenu(miLista);
                break;
            }
            case 2:
                miLista.mostrarAdelante();
                break;
            case 3:
                miLista.mostrarAtras();
                break;
            case 4:
                cout << "Ingresa el numero a eliminar: ";
                cin >> valor;
                miLista.eliminar(valor);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida. Intenta de nuevo.\n";
        }
    }

    return 0;
}