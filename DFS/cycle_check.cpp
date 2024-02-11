#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> graph[N];
bool vis[N];

bool dfs(int vertex, int parent)
{
    bool isloopexist = false;
    vis[vertex] = 1;

    for (int child : graph[vertex])
    {
        if (vis[child] == 1 && child == parent)
        {
            continue;
        }

        if (vis[child] == 1)
        {
            return true;
        }

        isloopexist |= dfs(child, vertex);
    }

    return isloopexist;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    bool isloop = false;
    for (int i = 1; i <= n; i++)
    {
        if (dfs(i, 0) == true)
        {
            isloop = true;
            break;
        }
    }

    if (isloop)
    {
        cout << "graph has loop" << endl;
    }
    else
    {
        cout << "graph has not any loop" << endl;
    }
}