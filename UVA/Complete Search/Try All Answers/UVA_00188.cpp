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

int process(string a){
    int hash=0;
    f(i,0,a.size()){
        hash+=(a[i]-'a'+1)<<(5*(a.size()-i-1));
    }
    return hash;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string line;
    vi hashes;
    while(getline(cin,line)){
        hashes.clear();
        stringstream s(line);
        string a;
        while(s>>a){
            hashes.pb(process(a));
        }
        sort(hashes.begin(),hashes.end());
        int c=hashes[0];
        int n=hashes.size();
        while(true){
            bool test=true;
            int nextcandidate=-1;
            f(i,0,hashes.size()){
                f(j,i+1,hashes.size()){
                    if (c/hashes[i]%n==c/hashes[j]%n){
                        nextcandidate=max(nextcandidate,min((c/hashes[i]+1)*hashes[i],(c/hashes[j]+1)*hashes[j]));
                        test=false;
                    }
                }
            }
            if (test)
                break;
            c=nextcandidate;
        }
        cout<<line<<'\n';
        cout<<c<<"\n\n";

    }
}
