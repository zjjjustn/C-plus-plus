#pragma once
#include"Student.hpp"
#include"Link.hpp"

class StudentManger
{
public:
    StudentManger()
    {
        Link = new Link();

    }
    void add_student(Student &stu);
    {
        
    }
    void delete_student(Student &stu);
    {

    }
private:
    Link *link;
}