#include <iostream>
#include <string>
#include <memory>
#include "IOC.hpp"
#include "MyCal.hpp"

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

class Mod : public Cal
{
public:
    Mod(double a, double b) : Cal(a, b)
    {
    }

    double get_result() override
    {
        return double((int)m_a % (int)m_b);
    }
};

class CalSubject : public Cal
{
public:
    CalSubject(Cal *cal) : Cal(0, 0), m_cal(cal)
    {
    }
    virtual double get_result()
    {
        if (m_cal->m_a >= 1 && m_cal->m_a <= 10)
        {
            return m_cal->get_result();
        }
        else
        {
            throw(">10 < 1!");
        }
    }

private:
    Cal *m_cal;
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

    CalSubject subject(cal);

    cout << subject.get_result() << endl;

    return 0;
}