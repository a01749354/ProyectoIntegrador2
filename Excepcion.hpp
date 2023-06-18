/* 
Autores:
Omar Alejandro Lopez Velasco A00838219
Andres Felipe Garcia Vina A01800027

se realizo en conjunto mediante la extension livershare de VSCode
*/

#ifndef EXCEPCION_HPP
#define EXCEPCION_HPP
#include <exception>
#include <string>
using namespace std;

class Excepcion: public exception{
    private:
        string mensaje;
    public:
        Excepcion();
        Excepcion(string);
        void display();
};

#endif  