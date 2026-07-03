#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Insertion Sort
void insertionSort(vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// merge sort
void merge(vector<int> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}

// Hybrid part
void hybridMergeSort(vector<int> &arr, int left, int right, int threshold = 10)
{
    if (right - left + 1 <= threshold)
    {
        insertionSort(arr, left, right);
        return;
    }
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        hybridMergeSort(arr, left, middle, threshold);
        hybridMergeSort(arr, middle + 1, right, threshold);

        merge(arr, left, middle, right);
    }
}

void printArray(const vector<int> &arr)
{
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {25, 17, 8, 42, 17, 3, 19, 8, 33};

    cout << "array befor the sort: " << endl;
    printArray(arr1);

    // insertion sort test
    vector<int> arrIS = arr1;
    insertionSort(arrIS, 0, arrIS.size() - 1);
    cout << endl << "Insertion Sort: " << endl;
    printArray(arrIS);

    // merge sort test
    vector<int> arrMS = arr1;
    mergeSort(arrMS, 0, arrMS.size() - 1);
    cout << "Merge Sort: " << endl;
    printArray(arrMS);

    // hybrid test
    cout << endl << "Hybrid Merge and Insertion Sorts: " << endl;

    // test with 3 threshold
    vector<int> arrHybrid1 = arr1;
    hybridMergeSort(arrHybrid1, 0, arrHybrid1.size() - 1, 3);
    cout << "3 threshold " << endl;
    printArray(arrHybrid1);

    // 10 threshold
    vector<int> arrHybrid2 = arr1;
    hybridMergeSort(arrHybrid2, 0, arrHybrid2.size() - 1, 10);
    cout << "10 threshold " << endl;
    printArray(arrHybrid2);

    // 20 threshold
    vector<int> arrHybrid3 = arr1;
    hybridMergeSort(arrHybrid3, 0, arrHybrid3.size() - 1, 20);
    cout << "20 threshold: " << endl;
    printArray(arrHybrid3);

    // test in a bigger array
    vector<int> arrLarge = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30,45, 55, 20, 88, 33, 44, 66, 10, 99, 7};
    cout << endl << "bigger array: " << endl;
    printArray(arrLarge);

    // merge sort
    vector<int> arrLargeMS = arrLarge;
    mergeSort(arrLargeMS, 0, arrLargeMS.size() - 1);
    cout << "Merge Sort: ";
    printArray(arrLargeMS);

    // Hybrid test
    vector<int> arrLargeHybrid = arrLarge;
    hybridMergeSort(arrLargeHybrid, 0, arrLargeHybrid.size() - 1, 5);
    cout << "Hybrid Sort: ";
    printArray(arrLargeHybrid);

    // insertion advantage
    vector<int> arrNearlySorted = {1, 2, 3, 5, 4, 6, 7, 8, 9, 10};
    cout << endl << "barly sorted array: ";
    printArray(arrNearlySorted);

    // hybrid test
    vector<int> arrNearlySortedHybrid = arrNearlySorted;
    hybridMergeSort(arrNearlySortedHybrid, 0, arrNearlySortedHybrid.size() - 1, 10);
    cout << "Hybrid test: ";
    printArray(arrNearlySortedHybrid);

    return 0;
}