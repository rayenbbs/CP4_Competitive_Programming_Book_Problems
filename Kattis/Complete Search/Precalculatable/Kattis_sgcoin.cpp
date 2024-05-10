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


long long H(long long previousHash, string &transaction,
            long long token) {
    long long v = previousHash;
    for (int i = 0; i < transaction.length(); i++) {
        v = (v * 31 + transaction[i]) % 1000000007;
    }
    return (v * 7 + token) % 1000000007;
}


vi vect={9999279,9999293,9999307,9999321,9999335,9999349,9999370,9999384,9999398,9999412,9999426,9999440,9999461,9999475,9999489,9999503,9999517,9999531,9999552,9999566,9999580,9999594,9999608,9999622,9999643,9999657,9999671,9999685,9999699,9999713,9999734,9999748,9999762,9999776,9999790,9999804,9999825,9999839,9999853,9999867,9999881,9999895,9999916,9999930,9999944,9999958,9999972,9999986,7,21,35,49,63,84,98,112,126,140,154,175,189,203,217,231,245,266,280,294,308,322,336,357,371,385,399,413,427,448,462,476,490,504,518,539,553,567,581,595,609,630,644,658,672,686,700,721,735,749,763,777,791};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long q;
    cin >>q;
    string a="g";
    int temp=vect[q/10000000];
    int hash=H(q,a,temp);
    cout<<"g "<< temp<<endl;
    cout<<"g "<<vect[hash/10000000]<<endl;

    return 0;




}