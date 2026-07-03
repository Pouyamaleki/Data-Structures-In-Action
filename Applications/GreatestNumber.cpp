#include <iostream>
#include <vector>
#include <string>

using namespace std;

// comparing two numbers using strings
bool isBetter(const string &a, const string &b)
{
    return a + b > b + a;
}

// a function to merge two array
void merge(vector<string> &arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = arr[middle + 1 + i];
    } 

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (isBetter(L[i], R[j]))
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    while (j < n2)
    {
        arr[k++] = R[j++];
    }
}

// merge sort function
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

int main()
{
    // this part is for faster input and output to prevent the time limit
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> nums(n);

    // getting the numbers
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    // sort the numbers using the merge sort
    mergeSort(nums, 0, n - 1);

    // combining the numbers
    string result;
    for (const string &s : nums)
    {
        result += s;
    }

    // if all of the numbers are 0 , the output should be 0 too
    bool allZero = true;
    for (char c : result)
    {
        if (c != '0')
        {
            allZero = false;
            break;
        }
    }

    if (allZero)
    {
        cout << "0" << endl;
    }
    else
        cout << result << endl;

    return 0;
}