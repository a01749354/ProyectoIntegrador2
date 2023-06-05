#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include"Video.h"
#include"Cliente.h"
#include<iostream>
#include<vector>
#include<string>

using std::string;
using std::vector;

class Proveedor{

string nombre;
vector<Video*>videos;//agregacion, vector que apuntara a los videos con los que cuente la plataforma
vector<Cliente>clientes;//composicion SI LA PLATAFORMA DESAPARECE TAMBIEN LOS CLIENTES
string contrasenia;
public:
    Proveedor() = default;
    Proveedor(string,string);
    void mostrar_videos();
    void calificar_video(string);//recibe el usuario para saber quien califica el video
    void agregar_video(Video *video);
    void mostrar_rating_nombre();
    void mostrar_rating_plataforma();
    void mostrar_videos_rating();
    void mostrar_videos_genero();
    void agregar_cliente(Cliente);
    string getContrasenia();
    void mostrarClientes();
};

#endif