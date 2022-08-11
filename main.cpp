#include <iostream>
#include <string>
#include <map>

enum shape {
    shape_triangle,
    shape_square,
    shape_circle,
    shape_line,
    shape_point,
    shape_size
};

std::map<shape,std::string> names = {
        {shape_triangle, "Triangle"},
        {shape_square, "Square"},
        {shape_circle, "Circle"},
        {shape_line, "Line"},
        {shape_point, "Point"}
                                     };

class Shape {
public:
    virtual ~Shape(){};
    virtual std::string getName() const = 0;
    virtual shape getType() const = 0;
    virtual void testMethod() = 0;
};

class Triangle : public Shape {
public:
    Triangle(){}
    Triangle(const int a[],const int b[]) {}
    virtual ~Triangle(){}
    virtual std::string getName() const {return names[shape_triangle];}
    virtual shape getType() const {return shape_triangle;}
    virtual void testMethod() { ;/* do something*/}
private:
    int x[3];
    int y[3];
};

class Square : public Shape {
public:
    Square(){}
    Square(const int a[],const int b[]) {}
    virtual ~Square(){}
    virtual std::string getName() const {return names[shape_square];}
    virtual shape getType() const {return shape_square;}
    virtual void testMethod() { ;/* do something*/}
private:
    int x[4];
    int y[4];
};

class Circle : public Shape {
public:
    Circle(){}
    Circle(int x_, int y_, int radius_):x(x_),y(y_),radius(radius_) {}
    virtual ~Circle(){}
    virtual std::string getName() const {return names[shape_circle];}
    virtual shape getType() const {return shape_circle;}
    virtual void testMethod() { ;/* do something*/}
private:
    int x,y;
    int radius;
};


class Line : public Shape {
public:
    Line(){}
    Line(int x1,int y1,int x2,int y2):xLeft(x1),yLeft(y1),xRight(x2),yRight(y2) {}
    virtual ~Line(){}
    virtual std::string getName() const {return names[shape_line];}
    virtual shape getType() const {return shape_line;}
    virtual void testMethod() { ;/* do something*/}
private:
    int xLeft,yLeft;
    int xRight,yRight;
};


class Point : public Shape {
public:
    Point(){}
    Point(int x_, int y_):x(x_),y(y_) {}
    virtual ~Point(){}
    virtual std::string getName() const {return names[shape_point];}
    virtual shape getType() const {return shape_point;}
    virtual void testMethod() { ;/* do something*/}
private:
    int x,y;
};


void initType(Shape ** ptr) {
    int type;
    std::cin >> type;
    shape shape_type = (shape)type;
    switch (shape_type) {
        case shape_line:
            *ptr = new Line();
            break;
        case shape_circle:
            *ptr = new Circle();
            break;
        case shape_square:
            *ptr = new Square();
            break;
        case shape_triangle:
            *ptr = new Triangle();
            break;
        case shape_point:
            *ptr = new Point();
            break;
        default:
            break;
    }
}

int main() {

    Shape * ptr = nullptr;

    initType(&ptr);

    if (ptr)
        std::cout << ptr->getName() << " " << ptr->getType() << std::endl;
    else
        std::cout << "Bad type" << std::endl;

    return 0;
}
