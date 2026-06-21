#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

const int LIMIT = 2005;

int main()
{
    // to run the program faster
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // adjacency matrix using bitset
    vector<bitset<LIMIT>> adj(N + 1);

    // for loop to get the edges
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].flip(b); // mark edge a-b
        adj[b].flip(a); // mark edge b-a
    }

    bool hasK23 = false;

    // check every pair of nodes to see if they have at least 3 common neighbors or no
    for (int x = 1; x <= N && !hasK23; x++)
    {
        for (int y = x + 1; y <= N && !hasK23; y++)
        {
            int common = (adj[x] & adj[y]).count(); // count the common neighbors

            if (common >= 3)
            {
                hasK23 = true;
                break;
            }
        }
    }

    // print the final answer
    if (hasK23)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}