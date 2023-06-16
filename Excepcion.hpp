
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