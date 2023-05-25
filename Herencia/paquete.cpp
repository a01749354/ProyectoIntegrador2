#include <iostream>
#include "paquete.h"
using namespace std;

Paquete::Paquete(string Nombre, string Direccion, string Ciudad, string Estado, int CodigoPosta, int estandar, double Largo, double Ancho, double CostoPorKg, double Profundidad, double Peso):Envio(Nombre, Direccion, Ciudad, Estado, CodigoPosta, estandar) {
    if(Largo < 0){
        Largo = Largo*-1;
    }
    if(Ancho < 0){
        Ancho = Ancho*-1;
    }
    if(Profundidad < 0){
        Profundidad = Profundidad*-1;
    }
    if(Peso < 0){
        Peso = Peso*-1;
    }
    if(CostoPorKg < 0){
        CostoPorKg = CostoPorKg*-1;
    }
    //Igualas los parametros a los atributos de la clase
    largo = Largo;
    ancho = Ancho;
    costoPorKg = CostoPorKg;
    profundidad = Profundidad;
    peso = Peso;

}

double Paquete::calcularCosto(){
    costo = (peso * costoPorKg) + costo_estandar;
    return costo;
}

double Paquete::getlargo(){
    return largo;
}

