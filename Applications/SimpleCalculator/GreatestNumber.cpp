#include <iostream>
#include <vector>
#include <string>

using namespace std;

// function to compare to string
bool isGreater(const string &a, const string &b)
{
    return (a + b) > (b + a);
}

// merge sort
void merge(vector<string> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<string> leftArr(n1);
    vector<string> rightArr(n2);

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
        if (isGreater(leftArr[i], rightArr[j]))
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

// merge sort recurtion
void mergeSort(vector<string> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int middle = left + (right - left) / 2;

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);

    merge(arr, left, middle, right);
}

// main function to tst the program
int main()
{
    // to make the input and output faster for the time limit
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr(n);
    bool allZero = true;

    // get the numbers
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] != "0")
        {
            allZero = false;
        }
    }

    // if all of the numbers are 0 the outcome will be 0 too
    if (allZero)
    {
        cout << 0 << endl;
        return 0;
    }

    // merge sort test
    mergeSort(arr, 0, n - 1);

    // comining the numbers
    string result = "";
    for (int i = 0; i < n; i++)
    {
        result += arr[i];
    }

    // if the first character is 0
    if (result[0] == '0')
    {
        cout << 0 << endl;
    }
    else
    {
        cout << result << endl;
    }

    return 0;
}