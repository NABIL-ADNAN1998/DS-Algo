#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int INF = 1e9 + 10;

int n, m;
int val[N][N];
int vis[N][N];
int lev[N][N];

void reset()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vis[i][j] = 0;
            lev[i][j] = INF;
        }
    }
}
vector<pair<int, int>> movements{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

bool isvalid(int i, int j)
{
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs()
{
    int ans = 0;
    queue<pair<int, int>> q;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mx = max(mx, val[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (val[i][j] == mx)
            {
                q.push({i, j});
                vis[i][j] = 1;
                lev[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        pair<int, int> cv = q.front();
        q.pop();
        int cvx = cv.first;
        int cvy = cv.second;

        for (auto movement : movements)
        {
            int childx = movement.first + cvx;
            int childy = movement.second + cvy;
            if (vis[childx][childy] == 1)
            {
                continue;
            }
            if (!isvalid(childx, childy))
            {
                continue;
            }

            q.push({childx, childy});
            lev[childx][childy] = lev[cvx][cvy] + 1;
            vis[childx][childy] = 1;
            ans = max(ans, lev[childx][childy]);
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> val[i][j];
            }
        }

        reset();
        cout << bfs() << endl;
    }
}
