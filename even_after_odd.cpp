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
    if (head == NULL)
    {
        insert_at_head(head, val);
        return;
    }

    node* n = new node(val);
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


void even_after_odd(node* &head)
{
    node* odd = head;
    node* even = head->next;
    node* even_start = even;

    while(odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = even_start;
    if (odd->next == NULL)
    {
        even->next = NULL;
    }
}

int main()
{
    node* head = NULL;
    int arr[] = {1,2,3,4,5,6,7};
    for(int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        insert_at_tail(head, arr[i]);
    }

    display(head);

    even_after_odd(head);

    display(head);

    return 0;
}