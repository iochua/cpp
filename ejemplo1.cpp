#include <iostream>
using namespace std;
class Alumno{
    private:
    string nombre;
    int edad;
    float promedio;

    public:
    void registrar();
    void mostrar();
    void modificarPromedio(float);
};
void Alumno::registrar(){

    cout<<"Nombre: ";//printf
    getline(cin,nombre);

    cout<<"Edad: ";
    cin>>edad;//scanf
   
    cout<<"Promedio: ";
    cin>>promedio;//scanf
}
void Alumno::mostrar(){
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Promedio: "<<promedio<<endl;

    
}
void Alumno::modificarPromedio(float prom){
    promedio=prom;
}
int main(){
    float nota;
    Alumno alumno1;
    alumno1.registrar();
    alumno1.mostrar();
    cout<<"Actualizar Promedio: ";
    cin>> nota;
    alumno1.modificarPromedio(nota);
    alumno1.mostrar();
}