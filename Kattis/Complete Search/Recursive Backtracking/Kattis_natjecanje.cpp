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




//iterative solution with sets


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,r;
    cin >>n>>s>>r;
    uset <int> sset;
    uset <int> rset;
    vi vs(s);
    f(i,0,s){
        int a;
        cin >>a;
        vs[i]=a;
        sset.insert(a);
    }
    f(i,0,r){
        int a;
        cin >>a;
        rset.insert(a);
    }
    uset<int> solved;
    f(i,1,n+1){
        if (rset.find(i)!=rset.end()){
            if (sset.find(i)!=sset.end()){
                solved.insert(i);
                rset.erase(i);
            }
        }
    }
    f(i,1,n+1){
        if (rset.find(i)!=rset.end()){
            if (i-1>0){
                if  (sset.find(i-1)!=sset.end()){
                    if (solved.find(i-1)==solved.end()){
                        solved.insert(i-1);
                        continue;
                    }
                }
            }
            if (i+1<=n){
                if  (sset.find(i+1)!=sset.end()){
                    if (solved.find(i+1)==solved.end()){
                        solved.insert(i+1);
                        continue;
                    }
                }
            }
        }
    }
    int result=0;
    f(i,0,vs.size()){
        if (solved.find(vs[i])==solved.end()){
            ++result;
        }
    }
    cout<<result<<'\n';
}


// Solution with backtracking
/*

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




void backtrack(int n,uset<int> &solved,uset<int> &rset,uset<int> &sset,int count,int limit,int &result) {
    if (n==limit){
        result=max(result,count);
        return;
    }
    else if (rset.find(n)!=rset.end()){
        if (sset.find(n)!=sset.end()){
            if (solved.find(n)==solved.end()) {
                solved.insert(n);
                ++count;
                result=max(result,count);
            }
            backtrack(n + 1, solved, rset, sset, count, limit, result);
        }
        else {
            if (sset.find(n - 1) != sset.end()) {
                if (solved.find(n - 1) == solved.end()) {
                    solved.insert(n - 1);
                    ++count;
                    result = max(result, count);
                    backtrack(n + 1, solved, rset, sset, count, limit, result);
                    solved.erase(n - 1);
                    --count;
                }
            }
            if (sset.find(n + 1) != sset.end()) {
                if (solved.find(n + 1) == solved.end()) {
                    solved.insert(n + 1);
                    ++count;
                    result = max(result, count);
                    backtrack(n + 1, solved, rset, sset, count, limit, result);
                    solved.erase(n + 1);
                    --count;
                }
            }
            backtrack(n + 1, solved, rset, sset, count, limit, result);
        }
    }
    else
        backtrack(n+1,solved,rset,sset,count,limit,result);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,s,r;
    cin >>n>>s>>r;
    uset <int> sset;
    uset <int> rset;
    vi vs(s);
    f(i,0,s){
        int a;
        cin >>a;
        vs[i]=a;
        sset.insert(a);
    }
    f(i,0,r){
        int a;
        cin >>a;
        rset.insert(a);
    }

    uset<int> solved;
    int count=0;
    int result=-1;
    backtrack(1,solved,rset,sset,count,n+1,result);
    cout<<s-result<<endl;
}






 */