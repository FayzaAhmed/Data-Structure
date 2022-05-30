#include <iostream>
using namespace std;
template <class T>
//STL list implementation
class List
{
private:
    struct Node
    {
        T data;
        Node* next;
    };
    Node* head;
    Node* tail;
    Node* dummy;    //the node after the tail node
    int length;    // tells me how many nodes are there in the list

public:
    List()  //default constructor
    {
        length = 0;
        Node* dummyNode = new Node;
        head = tail = dummyNode;
        dummy = dummyNode;
        dummy->next = nullptr;

    }

    List(T value, int initial_size)  // constructs a list having initial_size elements whose values are value <parametrized constructor>
    {
        length = initial_size;
        Node* newNode = new Node;
        newNode->data = value;

        head = tail = newNode;
        Node* temp = head;

        for(int i = 1; i < initial_size; i++)
        {
               Node* newnode = new Node;
               newnode->data = value;
               temp->next = newnode;
               temp = tail = temp->next;
               newnode->next = nullptr;
        }

         Node* dummyNode = new Node;
         tail->next = dummyNode;
         dummy = dummyNode;
    }

    int Size()     //returns the current number of elements in the list
    {
        return length;
    }

    void addFirst(T element)
    {
        Node* newnode = new Node;
        newnode->data = element;

        if(length == 0)
        {
           head = tail = newnode;
           newnode->next = dummy;
        }
        else
        {
           newnode->next = head;
           head = newnode;
        }
        length++;
    }

    void addLast(T element)
    {
        Node* newnode = new Node;
        newnode->data = element;
        if(length==0)
        {
            head = tail = newnode;
            newnode->next = dummy;
        }
        else
        {
         tail->next = newnode;
         tail = newnode;
         newnode->next = dummy;
        }
        length++;
    }

    Node* getPrevious(Node* target)  //takes a node and returns its previous node
    {
        Node* current = head;
        while(current != tail)
        {
            if(current->next == target)
                return current;
            current = current->next;
        }
        return nullptr;
    }

