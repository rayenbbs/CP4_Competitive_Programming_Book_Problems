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
    // O(n^2) algo because input is small
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    int r=0,s=0;
    f(i,0,n){
        if (a[i]==b[i]){
            ++r;
            b[i]='!';
            a[i]='!';
        }
    }
    f(i,0,n){
        if (b[i]!='!'){
            f(j,0,n){
                if (a[j]==b[i]){
                    a[j]='!';
                    b[i]='!';
                    ++s;
                    break;
                }
            }
        }
    }
    cout<<r<<" "<<s<<'\n';
    return 0;
}


/*
 using multiset

 int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    multiset<char> myset;
    f(i,0,a.size()){
        myset.insert(a[i]);
    }
    int r=0,s=0;
    f(i,0,n){
        if (a[i]==b[i]){
            b[i]=-1;
            r++;
            myset.erase(myset.find(a[i]));
        }
    }
    f(i,0,n){
        if(myset.find(b[i])!=myset.end()){
            myset.erase(myset.find(b[i]));
            s++;
        }
    }
    cout<<r<<" "<<s<<'\n';
 *
 */