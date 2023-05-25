#ifndef SOBRE_H
#define SOBRE_H
#include "envio.h"
using namespace std;

class Sobre:
    public Envio{
            private:
            double largo;
            double ancho;
            double cargo_adicional;

        public:
            Sobre(string Nombre, string Direccion, string Ciudad, string Estado, int CodigoPostal, int estandar, double Largo,double Ancho, double Cargo_adicional);
            double calculaCosto(); //la funcion regresa un valor de decimales
    };

#endif