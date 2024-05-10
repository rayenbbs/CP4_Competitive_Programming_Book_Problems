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
    vi v1(24);
    vi v2(24);
    vi unsortedresult(24);

    while(cin >>n){
        v1.clear();
        v2.clear();
        unsortedresult.clear();
        f(i,0,n){
            cin >>v1[i];
        }
        f(i,0,n){
            cin >>v2[i];
        }
        umap <int,int> mymap(2*n);
        f(i,0,n){
            mymap[v2[i]]=i;
        }
        f(i,0,n){
            unsortedresult.emplace_back(mymap[v1[i]]);
        }
        int count=0;
        f(i,0,n){ //O(n^2) inversion count with the trivial o(n^2) bubble sort algo since the input is too low(N<=24)
            f(j,i+1,n){
                if (unsortedresult[i]>unsortedresult[j]){
                    ++count;
                    int temp=unsortedresult[i];
                    unsortedresult[i]=unsortedresult[j];
                    unsortedresult[j]=temp;
                }
            }
        }
        cout<<count<<endl;
    }

}