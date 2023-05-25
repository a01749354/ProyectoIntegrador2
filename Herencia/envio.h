#ifndef ENVIO_H
#define ENVIO_H
#include <string>
using namespace std;
class Envio {
    private:
        string nombre;
        string direccion;
        string ciudad;  
        string estado;
        int codigoPostal;
        double costo_estandar;
        double costo;
    public:
        Envio(string Nombre, string Direccion, string Ciudad, string Estado, int CodigoPostal);
        double calculaCosto(); 
        void imprimir();
};

#endif