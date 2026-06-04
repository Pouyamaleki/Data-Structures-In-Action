#include <iostream>

using namespace std;

// node structure
struct node
{
    int Number;
    node *next = nullptr;
};

int main()
{
    int n;
    cin >> n;

    if (!n)
    {
        cout << "True" << endl;
        return 0;
    }
    else if (n == 1)
    {
        cin >> n;
        cout << "True" << endl;
        return 0;
    }

    // allocate and assigning the head and the first node
    node *head;
    node *newnode = new node;
    cin >> newnode->Number;
    head = newnode;

    // allocate and assign the other nodes
    node *temp;
    temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        node *newnode = new node;
        cin >> newnode->Number;
        temp->next = newnode;
        temp = temp->next;
    }

    // Compare Step
    node *Rtemp;
    temp = head;

    for (int i = 0; i < n / 2; i++) // does not Compare the middle node
    {
        Rtemp = head;
        int counter = 0;
        while (counter < n - i - 1)
        {
            Rtemp = Rtemp->next;
            counter++;
        }

        if (temp->Number != Rtemp->Number)
        {
            cout << "False" << endl;
            return 0;
        }

        temp = temp->next;
    }

    cout << "True" << endl;

    // free the allocated memory
    temp = head;
    while(temp != nullptr)
    {
        head = head->next;
        delete temp;
        temp = head;
    }

    return 0;
}