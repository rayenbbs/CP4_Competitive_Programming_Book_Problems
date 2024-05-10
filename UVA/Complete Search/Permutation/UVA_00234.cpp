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
    int p;
    cin >>p;
    int testcount=1;
    while(p!=0){
        vi vresult;
        vi v;
        f(i,0,p){
            int t;
            cin >>t;
            v.pb(t);
        }
        int a;
        vi v1;
        vi v2;
        vi v3;
        vi v4;
        vi v5;
        cin >>a;
        f(i,0,a){
            int p1,p2;
            cin >>p1>>p2;
            if(p1==1){
                v1.pb(p2);
            }
            if(p1==2){
                v2.pb(p2);
            }
            if(p1==3){
                v3.pb(p2);
            }
            if(p1==4){
                v4.pb(p2);
            }
            if(p1==5){
                v5.pb(p2);
            }
        }
        int min1=INF;
        int min2=INF;
        int min3=INF;
        int min4=INF;
        int min5=INF;
        sort(v.begin(),v.end());
        do{
            ll intermin1=INF;
            ll intermin2=INF;
            ll intermin3=INF;
            ll intermin4=INF;
            ll intermin5=INF;
            if (!v1.empty()){
                intermin1=0;
            }
            if (!v2.empty()){
                intermin2=0;
            }
            if (!v3.empty()){
                intermin3=0;
            }
            if (!v4.empty()){
                intermin4=0;
            }
            if (!v5.empty()){
                intermin5=0;
            }
            f(j,0,v1.size()){
                ll sum=0;
                ll mini=INF;
                mini=min(mini,abs(v1[j]-sum));
                f(i,0,v.size()){
                    sum+=v[i];
                    mini=min(mini,abs(v1[j]-sum));
                }
                intermin1+=mini;
            }
            f(j,0,v2.size()){
                int sum=0;
                int mini=INF;
                mini=min(mini,abs(v2[j]-sum));
                f(i,0,v.size()){
                    sum+=v[i];
                    mini=min(mini,abs(v2[j]-sum));
                }
                intermin2+=mini;
            }
            f(j,0,v3.size()){
                int sum=0;
                int mini=INF;
                mini=min(mini,abs(v3[j]-sum));

                f(i,0,v.size()){
                    sum+=v[i];
                    mini=min(mini,abs(v3[j]-sum));
                }
                intermin3+=mini;
            }
            f(j,0,v4.size()){
                int sum=0;
                int mini=INF;
                mini=min(mini,abs(v4[j]-sum));
                f(i,0,v.size()){
                    sum+=v[i];
                    mini=min(mini,abs(v4[j]-sum));
                }
                intermin4+=mini;
            }
            f(j,0,v5.size()){
                int sum=0;
                int mini=INF;
                mini=min(mini,abs(v5[j]-sum));

                f(i,0,v.size()){
                    sum+=v[i];
                    mini=min(mini,abs(v5[j]-sum));
                }
                intermin5+=mini;
            }
            if (intermin1<min1 ){
                min1=intermin1;
                min2=intermin2;
                min3=intermin3;
                min4=intermin4;
                min5=intermin5;
                vresult.clear();
                f(m,0,v.size()){
                    vresult.pb(v[m]);
                }
            }
            else if (intermin1==min1){
                if (intermin2<min2){
                    min2=intermin2;
                    min3=intermin3;
                    min4=intermin4;
                    min5=intermin5;
                    vresult.clear();
                    f(m,0,v.size()){
                        vresult.pb(v[m]);
                    }
                }
                else if (intermin2==min2){

                    if (intermin3<min3){
                        min3=intermin3;
                        min4=intermin4;
                        min5=intermin5;
                        vresult.clear();
                        f(m,0,v.size()){
                            vresult.pb(v[m]);
                        }
                    }
                    else if (intermin3==min3){
                        if (intermin4<min4){
                            min4=intermin4;
                            min5=intermin5;
                            vresult.clear();
                            f(m,0,v.size()){
                                vresult.pb(v[m]);
                            }
                        }
                        else if (intermin4==min4){
                            if (intermin5<min5){
                                min5=intermin5;
                                vresult.clear();
                                f(m,0,v.size()){
                                    vresult.pb(v[m]);
                                }
                            }
                        }
                    }
                }
            }
        }while(next_permutation(v.begin(),v.end()));
        cout<<"Data set "<<testcount++<<'\n';
        cout<<"Order:";
        f(i,0,vresult.size()){
            cout<<" "<<vresult[i];
        }
        cout<<"\n";
        int total=0;
        if (min1!=INF){
            total+=min1;
        }
        if (min2!=INF){
            total+=min2;
        }
        if (min3!=INF){
            total+=min3;
        }
        if (min4!=INF){
            total+=min4;
        }
        if (min5!=INF){
            total+=min5;
        }
        cout<<"Error: "<<total<<'\n';
        cin >>p;
    }
}