#include <iostream>

using namespace std;

template <typename QueueArray>
class MyQueue
{
private:
    QueueArray *arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    //Constructor
    MyQueue(int cap = 5)
    {
        capacity = cap;
        arr = new QueueArray[capacity];
        // in a empty Queue rear is always one less then front
        front = 0;
        rear = -1;
        size = 0;
    }

    //Destructor
    ~MyQueue()
    {
        delete[] arr;
    }

    // a Function to add member to the Queue
    void enqueue(QueueArray value)
    {
        if (size == capacity)
        {
            cout << "The Queue is full!!!!!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // a Function to delete member from the Queue
    QueueArray dequeue()
    {
        if (is_empty())
        {
            cout << "The Queue is Empty!!!" << endl;
            return QueueArray();
        }
        QueueArray value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    // a Function to show the front Location
    QueueArray get_front()
    {
        if (is_empty())
        {
            cout << "The Queue is empty!!!!" << endl;
            return QueueArray();
        }
        return arr[front];
    }

    // a Function to show the size of Queue
    int get_size()
    {
        return size;
    }

    // a Function to ckeck if the Queue is empty or no
    bool is_empty()
    {
        return size == 0;
    }

    // a Function to show the Queue members
    void show()
    {
        if (is_empty())
        {
            cout << "The Queue is empty!!!!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < size; i++)
        {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

// Main Function

int main()
{
    MyQueue<int> q;
    
    cout << "Simple Queue test: " << endl;

    // add 10, 20, 30 to a int Queue
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.show();
    
    //dequeue test
    cout << "Member " << q.dequeue() << " has been removed from the Queue" << endl;
    //show test (20,30)
    q.show();
    
    //add test
    q.enqueue(40);
    q.enqueue(50);
    //show (20, 30, 40, 50)
    q.show();
    
    cout << "Number of the Members: " << q.get_size() << endl;
    cout << "First Member (front): " << q.get_front() << endl;
    
    return 0;
}