#include <iostream>
using namespace std;
class LinkedList
{
    struct Node
    {
        int item;
        Node *next;
    };

private:
    Node *first;
    Node *last;
    int length;

public:
    LinkedList()
    {
        first = last = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void insertFirst(int element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = first;
            first = newNode;
        }
        length++;
    }
    void deleteFirst()
    {
        if (length == 0)
            return;
        else if (length == 1)
        {
            delete (first);
            first = last = NULL;
            length--;
        }
        else
        {
            Node *temp = first;
            first = first->next;
            delete temp;
            length--;
        }
    }
    void insertLast(int element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else
        {
            last->next = newNode;
            last = newNode;
            newNode->next = NULL;
        }
        length++;
    }
    void insertAtPosition(int pos, int element)
    {
        if (pos < 0 || pos > length)
            cout << "Out of Range";
        else
        {
            Node *newNode = new Node;
            newNode->item = element;
            if (pos == 0)
                insertFirst(element);
            else if (pos == length)
                insertLast(element);
            else
            {
                Node *Cur = first;
                for (int i = 1; i < pos; i++)
                {
                    Cur = Cur->next;
                }
                newNode->next = Cur->next;
                Cur->next = newNode;
                length++;
            }
        }
    }
    void print()
    {
        Node *Cur = first;
        while (Cur != NULL)
        {
            cout << Cur->item << " ";
            Cur = Cur->next;
        }
    }
    void delete_last()
    {
        Node *Cur = first;
        for (int i = 1; i < length - 1; i++)
        {
            Cur = Cur->next;
        }
        last = Cur;
        delete Cur->next;
        Cur->next = NULL;
        length--;
    }
};
int main()
{
    LinkedList l;
    l.insertFirst(10);
    l.insertLast(30);
    l.insertLast(40);
    l.insertAtPosition(1, 20);
    l.print();
    cout << endl;
    l.deleteFirst();
    l.delete_last();
    l.print();
}
