#include <iostream>
#include "Video.h"

//Carlos Alberto Mendoza Medina A01661896 
//Jonathan Josué Fuentes Ramírez A01661894

class Movie:public Video{
    public:
        int id;
        std::string nombre;
        float duracion;
        float rating;
        std::string genre;
        Movie(int elId, std::string elNombre, float laDuracion, std::string elGenre,float rate){
            id = elId;
            nombre = elNombre;
            duracion = laDuracion;
            rating = rate;
            genre = elGenre;
        };
        void toStr(){
            std::cout << "***********************************"  << std::endl;
            std::cout << "The ID: " << id << std::endl;
            std::cout << "The Name: " << nombre << std::endl;
            std::cout << "The duration: " << duracion << std::endl;
            std::cout << "The genre: " << genre << std::endl;
            std::cout << "The rating: " << rating << std::endl;
        };
};