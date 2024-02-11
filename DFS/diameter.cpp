#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int depth[N];

void dfs(int vertex, int par)
{

    for (auto child : g[vertex])
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
    int v, e;
    cin >> v >> e;

    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);

    int one_point, another_point;
    int max_d = -2;
    for (int i = 1; i <= v; i++)
    {
        if (depth[i] > max_d)
        {
            max_d = depth[i];
            one_point = i;
        }
        depth[i] = 0;
    }

    max_d = -2;

    dfs(one_point, 0);

    for (int i = 1; i <= v; i++)
    {
        if (depth[i] > max_d)
        {
            max_d = depth[i];
            another_point = i;
        }
        depth[i] = 0;
    }

    cout << one_point << " " << another_point;
}