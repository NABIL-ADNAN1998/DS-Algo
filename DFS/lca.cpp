#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> g[N];
int parent[N];

void dfs(int vertex, int par)
{
    parent[vertex] = par;
    for (auto child : g[vertex])
    {
        if (child == par)
        {
            continue;
        }
        dfs(child, vertex);
    }
}

vector<int> path(int x)
{
    vector<int> ans;
    ans.push_back(x);
    int z = parent[x];
    while (z != 0)
    {
        ans.push_back(z);
        z = parent[z];
    }

    reverse(ans.begin(), ans.end());
    return ans;
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
    int x, y;
    cin >> x >> y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);

    // for (int i = 0; i < path_y.size(); i++)
    // {
    //     cout << path_y[i] << " ";
    // }

    int lca, n;

    for (int i = 0; i < min(path_x.size(), path_y.size()); i++)
    {
        if (path_x[i] == path_y[i])
        {
            lca = path_x[i];
        }
        else
        {
            break;
        }
    }

    cout << "lca = " << lca << endl;
}