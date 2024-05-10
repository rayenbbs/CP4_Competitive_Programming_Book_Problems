#include <bits/stdc++.h>
using namespace std;

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


#define f(i,s,e) for(int i=s;i<e;i++)
#define cf(i,s,e) for(int i=s;i<=e;i++)
#define rf(i,e,s) for(int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()


#define PI 3.1415926535897932384626433832795

#define LSOne(S) ((S) & -(S))




int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin>>t;
    string line;
    getline(cin,line);
    cin.ignore();
    int testcase=0;
    while(t--){
        if (testcase){
            cout<<'\n';
        }
        ++testcase;
        vector<vector<int>>v(100,vector<int>(9));
        vector<pair<pair<int,int>,int>> results(100);
        int team,problem,time;
        char verdict;
        f(i, 0, 100) {
            results[i] = {{0, 0}, i};
        }
        vi submitted(100);
        while(getline(cin,line) && !line.empty() && stringstream(line)>>team>>problem>>time>>verdict) {
            --team; --problem;
            submitted[team]=1;
            if (verdict == 'I') {
                if (v[team][problem] != -1)
                    v[team][problem]++;
            } else if (verdict == 'C') {
                if (v[team][problem] != -1) {
                    results[team].first.first++;
                    results[team].first.second += time + 20*v[team][problem];
                    v[team][problem] = -1;
                }
            }
        }
        sort(results.begin(),results.end(),[](pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
            if (a.first.first==b.first.first){
                if(a.first.second==b.first.second){
                    return (a.second<b.second);
                }
                else{
                    return (a.first.second<b.first.second);
                }
            }
            else{
                return (a.first.first>b.first.first);
            }
        });
        f(i,0,results.size()){
            if(results[i].first.first>0){
                cout<<results[i].second+1<<" "<<results[i].first.first<<" "<<results[i].first.second<<"\n";
            }
            else{
                if (submitted[results[i].second]){
                    cout<<results[i].second+1<<" "<<results[i].first.first<<" "<<results[i].first.second<<"\n";
                }
            }
        }
    }

    return 0;
}
