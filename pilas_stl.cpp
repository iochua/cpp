#include <iostream>
#include <stack>
#include <string>

using namespace std;

void mostrarLibros(stack<string> pilaCopia) {//copia la pila recibida como parametro para no usar la original
    if (pilaCopia.empty()) {
        cout << "La pila de libros esta vacía\n";
        return;
    }
    
    cout << "Libros en la pila\n";
    while (!pilaCopia.empty()) {
        cout << pilaCopia.top() << "\n";//extrae solo el ultimo libro de la pila
        pilaCopia.pop(); //elimina el libro ya mostrado para seguir con el actual siguiente
    }
}

int main() {
    stack<string> pilaLibros; //se inicializa la pila de libros
    int opc;
    string nombreLibro;

    do {
        cout << "GESTION DE PILA DE LIBROS\n";
        cout << "1. Agregar un libro a la pila\n";
        cout << "2. Retirar el libro superior\n";
        cout << "3. Mostrar el libro superior\n";
        cout << "4. Mostrar la cantidad de libros\n";
        cout << "5. Mostrar todos los libros de la pila\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opc;
        cin.ignore(); 

        switch (opc) {
            case 1:
                cout << "Ingrese el nombre del libro: ";
                getline(cin, nombreLibro);
                pilaLibros.push(nombreLibro);//pusheamos el nuevo libro a la pila
                cout << "Libro '" << nombreLibro << "' agregado a la pila.\n";
                break;

            case 2:
                if (!pilaLibros.empty()) {
                    cout << "Se retiro el libro: " << pilaLibros.top() << "\n";//extraemos el elemto top de la pila
                    pilaLibros.pop();//cleareamos la variable para proximos usos
                } else {
                    cout << "Error: La pila esta vacia, no se puede retirar ningun libro.\n";
                }
                break;

            case 3:
                if (!pilaLibros.empty()) {
                    cout << "El libro en la parte superior es: " << pilaLibros.top() << "\n";
                } else {
                    cout << "La pila esta vacia\n";
                }
                break;

            case 4:
                cout << "Numero de libros en la pila actualmente: " << pilaLibros.size() << "\n";//sacamos el tamaño de la pila como en los arreglos
                break;

            case 5:
                mostrarLibros(pilaLibros);//llamamos a la funcion con la pila actual como parametro
                break;

            case 6:
                cout << "Saliendo del programa\n";
                break;

            default:
                cout << "Opcion no valida\n";
                break;
        }

    } while (opc != 6);

    return 0;
}