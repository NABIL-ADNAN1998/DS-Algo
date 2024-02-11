#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node *next;

    node(int v)
    {
        value = v;
        next = NULL;
    }
};

void insert_at_head(node *&head, int v)
{

    node *x = new node(v);

    x->next = head;

    head = x;
}

void insert_at_tail(node *&tail, int value)
{
    // cout << tail->value << endl;
    node *x = new node(value);
    tail->next = x;
    tail = x;
}

void insert_at_any_pos(node *&head, int pos, int value)
{

    node *x = new node(value);
    node *temp = head;

    for (int count = 2; count < pos; count++)
    {
        temp = temp->next;
    }

    x->next = temp->next;
    temp->next = x;
}

void delete_at_head(node *&head)
{
    node *temp = head;
    temp = temp->next;
    head = temp;
}

void delete_at_tail(node *&head)
{
    node *temp = head;
    int s = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        s++;
    }

    int count = 1;
    temp = head;
    while (count < (s - 1))
    {
        temp = temp->next;
        count++;
    }

    temp->next = NULL;
}

void delete_node_at_any_pos(node *&head, int pos)
{
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    temp->next = temp->next->next;
}

int main()
{
    node *head = new node(10);
    node *tail;

    node *a = new node(20);
    node *b = new node(30);
    node *c = new node(40);
    node *d = new node(50);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    // make tail
    node *temp = head;
    while (1)
    {
        if (temp->next == NULL)
        {
            tail = temp;
            break;
        }
        temp = temp->next;
    }

    // cout << tail->value << endl;

    insert_at_head(head, 5);

    insert_at_tail(tail, 100);

    insert_at_any_pos(head, 3, 200);

    delete_node_at_any_pos(head, 3);

    delete_at_tail(head);

    delete_at_head(head);

    // cout << tail->value << endl;

    node *t = head;
    while (1)
    {
        cout << t->value << " ";
        t = t->next;
    }
}