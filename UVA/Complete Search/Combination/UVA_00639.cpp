#include <bits/stdc++.h>
using namespace std;



#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vii vector<vi>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set


#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back


#define MOD 1000000007
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n!=0){
        vector<vector<char>> board(n, vector<char>(n,'.'));
        f(i, 0, n) {
            f(j, 0, n) {
                cin >> board[i][j];
            }
        }
        int best = -1;
        f(i, 0, 1 << (n * n)) {
            vector<vector<char>> boardinter(n, vector<char>(n));
            f(r,0,n){
                f(c,0,n){
                    boardinter[r][c]=board[r][c];
                }
            }
            bool test = true;
            int count = 0;
            f(j, 0, n * n) {
                if (1 << j & i) {
                    int r = j / n;
                    int c = j % n;
                    if (board[r][c] == '.') {
                        boardinter[r][c] = 'r';
                        ++count;
                    } else {
                        test = false;
                        break;
                    }
                }
            }
            if (test) {
                f(t, 0, n * n) {
                    int r = t / n;
                    int c = t % n;
                    if (boardinter[r][c] == 'r') {
                        f(p, c + 1, n) {
                            if (boardinter[r][p] == 'r' && p != c)
                                test = false;
                            if (boardinter[r][p] == 'X')
                                break;
                        }
                        for (int p = c - 1; p >= 0; p--) {
                            if (boardinter[r][p] == 'X')
                                break;
                            if (boardinter[r][p] == 'r' && p != c)
                                test = false;
                        }
                        f(p, r + 1, n) {
                            if (boardinter[p][c] == 'r' && p != r)
                                test = false;
                            if (boardinter[p][c] == 'X')
                                break;
                        }
                        for (int p = c - 1; p >= 0; p--) {
                            if (boardinter[p][c] == 'X')
                                break;
                            if (boardinter[p][c] == 'r' && p != r)
                                test = false;
                        }
                    }
                    if (!test)
                        break;
                }
            }
            if (test) {
                best = max(best, count);
            }
        }
        cout << best << '\n';
        cin >> n;
    }
}
