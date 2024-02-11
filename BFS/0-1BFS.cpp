// a directed graph . I need to go 1 to n. how many direction should I reverse for going 1 to n.
// checking github

#include <bits/stdc++.h>
using namespace std;
int const N = 1e5 + 10;
int const INF = 1e9 + 30;

vector<pair<int, int>> g[N];
vector<int> level(N, INF);

int v, e;

int bfs()
{
    deque<int> q;
    q.push_back(1);
    level[1] = 0;

    while (!q.empty())
    {
        int curr_v = q.front();
        cout << curr_v << " ";
        q.pop_front();
        for (auto child : g[curr_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (level[curr_v] + wt < level[child_v])
            {
                level[child_v] = level[curr_v] + wt;

                if (wt == 1)
                {
                    q.push_back(child_v);
                }
                else
                {
                    q.push_front(child_v);
                }
            }
        }
    }

    return level[v] == INF ? -1 : level[v];
}

int main()
{

    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            continue;
        }
        g[x].push_back({y, 0}); // normal direction e gele cost 0
        g[y].push_back({x, 1}); // reverse direction er value 1 kore dilam
    }

    int ans = bfs();
    cout << ans << endl;
}
