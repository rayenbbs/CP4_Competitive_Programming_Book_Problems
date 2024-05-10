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

pair<int,int> evaluate(vi& v){
    int nominator=0;
    int denominator=0;
    f(i,0,5){
        nominator+=(v[i]*pow(10,4-i));
    }
    f(i,5,10){
        denominator+=(v[i]*pow(10,9-i));
    }
    return{nominator,denominator};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vi digits(10);
    f(i,0,10){
        digits[i]=i;
    }
    umap <int,int> mymap;
    int n;
    cin >>n;
    int t=0;
    vi ns;
    while(n!=0){
        ns.pb(n);
        mymap[n]=t++;
        cin >>n;
    }
    vector<vector<pair<int,int>>> results(t);
    do{
        pair<int,int> test= evaluate(digits);
        if (test.first%test.second==0 && mymap.find(test.first/test.second)!=mymap.end()){
            results[mymap[test.first/test.second]].eb(test.first,test.second);
        }
    }while(next_permutation(digits.begin(),digits.end()));
    f(i,0,ns.size()){
        if (i!=0)printf("\n");
        int target=ns[i];
        if (results[mymap[target]].empty()){
            printf("There are no solutions for %d.\n",target);
        }
        else {
            sort(results[mymap[target]].begin(),results[mymap[target]].end());
            for (pair<int, int> v: results[mymap[target]]) {
                printf("%05d / %05d = %d\n", v.first, v.second, target);
            }
        }
    }

}
