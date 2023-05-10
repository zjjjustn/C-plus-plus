#include<iostream>

using namespace std;

int main(int argc ,char **argv)
{
   
    cout << "hello world\n";

    int num = 5;
    const char *name = "hello world";
    int age =6;
    char src[100];

    printf("%d,%s,%d\n",num,name,age);

    cout<<"num = "<<num<<""<<"name = "<< name <<"age = "<< age <<"\n";
    
    cin>>num;
    cin>>age;
    cin.getline(src,100);

    cout<<src<<endl;

    

    return 0;
}