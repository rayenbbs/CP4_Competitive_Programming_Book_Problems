#include <bits/stdc++.h>
using namespace std;


#define LSOne(S) ((S) & -(S))
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


#define MOD 998244353
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
    cin>>t;
    int testcount=1;
    while(t--){
        cout<<"Case #"<<testcount++<<'\n';
        int n; cin >>n;
        vii matrix(n,vi(n));
        f(r,0,n){
            f(c,0,n) {
                char a;
                cin>>a;
                matrix[r][c]=a-'0';
            }
        }
        int q; cin>>q;
        while(q--) {
            string command;
            cin >> command;
            if (command == "inc") {
                f(r, 0, n) {
                    f(c, 0, n) {
                        matrix[r][c] += 1;
                        matrix[r][c] %= 10;
                    }
                }
            }
            if (command == "row") {
                int a, b;
                cin >> a >> b;
                --a;
                --b;
                f(c, 0, n) {
                    int temp = matrix[a][c];
                    matrix[a][c] = matrix[b][c];
                    matrix[b][c] = temp;
                }
            }
            if (command=="dec"){
                f(r,0,n){
                    f(c,0,n){
                        matrix[r][c]--;
                        matrix[r][c]%=10;
                        if (matrix[r][c]<0){
                            matrix[r][c]+=10;
                        }
                    }
                }
            }
            if (command == "col") {
                int a, b;
                cin >> a >> b;
                --a;
                --b;
                f(r, 0, n) {
                    int temp = matrix[r][a];
                    matrix[r][a] = matrix[r][b];
                    matrix[r][b] = temp;
                }
            }
            if (command == "transpose") {
                vii temp (n,vi(n));
                f(r, 0, n) {
                    f(c, 0, n) {
                        temp[c][r] = matrix[r][c];
                    }
                }
                f(r, 0, n) {
                    f(c, 0, n) {
                        matrix[r][c]=temp[r][c] ;
                    }
                }
            }

        }
        f(r,0,n){
            f(c,0,n){
                cout<<matrix[r][c];
            }
            cout<<'\n';
        }
        cout<<'\n';
    }


    return 0;
}