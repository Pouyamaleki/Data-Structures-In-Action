#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// a function to make the keys
long long makeKey(int u, int v)
{
    if (u > v)
    {
        swap(u, v);
    }

    return (long long)u * 1000001 + v;
}

int main()
{
    // to run the program faster
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // get enough space for the edges
    vector<long long> edges;
    edges.reserve(m);

    // get the edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(makeKey(u, v));
    }

    // sort the edges for the binery search
    sort(edges.begin(), edges.end());

    int q;
    cin >> q;

    // get every Question and check them
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        long long key = makeKey(u, v);

        // check for the right answer
        if (binary_search(edges.begin(), edges.end(), key))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}