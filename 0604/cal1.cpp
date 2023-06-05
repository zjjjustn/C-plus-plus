#include <iostream>

using namespace std;

class Cal
{
public:
    Cal(double a, double b) : m_a(a), m_b(b)
    {

    }
    
    double get_result(string op)
    {
        if(op == "+")
        {
            return m_a + m_b;
        }
        else if(op == "-")
        {
            return m_a - m_b;
        }
    }

    double m_a;
    double m_b;
};

int main(int argc, char **argv)
{
    string op;
    double a;
    double b;

    cin >> a;
    cin >> b;
    cin >> op;

    Cal cal(a,b);
    cout << cal.get_result(op) << endl;

    
    return 0;
}