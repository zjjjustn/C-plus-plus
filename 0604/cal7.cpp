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

class Test
{
public:
    Test() = default;
    Test(int t) : m_t(t)
    {
    }
    int m_t;
};

ostream & operator<<(ostream &out, const Test &t)
{
    out << t.m_t;
    return out;
}

class CalTest
{
public:
    CalTest(Test a, Test b) : m_a(a), m_b(b)
    {
    }
    virtual Test get_result() = 0;
    Test m_a;
    Test m_b;
};

class AddTest : public CalTest
{
public:
    AddTest(Test a, Test b) : CalTest(a, b)
    {
    }
    virtual Test get_result()
    {
        return Test(m_a.m_t + m_b.m_t);
    }
};

class SubTest : public CalTest
{
public:
    SubTest(Test a, Test b) : CalTest(a, b)
    {
    }
    virtual Test get_result()
    {
        return Test(m_a.m_t - m_b.m_t);
    }
};

class MulTest : public CalTest
{
public:
    MulTest(Test a, Test b) : CalTest(a, b)
    {
    }
    virtual Test get_result()
    {
        return Test(m_a.m_t * m_b.m_t);
    }
};

class DivTest : public CalTest
{
public:
    DivTest(Test a, Test b) : CalTest(a, b)
    {
    }
    virtual Test get_result()
    {
        return Test(m_a.m_t / m_b.m_t);
    }
};

class ModTest : public CalTest
{
public:
    ModTest(Test a, Test b) : CalTest(a, b)
    {
    }
    virtual Test get_result()
    {
        return Test(m_a.m_t % m_b.m_t);
    }
};

class CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) = 0;
    virtual CalTest *createTest(Test a, Test b) = 0;
};

class AddFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Add(a, b);
    }

    virtual CalTest *createTest(Test a, Test b)
    {
        return new AddTest(a, b);
    }
};

class SubFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Sub(a, b);
    }

    virtual CalTest *createTest(Test a, Test b)
    {
        return new SubTest(a, b);
    }
};

class MulFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Mul(a, b);
    }

    virtual CalTest *createTest(Test a, Test b)
    {
        return new MulTest(a, b);
    }
};

class DivFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Div(a, b);
    }

    virtual CalTest *createTest(Test a, Test b)
    {
        return new MulTest(a, b);
    }
};

class ModFactory : public CalFactory
{
public:
    virtual Cal *createOperator(double a, double b) override
    {
        return new Mod(a, b);
    }

    virtual CalTest *createTest(Test a, Test b)
    {
        return new ModTest(a, b);
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
    CalFactory *factory = con.Resolve(op);

    Cal *cal = factory->createOperator(a, b);
    CalTest *tcal = factory->createTest(Test(a), Test(b));
    cout << cal->get_result() << endl;
    cout << tcal->get_result() << endl;

    return 0;
}