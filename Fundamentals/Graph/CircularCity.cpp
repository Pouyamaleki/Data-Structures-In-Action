#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Bolean variables to check if there is a direction or no
    bool ToCenter = false , AwayFromCenter = false;

    // for loop to input the values
    for (int i = 0; i < n; i++)
    {
        int direction;
        cin >> direction;

        // check if there is both to center and away from center direction
        if (direction == 0)
        {
           ToCenter = true;
        }
        else
        {
            AwayFromCenter = true;
        }
    }

    /* loop to get the other directions and we ignore them
    beacuse it's a part of the input and we don't need them */
    for (int i = 1; i < m; i++)
    {
        int direction;
        cin >> direction;
    }

    // check for the finall answer
    if (ToCenter && AwayFromCenter)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}