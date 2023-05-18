#include<iostream>
#include<string.h>

using namespace std;
class Test
{
    public:
Test()
{
    cout<<"Test construct"<<endl;
}
Test(char *data,int len)
{
    cout<<"Test con"<<endl;
    int len = strlen(data)+1;
    m_data = new char[len];
    memcpy(m_data,data,len);
    m_len = len;
}

~Test()
{
    cout<<"yest"<<endl;
    if(data!=nullptr)
    {
        int size = strlen(data);
        m_data = new char[size +1];
        memcpy(m_dara,data,size);
    }
}
}


int main(int argc,char **argc)
{
    Test t()
}