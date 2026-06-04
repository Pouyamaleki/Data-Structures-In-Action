#include <iostream>

using namespace std;

int main()
{
    int size, counter = 0;
    cin >> size;
    if (!size)
    {
        cout << "0" << endl;
        return 0;
    }

    int Numbers[size];
    for (int i = 0; i < size; i++)
    {
        cin >> Numbers[i];
    }

    for (int i = 1; i < size; i++)
    {
        if(Numbers[counter] != Numbers[i])
        {
            counter++;
            Numbers[counter] = Numbers[i];
        }
    }

    cout << ++counter << endl;

    /*if you want to see the Numbers without repitetive members
    for(int i = 0; i < counter; i++)
    {
        cout << Numbers[i] << endl;
    }*/

    return 0;
}