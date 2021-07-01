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
        insert_at_head(head, val);
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

int length(node* head)
{
    int l = 0;
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
        l++;
    }
    return l;
}

node* append_k(node* head, int k)
{
    node* new_tail;
    node* tail = head;
    node* new_head;

    int l = length(head);
    k = k%l;
    int count = 1;
    
    while(tail->next != NULL)
    {
        if (count == l - k)
        {
            new_tail = tail;
        }
        
        if (count == l - k + 1)
        {
            new_head = tail;
        }

        tail = tail->next;
        count++;
    }

    new_tail->next = NULL;
    tail->next = head;

    return new_head;

}

int main()
{
    node* head = NULL;
    int arr[] = {1,2,3,4,5,6,7};
    for(int i = 0; i < 7; i++)
    {
        insert_at_tail(head, arr[i]);
    }
    display(head);

    node* new_head = append_k(head,3);
    display(new_head);

    return 0;
    
}