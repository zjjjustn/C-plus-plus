#include<iostream>
#include<string>
using namespace std;
class AbsAdd
{
public:
    virtual int add(int a,int b) = 0;
};

class Add:public AbsAdd
{
public:
    virtual int add(int a,int b)
    {
        cout<<"add"<<endl;
        return a+b;
    }
};
class Add2 :public AbsAdd
{
public:
    virtual int add(int a,int b)
    {
        cout << "hello world" <<endl;
        return a+b;
    }
};

class Sub
{
public:
    int sub(int a,int b)
    {
        return a - b;
    }    
};
class Mul
{
public:
    int mul(int a,int b)
    {
        return a+b;
    }
};
class AbsDiv
{
public:
    virtual int div(int a,int b) = 0;
};

class Div : public AbsDiv
{
public:
    int div(int a,int b)
    {
        if(b == 0)
        {
            return 0;
        }
        return a/b;
    }
};

class Div2 : public AbsDiv
{
public:
    int div(int a,int b)
    {
        cout << "Div" << endl;
        if(b == 0)
        {
            return 0;
        }
        return a/b;
    }
};

class Cal
{
public:
    Cal(AbsAdd *a,Sub *s,Mul *m,AbsDiv *d): pa(a),ps(s),pd(d),pm(m)
    {

    }
    int get_result(int num1,int num2,string op)
    {
        if(op == "+")
        {
            pa->add(num1,num2);
        }
    }
    ~Cal()
    {
        delete pa;
        delete ps;
        delete pd;
        delete pm;
    }
private:
    AbsAdd *pa;
    Sub *ps;
    Mul *pm;
    AbsDiv *pd;
};

class Cal2 : public Add,public Sub,public Mul, public Div
{
public:
    int get_result(int a,int b,string op)
    {
        if(op == "+")
        {
            add(a,b);
        }
    }
};

int main(int argc,char **argv)
{
    AbsAdd *a = new Add2;
    Sub *s = new Sub;
    Mul *m = new Mul;
    AbsDiv *d = new Div;

    Cal cal(a,s,m,d);
    cout << cal.get_result(5,0,"+")<<endl;

    return 0;
}