#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
const int INF = 1e9 + 10;

int dist[N][N];

int main()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            dist[i][j] = INF;
        }
    }

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        if (x == y)
        {
            dist[x][y] = 0;
        }
        else
        {
            dist[x][y] = wt;
        }
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "I"
                     << " ";
            }
            else
            {

                cout << dist[i][j] << " ";
            }
        }

        cout << endl;
    }
}