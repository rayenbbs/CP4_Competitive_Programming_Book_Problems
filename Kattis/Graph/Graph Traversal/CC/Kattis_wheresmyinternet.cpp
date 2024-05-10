#include <bits/stdc++.h>
using namespace std;

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
    int n, m;
    cin >> n >> m;
    AL.assign(n + 1, vi());
    dfs_num.assign(n + 1, UNVISITED);
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
    }
    dfs(1);
    int dummy = 0;
    auto it = dfs_num.begin();
    ++it;
    for (; it != dfs_num.end(); ++it)
    {
        if ((*it) == UNVISITED)
        {
            cout << (distance(dfs_num.begin(), it)) << '\n';
            dummy = 1;
        }
    }
    if (dummy == 0)
    {
        cout << "Connected\n";
    }

    return 0;
}