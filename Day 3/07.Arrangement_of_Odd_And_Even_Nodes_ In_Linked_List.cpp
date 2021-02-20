#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *nxt;
    Node() {
        Node(0);
    }

    Node(int data)
    {
        this->data = data;
        this->nxt = NULL;
    }
};

void printList(Node * head) {
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->nxt;
    }
    cout << "\n";
}

int getSize(Node * head) {
    Node *ptr = head;
    int size = 0;
    while (ptr != NULL) {
        size++;
        ptr = ptr->nxt;
    }
    return size;
}

Node * rearrange(Node * head) {
    if (head == NULL || head->nxt == NULL) 
        return head;
    Node *ptr = head, *nxt = NULL, *prev = NULL;
    Node dummy;
    Node *even = &dummy;
    while (ptr != NULL) {
        prev = ptr;
        nxt = ptr->nxt;
        ptr->nxt = nxt->nxt;
        even->nxt = nxt;
        even = even->nxt;
        ptr = ptr->nxt;
    }
    prev->nxt = dummy.nxt;
    return head;    
}