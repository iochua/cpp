#include <iostream>//JOSHUA CONTRERAS LÓPEZ 4-2
#include <string>
using namespace std;

class producto{
    private:
        int codigo_pr;
        string nombre;
        int stock;
        float precio;
    public:
        void Agregar();
        void Eliminar();
        void Mostrar();
};

void producto::Agregar( ){
    cout<<"Nombre del producto(usando _ como espacios):\n";
    cin>>nombre;

    cout<<"Introduce codigo del producto:\n";
    cin>>codigo_pr;

    cout<<"Stock:\n";
    cin>>stock;

    cout<<"Precio:\n";
    cin>>precio;
}

void producto::Eliminar(){
    codigo_pr = 0;
    nombre = "";
    stock = 0;
    precio = 0.0;
    cout<<"Producto eliminado\n";
}

void producto::Mostrar(){
    cout<<"PRODUCTO\n";
    
    cout<<"Codigo del producto: "<<codigo_pr<<endl;

    cout<<"Nombre: "<<nombre<<endl;
    
    cout<<"Stock: "<<stock<<endl;
    
    cout<<"Precio: "<<precio<<endl;
}

int main(){
    producto producto1;
    
    producto1.Agregar();
    producto1.Mostrar();
    producto1.Eliminar();
    producto1.Mostrar();
   

    return 0;
}