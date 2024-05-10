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


    int t;
    cin >>t;
    int testcount=1;
    vector<pair<string,pair<int,int>>> players(10);
    while(t--){
        f(i,0,10){
            string s;
            int a,d;
            cin >>s>>a>>d;
            players[i]={s,{a,d}};
        }
        sort(players.begin(),players.end(),[](pair<string,pair<int,int>> a,pair<string,pair<int,int>> b){
            return a.first<b.first;
        });
        vi results(5);
        int maxa=-1;
        int maxd=INF;
        f(a,0,10-4){
            f(b,a+1,10-3){
                f(c,b+1,10-2){
                    f(d,c+1,10-1){
                        f(e,d+1,10){
                            int asum=0;
                            int dsum=0;
                            asum+=players[a].second.first;
                            asum+=players[b].second.first;
                            asum+=players[c].second.first;
                            asum+=players[d].second.first;
                            asum+=players[e].second.first;
                            dsum+=players[a].second.second;
                            dsum+=players[b].second.second;
                            dsum+=players[c].second.second;
                            dsum+=players[d].second.second;
                            dsum+=players[e].second.second;
                            if (asum>maxa){
                                maxa=asum;
                                results[0]=a;
                                results[1]=b;
                                results[2]=c;
                                results[3]=d;
                                results[4]=e;
                                maxd=dsum;
                            }
                            else if(asum==maxa){
                                if (dsum<maxd){
                                    results[0]=a;
                                    results[1]=b;
                                    results[2]=c;
                                    results[3]=d;
                                    results[4]=e;
                                    maxd=dsum;
                                }
                            }
                        }
                    }
                }
            }
        }
        uset<string> myset;
        cout << "Case " << testcount++ << ":\n";
        cout << "(" << players[results[0]].first << ", " << players[results[1]].first << ", " << players[results[2]].first << ", " << players[results[3]].first << ", " << players[results[4]].first << ")\n";
        f(i,0,5){
            myset.insert(players[results[i]].first);
        }
        vector<string> resultd;
        f(i,0,10){
            if (myset.find(players[i].first)==myset.end()){
                resultd.pb(players[i].first);
            }
        }
        cout << "(" << resultd[0] << ", " << resultd[1]  << ", " << resultd[2]  << ", " << resultd[3]  << ", " << resultd[4]  << ")\n";

    }



}
