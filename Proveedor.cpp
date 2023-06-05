#include"Proveedor.h"
#include"Cliente.h"
#include<string>
#include<iostream>
#include<vector>
using namespace std;

//constructor
Proveedor::Proveedor(string nom,string con): nombre{nom},contrasenia{con}{}


void Proveedor::mostrar_videos(){
for(auto &video : videos){//recorremos el arreglo de videos con los que cuenta la plataforma
video->mostrar_informacion();
}

}


void Proveedor::calificar_video(string usuario){//calificar video por nombre 
string titulo;
bool titulo_encontrado{false};
bool resenia_exitosa{false};
cout<<"Videos Disponibles: "<<endl;
for(auto &video : videos){//recorremos el arreglo de videos con los que cuenta la plataforma
cout<<video->getNombre()<<endl;
}
fflush(stdin);//limpiamos memoria cache
cout<<"Ingresa el titulo de la Pelicula/Serie que deseas calificar: ";
getline(cin,titulo); //usamos el getline para obtener los espacios

for(auto &video : this->videos){
    if(video->getNombre()==titulo){//si el video si esta registrado en la plataforma
        resenia_exitosa = video->calificar_video();
        titulo_encontrado=true;
    }
}

if(titulo_encontrado&&resenia_exitosa){
    for(auto &cliente : clientes){
        if(cliente.getUsuario()==usuario)
        {
            cliente.setNumResenias(cliente.getNumResenias()+1);//incrementamos en uno
        }
    }
}

if(!titulo_encontrado){
        cout<<"El titulo buscado no se encuentra disponible actualmente"<<endl;
    }
}


void Proveedor::agregar_video(Video *video){ //agregamos los videos con los que cuenta la plataforma
videos.push_back(video);
}

void Proveedor::mostrar_rating_nombre(){
bool titulo_encontrado{false};
string nombre;
cout<<endl<<"Titulos Disponibles: "<<endl;
for(auto &video : videos){
    cout<<video->getNombre()<<endl;
}
cout<<"Ingresa el titulo deseado del cual saber quieres saber su rating: ";
fflush(stdin);//limpiamos memoria cache
getline(cin,nombre);
for(auto &video : videos){
    if(nombre==video->getNombre()){
        video->mostrar_informacion();
        titulo_encontrado = true;
    }
}

if (!titulo_encontrado){
    cout<<endl<<"El titulo ingresado no se encuentra actualmente"<<endl;
}
}


void Proveedor::mostrar_rating_plataforma(){//en este metodo aplicamos la sobrecarga de operadores
float suma_rating{0};
int numero_res{0};
for(auto &video : videos){
suma_rating = suma_rating+*video;//overloaded operator
//suma_rating += video->getRating(); //obtenemos el rating de cada video registrado en la plataforma y los sumamos
numero_res += *video; 
//
//numero_res += video->isCalificado(); //obtenemos el numero de videos que han sido calificados
}    


if(numero_res==0){
    cout<<"La plataforma aun no cuenta con resenias"<<endl;
}
else{
cout<<"El rating de la plataforma de acuerdo a los usuarios es de: "<<suma_rating/numero_res<<endl;
}
}

void Proveedor::mostrar_videos_rating(){//creemos que es mejor mostrar videos donde
//el usuario seleccione un minimo de rating en lugar de solo mostrar videos con un 
//rating especifico
    int rating_ingresado;
    try{
    cout<<"Mostrar videos con rating a partir de (1-5): ";
    cin>>rating_ingresado;//implementar try catch
    if(rating_ingresado != 1 && rating_ingresado != 2 && rating_ingresado != 3 && rating_ingresado != 4 && rating_ingresado != 5){//si no es un digito
        throw -1;
    }
    for(auto &video : videos){
        if(video->getRating()>=rating_ingresado){
            video->mostrar_informacion();
        }
    }

    }catch(int e){
        cout<<"Dato invalido"<<endl;
    }
    
}


void Proveedor::mostrar_videos_genero(){
    string genero;
    cout<<"Ingresa el genero que deseas buscar: ";
    cin>>genero;
    for(auto &video : videos){
        if(genero==video->getGenero()){
            video->mostrar_informacion();
        }
    }
}

void Proveedor::agregar_cliente(Cliente cliente){
clientes.push_back(cliente);
}


string Proveedor::getContrasenia(){
    return contrasenia;
    }


void Proveedor::mostrarClientes(){
    for(auto &cliente:clientes){
        cliente.mostrarDatos();
    }
}