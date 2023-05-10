#include<iostream>

using namespace std;

namespace V
{
    namespace V1
    {
        void print()
        {
            cout<<"hello world"<<endl;
            cout<<"welcome to jsetc!"<<endl;
        }
    }
   namespace V2
    {
        void print()
        {
            cout<<"hello world"<<endl;
            cout<<"welcome to jsetc!"<<endl;
        }
    }
    inline namespace V3
    {
        void print()
        {
            cout<<"hello world"<<endl;
            cout<<"welcome to jsetc!"<<endl;
            cout<<"hello world"<<endl;
            cout<<"welcome to jsetc!"<<endl;
        }
    }
}

int main()
{
    V::print();

    return 0;
}