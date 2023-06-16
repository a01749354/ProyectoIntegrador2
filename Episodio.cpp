/* 
Autores:
Omar Alejandro Lopez Velasco A00838219
Andres Felipe Garcia Vina A01800027

Hecho por Omar
*/

#include "Episodio.hpp"
#include <iostream>
#include <string>
using namespace std;


Episodio::Episodio(string id , string nombre, float duracion, string genero, float calificacion, string titulo, int temporada, string serie):Video(id,nombre,duracion,genero,calificacion),titulo(titulo),temporada(temporada), serie(serie){};

void Episodio::getInfo(){
    Video::getInfo();
    cout<<" Titulo: "<<titulo<<" Temporada: "<<temporada<<" Serie: "<<serie<<endl;
};
