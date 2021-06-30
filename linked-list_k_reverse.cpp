#include<iostream>

using namespace std;

class node
{
    public:
    int data;
    node* next;

    node(int val){
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

node* reverse_k(node* &head, int k)
{
    node* prev = NULL;
    node* curr = head;
    node* nextptr;

    int count = 0;
    while(curr != NULL && count < k)
    {
        nextptr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextptr;

        count++;
    }
    if (nextptr != NULL)
    {
        head->next = reverse_k(nextptr, k);
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
    insert_at_tail(head, 6);

    display(head);
    int k = 2;
    node* new_head = reverse_k(head, k);

    display(new_head);

    return 0;
}