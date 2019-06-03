#include "INPG_Nawigacja.hpp"

#include <iostream>
#include <fstream>
#include <sstream>


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
    // WaĹĽne !!! - przydatny warunek do odczytywania listy sasiednich punktĂłw to !isspace(*it) - wykrywa brak spacji
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
    plik.open( "C:\\Users\\To_Ja\\Desktop\\Inform\\mdig-agh-air_inf1_lab_cpp_exercises-8565224dab68\\solutions\\INPG_Nawigacja\\BazaDanych.txt", std::ios::in);
    if( plik.good())
    {
        while(!plik.eof())
        {
            getline(plik, linia);
            auto a = Point(linia);
            PointList_.push_back(a); //tworzenie punktu za pomocÄ… lini
        }
        plik.close();
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}

std::size_t PointList::find(int x) const {
    for (std::size_t posit =0 ; posit<PointList_.size(); posit++)
    {
        if (PointList_[posit].getid() == x) return posit;
    }
    return 0; // Do zmiany - dodadanie wyjÄ…tku gdy nie znajdzie siÄ™ punktu WAĹ»NE
}

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
    return 0; // Do zmiany - dodadanie wyjÄ…tku gdy baza jest poprawna
}
