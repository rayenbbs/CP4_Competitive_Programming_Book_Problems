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
    uset<int> count(20);
    int testcount=1;
    uset <int> myset(20);
    int total;
    vi result(5);
    vi weights(10);
    int countdistinct;
    int countint;
    bool test;
    umap <int,int> mymap;
    int q;
    while(t--){
        printf("Case %d: ",testcount++);
        total=0;
        myset.clear();
        mymap.clear();
        countdistinct=0;
        f(i,0,10){
            cin >>q;
            weights[i]=q;
            ++mymap[q];
            total+=q;
            if (myset.find(q)==myset.end()) {
                myset.insert(q);
                countdistinct++;
            }
        }
        int maxint=weights[9];
        sort(weights.begin(),weights.end());
        bool bigtest=true;
        f(a,0,weights[0]+1)
        {
            int b=weights[0]-a;
            int c=weights[1]-a;
            int d;
            if (b+c!=weights[2]){
                d=weights[2]-a;
            }
            else d=weights[3]-a;
            if (a + b < ((total / 4) - (3 * (maxint - 1)))) {
                continue;
            }
            if (a + b + c < ((total / 4) - (2 * (maxint - 1)))) {
                continue;
            }
            int e = (total / 4) - a - b - c - d;
            result[0] = a;
            result[1] = b;
            result[2] = c;
            result[3] = d;
            result[4] = e;
            sort(result.begin(), result.end());
            count.clear();
            countint = 0;
            test = false;
            umap <int,int> mapinter;
            f(i, 0, 5) {
                f(j, i + 1, 5) {
                    test = false;
                    if (myset.find(result[i] + result[j]) != myset.end()) {
                        ++mapinter[result[i] + result[j]];
                        test = true;
                        if (count.find(result[i] + result[j]) == count.end()) {
                            count.insert(result[i] + result[j]);
                            ++countint;
                        }
                    }
                    if (!test) {
                        break;
                    }
                }
                if (!test) {
                    break;
                }
            }
            if (countint == countdistinct) {
                bool test1=true;
                f(i,0,10){
                    //printf("%d %d\n",mymap[weights[i]],mapinter[weights[i]]);
                    if (mymap[weights[i]]!=mapinter[weights[i]])
                        test1=false;
                }
                if (test1) {
                    f(i, 0, result.size()) {
                        if (i != 0) {
                            printf(" ");
                        }
                        printf("%d", result[i]);
                    }

                    printf("\n");
                    break;
                }
            }

        }
    }


}