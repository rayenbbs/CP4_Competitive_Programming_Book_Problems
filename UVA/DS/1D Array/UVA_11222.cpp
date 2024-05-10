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

    int t;
    cin>>t;
    cin.ignore();

    int testcount=1;
    while(t--){
        cout<<"Case #"<<testcount++<<":\n";
        uset<int> f1;
        uset<int> f2;
        uset<int> f3;
        int s,a;
        cin>>s;
        while(s--){
            cin>>a;
            f1.insert(a);
        }
        cin>>s;
        while(s--){
            cin>>a;
            f2.insert(a);
        }
        cin>>s;
        while(s--){
            cin>>a;
            f3.insert(a);
        }
        vi result1;
        vi result2;
        vi result3;
        for(auto u:f1){
            if (f2.find(u)==f2.end() && f3.find(u)==f3.end()){
                result1.pb(u);
            }
        }
        for(auto u:f2){
            if (f1.find(u)==f1.end() && f3.find(u)==f3.end()){
                result2.pb(u);
            }
        }
        for(auto u:f3){
            if (f1.find(u)==f1.end() && f2.find(u)==f2.end()){
                result3.pb(u);
            }
        }
        sort(result1.begin(),result1.end());
        sort(result2.begin(),result2.end());
        sort(result3.begin(),result3.end());

        if (result1.size()>= result2.size() && result1.size()>=result3.size()){
            cout<<"1 "<<result1.size();
            f(i,0,result1.size()){
                cout<<" "<<result1[i];
            }
            cout<<'\n';
        }
        if (result2.size()>= result1.size() && result2.size()>=result3.size()){
            cout<<"2 "<<result2.size();
            f(i,0,result2.size()){
                cout<<" "<<result2[i];
            }
            cout<<'\n';

        }
        if (result3.size()>= result1.size() && result3.size()>=result2.size()){
            cout<<"3 "<<result3.size();
            f(i,0,result3.size()){
                cout<<" "<<result3[i];
            }
            cout<<'\n';

        }
    }
    return 0;
}

