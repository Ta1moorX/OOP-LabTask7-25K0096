#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    int borderThickness;
public:
    Shape(string c, int b) : color(c), borderThickness(b) {}
    virtual void draw() = 0;
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r, string c, int b) : Shape(c, b), radius(r) {}
    void draw() override {
        cout << "Drawing Circle | Color: " << color << " | Radius: " << radius << endl;
    }
    double calculateArea() override { return 3.14159 * radius * radius; }
    double calculatePerimeter() override { return 2 * 3.14159 * radius; }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h, string c, int b) : Shape(c, b), width(w), height(h) {}
    void draw() override {
        cout << "Drawing Rectangle | Color: " << color
             << " | " << width << "x" << height << endl;
    }
    double calculateArea() override { return width * height; }
    double calculatePerimeter() override { return 2 * (width + height); }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(double a, double b, double c, string col, int border)
        : Shape(col, border), a(a), b(b), c(c) {}
    void draw() override {
        cout << "Drawing Triangle | Color: " << color
             << " | Sides: " << a << ", " << b << ", " << c << endl;
    }
    double calculateArea() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s-a) * (s-b) * (s-c));
    }
    double calculatePerimeter() override { return a + b + c; }
};

int main() {
    Shape* shapes[3];
    shapes[0] = new Circle(5, "Red", 2);
    shapes[1] = new Rectangle(4, 6, "Blue", 1);
    shapes[2] = new Triangle(3, 4, 5, "Green", 1);

    for (int i = 0; i < 3; i++) {
        shapes[i]->draw();
        cout << "  Area:      " << shapes[i]->calculateArea() << endl;
        cout << "  Perimeter: " << shapes[i]->calculatePerimeter() << endl << endl;
    }

    for (int i = 0; i < 3; i++) delete shapes[i];
    return 0;
}
