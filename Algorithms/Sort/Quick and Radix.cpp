#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

// Quick Sort
void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        // making the partitions
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[low])
        {
            swap(arr[mid], arr[low]);
        }
        if (arr[high] < arr[low])
        {
            swap(arr[high], arr[low]);
        }
        if (arr[high] < arr[mid])
        {
            swap(arr[high], arr[mid]);
        }
        swap(arr[mid], arr[high]); //assigning the pivot

        int pivot = arr[high];
        int b = low - 1;

        // array navigation
        for (int i = low; i < high; i++)
        {
            if (arr[i] <= pivot)
            {
                b++;
                swap(arr[b], arr[i]);
            }
        }

        swap(arr[b + 1], arr[high]);
        int pivotIndex = b + 1;

        // Quick Sort for the left side
        quickSort(arr, low, pivotIndex - 1);
        // QuickSort for the Right side
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Radix Sort
void countingSortByByte(vector<int> &arr, int exp)
{
    const int BASE = 256;
    int n = arr.size();
    vector<int> output(n);
    vector<int> count(BASE, 0);

    // Counting
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % BASE;
        count[digit]++;
    }
    for (int i = 1; i < BASE; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % BASE;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }

    int maxVal = *max_element(arr.begin(), arr.end());
    
    for (int exp = 1; maxVal / exp > 0; exp *= 256)
    {
        countingSortByByte(arr, exp);
    }
}

// Hybrid part
int countDigits(int num)
{
    if (num == 0)
    {
        return 1;
    }

    int digits = 0;
    
    while (num > 0)
    {
        digits++;
        num /= 10;
    
    }
    return digits;
}

// ceriteria for Radix Sort
bool shouldUseRadix(const vector<int> &arr, int thresholdSize = 100, int thresholdDigits = 4)
{
    if (arr.empty())
    {
        return false;
    }

    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());
    int digits = countDigits(maxVal);

    return (n < thresholdSize) || (digits < thresholdDigits);
}

void hybridSort(vector<int> &arr)
{
    if (arr.empty())
    {
        return;
    }
    if (shouldUseRadix(arr))
    {
        cout << "Radix Sort has been choose" << endl;
        radixSort(arr);
    }
    else
    {
        cout << "Quick Sort has been choose" << endl;
        quickSort(arr, 0, arr.size() - 1);
    }
}

// a function to print the array
void printArray(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

// main function to test the program
int main()
{
    vector<int> arr1 = {25, 17, 8, 42, 17, 3, 19, 8, 33};

    cout << "array before sort " << endl;
    printArray(arr1);

    // sort using the Quick sort algorithm
    vector<int> arrQS = arr1;
    quickSort(arrQS, 0, arrQS.size() - 1);
    cout << endl << "Quick Sort: " << endl;
    printArray(arrQS);

    // sort using the Radix Sort algorithm
    vector<int> arrRS = arr1;
    radixSort(arrRS);
    cout << "Radix Sort: " << endl;
    printArray(arrRS);

    // hybrid
    vector<int> arrHybrid = arr1;
    cout << endl << "Hybrid Sort: " << endl;
    hybridSort(arrHybrid);
    cout << "Result: " << endl;
    printArray(arrHybrid);

    // test with a bigger array to show the Quick Sort advantage
    vector<int> arrLarge = {1000, 999, 888, 777, 666, 555, 444, 333, 222, 111, 0, 12345, 98765, 54321};
    cout << endl << "the bigger array: " << endl;
    printArray(arrLarge);
    hybridSort(arrLarge);
    cout << "result: " << endl;
    printArray(arrLarge);

    return 0;
}