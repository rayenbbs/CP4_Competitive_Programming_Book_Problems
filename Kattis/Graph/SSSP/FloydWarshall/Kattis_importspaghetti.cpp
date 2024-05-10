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


#define MOD 998244353
#define PI 3.1415926535897932384626433832795
#define INF 1e9

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

void printPath(int i, int j,vii &p,int &count,umap<int,string> & mymap) {
    if (j==i)
        cout<<mymap[i];
    if (p[i][j] == i) count++;
    if (count<2) printPath(i, p[i][j],p,count,mymap);
    if (j!=i)
        cout<<" "<<mymap[j];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string line;

    int n;
    getline(cin,line);
    stringstream ss(line);
    ss>>n;
    getline(cin,line);
    ss.clear();
    ss.str(line);
    umap<int,string> mymap;
    umap<string,int> revmap;

    f(i,0,n){
        string a;
        ss>>a;
        mymap[i]=a;
        revmap[a]=i;
    }

    string a;
    int nl;
    vii AM(n,vi(n,INF));
    f(i,0,n){
        getline(cin,line);
        ss.clear();
        ss.str(line);
        ss>>a;
        ss>>nl;
        f(j,0,nl){
            string b;
            getline(cin,line);
            ss.clear();
            ss.str(line);
            while(ss>>b){
                if (b=="import")
                    continue;
                else{
                    if (b[b.size()-1]==','){
                        b.pop_back();
                    }
                    AM[revmap[a]][revmap[b]]=1;
                }
            }

        }
    }
    int V=n;
    vii p(n,vi(n,INF));

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            p[i][j] = i; // initialization
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (AM[i][k]+AM[k][j] < AM[i][j]) { // use if statement
                    AM[i][j] = AM[i][k]+AM[k][j];
                    p[i][j] = p[k][j]; // update the p matrix
                }
    int min=INF;
    int v;
    f(i,0,n){
        if (AM[i][i]<min){
            min=AM[i][i];
            v=i;
        }
    }
    int count=1;
    if (min!=INF)
        printPath(v,v,p,count,mymap);
    else cout<<"SHIP IT";


    return 0;

}