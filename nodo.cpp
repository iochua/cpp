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

        void insertarFinal(int valor){
            nodo* nuevo = new nodo(valor); //metodo: new, crea espacio en la memoria de la computadora
            
            //nuevo->setSiguiente(inicio); //este operador es para extraer los metodos de un puntero
            //inicio = nuevo;
            if (inicio == NULL){
                inicio = nuevo;
            } 
            else{
                nodo* actual = inicio;
                while (actual->getSiguiente() != NULL){
                    actual = actual->getSiguiente();
                }
                actual->setSiguiente(nuevo);
            }
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
    lista Lista;
    int numero=0,op=0;

    do {
        cout << "Selecciona una opcion: " << endl;
        cout << "1. Insertar" << endl;
        cout << "2. Mostrar" << endl;
        cout << "3. Salir" << endl;
        cin >> op;
        switch(op) {
            case 1:
                cout << "dame numero: " << endl;
                cin>>numero;
                Lista.insertarFinal(numero);
                system("cls");
                break;  
            case 2:
            Lista.mostrar();
            break;
        }   
    } while(op != 3);
    
    return 0;
}