#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>
#define umap unordered_map
#define uset unordered_set

#include <bits/extc++.h> // pbds
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag,
        tree_order_statistics_node_update> ost;

#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define PI 3.1415926535897932384626433832795
#define LSOne(S) ((S) & -(S))

const ll INF = 2e18L + 5;
const int MOD = 1e9L + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    int t; cin>>t;
    cin.ignore();
    while(t--) {
        string line;
        getline(cin, line);
        list<char> mylist;
        auto it=mylist.begin();
        for(auto c:line){
            if(c==']')
                it=mylist.end();
            else if(c=='[')
                it=mylist.begin();
            else if(c=='<'){
                if(it==mylist.begin())
                    continue;
                --it;
                it=mylist.erase(it);
            }
            else{
                it=mylist.insert(it,c);
                ++it;
            }
        }
        for(auto c:mylist){
            cout<<c;
        }
        cout<<'\n';

    }



}




