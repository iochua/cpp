#include <iostream>
using namespace std;

class nodo{
    private:
        int dato;
        nodo* siguiente;
        nodo* anterior;
    public:
        nodo(int valor){ 
            dato = valor;
            siguiente = NULL;
            anterior = NULL; 
        }

    int getDato(){
        return dato;
    }

    nodo* getSiguiente(){
        return siguiente;
    }

    void setSiguiente(nodo* sig){
        siguiente = sig;
    }

    nodo* getAnterior(){
        return anterior;
    }

    void setAnterior(nodo* ant){
        anterior = ant;
    }
};

class lista{
    private:
        nodo* inicio;
    public:
        lista(){ 
            inicio = NULL;
        }

        void insertarInicio(int valor){
            nodo* nuevo = new nodo(valor); 
            
            nuevo->setSiguiente(inicio); 
            if(inicio != NULL){
                inicio->setAnterior(nuevo); 
            }
            inicio = nuevo;
        }

        void insertarFinal(int valor){
            nodo* nuevo = new nodo(valor); 
            if (inicio == NULL){
                inicio = nuevo;
            } 
            else{
                nodo* actual = inicio;
                while (actual->getSiguiente() != NULL){
                    actual = actual->getSiguiente();
                }
                actual->setSiguiente(nuevo);
                nuevo->setAnterior(actual); 
            }
        }

        void mostrarAdelante(){
            nodo* actual = inicio;
            while(actual != NULL){
                cout << actual->getDato() << " <-> ";
                actual = actual->getSiguiente();
            }
            cout << "NULL" << endl;
        }

        void mostrarAtras(){
            if (inicio == NULL){
                cout << "NULL" << endl;
                return;
            }

            nodo* actual = inicio;
            while (actual->getSiguiente() != NULL){
                actual = actual->getSiguiente();
            }

            while(actual != NULL){
                cout << actual->getDato() << " <-> ";
                actual = actual->getAnterior();
            }
            cout << "NULL" << endl;
        }

        void eliminar(int valor){
            //lista vacia
            if (inicio == NULL){
                cout << "La lista esta vacia." << endl;
                return;
            }

            //si el nodo es el primero
            if (inicio->getDato() == valor){
                nodo* borrar = inicio;
                inicio = inicio->getSiguiente();
                if (inicio != NULL){
                    inicio->setAnterior(NULL); 
                }
                delete borrar;
                cout << "Nodo " << valor << " eliminado correctamente." << endl;
                return;
            }
            
            //si el nodo está en medio
            nodo* actual = inicio;

            while (actual != NULL && actual->getDato() != valor){
                actual = actual->getSiguiente();
            }

            if (actual == NULL){
                cout << "El numero " << valor << " no existe en la lista." << endl;
                return;
            }

            //contectar los nodos anterior y siguiente
            actual->getAnterior()->setSiguiente(actual->getSiguiente());
            
            //si el nodo no es el ultimo, no se contecta a un nulo siguiente
            if (actual->getSiguiente() != NULL){
                actual->getSiguiente()->setAnterior(actual->getAnterior());
            }

            delete actual;
            cout << "Nodo " << valor << "eliminado correctamente" << endl;
        }

    ~lista(){ 
        nodo* actual = inicio;

        while(actual != NULL){
            nodo* siguiente = actual->getSiguiente();
            delete actual; 
            actual = siguiente;
        }
    }
};

int main(){
    lista Lista;
    int numero = 0, op = 0;

    do {
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Mostrar adelante" << endl;
        cout << "4. Mostrar atras" << endl;
        cout << "5. Eliminar" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> op;
        
        switch(op) {
            case 1:
                cout << "Dame numero: ";
                cin >> numero;
                Lista.insertarInicio(numero);
                system("cls");
                break;  
            case 2:
                cout << "Dame numero: ";
                cin >> numero;
                Lista.insertarFinal(numero);
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "Adelante: ";
                Lista.mostrarAdelante();
                break;
            case 4:
                system("cls");
                cout << "Atras: ";
                Lista.mostrarAtras();
                break;
            case 5:
                cout << "Dame numero a eliminar: ";
                cin >> numero;
                Lista.eliminar(numero);
                break;
            case 6:
                cout << "Saliendo del programa" << endl;
                break;
            default:
                cout << "Opcion no valida, elija una opcion valida" << endl;
        }   
    } while(op != 6);
    
    return 0;
}