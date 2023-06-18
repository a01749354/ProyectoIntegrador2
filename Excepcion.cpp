
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