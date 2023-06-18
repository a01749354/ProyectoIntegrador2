
#ifndef EPISODIO_H
#define EPISODIO_H
#include "Video.hpp"
#include <string> 
using namespace std;


class Episodio : public Video{
    private: 
        string titulo;
        int temporada;
        string serie;
    public:
        Episodio(string, string, float, string, float, string, int, string);
        void getInfo();
};

#endif