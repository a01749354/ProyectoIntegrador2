#ifndef CLIENTE_H
#define CLIENTE_H


#include <string>
using std::string;
class Cliente{

private:
    string usuario;
    string contrasenia;
    string edad;//la razon por la que es string, es porque no haremos ninguna operacion con este atributo
    int numero_resenias{0};


public:
    Cliente(string,string,string);
    string getUsuario();
    string getContrasenia();
    void mostrarDatos();
    void setNumResenias(int);
    int getNumResenias();
};


#endif