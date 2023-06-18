/* 
Autores:
Omar Alejandro Lopez Velasco A00838219
Andres Felipe Garcia Vina A01800027

se realizo en conjunto mediante la extension livershare de VSCode
*/

#include "Excepcion.hpp"
#include <iostream>
using namespace std;

Excepcion::Excepcion(){
    mensaje = "Error";
}

Excepcion::Excepcion(string mensaje){
    this->mensaje = mensaje;
}

void Excepcion::display(){
    cout<<"Error: "<<mensaje<<endl;
}