
#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP
#include <string>
#include <vector>
#include "Video.hpp"
#include "Episodio.hpp"
#include "Pelicula.hpp"
#include "Serie.hpp"

class Plataforma{
    private:
        string nombre;
        vector<Pelicula> peliculas;
        vector<Serie> series;
    public:
        Plataforma(string);
        void iniciar();
        void leerPeliculas();
        void leerSeries();
        void addEps();
        void filtrarVideosGenero(string);
        void filtrarVideosCalificacion(float);
        void mostrarEpisodiosSerieCalif(string,float);
        void filtrarPeliculasCalificacion(float);
        void calificar(string, float);
        void menu();
        void nombrePeliculasDisponibles();
        void nombreSeriesDisponibles();
};

#endif