#ifndef MATLAB_HPP_
#define MATLAB_HPP_

#include <vector>
#include <string>
// jeszcze nie potrzebne #include <functional>

class Point {
public:
    Point(int id, int x, int y, std::string name, std::vector<int> list) : id_(id), x_(x), y_(y), name_(name), list_(list) {};
    Point(const Point&) = default;
    Point(std::string str);

    int getid() const {return id_;}

    int getx() const {return x_;}

    int gety() const {return y_;}

    std::string getname() const {return name_;}

    std::vector<int> getlist() const {return list_;}
private:
    int id_;

    int x_;

    int y_;

    std::string name_; //std::vector<std::string> do wprowadzenia wielu nazw

    std::vector<int> list_;
};

class PointList {
public:
    PointList(Point construct_map): PointList_(1,construct_map) {};
    void Import_Map();
    const Point& operator[](std::size_t pos) const { return PointList_[pos]; }

    Point& operator[](std::size_t pos) { return PointList_[pos]; }

    std::vector<Point>::const_iterator cbegin() const { return PointList_.cbegin(); }

    std::vector<Point>::const_iterator cend() const { return PointList_.cend(); }

    std::vector<Point>::iterator begin() { return PointList_.begin(); }

    std::vector<Point>::const_iterator begin() const { return PointList_.cbegin(); }

    std::vector<Point>::iterator end() { return PointList_.end(); }

    std::vector<Point>::const_iterator end() const { return PointList_.cend(); }

private:
    std::vector<Point> PointList_;
};

#endif /* MATLAB_HPP_ */
