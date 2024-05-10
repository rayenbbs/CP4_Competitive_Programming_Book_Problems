#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX_V = 1010;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
vector<vi> AL;
vi dfs_num;
enum
{
    VISITED = -1,
    UNVISITED = -2
};
void dfs(int u)
{
    dfs_num[u] = VISITED;
    for (auto &v : AL[u])
    {
        if (dfs_num[v] == UNVISITED)
        {
            dfs(v);
        }
    }
}


int main()
{
    int n, m, r;
    cin >> n;
    while (n--)
    {
        int CC = 0;
        cin >> m >> r;
        int a, b;
        AL.assign(m, vi());
        dfs_num.assign(m, UNVISITED);
        while (r--)
        {
            cin >> a >> b;
            AL[a].push_back(b);
            AL[b].push_back(a);
        }
        for (int i = 0; i < m; i++)
        {
            if (dfs_num[i] == UNVISITED)
            {
                ++CC;
                dfs(i);
            }
        }
        cout << CC - 1 << endl;
    }
    return 0;
}