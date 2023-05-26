#include<iostream>
#include<memory>
#include<vector>
#include"SmartPointer.hpp"

using namespace std;

class A
{
public:
    A()
    {
        cout << "A" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};

void test(unique_ptr<int> &p)
{

}

int my_delete(A *pa)
{
    cout << "my_delete" <<endl;
    delete[] pa;
}

void
{
    unique_ptr<int> pi(new int(5));
    //unique_ptr<int> pi2(pi); 禁止拷贝构造函数
    unique_ptr<int> pi3;
    //pi3 = pi; //=禁止

    unique_ptr<int> pi4 = std::make_unique<int>(5);

    cout << sizeof(pi) <<endl;
    cout << *pi << endl;

    // int *p = pi.get();
    // p++;

    //成员方法
    //pi = nullptr;
    pi.reset(new int(6));
    pi.reset();

    pi.release();

    pi.swap(pi4);

    //删除器
    shared_ptr<A> pa2(new A[5],my_delete);
    shared_ptr<A> pa3(new A[5],my_delete2);
    
    vector<shared_ptr<A>> va;
    va.push_back(pa2);

    unique_ptr<A,int(*)(A *)> pa(new A[5],my_delete);
    unique_ptr<A,void(*)(A *)> pa4(new A[5],my_delete2);

    vector<unique_ptr<A,int(*)(A *)>> va2;
    va2.push_back(std::move(pa));

}


int main(int argc,char **argv)
{
    SmartPointer<int> pi(new int(5));
    SmartPointer<int> pii(new )
    SmartPointer<int> pi2;
    SmartPointer<int> pi3(pi2);
    SmartPointer<int> pi4;

    return 0;
}