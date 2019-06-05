#include "INPG_Nawigacja.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>


Point::Point(std::string str) {
    std::ostringstream oss;
    std::vector<std::string> pointstring;
    for (auto it = str.begin(); it != str.end() ; ++it) {
        if (*it != '#') {
            oss << *it;
        } else {
            pointstring.push_back(oss.str());
            oss.str("");
            oss.clear();
        }
    }
    // Ważne !!! - przydatny warunek do odczytywania listy sasiednich punktów to !isspace(*it) - wykrywa brak spacji
    int id = std::stoi( pointstring[0] );
    int x = std::stoi( pointstring[1] );
    int y = std::stoi( pointstring[2] );
    std::string name = pointstring[3];
    std::vector<int> list;
    std::string liststr = pointstring[4];
    int temp_var;
    for (auto it = liststr.begin(); it != liststr.end() ; ++it) {
        if (!isspace(*it)) {
            oss << *it;
        } else {
            temp_var = std::stoi(oss.str());
            list.push_back(temp_var);
            oss.str("");
            oss.clear();
        }
    }
    temp_var = std::stoi(oss.str());
    list.push_back(temp_var);
    oss.str("");
    oss.clear();
    pointstring = {};
    id_= id;
    x_=x;
    y_=y;
    name_=name;
    list_=list;
}

void PointList::Import_Map() {
    PointList_ = {};
    std::string linia;
    std::fstream plik;
    plik.open( "C:\\Users\\To_Ja\\Desktop\\Inform\\mdig-agh-air_inf1_lab_cpp_exercises-8565224dab68\\solutions\\INPG_Nawigacja\\BazaTest.txt", std::ios::in);
    if( plik.good())
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            auto a = Point(linia);
            PointList_.push_back(a); //tworzenie punktu za pomocą lini
        }
        plik.close();
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

std::size_t PointList::find(int x) const {
    for (std::size_t posit =0 ; posit<PointList_.size(); posit++)
    {
        if (PointList_[posit].getid() == x) return posit;
    }
    return 0; // Do zmiany - dodadanie wyjątku gdy nie znajdzie się punktu WAŻNE
}

float distance(Point A, Point B) {
    float a = sqrt((A.getx()-B.getx())*(A.getx()-B.getx())+(A.gety()-B.gety())*(A.gety()-B.gety()));
    return a;
}

std::size_t PointRoad::find(int x) const {
    for (std::size_t posit =0 ; posit<Road_.size(); posit++)
    {
        if (Road_[posit].getid() == x) return posit;
    }
    return 0; // Do zmiany - dodadanie wyjątku gdy nie znajdzie się punktu WAŻNE
}

float PointRoad::distance_calculate() const{
    int siz = Road_.size();
    float a = 0;
    for (int it = 0; it < siz - 1; it++){
        a += distance(Road_[it],Road_[it+1]);
    }
    return a;
}

std::vector<Point> FindRoad(int A,int B, PointList Map){
    int a = Map.find(A); // Wszystkie komentarze w postaci "// std::cout" służą do ułatwienia testowania i modyfikacji funkcji
    int b = Map.find(B);
    Point P = Map[a];
    Point G = Map[b];
    std::vector<Point> Road;
    int last;
    std::vector<std::vector<float>> distances;
    Road.push_back(P);
    std::vector<float> distancevec;
    do{
        last = Road.size() - 1;
        for(unsigned long long i = 0; i < Road[last].getlist().size(); i++){
            distancevec.push_back(distance(G,Map[Map.find(Road[last].getlist()[i])]));
            //std::cout<<"\n odleglosc: " <<distancevec[i];
        }
        //powyższy fragment tworzy za każdym razem dla ostatniego punktu vector distancevec - okrela on odległość sąsiadów od punktu docelowego
        int n = distancevec.size();
        //std::cout<<"\n id wielkosc wektora distancevec" << n;
        int mic = distancevec[0];
        int posit = 0;
        for(int i = 0; i != n; ++i)
        {
            if(distancevec[i] < mic) {
                mic = distancevec[i];
                posit = i;
            }
        }
        // powyższy fragment znajduje pozycje w wektorze distance o najmniejszej wartości
        //std::cout<<"\n id nowego elementu " << Road[last].getlist()[posit];
        //std::cout <<"\n dodaje punkt: " << Map[Map.find(Road[last].getlist()[posit])].getid();
        distances.push_back(distancevec);
        distancevec.clear();
        Road.push_back(Map[Map.find(Road[last].getlist()[posit])]);
        last += 1;
        // powyższy fragment dodaje do tworzącej się drogi punkt najbliższy punktu końcowemu
        //std::cout<< "\n Nowa pętla \n\n";
    }
    while(distance(Road[last],G)!=0); // sprawdzenie czy punkt jest punktem ostatnim
    return Road;
}
/* Błędny algorytm, zalążek dalszej pracy

 int find_lack_of_id() {
    std::string linia;
    std::fstream plik;
    int number = 0;
    int i = 0;
    plik.open( "C:\\Users\\To_Ja\\Desktop\\Inform\\mdig-agh-air_inf1_lab_cpp_exercises-8565224dab68\\solutions\\INPG_Nawigacja\\BazaDanych.txt", std::ios::in);
    if( plik.good())
    {
        while(!plik.eof()) {
            getline(plik, linia);
            number = 0;
            auto it = linia.begin();
            if(*it == ""){
                return i;
            }
            i++;
        }
        plik.close();
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
    return 0; // Do zmiany - dodadanie wyjątku gdy baza jest poprawna
}
*/
