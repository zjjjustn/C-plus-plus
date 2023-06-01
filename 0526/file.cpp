#include<iostream>
#include<fstream>
using namespace std;

int main(int argc,char** argv)
{
    ifstream rfile("a.txt");
    ofstream wfile("b.txt");
    
    //打开文件
    rfile.open("a.txt",ios::in);
    if(rfile.fail())
    {
        cout<<"open file error!"<<endl;
    }

    return 0;
}