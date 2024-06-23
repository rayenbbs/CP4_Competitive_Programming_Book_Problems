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
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<string> persons(n);
        vector<pair<ll,int>> scores(n);
        f(i,0,n){
            scores[i]={0,i};
            string person; cin>>person; person.pop_back();
            string level; cin>>level;
            string dummy; cin>>dummy;
            persons[i]=person;
            dummy.clear();
            int count=11;
            rf(j,level.size(),0){
                if(j==0){
                    dummy.push_back(level[j]);
                    reverse(dummy.begin(),dummy.end());
                    count--;
                    if(dummy=="upper"){
                        scores[i].first+=((ll)pow(10,count))*3;
                    }
                    else if(dummy=="middle"){
                        scores[i].first+=((ll)pow(10,count))*2;
                    }
                    else{
                        scores[i].first+=((ll)pow(10,count));
                    }
                    dummy.clear();
                }
                else if (level[j]=='-'){
                    reverse(dummy.begin(),dummy.end());
                    count--;
                    if(dummy=="upper"){
                        scores[i].first+=((ll)pow(10,count))*3;
                    }
                    else if(dummy=="middle"){
                        scores[i].first+=((ll)pow(10,count))*2;
                    }
                    else{
                        scores[i].first+=((ll)pow(10,count));
                    }
                    dummy.clear();
                }
                else{
                    dummy.push_back(level[j]);
                }
            }
        }
        sort(scores.begin(),scores.end(),[&persons](auto& a,auto& b){
            ll tempa=a.first,tempb=b.first;
            int dummya=0,dummyb=0;
            while(tempa%10==0){
                dummya++;
                tempa/=10;
            }
            while(tempb%10==0){
                dummyb++;
                tempb/=10;
            }
            if(10-dummyb < 10-dummya){
                f(i,dummya,dummyb){
                    tempb*=10;
                    tempb+=2;
                }
            }
            else{
                f(i,dummyb,dummya){
                    tempa*=10;
                    tempa+=2;
                }
            }

            if(tempa!=tempb){
                return (tempa>tempb);
            }
            else return(persons[a.second]<persons[b.second]);
        });
        f(i,0,n){
            cout<<persons[scores[i].second]<<'\n';
        }
        cout<<"==============================\n";
    }

    return 0;
}