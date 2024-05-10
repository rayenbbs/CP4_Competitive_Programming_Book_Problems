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




void backtrack(vi &solution,vi &temp,int s,int indice,vi &scores,int score){
    if (score>s)
        return;
    if (!solution.empty() && temp.size()>solution.size()){
        return ;
    }
    else if(score==s && solution.empty()){
        solution.assign(temp.begin(),temp.end());
        return ;
    }
    else if(score==s && !solution.empty() && temp.size()<solution.size()){
        solution.assign(temp.begin(),temp.end());
        return ;
    }
    else{
        temp.pb(scores[indice]);
        score+=scores[indice];
        f(i,indice,scores.size()){
            backtrack(solution,temp,s,i,scores,score);
        }
        temp.pop_back();
    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    int testcount=1;
    while(t--){
        cout<<"Case "<<testcount++<<": ";
        int n,s;
        cin >>n>>s;
        vi v(n);
        f(i,0,n){
            int a;
            cin >>a;
            v[i]=a;
        }
        sort(v.begin(),v.end(),[](int a,int b){
            return a>b;
        });
        vi solution;
        vi temp;
        f(i,0,n){
            backtrack(solution,temp,s,i,v,0);
        }

        if (!solution.empty()){
            cout<<"["<<solution.size()<<"]";
            f(i,0,solution.size()){
                cout<<" "<<solution[i];
            }
            cout<<endl;
        }
        else cout<<"impossible\n";

    }
}


