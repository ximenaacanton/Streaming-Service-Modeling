/*
Ximena Cantón Ayllón 
Streaming Service Modeling 
*/
#ifndef PELICULAS_H
#define PELICULAS_H
#include "Video.h"
using namespace std;

class Pelicula: public Video{
    public: 
    Pelicula(string id, string nombre, int duracion, string genero);
};
#endif