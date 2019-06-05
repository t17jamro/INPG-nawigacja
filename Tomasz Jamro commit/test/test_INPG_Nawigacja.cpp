#include "gtest/gtest.h"
#include <math.h>
#include "INPG_Nawigacja.hpp"
// UWAGA! Testy należy wykonywać z plikiem tekstowym BazaTestowa.txt, korzystanie z oficjalnej bazy danych nie zadziała

TEST(PointCreateTest, NormalConstructor) {   
    //Test na tworzenie obiektu Punkt - podanie dokładnych danych do każdego pola
    Point testpoint(4,34,54,"Nazwa",std::vector<int>{55,6,8});
    EXPECT_EQ(testpoint.getlist().size(),3U);
    EXPECT_EQ(testpoint.getlist()[2],8);
    EXPECT_EQ(testpoint.getid(),4);
    EXPECT_EQ(testpoint.getx(),34);
    EXPECT_EQ(testpoint.gety(),54);
    EXPECT_EQ(testpoint.getname(),"Nazwa");
}

TEST(PointCreateTest, StringConstructor){ 
    //test na tworzeniu obiektu Punkt z pojedyńczej lini tekstu, w kodowaniu odpowiednim dla bazy danych
    Point testpoint("5#35#55#Nazwa2#64 63 81#");
    EXPECT_EQ(testpoint.getlist().size(),3U);
    EXPECT_EQ(testpoint.getlist()[2],81);
    EXPECT_EQ(testpoint.getid(),5);
    EXPECT_EQ(testpoint.getx(),35);
    EXPECT_EQ(testpoint.gety(),55);
    EXPECT_EQ(testpoint.getname(),"Nazwa2");

}

TEST(MapCreateTest, ImportMapFunction) { 
    //test na tworzeniu Obiektu Listy Punktów z bazy danych
    //Powinien być tworzony przez przypadkowy punkt a następnie odrazu y poprzez importowanie danych
    Point x(10,34,54,"Nazwa",std::vector<int>{55,6,8});
    PointList test(x);
    Point testpoint = test[0];
    EXPECT_EQ(testpoint.getlist().size(),3U);
    EXPECT_EQ(testpoint.getlist()[2],8);
    EXPECT_EQ(testpoint.getid(),10);
    EXPECT_EQ(testpoint.getx(),34);
    EXPECT_EQ(testpoint.gety(),54);
    EXPECT_EQ(testpoint.getname(),"Nazwa");
    test.Import_Map(); // WAŻNE, zmien ścieżkę dostępu do twojego $REPO$\INPG_Nawigacja\BazaDanych.txt w pliku źródłowym INPG_Nawigacja.cpp
    Point testpoint2 = test[0];
    EXPECT_EQ(testpoint2.getlist().size(),2U);
    EXPECT_EQ(testpoint2.getlist()[1],3);
    EXPECT_EQ(testpoint2.getid(),1);
    EXPECT_EQ(testpoint2.getx(),0);
    EXPECT_EQ(testpoint2.gety(),0);
    EXPECT_EQ(testpoint2.getname(),"PunktA");

}


TEST(MapCreateTest, FindPointMapFunction) {
    //test na szukanie pozycji pojedyńczego punktu w środku obiektu Listy punktów poprzez id
    Point x(4,34,54,"Nazwa",std::vector<int>{55,6,8});
    PointList test(x);
    std::size_t xpos = test.find(4);
    int t = xpos;
    EXPECT_EQ(test[t].getlist().size(),3U);
    EXPECT_EQ(test[t].getid(),4);
    EXPECT_EQ(test[t].gety(),x.gety());
}

TEST(RoadCreateTest, DistanceFunction){
    //test na obliczanie długości pomiędzy dwoma punktami poprzez funkcje
    Point x(4,0,0,"Nazwa",std::vector<int>{55,6,8});
    Point t(4,3,4,"Nazwa",std::vector<int>{55,6,8});
    EXPECT_EQ(distance(x,t),sqrt(25));
}

TEST(RoadCreateTest,DistanceTotal){
    //test na tworzenie obiektu drogi i obliczanie jego długości
    std::vector<Point> q = {};
    Point x(4,0,0,"Nazwa",std::vector<int>{55,6,8});
    Point t(4,3,4,"Nazwa",std::vector<int>{55,6,8});
    Point f(4,3,9,"Nazwa",std::vector<int>{55,6,8});
    Point tef(4,-2,9,"Nazwa",std::vector<int>{55,6,8});
    q.push_back(x);
    q.push_back(t);
    q.push_back(f);
    q.push_back(tef);
    PointRoad road1(q);
    EXPECT_EQ(road1.distance_calculate(),15);
}

TEST(RoadCreateTest,DistanceTotalRoad){
    //Test na poprawne tworzenie drogi, i obliczanie jej odległości
    Point x(4,34,54,"Nazwa",std::vector<int>{55,6,8});
    PointList test(x);
    Point testpoint = test[0];
    test.Import_Map();
    std::vector<Point> radse = FindRoad(3,6,test);
    PointRoad q(radse);
    EXPECT_EQ(q.distance_calculate(),15);
}
