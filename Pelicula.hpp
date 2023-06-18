/* 
Autores:
Omar Alejandro Lopez Velasco A00838219
Andres Felipe Garcia Vina A01800027
*/

//creado por Felipe

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.hpp"
#include <string> 
using namespace std;


class Pelicula: public Video{
    private:
        string director;
    public:
        Pelicula(string, string, float, string, float, string);
        void getInfo();
        bool operator >(Pelicula);
        bool operator <(Pelicula);
};

#endif