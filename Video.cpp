/* 
Autores:
Omar Alejandro Lopez Velasco A00838219
Andres Felipe Garcia Vina A01800027

Hecho por Felipe
*/

#include "Video.hpp"
#include <iostream>
#include <string>
using namespace std;


Video::Video(string id, string nombre, float duracion, string genero, float calificacion){
    this->id = id;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
};

    
void Video::setCalificacion(float num){
    calificacion = num;
};

string Video::getId(){
    return id;
}
string Video::getNombre(){
    return nombre;
}
float Video::getDuracion(){
    return duracion;
}
string Video::getGenero(){
    return genero;
}
float Video::getCalificacion(){
    return calificacion;
}
void Video::getInfo(){
    cout<<"ID: "<<id<<" Nombre: "<<nombre<<" Duracion: "<<duracion<<" Genero: "<<genero<<" Calificacion: "<<calificacion;
};
      