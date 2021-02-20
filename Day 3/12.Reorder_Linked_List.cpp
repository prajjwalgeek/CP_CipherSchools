#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *nxt;
    Node() {
        Node(0);
    }

    Node(int data) {
        this->data = data;
        this->nxt = NULL;
    }
};

void printList(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->nxt;
    }
    cout << "\n";
}

int getSize(Node *head) {
    Node *ptr = head;
    int size = 0;
    while (ptr != NULL) {
        size++;
        ptr = ptr->nxt;
    }
    return size;
}

Node *cutInHalf(Node *head) {
    Node *slow = head, *fast = head;
    while (slow != NULL && fast != NULL && fast->nxt != NULL) {
        slow = slow->nxt;
        fast = fast->nxt->nxt;
    }
    Node *middle = slow->nxt;
    slow->nxt = NULL;
    return middle;
}

Node *reverse(Node *head) {
    if (head == NULL || head->nxt == NULL)
        return head;

    Node *curr = head, *nxt = NULL, *prev = NULL;
    while (curr != NULL) {
        nxt = curr->nxt;
        curr->nxt = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}

Node *alternativeMerge(Node *a, Node *b) {
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    else {
        Node *p, *q;
        while (a != NULL && b != NULL)
        {
            p = a->nxt;
            q = b->nxt;
            a->nxt = b;
            a = p;
            b->nxt = a;
            b = q;
        }
    }
}

Node *reorderLL(Node *head) {
    if (head == NULL || head->nxt == NULL) {
        return head;
    }
    // cut in half
    Node *second = cutInHalf(head);
    second = reverse(second);
    // alternate merge (*)
    return alternativeMerge(head, second);
}