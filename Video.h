/*
Ximena Cantón Ayllón 
Streaming Service Modeling 
*/
#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <vector>
using namespace std;

class Video{
    protected:
        string id;
        string nombre;
        int duracion;
        string genero;
        vector<int> calificaciones;

    public: 
        Video(string id, string nombre, int duracion, string genero);
    
        string getId() const;
        string getNombre() const;
        string getGenero() const;
        int getDuracion() const;
        double getCalificacionPromedio()const ;
        void agregarCalificacion(int calificacion); //local
        
        virtual void mostrar(ostream& os) const ;
        //sobrecargar << para combinar datos
        friend ostream& operator<<(ostream& os, const Video& video);
        friend ostream& mostrarCalificacionMinima(ostream& os, const Video& video);
        friend ostream& mostrarGenero(ostream& os, const Video& video);
     
};
#endif 