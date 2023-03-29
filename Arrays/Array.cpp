#include <iostream>
using namespace std;
class arrayList
{
    int *arr;
    int maxSize;
    int length;

public:
    arrayList(int s)
    {
        if (s < 0)
            maxSize = 10;
        else
            maxSize = s;
        length = 0;
        arr = new int[maxSize];
    }
    bool isEmpty()
    {
        return length == 0;
    }
    bool isFull()
    {
        return length == maxSize;
    }
    int getSize()
    {
        return length;
    }
    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void insertAtPos(int pos, int element)
    {
        if (isFull())
            cout << "List Full!";
        else if (pos < 0 || pos > length)
            cout << "Out Of Range!";
        else
            for (int i = length; i > pos; i--)
            {
                arr[i] = arr[i - 1];
            }
        arr[pos] = element;
        length++;
    }
    void removeAtPos(int pos)
    {
        if (isEmpty())
            cout << "List Empty!";
        else if (pos < 0 || pos > length)
            cout << "Out Of Range!";
        else
            for (int i = pos; i < length; i++)
            {
                arr[i] = arr[i + 1];
            }
        length--;
    }
    void insertAtEnd(int element)
    {
        if (isFull())
            cout << "The List Is Full!";
        else
            arr[length] = element;

        length++;
    }
    int search(int element)
    {
        for (int i = 0; i < length; i++)
        {
            if (arr[i] == element)
                return i;
        }
        return -1;
    }
    void insertNoDuplicate(int element)
    {
        if (search(element) == 1)
            insertAtEnd(element);
        else
            cout << "The Element Is There!";
    }
    void updateAt(int pos, int element)
    {
        if (pos < 0 || pos >= length)
            cout << "Out Of Range";
        else
            arr[pos] = element;
    }
    int getElement(int pos)
    {
        if (pos < 0 || pos >= length)
            cout << "Out Of Range";
        else
            return arr[pos];
    }
    ~arrayList()
    {
        delete[] arr;
    }
};
int main()
{
    arrayList ar(100);
    ar.insertAtPos(0, 10);
    ar.insertAtPos(1, 20);
    ar.insertAtEnd(30);
    ar.insertNoDuplicate(30);
    ar.updateAt(0, 5);
    cout << ar.getElement(1);
    cout << ar.getSize();
    ar.print();
}