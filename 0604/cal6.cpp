#include <iostream>
#include <string>
#include <memory>
#include "IOC.hpp"

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


class CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) = 0;
};

class AddFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Add(a, b);
    }
};

class SubFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Sub(a, b);
    }
};

class MulFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Mul(a, b);
    }
};

class DivFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Div(a, b);
    }
};

class ModFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Mod(a, b);
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
    
    IocContainer<CalFactory> con = IocContainer<CalFactory>::getInstance();
    con.RegisterType<AddFactory>("+");  //["+", [](){return new AddFactroy;}]
    con.RegisterType<SubFactory>("-");  
    //["+", [](){return new AddFactroy;}],["-", [](){return new SubFactroy;}]
    con.RegisterType<MulFactory>("*");
    con.RegisterType<DivFactory>("/");    
     //["+", [](){return new AddFactroy;}],["-", [](){return new SubFactroy;}]
      //["*", [](){return new MulFactroy;}],["/", [](){return new DivFactroy;}]
    con.RegisterType<ModFactory>("%");

    CalFactory *factory = con.Resolve(op);

    Cal *cal = factory->createOperator(a, b);
    cout << cal->get_result() << endl;

    return 0;
}