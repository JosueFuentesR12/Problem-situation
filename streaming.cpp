#include <iostream>
#include <fstream>
#include <vector>
#include "Video.h"

using namespace std;

void setVideoRating(std::vector<Video>&, int, float);

int main()
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("MoviesData.txt");

    // Create our video container...
    vector<Video> videosDB;
    
    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText))
    {
        
        // myText = "1,The Batman,153,Superhero/Action/Adventure,8.5"
        int elId = std::stoi(myText.substr(0, myText.find(",")));
        

        // myText = "The Batman,153,Superhero/Action/Adventure,8.5"
        myText = myText.substr(myText.find(",")+1, myText.length());
        std::string elNombre = myText.substr(0, myText.find(",")); 

        // myText = "153"
        float laDuracion = std::stof(myText.substr(myText.find(",")+1, myText.length()));
        // myText = "Romantic"
        myText = myText.substr(myText.find(",")+6, myText.length());
        std::string elGenero = myText.substr(0, myText.find(","));


        // rate = "8.5 "
        
        float rate =std::stof(myText.substr(myText.find(",")+1,myText.length()));  

       //Crear un objeto de tipo Video con los datos
       //obtenidos del txt y meterlo en el vector videosDB
       
       Video video_temp(elId, elNombre, laDuracion, elGenero,rate);
       videosDB.push_back(video_temp);
    }

    // Close the file
    MyReadFile.close();

    //Imprimir todos los videos dentro del vector videosDB:
    for(Video vid : videosDB){
        vid.toStr();
    };
    int res;
    cout<<"Do you want to leave a rate? "<<endl;
    cout<<"YES [1]    NO [2]"<<endl;
    cin>>res;

    if (res==1){
        cout<<"Movie ID:  ";
        int id;
        cin>>id;
        cout<<"Rate (0-10):  ";
        float rate;
        cin>>rate;

        setVideoRating(videosDB, id-1, rate);
        videosDB[id-1].toStr();

    }else if(res==2){
        cout<<"BYE";
        return 0;
    }
}

void setVideoRating(std::vector<Video>& movieDB, int elIndex, float elRating){
    movieDB[elIndex].rateVideo(elRating);
};

