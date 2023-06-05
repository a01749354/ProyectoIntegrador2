#ifndef VIDEO_H
#define VIDEO_H

#include<iostream>
#include<string>
#include<vector>

using std::string;
using std::vector;
class Video{
protected: 
    string id;
    string nombre;
    string duracion;
    string genero;
    float rating{0}; //rating promedio
    vector<int>resenias; //guardamos todas las calificaciones de los usuarios de un objeto video
    //constructores
    Video(string,string,string,string);


public: 
    //metodos
    string getNombre();
    void virtual mostrar_informacion() = 0;//funciones puras abstractas
    bool virtual calificar_video() = 0;
    float getRating();
    int isCalificado(); //para saber si el video ya fue calificado por algun usuario
    string getGenero();
    
    friend float operator + (const Video &,const Video &);
    friend float operator + (float,const Video &);
    friend void operator += (int&,const Video &);
};


#endif