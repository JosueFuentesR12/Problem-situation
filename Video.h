#include <iostream>

class Video{
    int id;
    std::string nombre;
    float duracion;
    float rating;
    std::string genre;
    public:
    Video(int elId, std::string elNombre, float laDuracion, std::string elGenre,float rate){
        id = elId;
        nombre = elNombre;
        duracion = laDuracion;
        rating = rate;
        genre = elGenre;
    };
    void toStr(){
        std::cout << "***************************"  << std::endl;
        std::cout << "The ID: " << id << std::endl;
        std::cout << "The Name: " << nombre << std::endl;
        std::cout << "The duration: " << duracion << std::endl;
        std::cout << "The genre: " << genre << std::endl;
        std::cout << "The rating: " << rating << std::endl;
    };
    void rateVideo(float elRating){
        rating = elRating;
    }
};