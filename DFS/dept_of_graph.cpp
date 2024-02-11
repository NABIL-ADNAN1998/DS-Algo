#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1e5 + 10;
vector<ll> graph[N];
ll depth[N];

void dfs(int vertex, int par)
{
    for (auto child : graph[vertex])
    {
        if (child == par)
        {
            continue;
        }
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int main()
{
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(13, 0);

    ll c = sizeof(depth) / sizeof(depth[0]), point1 = 1, point2 = 0, d = INT_MIN;

    cout << "depth = " << *max_element(depth, depth + c) << endl;

    for (int i = 1; i < 13; i++)
    {
        if (depth[i] >= depth[i - 1])
        {
            point1 = i;
        }
        depth[i] = 0;
    }

    cout << "first point = " << point1 << endl; // this is depth from a specific node. Not the highest depth

    dfs(point1, 0);

    for (int i = 1; i < 13; i++)
    {
        if (depth[i] >= depth[i - 1])
        {
            d = depth[i];
            point2 = i;
        }
    }

    // these are the two point whose distance is called diameter
    cout << "point1 = " << point1 << "  "
         << " point2 = " << point2 << endl;

    cout << "diameter = " << d << endl;
}