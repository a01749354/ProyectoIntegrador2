#include <iostream>
#include "envio.h"
using namespace std;

Envio::Envio(string Nombre, string Direccion, string Ciudad, string Estado, int CodigoPostal){
    //igualar los parametros del constructos a las variables de la clase    
    nombre = Nombre;
    direccion = Direccion;
    ciudad = Ciudad;
    estado = Estado;
    codigoPostal = CodigoPostal;
}


double Envio::calculaCosto(){
    //regresas la propiedad de costo de la clase
    return costo;
}