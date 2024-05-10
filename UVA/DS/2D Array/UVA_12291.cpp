#include <bits/stdc++.h>
using namespace std;

template<typename T>
T mmax(T t) {
    return t;
}

template<typename T, typename... Args>
T mmax(T t, Args... args) {
    return std::max(t, mmax(args...));
}

#define uint unsigned int
#define ll long long
#define ull unsigned long long
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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

#define LSOne(S) ((S) & -(S))
#define INF 1e18
vector<vector<char>> unit;
vector<vector<char>> target;
vector<vector<char>> temp;
vector<pii> path;
int m,n;

void init(){
    f(r,0,n){
        f(c,0,n){
            temp[r][c]=target[r][c];
        }
    }
}

void drawpath(int sourcer,int sourcec){
    f(r,0,m){
        f(c,0,m){
            if (unit[r][c]=='*'){
                path.eb(r-sourcer,c-sourcec);
            }
        }
    }

}

bool can(int r,int c){
    for(auto u:path){
        if( r+u.first>=0 && r+u.first<n && c+u.second>=0 && c+u.second<n && temp[r+u.first][c+u.second]=='*'){
            temp[r+u.first][c+u.second]='/';
        }
        else return false;
    }
    return true;
}

bool check(){
    init();
    bool test=true;
    int count=0;
    f(tempr,0,n){
        f(tempc,0,n){
            if (temp[tempr][tempc]=='*'){
                ++count;
                bool test1=can(tempr,tempc);
                test=test && test1;
            }
        }
    }
    return  count==2 && test;
}




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while(cin>>n>>m && m) {
        cin.ignore();
        path.clear();
        target.assign(n, vector<char>(n, '.'));
        temp.assign(n, vector<char>(n, '.'));

        f(r, 0, n) {
            string dummy;
            getline(cin,dummy);
            f(c, 0, dummy.size()) {
                target[r][c]=dummy[c];
            }
        }
        unit.assign(m, vector<char>(m, '.'));
        f(r, 0, m) {
            string dummy;
            getline(cin,dummy);
            f(c, 0, dummy.size()) {
                unit[r][c]=dummy[c];
            }
        }
        bool dummy=true;
        f(r, 0, m && dummy) {
            f(c, 0, m && dummy) {
                if(unit[r][c]=='*'){
                    drawpath(r,c);
                    dummy=false;
                    break;
                }
            }
        }
        if(check()){
            cout<<1<<'\n';
        }
        else cout<<0<<'\n';

    }


}