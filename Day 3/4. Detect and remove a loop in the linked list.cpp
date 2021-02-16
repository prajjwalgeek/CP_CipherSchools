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

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList()
    {
        this->head = NULL;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->nxt = head;
            head = newNode;
        }
    }

    void insertAtEnd(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->nxt != NULL)
            {
                ptr = ptr->nxt;
            }
            ptr->nxt = newNode;
        }
    }

    void printList()
    {
        Node *ptr = head;
        while (ptr != NULL)
        {
            cout << ptr->data << "->";
            ptr = ptr->nxt;
        }
        cout << "\n";
    }

    int getSize()
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

    bool detectLoop()
    {
        if (head == NULL || head->nxt == NULL)
        {
            return false;
        }
        Node *slow = head, *fast = head;
        while (slow != NULL && fast != NULL && fast->nxt != NULL)
        {
            slow = slow->nxt;
            fast = fast->nxt->nxt;
            if (slow == fast)
                return true;
        }
        return false;
    }

    void removeLoop()
    {
        if (head == NULL || head->nxt == NULL)
        {
            return;
        }
        Node *slow = head, *fast = head;
        bool loopPresent = false;
        while (slow != NULL && fast != NULL && fast->nxt != NULL)
        {
            slow = slow->nxt;
            fast = fast->nxt->nxt;
            if (slow == fast)
            {
                loopPresent = true;
                break;
            }
        }

        if (loopPresent)
        {
            slow = head;
            if (slow == fast)
            {
                while (fast->nxt != slow)
                {
                    fast = fast->nxt;
                }
            }
            else
            {
                while (slow->nxt != fast->nxt)
                {
                    slow = slow->nxt;
                    fast = fast->nxt;
                }
            }
            // Line removing the loop
            fast->nxt = NULL;
        }
    }
};

int main()
{
    SinglyLinkedList *sll = new SinglyLinkedList();
    sll->head = new Node(1);
    sll->head->nxt = new Node(2);
    sll->head->nxt->nxt = new Node(3);
    sll->head->nxt->nxt->nxt = new Node(4);
    sll->head->nxt->nxt->nxt->nxt = new Node(5);
    cout << sll->detectLoop() << "\n";
    sll->head->nxt->nxt->nxt->nxt->nxt = sll->head;
    cout << sll->detectLoop() << "\n";
    sll->removeLoop();
    cout << sll->detectLoop() << "\n";
    sll->head->nxt->nxt->nxt->nxt->nxt = sll->head->nxt;
    cout << sll->detectLoop() << "\n";
    sll->removeLoop();
    cout << sll->detectLoop() << "\n";
}