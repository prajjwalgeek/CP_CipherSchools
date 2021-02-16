#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *nxt;
    Node()
    {
        Node(0);
    }

    Node(int data)
    {
        this->data = data;
        this->nxt = NULL;
    }
};

void printList(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->nxt;
    }
    cout << "\n";
}

int getSize(Node *head)
{
    Node *ptr = head;
    int size = 0;
    while (ptr != NULL)
    {
        size++;
        ptr = ptr->nxt;
    }
    return size;
}

Node *findIntersectionHelper(Node *larger, Node *smaller, int difference)
{
    Node *ptr = larger, *qtr = smaller;
    for (int i = 0; i < difference; i++)
    {
        if (ptr == NULL)
            return NULL;
        ptr = ptr->nxt;
    }
    while (ptr != NULL && qtr != NULL)
    {
        if (ptr == qtr)
        {
            return ptr;
        }
        ptr = ptr->nxt;
        qtr = qtr->nxt;
    }
    return NULL;
}
Node *findIntersection(Node *a, Node *b)
{
    if (a == NULL || b == NULL)
    {
        return NULL;
    }
    int countA = getSize(a);
    int countB = getSize(b);
    int d = countA - countB;
    if (d >= 0)
    {
        return findIntersectionHelper(a, b, d);
    }
    else
    {
        return findIntersectionHelper(b, a, -1 * d);
    }
}

int main()
{
}