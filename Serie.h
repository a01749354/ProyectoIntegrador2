#ifndef SERIE_H
#define SERIE_H

#include"Video.h"
#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;

class Serie:public Video{
private:
    string numero_episodios;
    string numero_temporadas;


public: 
    Serie(string,string,string,string,string,string);
    void mostrar_informacion();//polimorfismo
    bool calificar_video();//polimorfismo

   
};

#endif