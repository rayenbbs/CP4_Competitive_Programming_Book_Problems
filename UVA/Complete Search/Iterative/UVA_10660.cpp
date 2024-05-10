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

vii grid(5,vi(5,0));


pair<int,int> cord(int a){
    pair<int,int> temp={a/5,a%5};
    return(temp);
}

int dist(int a,int b,int c,int d ,int e){
    pair<int,int> coorda=cord(a);
    pair<int,int> coordb=cord(b);
    pair<int,int> coordc=cord(c);
    pair<int,int> coordd=cord(d);
    pair<int,int> coorde=cord(e);
    int distance=0;
    f(i,0,5){
        f(j,0,5){
            int value=grid[i][j];
            int mindist=INF;
            mindist=min(mindist,(abs(coorda.first-i)+abs(coorda.second-j)));
            mindist=min(mindist,(abs(coordb.first-i)+abs(coordb.second-j)));
            mindist=min(mindist,(abs(coordc.first-i)+abs(coordc.second-j)));
            mindist=min(mindist,(abs(coordd.first-i)+abs(coordd.second-j)));
            mindist=min(mindist,(abs(coorde.first-i)+abs(coorde.second-j)));
            distance+=mindist*value;
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    while(t--){
        grid.assign(5,vi(5,0));
        int n;
        cin >>n;
        vector<pair<int,int>> test;
        f(i,0,n){
            int r,c,val;
            cin >>r>>c>>val;
            test.eb(r,c);
            grid[r][c]=val;
        }
        int min=INF;
        vi candidates(5);
        f(a,0,25-4){
            f(b,a+1,25-3){
                f(c,b+1,25-2){
                    f(d,c+1,25-1){
                        f(e,d+1,25){
                            int sum=dist(a,b,c,d,e);
                            if (sum<min){
                                min=sum;
                                candidates[0]=a;
                                candidates[1]=b;
                                candidates[2]=c;
                                candidates[3]=d;
                                candidates[4]=e;
                            }
                        }
                    }
                }
            }
        }
        printf("%d %d %d %d %d\n",candidates[0],candidates[1],candidates[2],candidates[3],candidates[4]);

    }


}