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
    //ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin>>n;
    int l=1; int r=n;
    int w1,w2;
    while(true) {
        if (r-l+1==1) {
            cout<<"A "<<l<<'\n';
            fflush(stdout);
            return 0;
        }
        else if (r-l+1==2){
            cout<<"Q "<<l<<" "<<l<<" "<<r<<" "<<r<<'\n';
            fflush(stdout);
            cin >>w1>>w2;
            if (w1==1){
                cout<<"A "<<l<<'\n';
                fflush(stdout);
                return 0;
            }
            else {
                cout<<"A "<<r<<'\n';
                fflush(stdout);
                return 0;
            }
        }
        else if (r-l+1==3){
            cout<<"Q "<<l<<" "<<l+1<<" "<<l+1<<" "<<r<<'\n';
            fflush(stdout);
            cin >>w1>>w2;
            if (w1==w2 && w1==1){
                cout<<"A "<<l+1<<'\n';
                fflush(stdout);
                return 0;
            }
            else if(w1==1 && w2==0){
                cout<<"A "<<l<<'\n';
                fflush(stdout);
                return 0;
            }
            else {
                cout << "A " << r << '\n';
                fflush(stdout);
                return 0;
            }
        }
        else if (r-l+1==4){
            cout<<"Q "<<l+1<<" "<<l+2<<" "<<l+2<<" "<<r<<'\n';
            fflush(stdout);
            cin >>w1>>w2;
            if (w1==w2 && w1==1){
                cout<<"A "<<l+2<<'\n';
                fflush(stdout);
                return 0;
            }
            else if(w1==1 && w2==0){
                cout<<"A "<<l+1<<'\n';
                fflush(stdout);
                return 0;
            }
            else if(w1==0 && w2==1){
                cout<<"A "<<r<<'\n';
                fflush(stdout);
                return 0;
            }
            else{
                cout<<"A "<<l<<'\n';
                fflush(stdout);
                return 0;
            }
        }
        else{
            int dist=r-l+1;
            int l1=l+(int)(dist*0.25),r1=l+(int)(dist*0.75)-1,l2=l+(int)(dist*0.5)-1,r2=r;
            cout<<"Q "<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<'\n';
            fflush(stdout);
            cin >>w1>>w2;
            if (w1 == 1 && w2 == 1) {
                l =  max(1,l2 - 1);
                r = min(n,r1 + 1);
                if (l2 == r1){
                    cout << "A " << r1 << endl;
                    return 0;
                }
            } else if (w1 == 0 && w2 == 1) {
                if (r2 - r1<=1){
                    cout << "A " << r2 << endl;
                    return 0;
                }
                l = r1;
                r=min(n,r2+1);
            } else if(w1==0 && w2==0) {
                if (l1 - l <=1){
                    cout << "A " << l << endl;
                    return 0;
                }
                r = l1;
                l=max(1,l-1);
            }
            else{
                if (l2 - l1<=1){
                    cout << "A " << l1 << endl;
                    return 0;
                }
                l = max(1,l1 - 1);
                r = l2;
            }
        }
    }
}