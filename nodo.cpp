#include <iostream>
using namespace std;

class nodo{
    private:
        int dato;
        nodo* siguiente;
    public:
        nodo(int valor){ //constructor de la clase
            dato = valor;
            siguiente = NULL;
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
};

class lista{
    private:
        nodo* inicio;
    public:
        lista(){ //constructor de la clase
            inicio = NULL;
        }

        void agregar(int valor){
            nodo* nuevo = new nodo(valor); //metodo: new, crea espacio en la memoria de la computadora
            
            nuevo->setSiguiente(inicio); //este operador es para extraer los metodos de un puntero

            inicio = nuevo;
        }

        void mostrar(){
            nodo* actual = inicio;
            while(actual != NULL){
                cout << actual->getDato() << " -> ";
                actual = actual->getSiguiente();
            }
            cout << "NULL" << endl;
        }
    ~lista(){ //destructor de la clase
        nodo* actual = inicio;

        while(actual != NULL){
            nodo* siguiente = actual->getSiguiente();
            delete actual; //libera el espacio en la memoria de la computadora
            actual = siguiente;
        }
    }
};

int main(){
    lista* miLista = new lista(); //crea un objeto de la clase lista

    miLista->agregar(10);
    miLista->agregar(20);
    miLista->agregar(30);

    miLista->mostrar();

    delete miLista; //libera el espacio en la memoria de la computadora
    return 0;
}