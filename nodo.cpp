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

        void insertarInicio(int valor){
            nodo* nuevo = new nodo(valor); //metodo: new, crea espacio en la memoria de la computadora
            
            nuevo->setSiguiente(inicio); //este operador es para extraer los metodos de un puntero
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
            }
        }



        void mostrarAdelante(){
            nodo* actual = inicio;
            while(actual != NULL){
                cout << actual->getDato() << " -> ";
                actual = actual->getSiguiente();
            }
            cout << "NULL" << endl;
        }
        void mostrarAtras(){

        }
        void eliminar(int valor){
            if(inicio != NULL){
                if(inicio->getDato() == valor){
                    nodo* nodoAEliminar = inicio;
                    inicio = inicio->getSiguiente(); // El inicio ahora es el segundo nodo
                    delete nodoAEliminar; // Liberamos la memoria
                    cout << "Nodo " << valor << " eliminado correctamente." << endl;
                    return;
                }

                // Caso 3: El nodo a eliminar está en medio o al final
                nodo* actual = inicio;
                nodo* anterior = NULL;

                // Recorremos la lista buscando el valor
                while(actual != NULL && actual->getDato() != valor){
                    anterior = actual; // Guardamos el rastro del nodo anterior
                    actual = actual->getSiguiente();// Avanzamos al siguiente
                }

                // Si llegamos a NULL significa que no encontramos el número
                if(actual == NULL){
                    cout << "El numero " << valor << " no existe en la lista." << endl;
                    return;
                }

                // Si lo encontramos, desconectamos el nodo actual y conectamos el anterior con el siguiente
                anterior->setSiguiente(actual->getSiguiente());
                delete actual; // Liberamos la memoria del nodo que sacamos
                cout << "Nodo " << valor << " eliminado correctamente." << endl;
            }
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
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Mostrar al inicio" << endl;
        cout << "4. Mostrar al final" << endl;
        cout << "5. Salir" << endl;
        cin >> op;
        switch(op) {
            case 1:
                cout << "dame numero: " << endl;
                cin>>numero;
                Lista.insertarInicio(numero);
                system("cls");
                break;  
            case 2:
                cout << "dame numero: " << endl;
                cin>>numero;
                Lista.insertarFinal(numero);
                system("cls");
                break;
            case 3:
                Lista.mostrarAdelante();
                break;
            case 4:
                Lista.mostrarAtras();
                break;
        }   
    } while(op != 5);
    
    return 0;
}