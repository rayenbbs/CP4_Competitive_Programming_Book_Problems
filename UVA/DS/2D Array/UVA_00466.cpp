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

int n;
vector<vector<char>> v;
vector<vector<char>> target;

void reflection(){
    vector<vector<char>> temp(n,vector<char>(n));
    f(r,0,n){
        f(c,0,n){
            temp[n-1-r][c]=v[r][c];
        }
    }
    f(r,0,n){
        f(c,0,n){
            v[r][c]=temp[r][c];
        }
    }
}

void rotation(){
    vector<vector<char>> temp(n,vector<char>(n));
    f(r,0,n){
        f(c,0,n){
            temp[c][n-1-r]=v[r][c];
        }
    }

    f(r,0,n){
        f(c,0,n){
            v[r][c]=temp[r][c];
        }
    }
}

bool check(){
    f(r,0,n){
        f(c,0,n){
            if (v[r][c]!=target[r][c]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testcount=1;
    while(cin>>n) {
        v.assign(n, vector<char>(n));
        target.assign(n, vector<char>(n));
        f(i, 0, n) {
            f(j, 0, 2 * n) {
                if (j % n == j) {
                    cin >> v[i][j];
                } else {
                    cin >> target[i][j%n];
                }
            }
        }
        if (check()) {
            cout <<"Pattern "<<testcount++<<" was preserved.\n";
        }
        else {
            rotation();
            if (check()) {
                cout << "Pattern " << testcount++ << " was rotated 90 degrees.\n";
            }
            else{
                rotation();
                if (check()) {
                    cout << "Pattern " << testcount++ << " was rotated 180 degrees.\n";
                }
                else {
                    rotation();
                    if (check()) {
                        cout << "Pattern " << testcount++ << " was rotated 270 degrees.\n";
                    }
                    else{
                        rotation();
                        reflection();
                        if(check()){
                            cout << "Pattern " << testcount++ << " was reflected vertically.\n";
                        }
                        else{
                            rotation();
                            if(check()) {
                                cout << "Pattern " << testcount++
                                     << " was reflected vertically and rotated 90 degrees.\n";
                            }
                            else{
                                rotation();
                                if(check()) {
                                    cout << "Pattern " << testcount++
                                         << " was reflected vertically and rotated 180 degrees.\n";
                                }
                                else{
                                    rotation();
                                    if(check()) {
                                        cout << "Pattern " << testcount++
                                             << " was reflected vertically and rotated 270 degrees.\n";
                                    }
                                    else{
                                        cout << "Pattern " << testcount++
                                             << " was improperly transformed.\n";
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

    }


    return 0;
}