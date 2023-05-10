#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    const volatile int MAX_LEN = 1024;
    //const int MAX_LEN = 1024;
    int *p = const_cast<int *>(&MAX_LEN);
    *p = 2048;

    cout << MAX_LEN << endl;

    return 0;
}