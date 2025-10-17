#include <iostream>
using namespace std;

// Comment #1: Define constants
const int MIN_NR = 10,
    MAX_NR = 99,
    MIN_LS = 5,
    MAX_LS = 20;

class DoublyLinkedList 
{
    // Comment #2: Define Node structure containing data as integer and previous and next pointer to the node.
    private: struct Node 
    {
        int data;
        Node * prev;
        Node * next;

        // Comment #2: Constructor to initialize the private members.
        Node(int val, Node * p = nullptr, Node * n = nullptr) 
        {
            data = val;
            prev = p;
            next = n;
        }
    };

    // Comment #2: Define private members. Head points to the beginning of doubly linked list and tail points to the last node.
    Node * head;
    Node * tail;

    void every_other_element()
    {
        Node * current = head;
        if (!current) 
        {
            cout << "List is empty." << endl;
            return;
        }

        while (current) 
        {
            cout << current -> data << " ";
            current = current -> next;
        }

        cout << endl;
    }

    // Comment #2: Public constructor to initialize the private members.
    public: DoublyLinkedList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    void insert_after(int value, int position) 
    {
        // Comment #2: If position to insert is less than 0, then print message and do not insert node.
        if (position < 0) 
        {
            cout << "Position must be >= 0." << endl;
            return;
        }

        // Comment #2: Create a node initialzed with the given value.
        Node * newNode = new Node(value);

        // Comment #2: If the head is null, that means the list is empty. Hence, set both head and tail pointers to the new node.
        if (!head) 
        {
            head = tail = newNode;
            return;
        }

        // Comment #2: Since list is not empty, search for position.
        Node * temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp -> next;

        // Comment #2: If position exceeds list size, delete new node and do not insert.
        if (!temp) 
        {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        // Comment #2: Found the position and insert the Node there.
        newNode -> next = temp -> next;
        newNode -> prev = temp;
        if (temp -> next)
            temp -> next -> prev = newNode;
        else
            // Comment #2: If temp is the last node, then make new Node as the last by setting tail pointer to it.
            tail = newNode;

        temp -> next = newNode;
    }

    void delete_val(int value) 
    {
        // Comment #2: If list is empty then exit without deleting any Node.
        if (!head) return;

        // Comment #2: The list is not empty, so search for matching value in the lsit.
        Node * temp = head;
        while (temp && temp -> data != value)
            temp = temp -> next;

        // Comment #2: If node with matching value not found, then return without deleting any node.
        if (!temp) return;

        // Comment #2: If node found, then delete the node either from the front, middle, or back.
        if (temp -> prev)
            temp -> prev -> next = temp -> next;
        else
            head = temp -> next;
        if (temp -> next)
            temp -> next -> prev = temp -> prev;
        else
            tail = temp -> prev;
        delete temp;
    }

    void delete_pos(int pos) 
    {
        // Comment #2: If list is empty, then exit without deleting node by position.
        if (!head) 
        {
            cout << "List is empty." << endl;
            return;
        }

        // Comment #2: If position is 1, then delete the node from the front.
        if (pos == 1) 
        {
            pop_front();
            return;
        }

        // Comment #2: Checking whether to delete from the middle or end.
        Node * temp = head;
        for (int i = 1; i < pos; i++) 
        {
            // Comment #2: If position dooes nto exist, then exit without deleting any node.
            if (!temp) 
            {
                cout << "Position doesn't exist." << endl;
                return;
            } 
            else
                temp = temp -> next;
        }

        if (!temp) 
        {
            cout << "Position doesn't exist." << endl;
            return;
        }

        // Comment #2: Position found, so check whether it is the last node or not.
        if (!temp -> next) 
        {
            // Comment #2: Delete last node.
            pop_back();
            return;
        }

        // Comment #2: Delete the middle node (it is not the front or the last).
        Node * tempPrev = temp -> prev;
        tempPrev -> next = temp -> next;
        temp -> next -> prev = tempPrev;

        delete temp;
    }

    void push_back(int v) 
    {
        // Comment #2: Create a node.
        Node * newNode = new Node(v);
        // Comment #2: If the list is empty, then set head and tail both to the new Node.
        if (!tail)
            head = tail = newNode;
        else 
        {
            // Comment #2: Otherwise, add new Node to the end of the list.
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
    }

    void push_front(int v) 
    {
        Node * newNode = new Node(v);
        if (!head)
            head = tail = newNode;
        else 
        {
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }

    void pop_front() 
    {
        if (!head) 
        {
            cout << "List is empty." << endl;
            return;
        }

        Node * temp = head;
        if (head -> next) 
        {
            head = head -> next;
            head -> prev = nullptr;
        } 
        else
            head = tail = nullptr;

        delete temp;
    }

    void pop_back() 
    {
        if (!tail) 
        {
            cout << "List is empty." << endl;
            return;
        }
        Node * temp = tail;
        if (tail -> prev) 
        {
            tail = tail -> prev;
            tail -> next = nullptr;
        } 
        else
            head = tail = nullptr;

        delete temp;
    }
    
    ~DoublyLinkedList() 
    {
        while (head) 
        {
            Node * temp = head;
            head = head -> next;
            delete temp;
        }
    }

    void print() 
    {
        Node * current = head;
        if (!current) 
        {
            cout << "List is empty." << endl;
            return;
        }

        while (current) 
        {
            cout << current -> data << " ";
            current = current -> next;
        }

        cout << endl;
    }

    void print_reverse() 
    {
        Node * current = tail;
        if (!current) 
        {
            cout << "List is empty." << endl;
            return;
        }

        while (current) 
        {
            cout << current -> data << " ";
            current = current -> prev;
        }

        cout << endl;
    }
};

int main() 
{
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning

    return 0; 
}