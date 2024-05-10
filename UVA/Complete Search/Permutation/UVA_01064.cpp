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
    int n,m;
    cin >>n>>m;
    int testcount=1;
    while(n!=0 || m!=0){
        cout<<"Case "<<testcount++<<": ";
        vi lengthm(n);
        f(i,0,n){
            cin >>lengthm[i];
        }
        vector<pair<int,pair<int,int>>> packetsorder;
        vector<vector<pair<int,int>>> packets(5,vector<pair<int,int>>());
        f(i,0,m){
            int mes,s,e;
            cin >>mes>>s>>e;
            packetsorder.push_back({mes-1,{s,e}});
            packets[mes-1].eb(s,e);
        }
        vi order={0,1,2,3,4};
        int buffersize;
        int maxf=INF;
        do{
            int intermax=0;
            f(i,0,5){
                buffersize=0;
                vector<pair<int,pair<int,int>>> buffer;
                int prev=1;
                f(j,0,packetsorder.size()){
                    if (prev>lengthm[order[i]])
                        break;
                    int findindice;
                    f(inter,0,5){
                        if (order[inter]==packetsorder[j].first){
                            findindice=inter;
                        }
                    }
                    if(packetsorder[j].first==order[i]){
                        if (packetsorder[j].second.first==prev){
                            prev=packetsorder[j].second.second+1;
                            bool test=true;
                            while(test){
                                test=false;
                                f(t,0,buffer.size()){
                                    if (buffer[t].first==order[i] && buffer[t].second.first==prev){
                                        buffersize-=(buffer[t].second.second-buffer[t].second.first+1);
                                        test=true;
                                        prev=buffer[t].second.second+1;
                                    }
                                }
                            }
                            continue;
                        }
                        else if (packetsorder[j].second.first!=prev){
                            buffersize+=(packetsorder[j].second.second-packetsorder[j].second.first+1);
                            intermax=max(intermax,buffersize);
                            buffer.push_back({packetsorder[j].first,{packetsorder[j].second.first,packetsorder[j].second.second}});
                        }
                    }
                    else if (findindice<i)
                        continue;
                    else{
                        buffersize+=(packetsorder[j].second.second-packetsorder[j].second.first+1);
                        intermax=max(intermax,buffersize);
                        buffer.push_back({packetsorder[j].first,{packetsorder[j].second.first,packetsorder[j].second.second}});
                    }
                }
            }
            maxf=min(maxf,intermax);
        }while(next_permutation(order.begin(),order.end()));
        cout<<maxf<<"\n\n";
        cin >>n>>m;
    }
}