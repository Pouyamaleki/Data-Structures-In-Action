#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    // adjacency matrix
    vector<vector<bool>> adj(N + 1, vector<bool>(N + 1, false));

    // get the Edges
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = true;
        adj[v][u] = true;
    }

    // check every node to see if they have atleast 3 neighbor or no
    for (int u = 1; u <= N; u++)
    {
        for (int v = u + 1; v <= N; v++)
        {
            int common = 0;

            for (int w = 1; w <= N; w++)
            {
                if (w != u && w != v && adj[u][w] && adj[v][w])
                {
                    common++;
                    if (common >= 3)
                    {   
                        cout << "YES" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}