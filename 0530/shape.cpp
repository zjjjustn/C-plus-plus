#include<iostream>
#include<vector>

using namespace std;

class Shape
{
public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w,double h) : m_w(w),m_h(h)
    {

    }
    double getArea() override
    {
        return m_w * m_h;
    }
    double m_w;
    double m_h;
};

class Circle : public Shape{
public:
    Circle(double r) : m_r(r)
    {

    }
    constexpr static double pi = 3.1415;
    double getArea() override
    {
        return pi * m_r * m_r;
    }
    double m_r;
};
double calculateTotalArea(vector<Shape *> &v)
{
    double result = 0.0;
    for(const auto &temp :v)
    {
        result = result + temp->getArea();
    }
}

int main(int argc,char ** argv) 
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle(3, 4));
    shapes.push_back(new Circle(5));

    double totalArea = calculateTotalArea(shapes);
    std::cout << "Total area: " << totalArea << std::endl;

    return 0;
}
