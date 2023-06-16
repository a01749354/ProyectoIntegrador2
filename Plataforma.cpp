

#include "Plataforma.hpp"
#include "Excepcion.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#define PELICULAS "peliculas.csv"
#define SERIES "serie.csv"
#define EPISODIOS "episodios.csv"

Plataforma::Plataforma(string nombre){
    this->nombre = nombre;
}

void Plataforma::leerPeliculas(){
    ifstream archivo(PELICULAS);
    string linea;
    char coma = ',';
    vector<string> datos;
    while(getline(archivo, linea))
    {
        stringstream stream(linea);
        string id,nombre,duracion,genero,calificacion,director;    
        getline(stream, id, coma);
        getline(stream, nombre, coma);
        getline(stream, duracion, coma);
        getline(stream, genero, coma);
        getline(stream, calificacion, coma);
        getline(stream, director, coma);

        Pelicula pelicula(id, nombre, std::stof(duracion), genero, std::stof(calificacion), director);
        peliculas.push_back(pelicula);
    };
    archivo.close();
};


void Plataforma::leerSeries(){
    ifstream archivo(SERIES);
    string linea;
    char coma = ',';
    vector<string> datos;
    while(getline(archivo, linea))
    {
        stringstream stream(linea);
        string id,nombre,calificacion,numEp;    
        getline(stream, id, coma);
        getline(stream, nombre, coma);
        getline(stream, calificacion, coma);
        getline(stream, numEp, coma);
        
        Serie serie(id, nombre, std::stof(calificacion), std::stof(numEp));
        series.push_back(serie);
    };
    archivo.close();
};

void Plataforma::addEps(){
    ifstream archivo(EPISODIOS);   
    string linea;
    char coma = ',';
    vector<string> datos;
    while(getline(archivo,linea))
    {
        stringstream stream(linea);
        string id,nombre,duracion,genero,calificacion,titulo,temporada,serie;
        getline(stream, id, coma);
        getline(stream, nombre, coma);
        getline(stream, duracion, coma);
        getline(stream, genero, coma);
        getline(stream, calificacion, coma);
        getline(stream, titulo, coma);
        getline(stream, temporada, coma);
        getline(stream, serie, coma);

        Episodio ep(id, nombre, std::stof(duracion), genero, std::stof(calificacion), titulo, std::stoi(temporada), serie);
        for(int i = 0; i < series.size(); i++){
            if(series[i].getNombre() == serie){
                series[i].episodios.push_back(ep);
            }
        }

    }
}

void Plataforma::filtrarVideosGenero(string genero){
    for(int i = 0; i < peliculas.size(); i++){
        if(peliculas[i].getGenero() == genero){
            peliculas[i].getInfo();
        }
    }
    for(int i = 0; i < series.size(); i++){
        for(int j = 0; j < series[i].episodios.size(); j++){
            if(series[i].episodios[j].getGenero() == genero){
                series[i].episodios[j].getInfo();
            }
        }
    }
};

void Plataforma::filtrarVideosCalificacion(float calificacion){

    if(calificacion < 0 || calificacion > 10){
        Excepcion e0("Calificacion invalida ingresa un numero entre 0 y 10");
        throw(e0);
    }

    for(int i = 0; i < peliculas.size(); i++){
        if(peliculas[i].getCalificacion() >= calificacion){
            peliculas[i].getInfo();
        }
    }
    for(int i = 0; i < series.size(); i++){
        for(int j = 0; j < series[i].episodios.size(); j++){
            if(series[i].episodios[j].getCalificacion() >= calificacion){
                series[i].episodios[j].getInfo();
            }
        }
    }
};

void Plataforma::mostrarEpisodiosSerieCalif(string nombre, float calificacion){
    for(int i = 0; i < series.size(); i++){
        if(series[i].getNombre() == nombre){
            for(int j = 0; j < series[i].episodios.size(); j++){
                if(series[i].episodios[j].getCalificacion() >= calificacion){
                    series[i].episodios[j].getInfo();
                }
            }
        }
    }
};

void Plataforma::filtrarPeliculasCalificacion(float calificacion){
    for(int i = 0; i < peliculas.size(); i++){
        if(peliculas[i].getCalificacion() >= calificacion){
            peliculas[i].getInfo();
        }
    }
};

void Plataforma::calificar(string nombre,float calificacion){
    for(int i = 0; i < peliculas.size(); i++){
        if(peliculas[i].getNombre() == nombre){
            cout<<"la calificacion de "<<peliculas[i].getNombre()<<" es: "<<peliculas[i].getCalificacion()<<endl;
            peliculas[i].setCalificacion(calificacion);
            cout<<"la calificacion cambio a: "<<peliculas[i].getCalificacion()<<endl;
            break;
        }
    }
    for(int i = 0; i < series.size(); i++){
        for(int j = 0; j < series[i].episodios.size(); j++){
            if(series[i].episodios[j].getNombre() == nombre){
                cout<<"la calificacion de "<<series[i].episodios[j].getNombre()<<" es: "<<series[i].episodios[j].getCalificacion()<<endl;
                series[i].episodios[j].setCalificacion(calificacion);
                cout<<"la calificacion cambio a: "<<series[i].episodios[j].getCalificacion()<<endl;
                break;
            }
        }
    }
};

