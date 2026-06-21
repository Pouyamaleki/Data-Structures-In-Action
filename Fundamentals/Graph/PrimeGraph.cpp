#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // adjacency matrix with n+1 * n+1 size
    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1, false));

    // for loop to input the Edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = true;
        graph[v][u] = true;
    }

    // number of Questions
    int q;
    cin >> q;

    // for loop to get and check the questions
    for (int i = 0; i < q; i++)
    {
        int u, v;
        cin >> u >> v;

        // chceck the Questions
        if (!graph[u][v])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}