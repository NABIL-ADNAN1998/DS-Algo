#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;

vector<int> g[N];
bool visited[N];

int dfs(int vertex)
{
    visited[vertex] = 1;
    for (auto child : g[vertex])
    {
        if (visited[child])
        {
            continue;
        }
        
        dfs(child);
    }
}

int main()
{

    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
}