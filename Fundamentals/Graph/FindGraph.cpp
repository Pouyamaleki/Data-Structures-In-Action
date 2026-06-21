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

    // adjacency matrix using bitset (instead of vector<vector<bool>>)
    vector<bitset<LIMIT>> adj(N + 1);

    // get the edges
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].flip(b); // mark edge a-b
        adj[b].flip(a); // mark edge b-a
    }

    bool hasK23 = false;

    // check every pair of nodes to see if they have at least 3 common neighbors
    for (int x = 1; x <= N && !hasK23; x++)
    {
        for (int y = x + 1; y <= N && !hasK23; y++)
        {
            int common = 0;
            bitset<LIMIT> inter = adj[x] & adj[y]; // common neighbors = intersection

            // count common neighbors
            for (int z = 1; z <= N; z++)
            {
                if (inter.test(z))
                {
                    common++;
                    if (common >= 3)
                    {
                        hasK23 = true;
                        break;
                    }
                }
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