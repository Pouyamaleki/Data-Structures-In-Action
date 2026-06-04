#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaxHeap
{
private:
    vector<int> heap; // array to store heap elements

    // Helper functions to get indices
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    // Heapify Down: used for deletion and building heap from array
    void heapifyDown(int i)
    {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);
        int n = heap.size();

        if (left < n && heap[left] > heap[largest])
        {
            largest = left;
        }
        if (right < n && heap[right] > heap[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(heap[i], heap[largest]);
            heapifyDown(largest); // recursive call
        }
    }

    // Heapify Up: used for insertion
    void heapifyUp(int i)
    {
        while (i > 0 && heap[parent(i)] < heap[i])
        {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Constructor: takes an array and builds a max-heap
    MaxHeap(vector<int> &arr)
    {
        heap = arr;
        // Start from last non-leaf node up to root
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
        {
            heapifyDown(i);
        }
    }

    // Insert a new key into the heap
    void insert(int key)
    {
        heap.push_back(key);        // add at the end
        heapifyUp(heap.size() - 1); // fix the heap property
    }

    // Delete root (maximum element)
    void deleteMax()
    {
        if (heap.empty())
        {
            cout << "Heap is empty. Cannot delete.\n";
            return;
        }
        // Replace root with last element
        heap[0] = heap.back();
        heap.pop_back(); // remove last element
        heapifyDown(0);  // restore heap property
    }

    // Delete a specific value (if exists)
    void deleteValue(int value)
    {
        int index = -1;
        // Search for the value
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == value)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Value " << value << " not found in heap.\n";
            return;
        }

        // Replace with last element
        heap[index] = heap.back();
        heap.pop_back();

        // Fix heap: either heapifyUp or heapifyDown
        if (index < heap.size())
        {
            // Try to move up if larger than parent
            if (index > 0 && heap[parent(index)] < heap[index])
            {
                heapifyUp(index);
            }
            else
            {
                heapifyDown(index);
            }
        }
    }

    // Search for a value in the heap (linear search)
    bool search(int value)
    {
        for (int i = 0; i < heap.size(); i++)
        {
            if (heap[i] == value)
            {
                return true;
            }
        }
        return false;
    }

    // Find minimum element in max-heap (must scan all leaves)
    int findMin()
    {
        if (heap.empty())
        {
            cout << "Heap is empty." << endl;
            return INT_MIN;
        }
        int minVal = heap[0];
        // Minimum will be in leaves: from index n/2 to n-1
        for (int i = heap.size() / 2; i < heap.size(); i++)
        {
            if (heap[i] < minVal)
            {
                minVal = heap[i];
            }
        }
        return minVal;
    }

    // Print the heap (for tracing)
    void printHeap()
    {
        cout << "Heap: ";
        for (int val : heap)
        {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main()
{
    // Step 1: Create initial array and build Max-Heap
    vector<int> arr = {10, 4, 15, 1, 8, 20, 7, 12, 3, 18};
    cout << "Initial array: ";
    for (int v : arr)
    {
        cout << v << " ";
    }
    cout << endl;

    MaxHeap h(arr);
    cout << "Max-Heap built from array:\n";
    h.printHeap();

    // Step 2: Insert new elements
    cout << endl;
    cout << " Inserting 25 and 5" << endl;
    h.insert(25);
    h.insert(5);
    h.printHeap();

    // Step 3: Delete max (root)
    cout << endl;
    cout << " Deleting max (root)" << endl;
    h.deleteMax();
    h.printHeap();

    // Step 4: Search for values
    cout << endl;
    cout << " Searching" << endl;
    int searchVal = 12;
    cout << "Search " << searchVal << ": " << (h.search(searchVal) ? "Found" : "Not found") << endl;
    searchVal = 99;
    cout << "Search " << searchVal << ": " << (h.search(searchVal) ? "Found" : "Not found") << endl;

    // Step 5: Find minimum in Max-Heap
    cout << endl;
    cout << "Find Minimum in Max-Heap" << endl;
    cout << "Minimum element: " << h.findMin() << endl;

    // Step 6: Delete specific values
    cout << endl;
    cout << "Deleting value 15" << endl;
    h.deleteValue(15);
    h.printHeap();

    cout << endl;
    cout << "Deleting value 1" << endl;
    h.deleteValue(1);
    h.printHeap();

    // Final heap state
    cout << endl;
    cout << "Final heap: ";
    h.printHeap();

    return 0;
}