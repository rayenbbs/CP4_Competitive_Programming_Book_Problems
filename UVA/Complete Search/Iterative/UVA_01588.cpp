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
    string a;
    string b;
    int result;
    while(cin >>a){
        result=INF;
        cin >>b;
        f(i,0,a.size()){
            f(j,0,b.size()){
                if (a[i]!='2' || b[j]!='2'){
                    int len=1;
                    int tempa=i-1;
                    int tempb=j-1;
                    int test=true;
                    while (test && tempb>=0 && tempa>=0){
                        if (a[tempa]=='2' && b[tempb]=='2'){
                            test=false;
                            break;
                        }
                        ++len;
                        --tempa;
                        --tempb;
                    }
                    if (tempb>=0){
                        len+=tempb+1;
                    }
                    if (tempa>=0){
                        len+=tempa+1;
                    }
                    tempa=i+1;
                    tempb=j+1;
                    while (test && tempb<b.size() && tempa<a.size()){

                        if (a[tempa]=='2' && b[tempb]=='2'){
                            test=false;
                            break;
                        }
                        ++len;
                        ++tempa;
                        ++tempb;
                    }
                    if (tempb<b.size()){
                        len+=b.size()-tempb;
                    }
                    if (tempa<a.size()){
                        len+=a.size()-tempa;
                    }
                    if (test){
                        result=min(result,len);
                    }
                }
            }
        }
        if (result==INF)
            cout<<a.size()+b.size()<<endl;
        else
            cout<<result<<endl;
    }

}