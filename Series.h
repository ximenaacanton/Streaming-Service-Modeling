/*
Ximena Cantón Ayllón 
Streaming Service Modeling 
*/
#ifndef SERIES_H
#define SERIES_H
#include "Video.h"
using namespace std;

class Serie: public Video{
    private:
    string serie;
    string episodio;

    public: 
    Serie(string id, string nombre, int duracion, string genero, string serie, string episodio);
    void mostrar(ostream& os) const override;
};
#endif