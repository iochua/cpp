#include <iostream>
using namespace std;
//Ana Patricia Sanchez Castro TIID 4-2 Listas enlazadas circulares C

class Nodo {
private:
    int id_pista; // Numero o identificador de la pista de aterrizaje
    Nodo* siguiente;

public://Constructor
    Nodo(int id) {
        id_pista = id;
        siguiente = NULL;
    }

    void setIDPista(int id) {
        id_pista = id;
    }

    int getIDPista() {
        return id_pista;
    }

    void setSiguiente(Nodo* s) {
        siguiente = s;
    }

    Nodo* getSiguiente() {
        return siguiente;
    }
};

class ListaCircular {
private:
    Nodo* inicio;//Indica la primer pista que se dio de alta
    Nodo* pistaActual; // Muestra cual es la pista del siguiente avion

public:
    ListaCircular() {
        inicio = NULL;
        pistaActual = NULL;
    }

    // Liberar memoria liberando la circularidad correctamente
    ~ListaCircular() {//Destructor
        if (inicio == NULL) return;

        Nodo* actual = inicio;
        Nodo* ultimo = inicio;

        while (ultimo->getSiguiente() != inicio) {
            ultimo = ultimo->getSiguiente();
        }
        ultimo->setSiguiente(NULL); // Romper el ciclo circular para evitar bucles

        while (actual != NULL) {
            Nodo* siguienteNodo = actual->getSiguiente();
            delete actual; //Elimina pista por pista
            actual = siguienteNodo;
        }
        inicio = NULL;
        pistaActual = NULL;
    }

    void insertar(int idPista) {
        Nodo* nuevoNodo = new Nodo(idPista);

        if (inicio == NULL) {
            inicio = nuevoNodo;
            nuevoNodo->setSiguiente(inicio); // Conectar a si mismo
            pistaActual = inicio;
        } else {
            Nodo* actual = inicio;//variable actualmentedelista = 1
            while (actual->getSiguiente() != inicio) { // 1, 2
                actual = actual->getSiguiente();
            }
            actual->setSiguiente(nuevoNodo);//1,2,3
            nuevoNodo->setSiguiente(inicio); // Cerrar el ciclo
        }
        cout << "Pista " << idPista << " agregada exitosamente.\n";
    }

    void eliminar(int idPista) {
        if (inicio == NULL) {
            cout << "No hay pistas para eliminar.\n";
            return;
        }

        Nodo* actual = inicio; //   actual es 1
        Nodo* anterior = NULL;// anterior es nulo

        // Caso de solo un nodo
        if (actual->getSiguiente() == inicio && actual->getIDPista() == idPista) { 
            delete actual;
            inicio = NULL;
            pistaActual = NULL;
            cout << "Pista " << idPista << " eliminada. La lista ahora esta vacia.\n";
            return;
        }

        // Buscar el nodo a eliminar
        do {
            if (actual->getIDPista() == idPista) {
                break;
            }
            anterior = actual;
            actual = actual->getSiguiente();
        } while (actual != inicio);

        //validacion de que el anterior ciclo terminó porque acabó la lista y no porque encontró el id a eliminar
        if (actual->getIDPista() != idPista) {
            cout << "Pista " << idPista << " no encontrada en la lista.\n";
            return;
        }

        // Ajustar puntero para actualizar el cierre del ciclo
        if (actual == inicio) { //si el nodo a eliminar es justo el inicio/primero y solo si la lista tiene más nodos aparte del inicio
            Nodo* ultimo = inicio;
            while (ultimo->getSiguiente() != inicio) {//recorrer la lista hasta encontrar el primero
                ultimo = ultimo->getSiguiente();
            }
            inicio = inicio->getSiguiente();
            ultimo->setSiguiente(inicio);// el siguiente del ultimo, será el primero (la lista reemplaza la union como ryley)
        } else {// si el nodo a eliminar no es el primero
            anterior->setSiguiente(actual->getSiguiente()); //se suelta el nodo a eliminar de la lista y su anterior apunta al su siguiente 
        }//lista: 1,2,3,4 -> 1,2,4

        // reapuntar pistaActual si apunta al nodo que se destruira
        if (pistaActual == actual) { //en caso de cumplir la condicion
            pistaActual = actual->getSiguiente(); //se recorre la lista para que pistaActual no apunte al nodo a eliminar cuando este se elimine
        }

        delete actual; //se elimina el nodo
        cout << "Pista " << idPista << " eliminada correctamente.\n";
    }

    void avanzar() {
        if (pistaActual == NULL) {
            cout << "No hay pistas disponibles para asignar aeronaves.\n";
            return;
        }

        cout << "Aeronave asignada a la Pista " << pistaActual->getIDPista() << ".\n"; //pides id de la pistaActual
        pistaActual = pistaActual->getSiguiente(); // recorres pistaActual a su siguiente
        cout << "Proxima pista en turno para aterrizaje: " << pistaActual->getIDPista() << "\n"; //pides id de la pistaActual una vez recorrida la lista
    }

    void recorrerCicloCompleto() {
        if (inicio == NULL) {
            cout << "La lista de pistas de aterrizaje esta vacia.\n";
            return;
        }

        Nodo* actual = inicio;
        cout << "Pistas de Aterrizaje en el ciclo: ";
        do {
            cout << "[Pista " << actual->getIDPista() << "] -> "; //pide el id de la pista actual que esta igualada al inicio
            actual = actual->getSiguiente(); //recorre el actual a su siguiente
        } while (actual != inicio); //hasta que actual vuelva a ser igual a inicio

        cout << "(vuelve al inicio: Pista " << inicio->getIDPista() << ")\n";
    }
};

int main() {
    ListaCircular aeropuerto;
    int opcion = 0;
    int idPista;

    while (opcion != 5) {
        cout << "\n Asigancion de pistas de aterrizaje \n";
        cout << "1. Insertar pista\n";
        cout << "2. Eliminar pista\n";
        cout << "3. Avanzar (Asignar turno a aeronave)\n";
        cout << "4. Recorrer ciclo completo\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese el numero/ID de la pista: ";
                cin >> idPista;
                aeropuerto.insertar(idPista);
                break;

            case 2:
                cout << "Ingrese el numero/ID de la pista a eliminar: ";
                cin >> idPista;
                aeropuerto.eliminar(idPista);
                break;

            case 3:
                aeropuerto.avanzar();
                break;

            case 4:
                aeropuerto.recorrerCicloCompleto();
                break;

            case 5:
                cout << "Cerrando sistema...\n";
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo \n";
        }
    }

    return 0;
}