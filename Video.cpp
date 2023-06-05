#include"Video.h"
#include<string>
#include<iostream>


using std::string;
using std::cout;
using std::endl;

//constructor
Video::Video(string i,string nom,string dur,string gen): id{i},nombre{nom},duracion{dur},genero{gen}{}

string Video::getNombre(){
    return nombre;
}


float Video::getRating(){
    return rating;
}


int Video::isCalificado(){
    if(resenias.size()==0){
        return 0; //no ha sido calificado
    }
    else{
    return 1; //si ya fue calificado
    }
}


string Video::getGenero(){
return genero;
}

float operator +(const Video& v1, const Video& v2){
    return v1.rating + v2.rating;
}

float operator +(float num, const Video& v){
    return num + v.rating;
    
}

void operator +=(int &num, const Video& v){
bool calificado{false};
if(v.resenias.size()!=0){//si el video cuenta con reseñas
    calificado = true;
}

if(calificado){
    num++;
}

}


