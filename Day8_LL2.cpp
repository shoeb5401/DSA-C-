#include<iostream>
using namespace std;

class node
{
public:

    int data;
    node *next;

    node()
    {
        next = NULL;
    }
};

class LinkedList
{
    node *head;

public :
    LinkedList()
    {
        head = NULL;
    }

    void print()
    {
        if(head == NULL)
            cout<<"List is Empty";
        else
        {
            node *temp = head;
            while(temp != NULL)
            {
                cout<<temp->data<<" -> ";
                temp = temp->next;
            }
        }
    }

    void insert_at_beg(int value)
    {
        node *temp = new node();
        temp->data = value;
        temp->next = head;
        head = temp;
    }

    void insert_at_end(int value)
    {
        node *temp = new node();
        temp-> data = value;
        if(head == NULL)
        {
            head = temp;
        }
        else{
         node *t = head;
          while(t->next != NULL)
            t = t->next;
          t->next = temp;
        }
    }
    void insert_at_position(int value, int position)
    {
        node *temp = new node();
        temp->data = value;
        if(position == 1)
        {
            temp->next = head;
            head = temp;
        }
        else{
            node *t = head;

            while(((position-2) != 0)&& (t->next != NULL))
            {
                  t = t->next;
                  position--;
            }

            temp->next = t->next;
            t->next = temp;
        }
    }
    void delete_at_beg()
    {
        if(head == NULL)
        {
            cout<<"Deletion not possible";
        }
        else
        {
            node *temp = head;
            head = head->next;
            delete(temp);
        }
    }

    void delete_at_end()
    {
        if(head== NULL)
            cout<<"list is empty";
        else if(head->next == NULL)
        {
            delete(head);
            head = NULL;
        }
        else
        {
            node *t = head;
            while(t->next->next != NULL)
                t = t->next;

            delete(t->next);
            t->next = NULL;
        }
    }

    void delete_at_position(int pos)
    {
        if(head == NULL)
            cout<<"Not possible";
        else if(pos == 1)
        {
            node *t = head;
            head = head->next;
            delete(t);
        }
        else
        {
            node *t = head;
             while(((pos-2) != 0)&& (t->next != NULL))
             {
                 t = t->next;
                 pos--;
             }
             node *temp = t->next;
             t->next = temp->next;
             delete(temp);
        }

    }

};


int main()
{
    LinkedList ll;
    ll.insert_at_beg(10);
    ll.insert_at_beg(20);
    ll.insert_at_beg(30);
    ll.insert_at_beg(40);
    ll.insert_at_beg(100);
    ll.insert_at_end(15);
    ll.insert_at_position(50 , 5);
    ll.delete_at_beg();
    ll.delete_at_end();
    ll.delete_at_position(3);
    ll.print();

    return 0;
}
