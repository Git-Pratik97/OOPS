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
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

node* merge_rec(node* &head1, node* &head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    node* result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = merge_rec(head1->next, head2);
    }

    else
    {
        result = head2;
        result->next = merge_rec(head1, head2->next);
    }

    return result;
}


int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    int a1[] = {1,4,7,9};
    int a2[] = {2,3,6,8};

    for(int i = 0; i < (sizeof(a1)/sizeof(a1[0])); i++)
    {
        insert_at_tail(head1, a1[i]);
    }
    
    for(int i = 0; i < (sizeof(a2)/sizeof(a2[0])); i++)
    {
        insert_at_tail(head2, a2[i]);
    }

    display(head1);
    display(head2);

    node* result = merge_rec(head1, head2);

    display(result);

    return 0;
}