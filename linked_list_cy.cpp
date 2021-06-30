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

bool detect_cycle(node* &head)
{
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

void make_cycle(node* &head, int pos)
{
    node* temp = head;
    node* starter;

    int count = 1;
    while(temp->next != NULL)
    {
        if (count == pos)
        {
            starter = temp;
        }
        
        temp = temp->next;
        count++;
    }

    temp->next = starter;
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

    make_cycle(head, 3);

    // display(head);

    cout << detect_cycle(head) <<endl;


    return 0;
}