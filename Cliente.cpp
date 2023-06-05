#include"Cliente.h"
#include<string>
#include<iostream>
using std::string;
using std::cout;
using std::endl;

//constructor
Cliente::Cliente(string usu,string contr,string ed):usuario{usu},contrasenia{contr},edad{ed}{}



string Cliente::getUsuario(){
    return usuario;
}

string Cliente::getContrasenia(){
    return contrasenia;
}

void Cliente::mostrarDatos(){
    cout<<endl<<endl;
    cout<<"Usuario: "<<usuario<<endl;
    cout<<"Edad: "<<edad<<endl;
    cout<<"Numero de Resenias hechas: "<<numero_resenias<<endl;
}

void Cliente::setNumResenias(int num){
    numero_resenias = num;
}

int Cliente::getNumResenias(){
    return numero_resenias;
}