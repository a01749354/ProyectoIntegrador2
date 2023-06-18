
#include "Serie.hpp"
#include <iostream>
#include <string>
using namespace std;


Serie::Serie(string id,string nombre, float calificacion,  int numEp){
    this->id = id;
    this->nombre = nombre;
    this->calificacion = calificacion;
    this->numEp = numEp;
    
};

void Serie::addEpisodio(Episodio episodio){
    episodios.push_back(episodio);
};

string Serie::getNombre(){
    return nombre;
};