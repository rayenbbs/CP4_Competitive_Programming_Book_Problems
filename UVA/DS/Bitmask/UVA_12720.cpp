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

int getMod(vi& str, int n, int k)
{

    // pwrTwo[i] will store ((2^i) % k)
    int pwrTwo[n];
    pwrTwo[0] = 1 % k;
    for (int i = 1; i < n; i++)
    {
        pwrTwo[i] = pwrTwo[i - 1] * (2 % k);
        pwrTwo[i] %= k;
    }

    // To store the result
    int res = 0;
    int i = 0, j = n - 1;
    while (i < n)
    {

        // If current bit is 1
        if (str[j] == 1)
        {
            // Add the current power of 2
            res += (pwrTwo[i]);
            res %= k;
        }
        i++;
        j--;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin >>test;
    f(t,0,test){
        cout<<"Case #"<<t+1<<": ";
        string target;
        vi stack;
        queue<int> q;
        cin >>target;
        f(i,0,target.size()){
            if (i<(int)target.size()/2)
                stack.push_back(target[i]-'0');
            else q.push(target[i]-'0');
        }
        vi result;
        while(!stack.empty() || !q.empty()){
            if (stack.size()>q.size()){
                result.push_back(stack[stack.size()-1]);
                stack.pop_back();
            }
            else if (stack.size()==q.size()){
                if (stack[stack.size()-1]>q.front()){
                    result.push_back(stack[stack.size()-1]);
                    stack.pop_back();
                }
                else
                {
                    result.push_back(q.front());
                    q.pop();
                }
            }
            else{
                result.push_back(q.front());
                q.pop();
            }
        }
        cout<<getMod(result,result.size(),MOD)<<endl;
    }

}