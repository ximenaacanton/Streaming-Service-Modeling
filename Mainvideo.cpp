/*
Ximena Cantón Ayllón 
Streaming Service Modeling 
*/

#include <iostream>
#include <fstream> //manejo de archivos
#include <sstream> //manejo de archivos
#include <vector>
#include "Peliculas.h"
#include "Series.h"

using namespace std;

//abrir archivo video.txt
vector<Video*> cargarCatalogo() { //inicio de funcion llamada cargarCatalogo que devuelve vector de objetos Video
    vector<Video*> catalogo; //declaración de vector (como funciones y variables pero aqui es VECTOR)
    ifstream archivo("videos.txt");//ABRE ARCHIVO
    string linea;//almacena cada linea del archivo

    while(getline(archivo,linea)){ //lee cada linea en el archivo
        stringstream ss(linea); //analizar linea 
        string tipo, id, nombre, genero, serie, episodio;
        int duracion;
        getline(ss,tipo,','); //extrae tipo de video
        getline(ss,id,',');
        getline(ss,nombre,',');
        ss>>duracion; // valor string a valor int de duración
        ss.ignore();
        getline(ss,genero,',');
        if(tipo=="c") {
            getline(ss,serie,',');
            getline(ss,episodio,',');
            catalogo.push_back(new Serie(id, nombre, duracion, genero, serie, episodio));
        }else{
            catalogo.push_back(new Pelicula(id, nombre, duracion, genero));
        }
    }    

    archivo.close();
    return catalogo;
}

//1. Mostrar todo el catalogo con calificaciones.

void mostrarCatalogo(const vector<Video*>& catalogo){
    for(const Video* video:catalogo){ //cada puntero a Video en catalogo
        cout<<*video<<endl; //info video con sobrecarga
    }
}

//2. Calificar un video

void calificarVideo(const vector<Video*>& catalogo){
    string id;
    int calificacion; 
    cout<<"Introduce ID a calificar: ";
    cin>>id;
    //busca el id del video introducido 
    auto it=find_if(catalogo.begin(),catalogo.end(),[&id](const Video* video) {
        return video->getId()==id;
    });
    if(it!=catalogo.end()){ //si se encuentra id pide calificación
        cout<<"Introduce la calificacion (entero entre 1 y 5): "; 
        cin>>calificacion;
        if(calificacion>=1 && calificacion<=5) {
            (*it)->agregarCalificacion(calificacion); //la agrega
            cout<<"La calificación se agregó correctamente"<<endl;
        }else{
            cout<<"La calificacion debe ser un numero entre 1 y 5"<<endl;
        }
    }else{
        cout<<"No se encontró ID."<<endl;
    }
}

//3. Mostrar peliculas o capitulos con una calificacion minima determinada

void mostrarCalificacionMinima (const vector<Video*>& catalogo){
    int tipoMostrar;
    double calificacionMinima;
    cout<<"¿Deseas ver peliculas, capitulos o ambos? (Película =1, Capítulo=2, Ambos=3)"<<endl;
    cin>>tipoMostrar;
    if(tipoMostrar>=1 && tipoMostrar<=3) { //validación
        cout<<"Ingresa calificación minima (se permiten números decimales): "<<endl;
        cin>>calificacionMinima;
        for(const Video* video:catalogo){ //iterador para desplegar información
            double promedio=video->getCalificacionPromedio();
            if(promedio>=calificacionMinima){
                if (tipoMostrar==1 && dynamic_cast<const Pelicula*>(video)){
                    mostrarCalificacionMinima(cout,*video)<<endl;
                }else if(tipoMostrar==2 && dynamic_cast<const Serie*>(video)){
                    mostrarCalificacionMinima(cout,*video)<<endl;
                }else if(tipoMostrar==3){
                    mostrarCalificacionMinima(cout,*video)<<endl;
                }
            }
        }
    }else{
        cout<<"Ingresa correctamente el número 1,2 o 3 dependiendo de que deseas ver."<<endl;
    }
}

//4. Mostrar peliculas o capitulos de un cierto genero.

void mostrarGenero (const vector<Video*>& catalogo){
    int tipoMostrar;
    string genero;
    cout<<"¿Deseas ver peliculas, capitulos o ambos? (Película =1, Capítulo=2, Ambos=3)"<<endl;
    cin>>tipoMostrar;
    if(tipoMostrar>=1 && tipoMostrar<=3) { //validación
        cout<<"Ingresa género que deseas consultar: "<<endl;
        cin>>genero;
        for(const Video* video:catalogo){ 
            if(genero==video->getGenero()){
                if (tipoMostrar==1 && dynamic_cast<const Pelicula*>(video)){
                    mostrarGenero(cout,*video)<<endl;
                }else if(tipoMostrar==2 && dynamic_cast<const Serie*>(video)){
                    mostrarGenero(cout,*video)<<endl;
                }else if(tipoMostrar==3){
                    mostrarGenero(cout,*video)<<endl;
                }
            }
        }
    }else{
        cout<<"Ingresa correctamente el número 1,2 o 3 dependiendo de que deseas ver."<<endl;
    }
}

int main() {
    vector<Video*> catalogo = cargarCatalogo();
    int opcion;

    do{
        cout<<"Menu:\n";
        cout<<"1. Mostrar todo el catalogo con calificaciones\n";
        cout<<"2. Calificar un video\n";
        cout<<"3. Mostrar peliculas o capitulos con una calificacion minima determinada\n";
        cout<<"4. Mostrar peliculas o capitulos de un cierto genero\n";
        cout<<"9. Salir\n";
        cout<<"Introduce una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1:
                mostrarCatalogo(catalogo);
                break;
            case 2:
                calificarVideo(catalogo);
                break;
            case 3:
                mostrarCalificacionMinima(catalogo);
                break;
            case 4:
                mostrarGenero(catalogo);
                break;
            case 9:
                cout<<"Saliendo del programa."<<endl;
                break;
            default:
                cout<<"Opcion no valida."<<endl;
                break;
        }
    }while(opcion!=9);

    for(Video*video:catalogo) { //libera memoria
        delete video;
    }

    return 0;
}

