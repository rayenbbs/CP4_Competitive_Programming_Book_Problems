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



int n,h;
int t;

bool shouldSwap(string &str, int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void permut(string &a, int indice){
    if (indice==a.size()){
        cout<<a<<endl;
    }
    else{
        f(i,indice,a.size()){
            bool check = shouldSwap(a, indice, i);
            if (check){
                char temp=a[indice];
                a[indice]=a[i];
                a[i]=temp;
                permut(a, indice + 1);
                temp=a[i];
                a[i]=a[indice];
                a[indice]=temp;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>t;
    while(t--){
        cin >>n>>h;
        string a(n,'0');
        f(i,n-h,n){
            a[i]='1';
        }
        permut(a,0);
        if (t!=0)
            cout<<"\n";
    }

}


