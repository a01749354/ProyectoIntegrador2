#include <iostream>
#include "sobre.h"
using namespace std;

Sobre::Sobre(string Nombre, string Direccion, string Ciudad, string Estado, int CodigoPostal, int estandar, double Largo,double Ancho, double Cargo_adicional):Envio(Nombre, Direccion, Ciudad, Estado, CodigoPostal, estandar){
    if (Largo < 0){
        Largo = Largo * -1;
    }
    if (Ancho < 0){
        Ancho = Ancho * -1;
    }
    largo = Largo;
    ancho = Ancho;
    cargo_adicional = Cargo_adicional;
}
double Sobre::calculaCosto(){
    if(ancho > 25 && largo > 30 || ancho > 30 && largo > 25){
        costo = costo_estandar + cargo_adicional; 
    }
    else{
        costo = costo_estandar;
    }   
}