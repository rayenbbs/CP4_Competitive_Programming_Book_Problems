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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    int countest=1;
    f(T,0,t){
        if (countest!=1) cout<<endl;
        countest++;
        umap<char,int> mymap;
        umap <int,char> revmap;
        uset <char> myset;
        int E1;
        int V1=0;
        cin >>E1;
        vii AM1(500,vi(500,INF));
        f(i,0,E1){
            char a,b;
            cin >>a>>b;
            if (myset.find(a)==myset.end())
            {
                myset.insert(a);
                mymap[a]=V1;
                revmap[V1]=a;
                ++V1;
            }
            if (myset.find(b)==myset.end())
            {
                myset.insert(b);
                mymap[b]=V1;
                revmap[V1]=b;
                ++V1;
            }
            AM1[mymap[a]][mymap[b]]=1;
        }
        cin >>E1;
        vii AM2(500,vi(500,INF));
        f(i,0,E1){
            char a,b;
            cin >>a>>b;
            if (myset.find(a)==myset.end())
            {
                myset.insert(a);
                mymap[a]=V1;
                revmap[V1]=a;
                ++V1;
            }
            if (myset.find(b)==myset.end())
            {
                myset.insert(b);
                mymap[b]=V1;
                revmap[V1]=b;
                ++V1;
            }
            AM2[mymap[a]][mymap[b]]=1;
        }
        f(i,0,V1){
            AM1[i][i]=0;
            AM2[i][i]=0;
        }
        for (int k = 0; k < V1; ++k) // loop order is k->i->j
            for (int i = 0; i < V1; ++i)
                for (int j = 0; j < V1; ++j)
                    AM1[i][j] = min(AM1[i][j], AM1[i][k]+AM1[k][j]);
        for (int k = 0; k < V1; ++k) // loop order is k->i->j
            for (int i = 0; i < V1; ++i)
                for (int j = 0; j < V1; ++j)
                    AM2[i][j] = min(AM2[i][j], AM2[i][k]+AM2[k][j]);
        bool test=true;
        for (int i = 0; i < V1; ++i)
            for (int j = 0; j < V1; ++j)
            {
                if ((AM1[i][j]==INF && AM2[i][j] !=INF) || (AM1[i][j]!=INF && AM2[i][j] ==INF )){
                    test=false;
                }
            }
        if (test)
            cout<<"YES\n";
        else cout<<"NO\n";
    }



    return 0;

}