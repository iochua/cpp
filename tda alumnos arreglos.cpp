#include <iostream>// JOSHUA CONTRERAS LÓPEZ 4-2
#include <string>
using namespace std;

class Alumno {
    private:
        string nombre;
        int edad;
        float promedio;

    public:
        void registrar();
        void mostrar();
        void modificarPromedio(float);
};

void Alumno::registrar() {
    cout << "Nombre: ";
    cin.ignore(); 
    getline(cin, nombre);

    cout << "Edad: ";
    cin >> edad;

    cout << "Promedio: ";
    cin >> promedio;
}

void Alumno::mostrar() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Promedio: " << promedio << endl;
}

void Alumno::modificarPromedio(float prom) {
    promedio = prom;
}

int main() {
    Alumno grupo[10]; 
    int cantidadActual = 0;
    int opcion = 0;

    while (opcion != 5) {
        cout << "\n MENU DE ALUMNOS \n";
        cout << "1. Registrar alumno\n";
        cout << "2. Mostrar todos los alumnos\n";
        cout << "3. Modificar promedio de un alumno\n";
        cout << "4. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (cantidadActual < 10) {
                    cout << "\nRegistrando Alumno [" << cantidadActual + 1 << "]\n";
                    grupo[cantidadActual].registrar();
                    cantidadActual++;
                    cout << "Alumno registrado\n";
                } else {
                    cout << "El espacio esta lleno (Maximo 10 alumnos)\n";
                }
                break;

            case 2:
                if (cantidadActual == 0) {
                    cout << "\nNo hay alumnos registrados\n";
                } else {
                    cout << "\nLISTA DE ALUMNOS\n";
                    for (int i = 0; i < cantidadActual; i++) {
                        cout << "\n[Posicion " << i + 1 << "]\n";
                        grupo[i].mostrar();
                    }
                }
                break;

            case 3:
                if (cantidadActual == 0) {
                    cout << "\nNo hay alumnos registrados para modificar.\n";
                } else {
                    int pos;
                    float nuevoPromedio;
                    cout << "\nIngresa la posicion del alumno (1 a " << cantidadActual << "): ";
                    cin >> pos;

                    if (pos >= 1 && pos <= cantidadActual) {
                        cout << "Ingresa el nuevo promedio: ";
                        cin >> nuevoPromedio;
                        grupo[pos - 1].modificarPromedio(nuevoPromedio);
                        cout << "-> Promedio actualizado con exito.\n";
                    } else {
                        cout << "Posicion no valida.\n";
                    }
                }
                break;

            case 4:
                cout << "Saliendo del programa\n";
                break;

            default:
                cout << "Opcion invalida. Intenta de nuevo-\n";
                break;
        }
    }

    return 0;
}