#include"Proveedor.h"
#include"Video.h"
#include"Serie.h"
#include"Pelicula.h"
#include"Cliente.h"


#include<iostream>
#include<stdexcept>
#include<vector>
#include<fstream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

//funcion para separar strings
//obtenida de https://www.geeksforgeeks.org/how-to-split-a-string-in-cc-python-and-java/
void separar_string(string s,char del,vector <string> &palabra_separada){
vector<string> palabras;
stringstream ss(s);
string palabra;
while(!ss.eof()){
getline(ss,palabra,del);
palabra_separada.push_back(palabra);
}
}


//main
int main(){

//variables
fstream peliculas;
fstream series;
string linea_pelicula;
string linea_serie;
Video *nuevo_video;
vector <string> parametro_pelicula;
vector <string> parametro_serie;
string usuario;
string edad;
string contrasenia;
string contrasenia_nueva;
string contrasenia_administrador;
char menu{'s'};
int opcion;
vector<int>opciones(7);
bool usuario_encontrado{false};
bool usuario_valido{false};

//objetos
vector<Video*> videos;
vector<Cliente*> clientes;
Proveedor netflix{"netflix","admin"};





//! lectura del archivo peliculas
peliculas.open("peliculas.txt",ios::in); //lectura de archivo
if(peliculas.is_open()){
    while(getline(peliculas,linea_pelicula)){ //mientras no haya lineas vacias
        separar_string(linea_pelicula,'-',parametro_pelicula);//separamos el string por "-" y usamos parametro por referencia
        nuevo_video = new Pelicula(parametro_pelicula[0],parametro_pelicula[1],parametro_pelicula[2],parametro_pelicula[3]);
        videos.push_back(nuevo_video);//guardamos el nuevo video en el arreglo
        parametro_pelicula.clear();//limpiamos el vector
    }
    peliculas.close();//cerramos el archivo
}

//! lectura del archivo Series
series.open("series.txt",ios::in); //lectura de archivo
if(series.is_open()){
    while(getline(series,linea_serie)){ //mientras no haya lineas vacias
        separar_string(linea_serie,'-',parametro_serie);//separamos el string por "-"
        nuevo_video = new Serie(parametro_serie[0],parametro_serie[1],parametro_serie[2],parametro_serie[3],parametro_serie[4],parametro_serie[5]);
        videos.push_back(nuevo_video);//guardamos el nuevo video en el arreglo
        parametro_serie.clear();//limpiamos el vector
    }
    series.close();//cerramos el archivo
}

for(auto &video: videos){
netflix.agregar_video(video);//agregamos todos los videos leidos del txt a la plataforma
}


cerrarSesion:
system("cls");
cout<<"Ingrese su Usuario: ";
cin>>usuario;
for(auto &cliente: clientes){
    if(usuario==cliente->getUsuario()){
        usuario_encontrado = true;
        cout<<"Ingrese su contrasenia: ";
        cin>>contrasenia;
        if(contrasenia==cliente->getContrasenia()){
            usuario_valido = true;
        }
    }
}

if(!usuario_encontrado){//le pedimos que se registre
cout<<"Parece que no estas registrado"<<endl;
cout<<"Por favor ingresa la contrasenia que deseas: ";
cin>>contrasenia_nueva;
cout<<"Ingresa tu edad: ";
cin>>edad;
Cliente *cliente_nuevo = new Cliente(usuario,contrasenia_nueva,edad);
clientes.push_back(cliente_nuevo);//agregamos al nuevo cliente
netflix.agregar_cliente(Cliente(usuario,contrasenia,edad));//composicion
cout<<"REGISTRADO CON EXITO"<<endl;
usuario_valido = true;
}



if(usuario_valido){
do{
    menu = 'n';
    system("cls");
    try{
    cout<<"Selecciona la opcion deseada: "<<endl;
    cout<<"(1) Mostrar Videos"<<endl;
    cout<<"(2) Calificar Videos"<<endl;
    cout<<"(3) Mostrar Rating de algun Titulo"<<endl;
    cout<<"(4) Mostrar Rating de la Plataforma"<<endl;
    cout<<"(5) Mostrar Videos por rating"<<endl;
    cout<<"(6) Mostrar videos por genero"<<endl;
    cout<<"(7) Mostrar Clientes Registrados (Administrador)"<<endl;
    cout<<"(8) Cerrar Sesion"<<endl;
    cout<<"(9) SALIR"<<endl; 
    cin>>opcion;
    if(cin.fail()){
        throw -1;
    }
    switch (opcion)
    {
    case 1:
        netflix.mostrar_videos();
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;

    case 2: 
        netflix.calificar_video(usuario);
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;
    
    case 3:
        netflix.mostrar_rating_nombre();
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;

    case 4:
        netflix.mostrar_rating_plataforma();
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;
    
    case 5:
        netflix.mostrar_videos_rating();
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;


    case 6:
        netflix.mostrar_videos_genero();
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;
    
    case 7:
        cout<<"Ingresa la Contrasenia de Administrador: ";
        cin>>contrasenia_administrador;
        if(contrasenia_administrador == netflix.getContrasenia()){
            netflix.mostrarClientes();
        }
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;

    case 8:
        goto cerrarSesion;
        break;

    case 9:
        exit(0);
        break;
    
    default:
        cout<<"Desea volver al menu? <s> <n>: ";
        cin>>menu;
        break;
    }
    
    }catch(int e){
        cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"Ingresa una opcion valida"<<endl;
        cout<<"Desea volver a ver el menu? <s> <n> ";
        cin>>menu;
    }
    


}while(menu!='n');
}
return 0;
}//fin del main

