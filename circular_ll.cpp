#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insert_at_head(node* &head, int val)
{
    node* n = new node(val);
    node* temp = head;

    if(head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    while(temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insert_at_tail(node* &head, int val)
{
    if (head == NULL)
    {
        insert_at_head(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != head)
    {
        temp = temp->next;

    }

    temp->next = n;
    n->next = head;
}

void display(node* head)
{
    node* temp = head;

    do{
        cout << temp->data << "->";
        temp = temp->next;
    }while(temp != head);

    cout << "<-" << endl;
}

void delete_at_head(node* &head)
{
    node* temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    node* del = head;
    temp->next = head->next;
    head = head->next;

    delete del;

}

void delete_at_tail(node* &head, int pos)
{
    node* temp = head;
    int count = 1;

    if (pos == 1)
    {
        delete_at_head(head);
        return;
    }

    while(count != pos-1)
    {
        temp = temp->next;
        count++;
    }

    node* del = temp->next;
    temp->next = temp->next->next;

    delete del;
}

int main()
{
    node* head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    insert_at_head(head, 6);

    display(head);

    delete_at_tail(head, 3);
    display(head);

    delete_at_tail(head, 1);

    display(head);

    return 0;

}