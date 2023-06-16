#ifndef SERIE_H
#define SERIE_H
#include "Episodio.hpp"
#include <vector>
#include <string> 
using namespace std;


class Serie{
    private: 
        string id;
        string nombre;
        float calificacion;
        int numEp;
    public:
        vector<Episodio> episodios; 
        Serie(string, string, float, int);
        void addEpisodio(Episodio);
        string getNombre();
};

#endif