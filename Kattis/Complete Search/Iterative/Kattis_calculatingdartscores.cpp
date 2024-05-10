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
    int n;
    cin >>n;
    f(a,0,21){
        f(ca,1,4)
        {
            f(b,0,21){
                f(cb,1,4){
                    f(c,0,21){
                        f(cc,1,4){
                            if (a*ca+b*cb+c*cc==n){
                                if (a!=0){
                                    if (ca==1){
                                        cout<<"single "<<a<<endl;
                                    }
                                    else if(ca==2){
                                        cout<<"double "<<a<<endl;
                                    }
                                    else cout<<"triple "<<a<<endl;
                                }

                                if (b!=0){
                                    if (cb==1){
                                        cout<<"single "<<b<<endl;
                                    }
                                    else if(cb==2){
                                        cout<<"double "<<b<<endl;
                                    }
                                    else cout<<"triple "<<b<<endl;
                                }
                                if (c!=0){
                                    if (cc==1){
                                        cout<<"single "<<c<<endl;
                                    }
                                    else if(cc==2){
                                        cout<<"double "<<c<<endl;
                                    }
                                    else cout<<"triple "<<c<<endl;
                                }
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<"impossible\n";



}