

#ifndef VIDEO_HPP
#define VIDEO_HPP
#include <string>
using namespace std;

class Video {
    private:
        string id;
        string nombre;
        float duracion;
        string genero;
        float calificacion;
    
    protected:
        Video(string, string, float, string, float);

    public:
        void setCalificacion(float);
        string getId();
        string getNombre();
        float getDuracion();
        string getGenero();
        float getCalificacion();
        virtual void getInfo();

};

#endif