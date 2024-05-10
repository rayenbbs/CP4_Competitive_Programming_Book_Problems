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
bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    if (x >= 0) {

        long long sr = sqrt(x);

        // if product of square root
        //is equal, then
        // return T/F
        return (sr * sr == x);
    }
    // else return false if n<0
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi result(51);
    vii stacks(50,vi());
    int n=1;
    int count=0;
    f(j,1,1000000){
        bool test=false;
        f(i,0,n){
            if (stacks[i].empty()) {
                ++count;
                stacks[i].eb(j);
                test=true;
                break;
            }
            else{
                if (isPerfectSquare(j+stacks[i].back())){
                    ++count;
                    stacks[i].eb(j);
                    test=true;
                    break;
                }
            }
        }
        if (!test){
            result[n]=count;
            n++;
            if (n==51){
                break;
            }
            count++;
            stacks[n-1].eb(j);
        }
    }
    int t;
    cin >>t;
    while(t--){
        int q;
        cin >>q;
        cout<<result[q]<<endl;
    }
}