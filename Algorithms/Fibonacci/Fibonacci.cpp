#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// check if the number is perfect squart or no (not neccessery)
bool isPerfectSquare(long long int x)
{
    long long int s = sqrt(x);

    return (s * s == x);
}

// check if the number is from the fibonacci or no
bool isFibonacci(long long int num)
{
    if (num < 0)
    {
        return false;
    }

    long long int a = 5 * num * num + 4;
    long long int b = 5 * num * num - 4;

    return (isPerfectSquare(a) || isPerfectSquare(b));
}

// Findsub function with the question prototype
vector<int> findFibSubset(vector<int> &arr)
{
    vector<int> result;
    for (int num : arr)
    {
        if (isFibonacci(num))
        {
            result.push_back(num);
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;

    // get the array
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // function call
    vector<int> result = findFibSubset(arr);

    // print the result
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        cout << " ";
    }

    cout << endl;

    return 0;
}