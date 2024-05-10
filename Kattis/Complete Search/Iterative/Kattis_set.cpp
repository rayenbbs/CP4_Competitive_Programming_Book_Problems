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
    vector<string> v(12);
    string q;

    f(i,0,12){
        cin >>q;
        v[i]=q;
    }
    int countresults=0;
    f(a,0,12-2){
        f(b,a+1,12-1)
        {
            f(c,b+1,12){
                string s1=v[a];
                string s2=v[b];
                string s3=v[c];
                int test=true;
                f(i,0,4){
                    if (!(s1[i]==s2[i] && s2[i]==s3[i])){
                        if (s1[i]==s2[i] || s2[i]==s3[i] || s3[i]==s1[i]){
                            test=false;
                        }
                    }
                }
                if (test){
                    ++countresults;
                    cout<<a+1<<" "<<b+1<<" "<<c+1<<endl;
                }
            }
        }
    }
    if(!countresults){
        cout<<"no sets"<<endl;
    }


}