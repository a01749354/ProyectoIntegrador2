#ifndef PELICULA_H
#define PELICULA_H

#include"Video.h"
#include<iostream>
#include<string>

using std::string;

class Pelicula:public Video{



public:
    //constructor
    Pelicula(string,string,string,string);
    //metodos
    void mostrar_informacion();
    bool calificar_video();

};

#endif