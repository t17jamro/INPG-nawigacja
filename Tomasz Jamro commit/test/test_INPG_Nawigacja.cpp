#include "gtest/gtest.h"

#include "INPG_Nawigacja.hpp"


TEST(PointCreateTest, NormalConstructor) {
    Point testpoint(4,34,54,"Nazwa",std::vector<int>{55,6,8});
    EXPECT_EQ(testpoint.getlist().size(),3U);
    EXPECT_EQ(testpoint.getlist()[2],8);
    EXPECT_EQ(testpoint.getid(),4);
    EXPECT_EQ(testpoint.getx(),34);
    EXPECT_EQ(testpoint.gety(),54);
    EXPECT_EQ(testpoint.getname(),"Nazwa");
}

TEST(PointCreateTest, StringConstructor){
    Point testpoint("5#35#55#Nazwa2#64 63 81#");
    EXPECT_EQ(testpoint.getlist().size(),3U);
    EXPECT_EQ(testpoint.getlist()[2],81);
    EXPECT_EQ(testpoint.getid(),5);
    EXPECT_EQ(testpoint.getx(),35);
    EXPECT_EQ(testpoint.gety(),55);
    EXPECT_EQ(testpoint.getname(),"Nazwa2");

}

TEST(PointCreateTest, ImportMap) {
    Point x(4,34,54,"Nazwa",std::vector<int>{55,6,8});
    PointList test(x);
    Point testpoint = test[0];
    EXPECT_EQ(testpoint.getlist().size(),3U);
    EXPECT_EQ(testpoint.getlist()[2],8);
    EXPECT_EQ(testpoint.getid(),4);
    EXPECT_EQ(testpoint.getx(),34);
    EXPECT_EQ(testpoint.gety(),54);
    EXPECT_EQ(testpoint.getname(),"Nazwa");
    test.Import_Map(); // WAŻNE, zmien ścieżkę dostępu do twojego $REPO$\INPG_Nawigacja\BazaDanych.txt w pliku źródłowym INPG_Nawigacja.cpp
    Point testpoint2 = test[1];
    EXPECT_EQ(testpoint2.getlist().size(),3U);
    EXPECT_EQ(testpoint2.getlist()[2],36);
    EXPECT_EQ(testpoint2.getid(),456);
    EXPECT_EQ(testpoint2.getx(),234);
    EXPECT_EQ(testpoint2.gety(),643);
    EXPECT_EQ(testpoint2.getname(),"Nazwa1");
    Point testpoint3 = test[2];
    EXPECT_EQ(testpoint3.getlist().size(),3U);
    EXPECT_EQ(testpoint3.getlist()[2],36);
    EXPECT_EQ(testpoint3.getid(),456);
    EXPECT_EQ(testpoint3.getx(),234);
    EXPECT_EQ(testpoint3.gety(),643);
    EXPECT_EQ(testpoint3.getname(),"Nazwa2");

}

TEST(PointCreateTest, FindPointMapFunction) {
    Point x(4,34,54,"Nazwa",std::vector<int>{55,6,8});
    PointList test(x);
    std::size_t xpos = test.find(4);
    int t = xpos;
    EXPECT_EQ(test[t].getlist().size(),3U);
    EXPECT_EQ(test[t].getid(),4);
    EXPECT_EQ(test[t].gety(),x.gety());
}
