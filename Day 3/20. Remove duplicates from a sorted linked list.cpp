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

void printList(Node * head) {
    Node *ptr = head;
    while (ptr != NULL) {
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

Node * removeDuplicateSortedLL(Node * head) {
    if (head == NULL || head->nxt == NULL)
        return head;
    Node * curr = head;
    Node * nxt = NULL;
    while (curr->nxt != NULL) {
        if (curr->data == curr->nxt->data) {
            nxt = curr->nxt;
            curr->nxt = nxt->nxt;
            delete nxt;
        } else {
            curr = curr->nxt;
        }
    }
    return head;

}

class SpecialNode {
    public:
    int data;
    Node *nxt;
    Node *random;
};

bool isPalindromeHelper(Node ** left, Node * right) {
    // Has the rigght pointer reached the end of LL or not?
    if (right == NULL) {
        return true;
    }
    bool isPalin = isPalindromeHelper(left, right->nxt);
    if (!isPalin) {
        return false;
    }

    bool dataEqual = ((*left)->data == right->data);
    (*left) = (*left)->nxt;
    return dataEqual;
}

bool isPalindrome(Node * head) {
    return isPalindromeHelper(&head, head);
}

int main()
{
}