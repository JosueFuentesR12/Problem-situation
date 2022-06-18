#include <iostream>
#include <fstream>
#include <vector>
#include "Video.h"
#include "Movie.h"
#include "Series.h"

//Carlos Alberto Mendoza Medina A01661896 
//Jonathan Josué Fuentes Ramírez A01661894

using namespace std;

void setVideoRating(std::vector<Video>&, int, float);
void getVide(std::vector<Video>& videoDB, string res);

int main()
{
    // Create a text string, which is used to output the text file
    string myText;

    // Read from the text file
    ifstream MyReadFile("MoviesData.txt");

    // Create our video container...
    vector<Movie> moviesDB;
    vector<Series> seriesDB;
    vector<Video> videoDB;
    
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
        videoDB.push_back(video_temp);
       if(laDuracion>70){
            Movie video_temp(elId, elNombre, laDuracion, elGenero,rate);
            moviesDB.push_back(video_temp);
       }else if(laDuracion<70){
            Series video_temp2(elId, elNombre, laDuracion, elGenero,rate);
            seriesDB.push_back(video_temp2);
       }
       //Video video_temp(elId, elNombre, laDuracion, elGenero,rate);
       //videosDB.push_back(video_temp);
    }

    // Close the file
    MyReadFile.close();

    //Imprimir todos los videos dentro de los vectores:
    cout<<"Movies: "<<endl;
    for(Movie vid1 : moviesDB){
        vid1.toStr();
    };
    cout<<"Series: "<<endl;
    for(Series vid2 : seriesDB){
        vid2.toStr();
    };

    int r;
    cout<<"Want to search a video in data base? "<<"\n"<<"YES [1]    NO [2]"<<endl;
    cin>>r;
    if(r==1){
        int sel = 0;
        while(sel!=4){
        
        cout<<"Select : "<<endl;
        cout<<"         [1] Movie "<<endl;
        cout<<"         [2] Serie "<<endl;
        cout<<"         [3] Genre "<<endl;
        cout<<"         [4] Exit "<<endl;
        cin>>sel;
        string res2;
        switch (sel)
        {
        case 1: 
            for(Movie vid1 : moviesDB){
            vid1.toStr();
            }; break;
        case 2:
            for(Series vid2 : seriesDB){
            vid2.toStr();
            }; break;
        case 3:
            cout<<"Select : "<<endl;
            cout<<"         Superhero "<<endl;
            cout<<"         Romantic "<<endl;
            cout<<"         Comedy "<<endl;
            cout<<"         Adventure "<<endl;
            cout<<"         Biography "<<endl;
            cout<<"         Music "<<endl;
            cout<<"         Animation "<<endl;
            cout<<"         SF "<<endl;
            cout<<"         Drama "<<endl;
            cout<<"Write all the genre : "<<endl;    
            cin>>res2;  
            getVide(videoDB, res2); break;
        case 4: break;
        default: cout<<"Error, incorrect value "<<endl; break;
        }

        }
    }else if(r==2){
        cout<<endl;
    }


    int res;
    cout<<"Do you want to leave a rate? "<<endl;
    cout<<"YES [1]    NO [2]"<<endl;
    cin>>res;

    if (res==1){
        cout<<"Video ID:  ";
        int id;
        cin>>id;
        cout<<"Rate (0-10):  ";
        float rate;
        cin>>rate;
        setVideoRating(videoDB, id-1, rate);
        videoDB[id-1].toStr();

    }else if(res==2){
        cout<<"End of program";
        return 0;
    }
}

void setVideoRating(std::vector<Video>& videoDB, int elIndex, float elRating){
    videoDB[elIndex].rateVideo(elRating);
};
void getVide(std::vector<Video>& videoDB, string res){
    if(res=="Superhero"){
        videoDB[0].toStr();
        videoDB[2].toStr();
        videoDB[7].toStr();
        videoDB[8].toStr();
        videoDB[11].toStr();
        videoDB[12].toStr();
    }else if(res=="Romantic"){
        videoDB[1].toStr();
    }else if(res=="Comedy"){
        videoDB[4].toStr();
        videoDB[5].toStr();
        videoDB[13].toStr();
    }else if(res=="Adventure"){
        videoDB[3].toStr();
        videoDB[6].toStr();
        videoDB[9].toStr();
        videoDB[22].toStr();
        videoDB[26].toStr();
    }else if(res=="Biography"){
        videoDB[10].toStr();
    }else if(res=="Music"){
        videoDB[14].toStr();
    }else if(res=="Animation"){
        videoDB[15].toStr();
        videoDB[18].toStr();
        videoDB[21].toStr();
        videoDB[23].toStr();
        videoDB[24].toStr();
        videoDB[25].toStr();
    }else if(res=="SF"){
        videoDB[16].toStr();
        videoDB[17].toStr();
        videoDB[20].toStr();
        videoDB[27].toStr();
    }else if(res=="Drama"){
        videoDB[19].toStr();
        videoDB[28].toStr();
        videoDB[29].toStr();
    }
    
};

