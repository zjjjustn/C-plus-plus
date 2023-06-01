// 值多态
#include <variant>
#include <iostream>
using namespace std;

constexpr double pi = 3.14;
struct Shape2
{
   virtual void getName() = 0;
};
struct Circle :  public Shape2
{
   Circle()
   {

   }
   Circle(double r) : r(r)
   {

   }
   void getName()
   {
       cout << "Circle" << endl;
   }
    double r;
};
double getArea(const Circle& c) {
    return pi * c.r * c.r;
}
double getPerimeter(const Circle& c) {
    return 2 * pi * c.r;
}

struct Triangle : public Shape2
{
    Triangle(double h, double w) : h(h), w(w)
    {

    }

    void getName()
    {
        cout << "Triangle" << endl;
    }
    double h;
    double w;
};
double getArea(const Triangle& c) {
    return  (c.h * c.w) / 2;
}
double getPerimeter(const Triangle& c) {
    return c.h + c.w;
}
struct Rectangle :public Shape2
{
public:
    Rectangle(double w, double h) : w(w), h(h)
    {

    }
    void getName()
    {
        cout << "Rectangle" << endl;
    }
    double w;
    double h;
};
double getArea(const Rectangle& c) {
    return c.h * c.w;
}
double getPerimeter(const Rectangle& c) {
    return 2 * (c.h + c.w);
}

using Shape = std::variant<Circle, Rectangle,Triangle>;
double getArea(const Shape& c) {
    return std::visit([](const auto& data) {return getArea(data); }, c);
}
double getPerimeter(const Shape& c) {
    return std::visit([](const auto& data) {return getPerimeter(data); }, c);
}

int main() {
    Shape sp = Circle(2);
    std::cout<<getArea(sp) << endl;
    std::cout << getPerimeter(sp) << endl;;

    sp = Rectangle(2,3);
    std::cout << getArea(sp) << endl;
    std::cout << getPerimeter(sp) << endl;
}