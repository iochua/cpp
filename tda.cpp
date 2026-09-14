#include <iostream>
using namespace std;
class Producto{
    private: 
    int codigo_pr;
    string nombre;
    int stock;
    float precio;
    public:
    void agregar();
    void mostrar();
    void modificar(float);
    
}