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

bitset<17> rw, ld, rd; // we have 15 diagonals

vi row(8);
int a,b;
int lineCounter;

void backtrack(int c) {
    if (c == 8 && row[b]==a) {  printf("%2d      %d", ++lineCounter, row[0]+1);
        for (int j = 1; j < 8; ++j) printf(" %d", row[j]+1);
        printf("\n");
        return; } // a solution
    for (int r = 0; r < 8; ++r) // try all possible row
        if (!rw[r] && !ld[r-c+8-1] && !rd[r+c]) {
            row[c]=r;
            rw[r] = ld[r-c+8-1] = rd[r+c] = true; // flag off
            backtrack(c+1);
            rw[r] = ld[r-c+8-1] = rd[r+c] = false; // restore
        }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC; scanf("%d", &TC);
    while (TC--) {
        scanf("%d %d", &a, &b); --a; --b; // to 0-based indexing
        lineCounter = 0;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack(0); // sub 8! operations
        if (TC) printf("\n");
    }
    return 0;
}