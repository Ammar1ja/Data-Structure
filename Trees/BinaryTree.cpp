#include <iostream>
using namespace std;
class Tree
{
    struct Node
    {
        int item;
        Tree *LC,*RC;
    };
    public:
        void insert(int item)
        {
            Node *newNode = new Node();
            newNode->item = item;
        }
};
int main()
{
    Tree *tree = new Tree();
    
}