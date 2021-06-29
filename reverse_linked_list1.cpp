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
    n->next = head;
    head = n;
}

void insert_at_tail(node* &head, int val)
{
    node* n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void delete_at_head(node* &head)
{
    node* del = head;
    head = head->next;
    delete del;
}

void deletion(node* &head, int val)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete_at_head(head);
        return;
    }

    node* temp = head;
    while(temp->next->data != val)
    {
        temp = temp->next;
    }

    node* del = temp->next;
    temp->next = temp->next->next;

    delete del;
}


node* reverse(node* &head)
{
    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    while(curr != NULL)
    {
        nextptr = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nextptr;
    }

    return prev;
}

int main()
{
    node* head = NULL;
    insert_at_tail(head, 1);
    insert_at_tail(head, 2);
    insert_at_tail(head, 3);
    insert_at_tail(head, 4);
    insert_at_tail(head, 5);
    // insert_at_head(head, 2);
    // insert_at_head(head, 3);

    display(head);

    // deletion(head, 4);
    // delete_at_head(head);
    node* reverse_head = reverse(head);
    display(reverse_head);



    return 0;
}