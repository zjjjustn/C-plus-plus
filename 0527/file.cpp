#include<iostream>
#include<string>
#include<fstream>
#include<string.h>
using namespace std;

int main(int argc,char **argv)
{
    // fstream file("a.txt",ios::in | ios::out | ios::trunc);
    // if(!file)
    // {
    //     cout << "open file error!" << endl;
    // }

    // file << "hello world";
    // string msg = "hello world";
    // file.write(msg.c_str(),msg.size());
    // file.put('a');

    // file.seekg(0,ios::beg);

    // char buffer[1024];
    // auto ch = file.get();
    // cout << ch << endl;
    // //file.get(buffer,1024)
    // //file.getline(buffer,1024,'\n');
    // file.read(buffer,1024);
    // cout << buffer << endl;
    ifstream from_file(argv[1],ios::in);
    if(!from_file)
    {
        cout << "read file open error!" <<endl;
    }
    ofstream to_file(argv[2],ios::out | ios::trunc);
    if(!to_file)
    {
        cout << "write file open error!" << endl;
    }

    char buffer[1024];

    while(!from_file.eof())
    {
        //from_file.getline(buffer,1024,'\n');
        memset(buffer,0,sizeof(buffer));
        from_file.get(buffer,1024,'\n');

        to_file.write(buffer,strlen(buffer));
        while (from_file.peek() == '\n')
        {
            to_file << "\n";
            from_file.ignore();
        }

    }
    from_file.close();
    to_file.close();




    return 0;
}