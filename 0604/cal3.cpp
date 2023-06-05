#include <iostream>

using namespace std;

class Operation
{
public:
    virtual double get_result(double a, double b) = 0;
};

class AddOperation : public Operation
{
public:
    double get_result(double a, double b)
    {
        return a + b;
    }
};

class SubOperation : public Operation
{
public:
    double get_result(double a, double b)
    {
        return a - b;
    }
};

class MulOperation : public Operation
{
public:
    double get_result(double a, double b)
    {
        return a * b;
    }
};

class DivOperation : public Operation
{
public:
    double get_result(double a, double b)
    {
        return a / b;
    }
};

class DivOperationV2 : public Operation
{
public:
    double get_result(double a, double b)
    {
        if (b == 0)
        {
            throw("b is zero!");
            return 0;
        }
        else
        {
            return a / b;
        }
    }
};

class Cal
{
public:
    Cal(Operation *add, Operation *sub, Operation *mul, Operation *div) : m_add(add), m_sub(sub), m_mul(mul), m_div(div)
    {
    }

    double get_result(double a, double b, string op)
    {
        if (op == "+")
        {
            return m_add->get_result(a, b);
        }
        else if (op == "-")
        {
            return m_sub->get_result(a, b);
        }
        else if (op == "*")
        {
            return m_mul->get_result(a, b);
        }
        else if (op == "/")
        {
            return m_div->get_result(a, b);
        }
    }

    ~Cal()
    {
        delete m_add;
        delete m_sub;
        delete m_div;
        delete m_mul;
    }

    Operation *m_add;
    Operation *m_sub;
    Operation *m_mul;
    Operation *m_div;
};

int main(int argc, char **argv)
{
    string op;
    double a;
    double b;

    cin >> a;
    cin >> b;
    cin >> op;
    
    Operation *add = new AddOperation;
    Operation *sub = new SubOperation;
    Operation *mul = new MulOperation;
    Operation *div = new DivOperation;


    Cal cal(add,sub,mul,div);
    cout << cal.get_result(a, b, op) << endl;

    return 0;
}