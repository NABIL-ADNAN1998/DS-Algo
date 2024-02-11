#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

vector<int> graph[N];
bool visited[N];

vector<vector<int>> cc; // element of connected components
vector<int> current_cc;

void dfs(int vertex)
{
    visited[vertex] = 1;
    current_cc.push_back(vertex);

    for (int child : graph[vertex])
    {
        if (visited[child] == 1)
        {
            continue;
        }

        dfs(child);
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 1)
        {
            continue;
        }

        current_cc.clear();
        dfs(i);
        count++;
    }

    cout << "total connected components : " << count << endl;
    cout << "total connected components : " << cc.size() << endl;

    for (vector<int> z : cc)
    {
        for (int x : z)
        {
            cout << x << " ";
        }

        cout << endl;
    }
}