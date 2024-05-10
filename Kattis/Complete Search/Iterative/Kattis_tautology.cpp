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

pair<int,int> evaluate(string a, int indice ,int p, int q,int r,int s , int t){
    if (a[indice]=='p'){
        return {p,indice+1};
    }
    if (a[indice]=='q'){
        return {q,indice+1};
    }
    if (a[indice]=='r'){
        return {r,indice+1};
    }
    if (a[indice]=='s'){
        return {s,indice+1};
    }
    if (a[indice]=='t'){
        return {t,indice+1};
    }
    if (a[indice]=='N'){
        pair<int,int> temp=evaluate(a,indice+1,p,q,r,s,t);
        return {(temp.first+1)%2,temp.second};
    }
    if (a[indice]=='E'){
        pair<int,int> temp1=evaluate(a,indice+1,p,q,r,s,t);
        pair<int,int> temp2=evaluate(a,temp1.second,p,q,r,s,t);
        if (temp1.first==temp2.first){
            return {1,temp2.second};
        }
        else return {0,temp2.second};
    }
    if (a[indice]=='C'){
        pair<int,int> temp1=evaluate(a,indice+1,p,q,r,s,t);
        pair<int,int> temp2=evaluate(a,temp1.second,p,q,r,s,t);
        if (temp1.first==1 && temp2.first==0){
            return {0,temp2.second};
        }
        else return {1,temp2.second};
    }
    if (a[indice]=='A'){
        pair<int,int> temp1=evaluate(a,indice+1,p,q,r,s,t);
        pair<int,int> temp2=evaluate(a,temp1.second,p,q,r,s,t);
        if (temp1.first==0 && temp2.first==0){
            return {0,temp2.second};
        }
        else return {1,temp2.second};
    }
    if (a[indice]=='K'){
        pair<int,int> temp1=evaluate(a,indice+1,p,q,r,s,t);
        pair<int,int> temp2=evaluate(a,temp1.second,p,q,r,s,t);
        if (temp1.first==1 && temp2.first==1){
            return {1,temp2.second};
        }
        else return {0,temp2.second};
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string test;
    cin >>test;
    while(test!="0"){
        int result;
        bool bol=true;
        f(i,0,pow(2,6)) {
            int p, q, r, s, t;
            if (i & 1 << 0) {
                p = 1;
            } else p = 0;
            if (i & 1 << 1) {
                q = 1;
            } else q = 0;
            if (i & 1 << 2) {
                r = 1;
            } else r = 0;
            if (i & 1 << 3) {
                s = 1;
            } else s = 0;
            if (i & 1 << 4) {
                t = 1;
            } else t = 0;
            if (evaluate(test,0,p,q,r,s,t).first==0) {
                bol=false;
                cout<<"not\n";
                break;
            }
        }
        if (bol)
            cout<<"tautology\n";
        cin >>test;

    }
}