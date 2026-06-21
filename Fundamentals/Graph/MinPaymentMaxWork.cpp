#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>

using namespace std;

// Edge structure for the flow graph
struct Edge
{
    int to, rev;
    double cap, cost;
};

// function to add an edge to the graph
void addEdge(vector<vector<Edge>> &graph, int from, int to, double cap, double cost)
{
    graph[from].push_back({to, (int)graph[to].size(), cap, cost});
    graph[to].push_back({from, (int)graph[from].size() - 1, 0, -cost});
}

// min cost and max work function
pair<double, double> minCostMaxFlow(vector<vector<Edge>> &graph, int s, int t, double maxFlow)
{
    int n = graph.size();
    double flow = 0, cost = 0;
    const double INF = 1e18;

    // a loop to set job for the workers
    while (flow < maxFlow - 1e-9)
    {
        // variables to find the best path
        vector<double> dist(n, INF);
        vector<int> pv(n), pe(n);
        vector<bool> inq(n, false);
        queue<int> q;

        dist[s] = 0;
        q.push(s);
        inq[s] = true;

        // to connect a node to others with minimum cost
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            inq[v] = false;

            // dor loop to update the Edges for the neighbors
            for (int i = 0; i < (int)graph[v].size(); i++)
            {
                Edge &e = graph[v][i];

                // update and check edges for lesser cost
                if (e.cap > 1e-9 && dist[e.to] > dist[v] + e.cost + 1e-12)
                {
                    dist[e.to] = dist[v] + e.cost;
                    pv[e.to] = v;
                    pe[e.to] = i;

                    // add the updated node to the queue
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }

        // this part is impossible but i use it to make sure the code work perfectly
        if (dist[t] == INF)
        {
            break;
        }

        // find the maximum additional flow that can be sent along this path
        double add = maxFlow - flow;
        for (int v = t; v != s; v = pv[v])
        {
            add = min(add, graph[pv[v]][pe[v]].cap);
        }

        // update edge capacities
        for (int v = t; v != s; v = pv[v])
        {
            Edge &e = graph[pv[v]][pe[v]];
            e.cap -= add;
            graph[v][e.rev].cap += add;
        }

        flow += add;
        cost += add * dist[t];
    }

    return {flow, cost};
}

int main()
{
    // to run the program faster
    ios::sync_with_stdio(false);
    cin.tie(0);

    // number of jobs
    int j;
    cin >> j;

    // get the difficulty of every job
    vector<double> h(j);
    for (int i = 0; i < j; i++)
    {
        cin >> h[i];
    }

    // number of workers
    int n;
    cin >> n;

    // get the maximum workload every worker can handle
    vector<double> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    // a matrix for workers and their abilities on each job
    vector<vector<double>> s(j, vector<double>(n));
    for (int i = 0; i < j; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> s[i][k];
        }
    }

    // build the minimum cost job graph
    int S = 0;                // source node
    int jobOffset = 1;        // job nodes from 1 to j
    int workerOffset = 1 + j; // worker nodes from j+1 to j+n
    int T = 1 + j + n;        // sink node
    int nodeCount = T + 1;
    vector<vector<Edge>> graph(nodeCount);

    // edge from source to each job with capacity
    for (int i = 0; i < j; i++)
    {
        addEdge(graph, S, jobOffset + i, h[i], 0.0);
    }

    // edge from each job to each worker with infinite capacity
    const double INF_CAP = 1e9;
    for (int i = 0; i < j; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (s[i][k] > 0)
            {
                addEdge(graph, jobOffset + i, workerOffset + k, INF_CAP, 1.0 / s[i][k]);
            }
        }
    }

    // edge from each worker to sink with capacity
    for (int k = 0; k < n; k++)
    {
        addEdge(graph, workerOffset + k, T, m[k], 0.0);
    }

    // total flow needed = sum of all job difficulties
    double totalEffort = 0;
    for (int i = 0; i < j; i++)
    {
        totalEffort += h[i];
    }

    // run the min-cost max-flow algorithm
    auto [flow, minCost] = minCostMaxFlow(graph, S, T, totalEffort);

    // print the minimum total working hours (with enough precision)
    cout << fixed << setprecision(12) << minCost << endl;

    return 0;
}