#ifndef PAQUETE_H
#define PAQUETE_H
#include "envio.h"
using namespace std;
class Paquete: 

    public Envio{
    //atributos
    private:
        double largo;
        double ancho;
        double costoPorKg;
        double profundidad;
        double peso;

    public:
        //Hereda los atributos de la clase Envio
        Paquete(string Nombre, string Direccion, string Ciudad, string Estado, int CodigoPosta, int estandar,double Largo, double Ancho, double CostoPorKg, double Profundidad, double Peso);
        double calcularCosto(); //la funcion regresa un valor de decimales
        double getlargo();
};

#endif