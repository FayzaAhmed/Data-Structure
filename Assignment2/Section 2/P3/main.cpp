#include <iostream>
using namespace std;

template <class t>
class Queue
{
public:
    t* q;
    int qsize;
    Queue()
    {
        qsize=0;
        q=new t[100];
    }
    Queue(t value, int intial_size)
    {
        qsize=intial_size;
        q=new t[intial_size];
        for(int i=0; i<intial_size; i++)
        {
            q[i]=value;
        }
    }

    ~Queue()
    {
        delete []q;
    }
    t& front()//Returns the first element by reference.
    {
        return q[0];
    }

    void pop()//Removes the first element.


    {
        for(int i=0; i<qsize; i++)
        {
            q[i]=q[i+1];
            qsize--;
        }
    }
    void push(t value)// adds an element to the back of the queue.
    {
        q[qsize++]=value;
    }
    int size()//returns the number of elements in the queue.
    {
        return qsize;
    }
};

class Stack{
    Queue<int>obj;
public:
    int top()//Returns the top element.
    {
        return obj.front();
    }
    void pop() //removes the top element.
    {
       return obj.pop();
    }
    void push(int value)//adds an element to the top of the stack.
    {
        int size=obj.qsize;

        obj.push(value);

        for(int i=0;i<size;i++)
        {
            obj.push(obj.front());

            obj.pop();
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << s.top() << endl;
    s.pop();
    s.push(30);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
