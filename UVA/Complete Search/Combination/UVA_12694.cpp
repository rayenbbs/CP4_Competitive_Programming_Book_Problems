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
    int t;
    cin >> t;
    int s,e;
    int countevent;
    int best;
    vector<pair<int, int>> selected;
    pair<int, int> target;
    pair<int, int> prevtarget;
    bool test;
    int countselected;
    while (t--) {
        countevent = 0;
        cin >> s >> e;
        vector<pair<int, int>> events;
        while (s != 0 || e != 0) {
            events.eb(s, e);
            ++countevent;
            cin >> s >> e;
        }
        best = -1;
        sort(events.begin(), events.end());
        f(i, 0, 1 << countevent) {
            selected.clear();
            countselected = 0;
            prevtarget={0,0};
            target={0,0};
            test = true;
            f(j, 0, countevent) {
                if (i & 1 << j) {
                    prevtarget=target;
                    target = events[j];
                    if (prevtarget.second >target.first) {
                        test = false;
                        break;
                    }
                    selected.eb(target.first, target.second);
                    ++countselected;
                }
            }
            if (!test) {
                continue;
            }
            if (countselected < best)
                continue;
            best = max(best, countselected);
        }
        cout<<best<<'\n';
    }
}
