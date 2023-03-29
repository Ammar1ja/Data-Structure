#include <iostream>
using namespace std;
class LinkedList
{
    struct Node
    {
        int item;
        Node *next;
        Node *prev;
    };

private:
    Node *first, *last;
    int length;

public:
    LinkedList()
    {
        length = 0;
        first = last = NULL;
    }
    void insertFirst(int item)
    {
        Node *newNode = new Node();
        newNode->item = item;
        if (length == 0)
        {
            first = newNode;
            newNode->prev = newNode->next = newNode;
        }
        else
        {
            newNode->next = first;
            newNode->prev = first->prev;
            first->prev->next = newNode;
            first->prev = newNode;
            first = newNode;
            first = last = newNode;
        }
        length++;
    }
    void insertLast(int item)
    {
        Node *newNode = new Node();
        newNode->item = item;
        if (length == 0)
        {
            first = newNode;
            newNode->prev = newNode->next = newNode;
        }
        else
        {
            newNode->next = first;
            newNode->prev = first->prev;
            first->prev->next = newNode;
            first->prev = newNode;
        }
        length++;
    }
    void insertAtPosition(int pos, int item)
    {
        if (pos == 0)
        {
            insertFirst(item);
        }
        else if (pos == length)
        {
            insertLast(item);
        }
        else
        {
            Node *newNode = new Node();
            Node *curr = new Node();
            curr = first;
            newNode->item = item;
            for (int i = 1; i < pos - 1; i++)
            {
                curr->next;
            }
            curr->next->prev = newNode;
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next = newNode;
        }
        length++;
    }
    void removeFirst()
    {
        if (length == 0)
            cout << "List is Empty";
        else if (length == 1)
        {
            first = NULL;
            delete first;
            length--;
        }
        else
        {
            Node *curr = new Node();
            curr = first;
            first->prev->next = first->next;
            first->next->prev = first->prev;
            first = first->next;
            delete curr;
            length--;
        }
    }
    void removeLast()
    {
        if (length == 0)
        {
            cout << "List is Empty";
        }
        else if (length == 1)
        {
            first = NULL;
            delete first;
            length--;
        }
        else
        {
            Node *curr = new Node();
            curr = first->prev;
            first->prev->prev->next = first;
            first->prev = first->prev->prev;
            delete curr;
            length--;
        }
    }
    void removeAtPosition(int pos)
    {
        if (pos == 1)
            removeFirst();
        else if (pos == length)
            removeLast();
        else
        {
            Node *curr = first;
            for (int i = 1; i < pos - 1; ++i)
            {
                curr = curr->next;
            }
            curr->next->next->prev = curr;
            curr->next = curr->next->next;
            length--;
        }
    }
    void reverse()
    {
        Node *curr = first->prev;
        for (int i = length; i >= 1; i--)
        {
            cout << curr->item + " ";
            curr = curr->prev;
        }
    }
    void search(int item)
    {
        int c = 1;
        Node *curr = first;
        for (int i = 1; i <= length; ++i)
        {
            if (item == curr->item)
            {
                cout << "Yes : " << i;
                c = 0;
                break;
            }
            curr = curr->next;
        }
        if (c != 0)
            cout << "Not Found";
    }
    void print()
    {
        Node *node = new Node();
        node = first;
        for (int i = 1; i <= length; ++i)
        {
            cout << node->item << " ";
            node = node->next;
        }
    }
};
int main()
{
    LinkedList l;
    l.insertFirst(30);
    l.insertFirst(20);
    l.insertFirst(10);
    l.search(30);
}
