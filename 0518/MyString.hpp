#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class MyString
{
public:
    MyString(): m_ptr(nullptr)
    {

    }
    MyString(const char *data)
    {
        if(data != nullptr)
        {
            int len = strlen(data)+1;
            m_ptr = new char[len];
            memcpy(m_ptr,data,len);
        }
        else
        {
            m_ptr = nullptr;
        }
    }
    MyString(const MyString &other)
    {
        if(other.m_ptr != nullptr)
        {
            int len = strlen(other.m_ptr)+1;
            m_ptr = new char[len];
            memcpy(m_ptr,other.m_ptr,len);
        }
        else
        {
            m_ptr = nullptr;
        }
    }

    MyString(MyString &&other)
    {
        this->m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    ~MyString()
    {
        if(m_ptr !=nullptr)
        {
            delete[] m_ptr;
        }
        m_ptr = nullptr;
    }


    const char * c_str() const
    {
        return m_ptr;
    }

    int size()
    {
        return strlen(m_ptr);
    }

    void append(MyString &other)
    {
        if(other.m_ptr != nullptr)
        {
            int len = strlen(m_ptr);
            char *temp = new char[len];
            strcat(temp,m_ptr);
            strcat(temp,other.m_ptr);
            delete[] m_ptr;
            m_ptr=new char[len];
            memcpy(m_ptr,temp,len);
            delete [] temp;
        }
    }
    

    char operator[](int index)
    {
        return m_ptr[index];
    }
    MyString &operator=(const MyString &other)
    {
        if(other.m_ptr != nullptr)
        {
            int len = strlen(other.m_ptr)+1;
            m_ptr = new char[len];
            memcpy(m_ptr,other.m_ptr,len);
        }
        else
        {
            m_ptr = nullptr;
        }
        return *this;

    }
    MyString &operator=(MyString &other)
    {

    }

    friend MyString& operator+(const MyString &s1,const MyString&s2);
    friend bool operator>(const MyString &s1,const MyString &s2);
    friend ostream& operator<<(ostream &out,const MyString &s);
    friend istream& operator>>(istream &in,MyString &s);


private:
    char *m_ptr;
}; 

ostream& operator<<(ostream &out,const MyString &s)
{
    out << "str = " << s.m_ptr;
    return out;
}

istream& operator>>(istream &in,MyString &s)
{
    delete [] s.m_ptr;
    s.m_ptr = new char[100];
    in >> s.m_ptr;
    return in;
}