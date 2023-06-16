/* 
Autores:
Omar Alejandro Lopez Velasco A00838219
Andres Felipe Garcia Vina A01800027
*/

//creado por Felipe

#include "Pelicula.hpp"
#include <iostream>
#include <string>
using namespace std;

Pelicula::Pelicula(string id, string nombre, float duracion, string genero,float calificacion, string director):Video(id,nombre,duracion,genero,calificacion), director(director){};

void Pelicula::getInfo(){
    Video::getInfo();
    cout<<" Director: "<<director<<endl;
};

bool Pelicula::operator >(Pelicula p1){
    if(this->getCalificacion() > p1.getCalificacion()){
        return true;
    }
    else{
        return false;
    }
};

bool Pelicula::operator <(Pelicula p1){
    if(this->getCalificacion() < p1.getCalificacion()){
        return true;
    }
    else{
        return false;
    }
};
