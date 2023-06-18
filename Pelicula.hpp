
#ifndef PELICULA_H
#define PELICULA_H
#include "Video.hpp"
#include <string> 
using namespace std;


class Pelicula: public Video{
    private:
        string director;
    public:
        Pelicula(string, string, float, string, float, string);
        void getInfo();
        bool operator >(Pelicula);
        bool operator <(Pelicula);
};

#endif