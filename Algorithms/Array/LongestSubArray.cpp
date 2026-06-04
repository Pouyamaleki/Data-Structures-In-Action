#include <iostream>

using namespace std;

int main()
{
    unsigned int size;
    cin >> size;
    long long int Numbers[size];
    bool IsPositive = true;

    for (int i = 0; i < size; i++)
    {
        cin >> Numbers[i];
        // check if there is any negative number in the array
        if (IsPositive == true && Numbers[i] < 0)
        {
            IsPositive = false;
        }
    }

    long long int k;
    cin >> k;

    int best = 0;
    // if there is not any negative number in the array
    if (IsPositive)
    {
        int Lcounter = 0;
        long long int sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += Numbers[i];

            while (sum > k && Lcounter <= i)
            {
                sum -= Numbers[Lcounter];
                Lcounter++;
            }
            if (sum <= k)
            {
                int Length = i - Lcounter + 1;
                if (Length > best)
                {
                    best = Length;
                }
            }
        }
    }
    // if there is atleast one negative number
    else
    {
        for (int Lcounter = 0; Lcounter < size; Lcounter++)
        {
            long long int sum = 0;
            for (int i = Lcounter; i < size; i++)
            {
                sum += Numbers[i];
                if (sum <= k)
                {
                    int Length = i - Lcounter + 1;
                    if (Length > best)
                    {
                        best = Length;
                    }
                }
            }
        }
    }

    cout << best << endl;

    return 0;
}