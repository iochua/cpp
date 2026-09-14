#include <iostream>
#include <cstdlib>
using namespace std;
//Ana Patricia Sanchez Castro TIID 4-2
//TDA producto

class producto{
	//atributos: codigo del producto, nombre, stock y precio
	private:
		int codigo_pr;
		string nombre;
		int stock;
		float precio;
		
		//metodos: agregar producto, modificar producto y mostrar datos
	public:
		void Agregar();
		void Modificar(int,float);
		void Mostrar();
};

void producto::Agregar( ){

cout<<"Codigo del producto: ";
cin>>codigo_pr;

cout<<"Nombre: ";
getline(cin,nombre);

cout<<"Stock: ";
cin>>stock;

cout<<"Precio: ";
cin>>precio;

}

void producto::Modificar(int stockn,float precion){
stock = stockn;
precio = precion;

}

void producto::Mostrar(){
	cout<<"Codigo del producto: "<<codigo_pr<<endl;

	cout<<"Nombre: "<<nombre<<endl;
	
	cout<<"Stock: "<<stock<<endl;
	
	cout<<"Precio: "<<precio<<endl;

}

int main(){
	int stocko;
	float precioo;
	producto producto1;
	producto1.Agregar();
	producto1.Mostrar();
	cout << "Actualizar stock: ";
	cin >> stocko;
	cout << "Actualizar precio: ";
	cin >> precioo;
	producto1.Modificar(stocko, precioo);
	producto1.Mostrar();
}









