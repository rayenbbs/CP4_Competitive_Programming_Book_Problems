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
    int t, n, m, l, a, b;
    cin >> t;
    while (t--)
    {
        int result = 0, z;
        cin >> n >> m >> l;
        AL.assign(n, vi());
        dfs_num.assign(n, UNVISITED);
        while (m--)
        {
            cin >> a >> b;
            AL[a - 1].push_back(b - 1);
        }
        while (l--)
        {
            cin >> z;
            dfs(z - 1);
        }
        for (auto i : dfs_num)
        {
            if (i == VISITED)
                ++result;
        }
        cout << result << endl;
    }
    return 0;
}