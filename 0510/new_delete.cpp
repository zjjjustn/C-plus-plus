#include<iostream>
#include<stdlib.h>

using namespace std;

int main(int argc,char **argv)
{
    int *p = (int *)malloc(sizeof(int));
    free(p);

    //new delete
    int *p1 = new int;
    int *p2 = new int (5);
    cout<< *p2 << endl;
    int *p3 = new int[5];
    int *p4 = new int[5]{1,2,3,4,5};
    for(int i = 0;i<5;i++)
    {
        cout << p4[i]<<endl;
    }
    delete p1;
    delete p2;
    delete [] p3;
    delete [] p4;

    p1 = nullptr;

    //分配多维数组
    int *pa = new int[5];
    //二位数组名作用：指针常量，保存首个一维数组的地址
    int (*paa)[5] = new int[5][5];

    int **paaw = new int *[5];
    paaw[0] = new int[3];
    paaw[1] = new int[4];
    paaw[2] = new int[5];
    paaw[3] = new int[6];
    paaw[4] = new int[7];
    // for (int i = 0;i<5;i++)
    // {
    //     paaw[i] = new int[5];
    // }
    paaw[0][1] = 10;
    cout<< paaw[0][1]<<endl;

    delete[] paaw[0];
    delete pa;


    return 0;
}