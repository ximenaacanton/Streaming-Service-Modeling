/*
Ximena Cantón Ayllón 
Streaming Service Modeling 
*/
#include <numeric>
#include <iostream>
#include <iomanip>
#include "Video.h"
using namespace std;

Video::Video(string id,string nombre,int duracion,string genero)
:id(id),nombre(nombre),duracion(duracion),genero(genero){
}//constructor

string Video::getId() const{
    return id;
}

string Video::getNombre() const{
    return nombre;
}

string Video::getGenero()const{
    return genero;
}

int Video::getDuracion()const{
    return duracion;
}

double Video::getCalificacionPromedio() const{
    if(calificaciones.empty()){
        return 0.0;// si no hay calificaciones regresa 0
    }
    double suma=accumulate(calificaciones.begin(),calificaciones.end(),0.0);//accumulate es para sumar valores de un vector- accumulate(valor del inicio, valor final, valor inicial de suma)
    return suma/calificaciones.size();
}

void Video::agregarCalificacion(int calificacion){
    calificaciones.push_back(calificacion);//añade al final
}

void Video::mostrar(ostream& os) const{
    os<<id<<","<<nombre<<","<< duracion<<","<<genero<<",";
    double promedio=getCalificacionPromedio();
    if (promedio==0.0) {
        os<<"SC";//Sin calificación
    }else{
        os<<fixed<<setprecision(1)<<promedio; //un decimal
    }
}

ostream& operator<<(ostream& os, const Video& video){
    video.mostrar(os);
    return os;
}

ostream& mostrarCalificacionMinima(ostream& os, const Video& video){
    double promedio=video.getCalificacionPromedio();
    if (promedio!=0.0) { 
        os<<video.id<<","<<video.nombre<<","<<fixed<<setprecision(1)<<promedio;
    }
    return os;
}

ostream& mostrarGenero(ostream& os, const Video& video){
    double promedio=video.getCalificacionPromedio();
    os<<video.id<<","<<video.nombre<<","<<video.genero<<","<<fixed<<setprecision(1)<<promedio;
    return os;
}