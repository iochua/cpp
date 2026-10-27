#include <iostream>
#include <string>

using namespace std;

class Transaccion {
public:
    int id;
    string tipo;
    double monto;
    string fecha;

    Transaccion() {//se inicializan para instanciar dato sin asignarle valores aun
        id = 0;
        tipo = "";
        monto = 0.0;
        fecha = "";
    }

    Transaccion(int newId, string newTipo, double newMonto, string newFecha) {
        id = newId;
        tipo = newTipo;
        monto = newMonto;
        fecha = newFecha;
    }
};

class Nodo {
private:
    Transaccion dato;
    Nodo* siguiente;

public:
    Nodo(Transaccion t) {
        dato = t;
        siguiente = NULL;
    }

    void setDato(Transaccion t) {
        dato = t;
    }

    Transaccion getDato() {
        return dato;
    }

    void setSiguiente(Nodo* s) {
        siguiente = s;
    }

    Nodo* getSiguiente() {
        return siguiente;
    }
};

class Lista {
private:
    Nodo* inicio;

public:
    Lista() {
        inicio = NULL;
    }

    ~Lista() {
        Nodo* actual = inicio;
        while (actual != NULL) {
            Nodo* siguienteNodo = actual->getSiguiente();
            delete actual;
            actual = siguienteNodo;
        }
    }

    //mostrar siempre la transacción más reciente primero
    void insertarInicio(Transaccion t) {
        Nodo* nuevoNodo = new Nodo(t);
        nuevoNodo->setSiguiente(inicio);
        inicio = nuevoNodo;
        cout << "Transaccion agregada al inicio con éxito.\n";
    }

    //agrega al final de la lista
    void insertarFinal(Transaccion t) {
        Nodo* nuevoNodo = new Nodo(t);
        if (inicio == NULL) {
            inicio = nuevoNodo;
        } else {
            Nodo* actual = inicio;
            while (actual->getSiguiente() != NULL) {
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(nuevoNodo);
        }
        cout << "Transaccion agregada al final con exito\n";
    }

    //muestra toda la lista de transaciones de más reciente a más antigua
    void mostrar() {
        if (inicio == NULL) {
            cout << "El historial de transacciones esta vacio\n";
            return;
        }
        Nodo* actual = inicio;
        cout << "\n--- HISTORIAL DE TRANSACCIONES ---\n";
        while (actual != NULL) {
            Transaccion t = actual->getDato();
            cout << "ID: " << t.id 
                 << " | Tipo: " << t.tipo 
                 << " | Monto: $" << t.monto 
                 << " | Fecha: " << t.fecha << "\n";
            actual = actual->getSiguiente();
        }
    }

    //muestra todas las transacciones mayores a un monto específico
    void buscar(double montoLimite) {
        if (inicio == NULL) {
            cout << "El historial esta vacio.\n";
            return;
        }
        Nodo* actual = inicio;
        bool encontrado = false;
        cout << "\nTransacciones mayores a $" << montoLimite << "\n";
        while (actual != NULL) {
            Transaccion t = actual->getDato();
            if (t.monto > montoLimite) {
                cout << "ID: " << t.id 
                     << " | Tipo: " << t.tipo 
                     << " | Monto: $" << t.monto 
                     << " | Fecha: " << t.fecha << "\n";
                encontrado = true;
            }
            actual = actual->getSiguiente();
        }
        if (!encontrado) {
            cout << "No se encontraron transacciones mayores al monto indicado\n";
        }
    }

    //elimina una transacción por su id
    void eliminar(int id) {
        if (inicio == NULL) {
            cout << "No existe ninguna transaccion\n";
            return;
        }

        Nodo* actual = inicio;
        Nodo* anterior = NULL;

        //recorre la lista hasta encontrar el nodo con el id especificado
        while (actual != NULL && actual->getDato().id != id) {
            anterior = actual;
            actual = actual->getSiguiente();
        }

        if (actual == NULL) {
            cout << "No se encontro ninguna transaccion con el ID: " << id << "\n";
            return;
        }

        //si la transacción a eliminar es el primer nodo
        if (actual == inicio) {
            inicio = actual->getSiguiente();
        } else {
            //si está en medio o al final
            anterior->setSiguiente(actual->getSiguiente());
        }

        delete actual;
        cout << "Transaccion con ID " << id << " eliminada correctamente.\n";
    }
};


int menu() {
    int opc;
    cout << "\n HISTORIAL DE TRANSACCIONES BANCO\n";
    cout << "1. Agregar transaccion reciente\n";
    cout << "2. Agregar transaccion antigua\n";
    cout << "3. Mostrar todas las transacciones\n";
    cout << "4. Buscar transacciones mayores a un monto\n";
    cout << "5. Eliminar transaccion por ID\n";
    cout << "6. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opc;
    return opc;
}

int main() {
    Lista historial;
    int opc = 0;

    int id;
    string tipo, fecha;
    double monto;

    while (opc != 6) {
        opc = menu();
        switch (opc) {
            case 1: {
                cout << "Ingrese ID de la transaccion: ";
                cin >> id;
                cout << "Ingrese Tipo (Deposito/Retiro): ";
                cin >> tipo;
                cout << "Ingrese Monto: $";
                cin >> monto;
                cout << "Ingrese Fecha (AAAA-MM-DD): ";
                cin >> fecha;

                Transaccion t(id, tipo, monto, fecha);
                historial.insertarInicio(t);
                break;
            }
            case 2: {
                cout << "Ingrese ID de la transaccion: ";
                cin >> id;
                cout << "Ingrese Tipo (Deposito/Retiro): ";
                cin >> tipo;
                cout << "Ingrese Monto: $";
                cin >> monto;
                cout << "Ingrese Fecha (AAAA-MM-DD): ";
                cin >> fecha;

                Transaccion t(id, tipo, monto, fecha);
                historial.insertarFinal(t);
                break;
            }
            case 3:
                historial.mostrar();
                break;

            case 4:
                cout << "Ingrese el monto minimo a buscar: $";
                cin >> monto;
                historial.buscar(monto);
                break;

            case 5:
                cout << "Ingrese el ID de la transaccion a eliminar: ";
                cin >> id;
                historial.eliminar(id);
                break;

            case 6:
                cout << "Saliendo del sistema\n";
                break;

            default:
                cout << "Opcion no valida\n";
                break;
        }
    }

    return 0;
}