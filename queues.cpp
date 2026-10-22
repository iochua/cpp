#include <iostream>
#include <queue>
using namespace std;

class paquete{
    public:
        int id;
        string ip_origen;   
        int tamano_kb;

        paquete(int newId, string newIp_origen, int newTamano_kb) {
            id = newId;
            ip_origen = newIp_origen;
            tamano_kb = newTamano_kb;
        }
};

int main()
{
    queue<paquete> buffer;
    int opc; 
    cout << "GESTION DE COLA DE PAQUETES\n";
    cout << "1. Agregar nuevo paquete a la cola\n";
    cout << "2. Procesar siguiente paquete de la cola\n";
    cout << "3. Mostrar estado del buffer (mostrar cola)\n";
    cout << "4. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opc;

    while (opc != 4) {
        switch (opc) {
            case 1: {
                int id; int tamano_kb;
                string ip_origen;
                cout << "Ingrese el ID del paquete: ";
                cin >> id;
                cout << "Ingrese la IP de origen: ";
                cin >> ip_origen;
                cout << "Ingrese el tamano: ";
                cin >> tamano_kb;

                if (buffer.size() >= 5) {
                    cout << "Buffer lleno. Paquete descartado (Packet Loss)\n";
                    break;
                } else{
                paquete nuevoPaquete(id, ip_origen, tamano_kb);
                buffer.push(nuevoPaquete);
                cout << "Paquete agregado al buffer\n";
                break;
                }
            }
            case 2:
                if (!buffer.empty()) {
                    paquete procesado = buffer.front(); //se obtiene el paquete del frente de la cola
                    buffer.pop();//se popea el paquete
                    cout << "Procesando paquete ID: " << procesado.id << ", IP: " << procesado.ip_origen << ", Tamano: " << procesado.tamano_kb << " KB\n";
                } else {
                    cout << "El buffer esta vacio\n";
                }
                break;
            case 3:
                cout << "Estado del buffer:\n";
                if (buffer.empty()) {
                    cout << "El buffer esta vacio\n";
                } else {
                    queue<paquete> copiaBuffer = buffer; //copia de la cola para no modificar la original
                    while (!copiaBuffer.empty()) {
                        paquete front = copiaBuffer.front();//se obtiene el paquete del frente de la copia de la cola
                        cout << "ID: " << front.id << ", IP: " << front.ip_origen << ", Tamano: " << front.tamano_kb << " KB\n";
                        copiaBuffer.pop();//se popea para que el siguiente front sea el siguiente de la cola
                    }
                }
                break;
            default:
                cout << "Opcion no valida\n";
        }
    }
    return 0;
}