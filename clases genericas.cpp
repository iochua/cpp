#include <iostream>
using namespace std;
//no entendi nanchi
template <typename R>

class Caja{
    private: 
        R valor;
    public:
        void asignar(R v){
            valor=v;
        }
        R obtener(){
            return valor;
        }
};
int main(){
    Caja<int> entero;
    Caja<float> decimal;
    Caja<string> texto;

    entero.asignar(25);
    decimal.asignar(2.5);
    texto.asignar("hola");

    cout<<entero.obtener()<<endl;
    cout<<decimal.obtener()<<endl;
    cout<<texto.obtener()<<endl;
}