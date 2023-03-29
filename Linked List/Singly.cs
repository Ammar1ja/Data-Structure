using System.Xml.Linq;

internal class Program
{
    private static void Main(string[] args)
    {
        Node node = new Node();
        node.insertFirst(10);
        node.insertLast(50);
        Console.WriteLine(node.search(10));
        node.print();

    }
    class Node
    {
        private int data;
        private Node next;
        private Node first;
        private Node last;
        private int length;
        public Node()
        {
            first = last = null;
            length = 0;
        }
        public void setData(int d)
        {
            data = d;
        }
        public void setNext(Node next)
        {
            this.next = next;
        }
        public int getData()
        {
            return data;
        }
        public Node getNext()
        {
            return next;
        }
        bool isEmpty()
        {
            return length == 0;
        }
        public void insertFirst(int element)
        {
            Node newNode = new Node();
            newNode.setData(element);
            if (length == 0)
            {
                first = last = newNode;
                newNode.setNext(null);
            }
            else
            {
                newNode.setNext(first);
                first = newNode;
            }
            length++;
        }
        public void insertLast(int element)
        {
            Node newNode = new Node();
            newNode.data = element;
            if (length == 0)
            {
                first = last = null;
                newNode.next = null;
            }
            else
            {
                last.next = newNode;
                last = newNode;
                newNode.next = null;
            }
            length++;
        }
        public void insertAtPosition(int pos, int data)
        {
            if (pos < 0 || pos > length)
                Console.WriteLine("Out of Range");
            else
            {
                Node newNode = new Node();
                newNode.setData(data);
                if (pos == 0)
                    insertFirst(data);
                else if (pos == length)
                    insertLast(data);
                else
                {
                    Node Cur = first;
                    for (int i = 1; i < pos; i++)
                    {
                        Cur = Cur.next;
                    }
                    newNode.next = Cur.next;
                    Cur.next = newNode;
                    length++;
                }
            }
        }
        public void removeFirst() 
        {
            if (length == 0)
                return;
            else if (length == 1)
            {
                first = last = null;
                length--;
            }
            else 
            {
                first = first.getNext();
                length--;
            }
        }
        public void removeLast()
        {
            if (length == 0)
                return;
            else if (length == 1)
            {
                first = last = null;
                length--;
            }
            else
            {
                Node Curr = first.getNext();
                Node prev = first;
                while (Curr != last)
                {
                    prev = Curr;
                    Curr = Curr.getNext();
                }
               
                prev.setNext(null);
                last = prev;
                length--;
            }
        }
        public void remove(int item)
        {
            if (isEmpty())
            {
                Console.WriteLine("Can not remove from empty list\n");
                return;
            }

            Node current, trailCurrent;
            if (first.getData()== item) // delete the first element, special case
            {
                current = first;

                first = first.getNext();
                length--;
                if (length == 0)
                    last = null;
            }
            else
            {
                current = first.getNext();
                trailCurrent = first;
                while (current != null)
                {
                    if (current.getData() == item)
                        break;
                    trailCurrent = current;
                    current = current.getNext();
                }

                if (current == null)
                    Console.WriteLine("The item is not there\n"); 
                else
                {
                    trailCurrent.setNext(current.getNext());
                    if (last == current) // delete the last item
                        last = trailCurrent;
               
                    length--;
                }
            }
        }
        public void reverse() 
        {
            Node prev, curr, next;
            prev = null;
            curr = first;
            next = curr.getNext();
            while (next !=null) 
            {
                next=curr.getNext();
                curr.setNext(prev);
                // walk
                prev = curr;
                curr = next;
            }
            first = prev;
        }
        public int search(int item) 
        {
            Node curr = first;
            int pos = 0;
            while (curr!=null) 
            {
                if (curr.getData()==item) 
                {
                    return pos;
                    curr = curr.getNext();
                    pos += 1;
                }
            }
            return -1;
        }
        public void print()
        {
            Node node = first;
            while (node != null)
            {
                Console.Write(node.getData() + " ");
                node = node.getNext();
            }
        }
    }
}