void Plataforma::iniciar(){
    bool band = true;
    string nombre, nombre2, pelicula1, pelicula2;
    int opcion;
    while (band){
        try
        {
            Plataforma::menu();
        cout<<"Ingrese una opcion: ";
        cin>>opcion;
        if(opcion < 0 || opcion > 6){
            Excepcion e1("Opcion invalida ingresa un numero entre 0 y 6");
            throw(e1);
        }
        switch (opcion)
        {
        case 0:
            band = false;
            cout<<"Gracias por usar la plataforma"<<endl;
            cout<<"Hasta luego"<<endl;
            break;
        case 1:
            Plataforma::leerPeliculas();
            Plataforma::leerSeries();
            Plataforma::addEps();
            cout<<"Archivos cargados"<<endl;
            break;
        
        case 2:
            int op2;
            cout<<"filtrar por genero(1) o calificacion(2)? (1/2): ";
            cin>>op2;
            if(op2 == 1){
                string genero;
                cout<<"Ingrese el genero: ";
                cin>>genero;
                Plataforma::filtrarVideosGenero(genero);
            }
            else if(op2 == 2){
                float calificacion;
                cout<<"Ingrese la calificacion: ";
                cin>>calificacion;
                Plataforma::filtrarVideosCalificacion(calificacion);
            }
            else{
                Excepcion e2("Opcion invalida ingresa un numero entre 1 y 2");
                throw(e2);
            }
            break;
        
        case 3:
            cout<<"Series disponibles: ";
            Plataforma::nombreSeriesDisponibles(); cout<<endl;
            float calificacion;
            cout<<"Ingrese el nombre de la serie: ";
            cin>>nombre;
            cout<<"Ingrese la calificacion: ";
            cin>>calificacion;
            Plataforma::mostrarEpisodiosSerieCalif(nombre, calificacion);
            break;

        case 4:
            float calificacion2;
            cout<<"Ingrese la calificacion: ";
            cin>>calificacion2;
            Plataforma::filtrarPeliculasCalificacion(calificacion2);
            break;
        
        case 5:
            float calificacion3;
            cout<<"Ingrese el nombre del video: ";
            cin>>nombre2;
            cout<<"Ingrese la calificacion: ";
            cin>>calificacion3;
            Plataforma::calificar(nombre2, calificacion3);
            break;
        
        case 6:
            cout<<"Peliculas disponibles: ";
            Plataforma::nombrePeliculasDisponibles(); cout<<endl;
            cout<<"Ingrese el nombre de la primera pelicula: ";
            cin>>pelicula1;
            cout<<"Ingrese el nombre de la segunda pelicula: ";
            cin>>pelicula2;
            for(int i = 0; i < peliculas.size(); i++){
                if(peliculas[i].getNombre() == pelicula1){
                    for(int j = 0; j < peliculas.size(); j++){
                        if(peliculas[j].getNombre() == pelicula2){
                            if(peliculas[i] > peliculas[j]){
                                cout<<peliculas[i].getNombre()<<" es mejor que "<<peliculas[j].getNombre()<<endl;
                            }
                            else if(peliculas[i] < peliculas[j]){
                                cout<<peliculas[j].getNombre()<<" es mejor que "<<peliculas[i].getNombre()<<endl;
                            }
                            else{
                                cout<<"Las peliculas son las mismas"<<endl;
                            }
                        }
                    }
                }
            }

        }
        }
        catch(Excepcion &e){
            e.display();
        }
    } 

};

void Plataforma::menu(){
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Cargar archivos"<<endl;
    cout<<"2. Mostrar los videos en general con una cierta calificación o un cierto género"<<endl;
    cout<<"3. Mostrar los episodios de una serie por su calificacion"<<endl;
    cout<<"4. Mostrar las películas con cierta calificacion"<<endl;
    cout<<"5. Calificar un video"<<endl;
    cout<<"6. Comparar Peliculas"<<endl;
    cout<<"0. Salir"<<endl;
}

void Plataforma::nombrePeliculasDisponibles(){
    for(int i = 0; i < peliculas.size(); i++){
        cout<<peliculas[i].getNombre()<<" ";
    }
}

void Plataforma::nombreSeriesDisponibles(){
    for(int i = 0; i < series.size(); i++){
        cout<<series[i].getNombre()<<" ";
    }
}