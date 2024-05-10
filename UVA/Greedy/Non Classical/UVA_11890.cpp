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

string expr;
int n;
deque<int> dq;

pair<ll,int> eval(bool currindicator,int indice){
    ll total=0;
    while (indice<expr.size()){
        if (expr[indice]==')'){
            break;
        }
        else if (expr[indice]=='+'){
            if (expr[indice+1]=='x'){
                if (currindicator){
                    total+=dq.back();
                    dq.pop_back();
                }
                else{
                    total-=dq.front();
                    dq.pop_front();
                }
                indice+=2;
            }
            else if(expr[indice+1]=='('){
                pair<ll,int> temp=eval(currindicator,indice+2);
                total+=temp.first;
                indice=temp.second;
            }
        }
        else if (expr[indice]=='-'){
            if (expr[indice+1]=='x'){
                if (!currindicator){
                    total+=dq.back();
                    dq.pop_back();
                }
                else{
                    total-=dq.front();
                    dq.pop_front();
                }
                indice+=2;
            }
            else if(expr[indice+1]=='('){
                pair<ll,int> temp=eval(!currindicator,indice+2);
                total+=temp.first;
                indice=temp.second;
            }
        }
        else if (expr[indice]=='x'){
            if (currindicator){
                total+=dq.back();
                dq.pop_back();
            }
            else{
                total-=dq.front();
                dq.pop_front();
            }
            indice++;
        }
        else if(expr[indice]=='('){
            pair<ll,int> temp=eval(currindicator,indice+1);
            total+=temp.first;
            indice=temp.second;
        }
    }
    return {total,indice+1};
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        dq.clear();
        cin>>expr>>n;
        f(i,0,n){
            int a;
            cin>>a;
            dq.push_back(a);
        }
        sort(dq.begin(),dq.end());
        cout<<eval(true,0).first<<'\n';
    }
}


