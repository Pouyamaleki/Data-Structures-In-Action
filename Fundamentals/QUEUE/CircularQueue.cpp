#include <iostream>
#include <vector>
using namespace std;

class CircularQueue
{
private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;
    int count;

public:
    // Constructor
    CircularQueue(int k)
    {
        capacity = k;
        arr.resize(k);
        front = 0;
        rear = -1;
        count = 0;
    }

    // add a member to the end of the Queue
    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }

        // rear move forward
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;

        return true;
    }

    // remove a member from the begining of the Queue
    bool deQueue()
    {
        if (isEmpty())
        {
            return false;
        }

        // front move forward
        front = (front + 1) % capacity;
        count--;

        return true;
    }

    // a Function to show the first member of the Queue (front)
    int Front()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[front];
    }

    // a Function to show the last member (rear)
    int Rear()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[rear];
    }

    // a Function to check if the Queue if empty or no
    bool isEmpty()
    {
        return count == 0;
    }

    // a Function to check if the Queue is full or no
    bool isFull()
    {
        return count == capacity;
    }

    // a Function to show the Queue
    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is empty!!!!" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = 0; i < count; i++)
        {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
        cout << "front: " << front << endl;
        cout << "rear: " << rear << endl;
        cout << "count: " << count << endl;
        cout << "capacity: " << capacity << endl;
        cout << endl;
    }
};

// Main Function

int main()
{

    CircularQueue cq(5);

    cout << "Circular Queue test:" << endl;
    ;

    cout << "Is the Queue empty? " << endl;
    cout << (cq.isEmpty() ? "Yes" : "No") << endl;
    cout << endl;

    // add a member to the Queue
    cq.enQueue(10);
    cq.enQueue(20);
    cq.enQueue(30);
    cq.enQueue(40);

    // display the Queue
    cq.display();

    // front and rear test
    cq.Front();
    cq.Rear();

    // remove a member
    cq.deQueue();
    cq.deQueue();
    cq.display();

    // add new members
    cq.enQueue(50);
    cq.enQueue(60);
    cq.enQueue(70);
    cq.enQueue(80);
    cq.display();

    // test isfull
    cq.isFull();

    // add member to a full Queue
    cq.enQueue(90);

    // empty the Queue
    while (!cq.isEmpty())
    {
        cout << "Removed: " << cq.Front() << endl;
        cq.deQueue();
    }
    cout << endl;

    // test front and rear in a empty Queue
    cout << "Front: " << cq.Front() << endl;
    cout << "Rear: " << cq.Rear() << endl;
    cout << endl;
    cout << "Is the Queue empty? " << endl;
    cout << (cq.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}