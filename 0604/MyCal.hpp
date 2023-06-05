#include <string>
using namespace std;

class MyCal
{
public:
    MyCal(double a, double b) : m_a(a), m_b(b)
    {

    }
    
    double execute(string op)
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