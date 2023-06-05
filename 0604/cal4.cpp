#include <iostream>
#include <string>
#include <memory>
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
    Add(double a, double b) : Cal(a, b)
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
    Sub(double a, double b) : Cal(a, b)
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
    Mul(double a, double b) : Cal(a, b)
    {
    }

    double get_result() override
    {
        return m_a - m_b;
    }
};

class Div : public Cal
{
public:
    Div(double a, double b) : Cal(a, b)
    {
    }

    double get_result() override
    {
        return m_a - m_b;
    }
};

class CalFactory
{
public:
    static Cal *createOperator(double a, double b,string op)
    {
        Cal *cal;
        
        if (op == "+")
        {
            cal = new Add(a, b);
        }
        else if (op == "-")
        {
            cal = new Sub(a, b);
        }
        else if (op == "*")
        {
            cal = new Mul(a, b);
        }
        else if(op == "/")
        {
            cal = new Div(a,b);
        }
        else if(op == "%")
        {
            
        }

        return cal;
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

    Cal *cal = CalFactory::createOperator(a,b,op); 

    cout << cal->get_result() << endl;

    shared_ptr<int> pi(new int(5));
    shared_ptr<int> pi2 = std::make_shared<int>(5);

    return 0;
}