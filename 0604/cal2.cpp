#include <iostream>
#include <string>

using namespace std;

class Cal
{
public:
    Cal(double a, double b) : m_a(a), m_b(b)
    {

    }
    virtual ~Cal()
    {

    }
    virtual double get_result() = 0;
    double m_a;
    double m_b;
};

class Add : public Cal
{
public:
    Add(double a, double b) : Cal(a,b)
    {

    }

    double get_result() override
    {
        return m_a + m_b;
    }
};

class Sub : public Cal
{
public:
    Sub(double a, double b) : Cal(a,b)
    {

    }

    double get_result() override
    {
        return m_a - m_b;
    }
};

class Mul : public Cal
{
public:
    Mul(double a, double b) : Cal(a,b)
    {

    }

    double get_result() override
    {
        return m_a - m_b;
    }
};


int main(int argc, char **argv)
{
    string op;
    double a;
    double b;

    cin >> a;
    cin >> b;
    cin >> op;
    
    Cal *cal;
    if(op == "+")
    {
        cal = new Add(a,b);
    }
    else if(op == "-")
    {
        cal = new Sub(a,b);
    }
    else if(op == "*")
    {
        cal = new Mul(a,b);
    }

    cout << cal->get_result() << endl;
    
    return 0;
}