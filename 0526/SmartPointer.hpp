#pragma once
#include<iostream>
using namespace std;
template <typename T>
class SmartPointer
{
public:
    template <typename U>
    friend class SmartPointer;

    SmartPointer(): m_p(nullptr)
    {
        m_count = new long(0);

    }
    explicit SmartPointer(T *p)
    {
        if(p != nullptr)
        {
            m_p = p;
            m_count = new long(1);
        }
        else
        {
            m_p = nullptr;
            m_count = new long(0);
        }
    }

    template <typename U>
    SmartPoint(T *p,SmartPoint<U> &other)
    {
        if(p != nullptr)
        {
            m_p = other.m_p;
            m_count = other.m_count;
            (*m_count)++;
        }
        else
        {
            m_p = nullptr;
            m_count = other.m_count;
        }
    }

    SmartPoint(SmartPoint<T> &other)
    {
        if(other.m_p != nullptr)
        {
            m_p = other.m_p;
            m_count =other.m_count;
            (*m_count)++;
        }
        else
        {
            m_p = nullptr;
            m_count = other.m_count;
        }
    }
    SmartPoint<T> operator=(const SmartPoint<T> &other)
    {
        if(other.m_p != nullptr)
        {
            m_p = other.m_p;
            m_count = other.m_count;
            (*m_count)++;
        }
        else
        {
            m_p = nullptr;
            m_count = other.m_count;
        }
        return *this;
    }

    SmartPoint(SmartPoint<T> &&other)
    {
        if(other.m_p != nullptr)
        {
            m_p = other.m_p;
            other.m_p = nullptr;
            m_count = other.m_count;
            other.m_count = nullptr;
        }
        else
        {
            m_p = nullptr;
            m_count = other.m_count;
        }
    }

    ~SmartPointer()
    {
        
        if((m_p != nullptr) && (--(*m_count) == 0))
        {
            cout << "~SmartPointer"<< endl;
            delete m_p;
            delete m_count;
            
        }
        else
        {
            m_p = nullptr;
            m_count = nullptr;
        }       
         
    }
    long use_count() const
    {
        return *m_count;
    }

    T *get()
    {
        return m_p;
    }

    void reset()
    {
        m_p = nullptr;
        (*m_count)--;

    }

    void swap(SmartPoint<T> &other)
    {
        std::swap(m_p,other.m_p);
        std::swap(m_count,other.m_count);
    }
    T operator*()
    {
        return *m_p;
    }
    T *operator->()
    {
        return m_p;
    }
    operator bool()
    {
        return m_p != nullptr;
    }

    T operator[](int index)
    {
        return m_p[index];
    }

    template <typename T1,typename U1>
    friend SmartPointer<T1> static_pointer_cast(SmartPointer<U1> &other);

private:
    T *m_p;
    long *m_count;
};

template <typename T ,typename U>
SmartPointer<T> static_pointer_cast(SmartPointer<U> &other)
{
    T *temp = static_cast<T *>(other.m_p);
    return SmartPointer(temp,other);
}