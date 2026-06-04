#include <iostream>

using namespace std;

// node structure
struct node
{
    long long int Number;
    node *next = nullptr;
};

int main()
{
    node *head;
    int n = 0;
    cin >> n;

    if (n == 0)
    {
        return 0;
    }

    // define the first node and head
    node *newnode = new node;
    head = newnode;
    cin >> newnode->Number;

    // get the nodes
    node *temp = nullptr;
    temp = head;
    for (int i = 0; i < n - 1; i++)
    {
        node *newnode = new node;
        cin >> newnode->Number;
        temp->next = newnode;
        temp = temp->next;
    }
    temp = nullptr;

    int k = 0;
    cin >> k;

    if (k == 1 || k == 0 || k > n)
    {
        temp = head;
        if (temp != nullptr)
        {
            cout << temp->Number;
            temp = temp->next;
        }
        while (temp != nullptr)
        {
            cout << " " << temp->Number;
            temp = temp->next;
        }

        // free the allocated memory
        temp = head;
        while (temp != nullptr)
        {
            node *toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
        return 0;
    }

    // pointers to invert the list
    node *dummy = new node;
    node *current;
    node *previous;
    node *nextnode;
    node *groupstart;
    node *previousgroupend;

    dummy->next = head;
    current = head;
    previousgroupend = dummy;

    // navigate the whole list
    while (current != nullptr)
    {
        groupstart = current;

        int counter = 0;
        while (current != nullptr && counter < k)
        {
            current = current->next;
            counter++;
        }

        if (counter < k)
        {
            break;
        }

        // invert k nodes
        previous = nullptr;
        current = groupstart;
        nextnode = nullptr;

        for (int i = 0; i < k; i++)
        {
            nextnode = current->next;
            current->next = previous;
            previous = current;
            current = nextnode;
        }

        // connect to the previous group
        previousgroupend->next = previous;
        // connect to the next group
        groupstart->next = current;
        // update the pointers for the next group
        previousgroupend = groupstart;
    }

    // navigate and print every node
    temp = dummy->next;
    if (temp != nullptr)
    {
        cout << temp->Number;
        temp = temp->next;
    }
    while (temp != nullptr)
    {
        cout << " " << temp->Number;
        temp = temp->next;
    }

    // free the allocated memory
    temp = dummy->next;
    while (temp != nullptr)
    {
        node *toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
    delete dummy;

    return 0;
}