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

node* merge(node* &head1, node* &head2)
{
    node* p1 = head1;
    node* p2 = head2;
    node* dummy = new node(-1);
    node* p3 = dummy;

    while(p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }

        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        
        p3 = p3->next;
    }

    while(p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

     while(p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummy->next;
}

int main()
{
    node* head1 = NULL;
    node* head2 = NULL;

    int a1[] = {1,4,5,7};
    int a2[] = {2,6,8};

    for (int i = 0; i < (sizeof(a1)/sizeof(a1[0])); i++)
    {
        insert_at_tail(head1, a1[i]);
    }
    for (int i = 0; i < (sizeof(a2)/sizeof(a2[0])); i++)
    {
        insert_at_tail(head2, a2[i]);
    }

    display(head1);
    display(head2);

    node* new_head = merge(head1, head2);

    display(new_head);

    return 0;
}