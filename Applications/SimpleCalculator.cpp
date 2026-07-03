#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);

    int stack[100000];
    int signStack[100000];
    int top = -1;

    int result = 0;
    int currentNum = 0;
    int sign = 1;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        if (c >= '0' && c <= '9')
        {
            currentNum = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9')
            {
                currentNum = currentNum * 10 + (s[i] - '0');
                i++;
            }
            i--;
            result += sign * currentNum;
            currentNum = 0;
        }
        else if (c == '+')
        {
            sign = 1;
        }
        else if (c == '-')
        {
            sign = -1;
        }
        else if (c == '(')
        {
            top++;
            stack[top] = result;
            signStack[top] = sign;

            result = 0;
            sign = 1;
        }
        else if (c == ')')
        {
            result = stack[top] + signStack[top] * result;
            top--;
        }
    }

    cout << result << endl;

    return 0;
}