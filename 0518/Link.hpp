#pragma once
#include<iostream>
using namespace std;
class Link
{
public:
    struct Node
    {
        int m_num;
        Node *next;

        Node(int num):m_num(num),next(nullptr)
        {

        }
    };
    Link(): head(nullptr)
    {

    }

    bool empty()
    {
        return head = nullptr;
    }
    void insert_head(Node *newNode)
    {
        newNode->next = head;
        head = newNode;

    }
    void insert_tall(Node *newNode)
    {
        if(head == nullptr)
        {
            head =newNode;
            newNode->next =nullptr;
        }
        else
        {
            Node *temp = head;
            while(temp!= nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;

        }
      
    }

    bool insert_mid(int num,Node *newNode)
    {
        Node *temp = head;
        while(temp!= nullptr)
        {
            if(temp->m_num == num)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                return true;
            }
            temp = temp->next;
        } 
        return false;
    }
    bool delete_node(Node *node)
    {
        if(head == nullptr)
        {
            return false;
        }
        if(head->m_num == node->m_num)
        {
            Node *temp =head;
            head = head->next;
            delete temp;
            return true;
        }
        Node *p =head;
        Node *n =head->next;

        while(n!=nullptr)
        {
            if(n->m_num == node->m_num)
            {
                p->next = n->next;
                delete n;
                n = nullptr;
                return true;
            }
            p = n;
            n= n->next;
        }
        return false;
    }
    void display()
    {
        if(head == nullptr)
        {

        }
        else{
            Node *temp = head;
            while(temp !=nullptr)
            {
                cout<<temp->m_num<<endl;


            }
        }
    }
private:
    Node *head
};