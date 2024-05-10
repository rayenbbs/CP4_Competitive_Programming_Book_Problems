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

int dr[] = {1, 0, -1, 0}; // the order is:
int dc[] = {0, 1, 0, -1}; // S/E/N/W
int C, R;
vector<vi> grid;
vector<vi> expgrid;
int boole = 0;
void floodfill(int r, int c, int i1, int &len)
{
    if ((r < 0) || (r >= R))
        ;
    else if ((c < 0) || (c >= C))
        ;

    else if (grid[r][c] > i1)
        ;
    else if (grid[r][c] < i1)
        boole = 1;
    else if (expgrid[r][c])
        ; // fama wehed asgher menou lbara mel grp
    else if (grid[r][c] == i1)
    {
        len++;
        expgrid[r][c] = 1; // explored w tebaa l groupe
        for (int d = 0; d < 4; ++d)
            floodfill(r + dr[d], c + dc[d], grid[r][c], len); // the code is neat as
    }
}

int main()
{
    int result = 0;
    cin >> C >> R;
    grid.assign(R, vi(C, -1));
    expgrid.assign(R, vi(C, 0));
    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {
            cin >> grid[r][c];
        }
    }

    for (int r = 0; r < R; r++)
    {
        for (int c = 0; c < C; c++)
        {

            if (!expgrid[r][c])
            {
                int len = 0;
                boole = 0;
                floodfill(r, c, grid[r][c], len);
                if (boole == 0)
                {
                    result += len;
                }
            }
        }
    }
    cout << result << endl;

    return 0;
}