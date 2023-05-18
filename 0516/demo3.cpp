#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class Person
{
public:
    char *name_;
    Person(const char *name)
    {
        int len = strlen(name);
        name_ = new char[len + 1];
        strcpy(name_,name);
        std::cout << "类型转换构造函数" << endl;
    };

    Person(const Person &person)
    {
        if (this != &person)
        {
            int len = strlen(person.name_);
            name_ = new char[len + 1];
            strcpy(name_,person.name_);
            std::cout << "拷贝构造函数" << std::endl;
        }
    }

    Person(Person &&person) noexcept
    {

        name_ = person.name_;
        person.name_ = nullptr;
        std::cout << "移动构造函数" << std::endl;
    }

    Person &operator=(Person &person)
    {
        if (this == &person)
        {
            return *this;
        }
        int len = strlen(person.name_) + 1;
        name_ = new char[len + 1];
        strcpy(name_,person.name_);
        std::cout << "拷贝赋值运算符" << std::endl;
    }

    Person &operator=(Person &&person) noexcept
    {
        if (this != &person)
        {
            name_ = person.name_;
            std::cout << "移动赋值运算符" << std::endl;
        }
        return *this;
    }

    ~Person()
    {
        delete[] name_;
    std:
        cout << "析构函数" << endl;
    }
};

Person getPerson()
{
    Person person("person in func");
    return person;
}

int main(void)
{
    Person person1("xiaohong");
    Person person2("xiaoming");
    Person person3(getPerson());
    Person person4(std::move(person1)); //移动构造函数
    Person person5(person2);//拷贝构造函数

    Person person6("xiaolan");
    person6 = std::move(person3); //移动赋值运算
    Person person7("xiaoqi");
    person7 = Person("xiaoqi"); //移动赋值运算
     //person7 = getPerson();
    Person person8("xiaoba");
    person8 = person1; //拷贝赋值运算符

    return 0;
}

