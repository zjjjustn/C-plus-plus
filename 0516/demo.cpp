#include<iostream>

using namespace std;

int main(int argc,char **argv)
{
    int num = 5;
    int &lnum = num;//左值引用
    const int &lnum = 5;

    int &&rnum = 5;

}