    void removeFirst()
    {
        if (length == 1)
        {
           head = tail = dummy;
           delete head;
           length--;
        }
        else
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    void Clear()
    {
        Node* temp = head;
        while(temp != dummy)
        {
            removeFirst();
            temp = temp->next;
        }
    }
class Iterator;
//*************************************************************************************
//*************************************************************************************
class Iterator           //inner class is like a friend, it can only access the outer class through an object only
{
     private:
            Node* current;
            List<T>* obj;        //that's why i created that object
     public:
        Iterator(List<T> &obj)
        {
            this->obj = obj;
            current = this->obj->head;
        }

        Iterator(Node* node)
        {
            current = node;
        }

        void operator= (Node* node)
        {
            this->current = node;
        }

        bool operator== (Node* node) // comparing iterator with a node
        {
            return current == node;
        }

        void operator++ ()          // ++ Prefix
        {
            current = current->next;
            if(current == obj->dummy)
                 throw "Exception: It's pointing after the last element!";
        }

        Node* operator++ (int)       // Postfix ++
        {
            Node* temp = current;
            current = current->next;
            if(current == obj->dummy)
                throw "Exception: It's pointing after the last element!";

            return temp;
        }

        void operator-- ()
        {
            Node* prev = obj->getPrevious(current);
            current = prev;
            if(current == obj->head)
                throw "Exception: It's pointing to the first element of the list!";
        }

        T& operator* ()    //dereference operator
        {
            return current->data;
        }

        bool operator == (const Iterator &other)  //comparing iterator with iterator
        {
            return current == other.current;
        }
        friend class List<T>;
    };
//************************************************************************************
//************************************************************************************

    void insertAtPos(int pos , T element)
    {
        if (pos == 0)
            addFirst(element);
        else if (pos == length)
            addLast(element);
        else
        {
            Node* newnode = new Node;
            newnode->data = element;

            Node* temp = head;
            for(int i =1; i<pos; i++)
                temp = temp->next;

            newnode->next = temp->next;
            temp->next = newnode;
            length++;
        }
    }

    void Insert(T value, Iterator position)  //adds an element at position specified by the iterator
    {
        int place = -1;                     //this variable is the position of the node that the iterator points to
        Node* temp = head;
        while(temp != dummy)
        {
            if( position == temp)            // I overloaded the operator== (in the iterator class) to be able to compare between an iterator and a node
            {
                place++;
                break;
            }
            place++;
            temp = temp->next;
        }
        insertAtPos(place,value);
    }


    void removeLast()
    {
        if (length == 1)
        {
           head = tail = dummy;
           delete tail;
           delete head;
           length--;
        }
        else
        {
            Node* previous = getPrevious(tail);
            delete tail;
            previous->next = dummy;
            tail = previous;
            length--;
        }
    }

    Iterator Erase(Iterator position)  // erases the element specified by the iterator and return an iterator to the next element
    {
        if(position== head)
        {
                removeFirst();  //this function has inside of it the step of ( head = head->next )
                return  head;   // that's why i just type return head
        }
        else if (position == tail)
        {
                removeLast();
                return nullptr;
        }
        else if (position == dummy)
        {
            throw "sorry can't point after the last element!";
        }
        else
        {
          Node* temp = head;
          while(temp != dummy)
              {
                if(position == temp)
                {   Node* previous = getPrevious(temp);
                    previous->next = temp->next;
                    delete temp;
                    return previous->next;
                }
                temp = temp->next;
              }
            return nullptr;
        }
    }


    List<T>& operator= (List<T> &another_list) // overloads the assignment operator to deep copy a list into another list and return the current list by reference.
    {
        if(length!=0)  //empty the list if it's already has numbers inside it
            Clear();

        Node* temp = head;                         //pointer to traverse the empty list
        Node* another_temp = another_list.head;   //pointer to traverse the full list

        for(int i = 0; i<another_list.length; i++)
        {
            addLast(another_temp->data);
            another_temp = another_temp->next;
            if(length == 1)
               temp = head;
            else
                temp = temp->next;
        }
        return *this;
    }

    Iterator Begin()
    {
        Iterator it(head);
        it.obj = this;
        return it;                    //  or simply i can type (  Iterator(head)   )
    }

    Iterator End()
    {
        Iterator it(dummy);
        it.obj = this;
        return it;      //the constructor that takes a node
    }

    bool exist(T deta)    //checks if a certain number exists in the list or not
    {
        bool flag=0;
        Node* temp = head;
        while(temp != dummy)
        {
            if(temp->data == deta)
            {
                 flag = 1;
                 break;
            }
            temp = temp->next;
        }
        return flag;
    }

    void Merge(List<T> &otherList)  //merges two sorted linked lists together + removing duplicates + without using an extra list
    {
        Node *otherPtr;
        for(otherPtr = otherList.head; otherPtr != otherList.dummy; )
        {
            if(exist(otherPtr->data))        //if there is a duplicate, skip
                    otherPtr = otherPtr->next;
            else
            {
                addLast(otherPtr->data);
                otherPtr = otherPtr->next;
            }
        }
    }

    void print()   //prints the content of the list
    {
        Node* temp = head;
        while(temp != dummy)
        {
             cout<<temp->data<<" ";
             temp = temp->next;
        }
    }

    ~List()               //A destructor
    {
        Node* current = head;
        while(current != dummy)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};
int main()
{
    try
    {
        List<int> myList;
        myList.addLast(1);
        myList.addLast(2);
        myList.addLast(3);
        List<int>::Iterator it = myList.Begin();
        ++it; //iterator point at 2
        cout << *it << endl; //display the node that iterator point at --> 2
        it = myList.Erase(it); // now myList contain only 1, 3
        myList.print();
        cout<<endl;
    }
    catch(const char* text )
    {
        cout<<text<<endl;
    }

    List <int> mylist;
    mylist.addLast(2);
    mylist.addLast(3);
    mylist.addLast(4);

    List <int> mylist2;
    mylist2.addLast(5);
    mylist2.addLast(2);
    mylist2.addLast(7);

    mylist.Merge(mylist2);
    mylist.print();
    return 0;
}
