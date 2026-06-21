#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    // to run the program faster
    ios::sync_with_stdio(false);
    cin.tie(0);

    // number of jobs
    int j;
    cin >> j;

    // get the dificulty of ever job
    vector<double> h(j);
    for (int i = 0; i < j; i++)
    {
        cin >> h[i];
    }

    // number of workers
    int n;
    cin >> n;

    // get the maximum work every worker can do
    vector<double> m(n);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
    }

    // a matrix for wrokers and their jobs
    vector<vector<double>> s(j, vector<double>(n));
    for (int i = 0; i < j; i++)
    {
        for (int k = 0; k < n; k++)
        {
            cin >> s[i][k];
        }
    }

    // check if every job will be done on time or no
    auto canFinish = [&](double time) -> bool
    {
        // make a copy from jobs dificullty
        vector<double> remaining = h;
        vector<double> remainingCap = m;

        // workers list that can do the job i
        for (int i = 0; i < j; i++)
        {
            vector<pair<double, int>> workers;
            for (int k = 0; k < n; k++)
            {
                if (s[i][k] > 0 && remainingCap[k] > 0)
                {
                    workers.push_back({s[i][k], k});
                }
            }
            // sort workers from strong to weak
            sort(workers.rbegin(), workers.rend());

            // set jobs for the workers that can do more jobs
            for (auto [ability, person] : workers)
            {
                if (remaining[i] <= 1e-9)
                {
                    break;
                }

                double maxWork = min(remainingCap[person] / h[i], time * ability / h[i]);
                double workDone = min(remaining[i], maxWork);
                remaining[i] -= workDone;
                remainingCap[person] -= workDone * h[i];
            }
        }

        // check if every job is done or no
        for (int i = 0; i < j; i++)
        {
            if (remaining[i] > 1e-9)
            {
                return false;
            }
        }
        return true;
    };

    // for binery search section
    double low = 0, high = 1e9;

    // find the minimum time with binery search
    for (int iter = 0; iter < 100; iter++)
    {
        double mid = (low + high) / 2;
        if (canFinish(mid))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    // show the minimum time
    cout << fixed << setprecision(10) << high << endl;

    return 0;
}