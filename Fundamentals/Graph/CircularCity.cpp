#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // Bolean variables to check if there is a direction or no
    bool ToCenter = false;
    bool AwayFromCenter = false;

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

    // check if every path has the same direction
    bool allCircularSameDirection = true;

    // get the first circular direction
    int firstCircularDirection;
    cin >> firstCircularDirection;

    // loop to get the other directions
    for (int i = 1; i < m; i++)
    {
        int direction;
        cin >> direction;

        // check if all of the direction are the same or no
        if (direction != firstCircularDirection)
        {
            allCircularSameDirection = false;
        }
    }

    // check for the finall answer
    if (allCircularSameDirection &&ToCenter && AwayFromCenter)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}