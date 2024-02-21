#include <bits/stdc++.h>
using namespace std;

const int N = 1e8 + 10;
const int INF = 1e9 + 10;

vector<pair<int, int>> g[N];
set<pair<int, int>> s;
vector<int> dist(N, INF);


void dijkstra(int source)
{
    s.insert({0, source});
    dist[source] = 0;

    while (s.size() > 0)
    {
        auto node = *s.begin();
        int v = node.second;
        int d = node.first;
        s.erase(s.begin());
        
      

        for (auto child : g[v])
        {
            // going to children of v
            int childv = child.first;  // node
            int childd = child.second; // weight

            if (dist[childv] > dist[v] + childd) // current weight > parent weight + self weight
            {
                dist[childv] = dist[v] + childd;
                s.insert({dist[childv], childv});
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g[x].push_back({y, w});
    }
}