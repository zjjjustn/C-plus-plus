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

class Factory
{
public:
    static CalFactory *createFactory(string op)
    {
        CalFactory *factory;
        if (op == "+")
        {
            factory = new AddFactory();
        }
        else if (op == "-")
        {
            factory = new SubFactory();
        }
        else if (op == "*")
        {
            factory = new MulFactory();
        }
        else if (op == "/")
        {
            factory = new MulFactory();
        }

        return factory;
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

    CalFactory *factory = Factory::createFactory(op);

    Cal *cal = factory->createOperator(a, b);
    cout << cal->get_result() << endl;

    return 0;
}