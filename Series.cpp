/*
Ximena Cantón Ayllón 
Streaming Service Modeling 
*/
#include "Series.h"
#include <iostream>
#include <iomanip>
Serie::Serie(string id, string nombre, int duracion, string genero, string serie, string episodio)
    :Video (id,nombre,duracion,genero), serie(serie), episodio(episodio){}

void Serie::mostrar(ostream& os) const{
    Video::mostrar(os);
    os<<","<<serie<<","<<episodio<<",";
    double promedio=getCalificacionPromedio();
    if (promedio==0.0) {
        os<<"SC";//Sin calificación
    }else{
        os<<fixed<<setprecision(1)<<promedio; //un decimal
    }
}


