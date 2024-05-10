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

string target;
ll counti;
string temp;
vi indices;

uset<char> vowels={'A','E','I','O','U'};

void backtrack(int indice, bool L){
    if (indice-1>=0 && indice-2>=0 && indice-3>=0) {
        if (vowels.find(target[indice - 1]) == vowels.end() && vowels.find(target[indice - 2]) == vowels.end() &&
            vowels.find(target[indice - 3]) == vowels.end())
        {
            return;
        }
        else if (vowels.find(target[indice - 1]) != vowels.end() && vowels.find(target[indice - 2]) != vowels.end() &&
                 vowels.find(target[indice - 3]) != vowels.end()) {
            return;
        }
    }
    if (indice==target.size()){

        if (L)
        {
            int powa=0;
            int powb=0;
            f(i,0,indices.size()){
                if (target[indices[i]]!='L'){
                    if (vowels.find(target[indices[i]])!=vowels.end()){
                        powa++;
                    }
                    if (vowels.find(target[indices[i]])==vowels.end()){
                        powb++;
                    }
                }
            }
            ll counta=(ll)pow(5,powa);
            ll countb=(ll)pow(20,powb);
            counti+=counta*countb;
        }
        return;
    }
    else if (target[indice]!='_') {
        backtrack(indice + 1, L);
    }
    else if (target[indice]=='_'){
        if (indice-1>=0 && indice-2>=0) {
            if (vowels.find(target[indice - 1]) == vowels.end() && vowels.find(target[indice - 2]) == vowels.end())  {
                bool test = false;
                char temp = 'A';
                target[indice] = temp;
                backtrack(indice + 1, L||test);
                test = false;
                target[indice] = '_';
            }
            else if (vowels.find(target[indice - 1]) != vowels.end() && vowels.find(target[indice - 2]) != vowels.end())  {
                bool test = false;
                char temp = 'B';
                target[indice] = temp;
                if (target[indice] == 'L') {
                    test = true;
                }
                backtrack(indice + 1, L||test);
                test = false;
                target[indice] = '_';
                temp = 'L';
                target[indice] = temp;
                if (target[indice] == 'L') {
                    test = true;
                }
                backtrack(indice + 1, L||test);
                target[indice] = '_';

            }
            else{
                bool test = false;
                char temp = 'A';
                target[indice] = temp;
                if (target[indice] == 'L') {
                    test = true;
                }
                backtrack(indice + 1, L||test);
                target[indice] = '_';
                temp = 'B';
                target[indice] = temp;
                if (target[indice] == 'L') {
                    test = true;
                }
                backtrack(indice + 1, L||test);
                target[indice] = '_';
                temp = 'L';
                target[indice] = temp;
                if (target[indice] == 'L') {
                    test = true;
                }
                backtrack(indice + 1, L||test);
                target[indice] = '_';

            }

        }
        else{
            bool test = false;
            char temp = 'A';
            target[indice] = temp;
            if (target[indice] == 'L') {
                test = true;
            }
            backtrack(indice + 1, L||test);
            target[indice] = '_';
            temp = 'B';
            target[indice] = temp;
            if (target[indice] == 'L') {
                test = true;
            }
            backtrack(indice + 1, L||test);
            target[indice] = '_';
            temp = 'L';
            target[indice] = temp;
            if (target[indice] == 'L') {
                test = true;
            }
            backtrack(indice + 1, L||test);
            target[indice] = '_';
        }

    }
}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>target;
    bool tempbol=false;
    f(i,0,target.size()){
        if (target[i]=='L'){
            tempbol=true;
        }
        else if (target[i]=='_'){
            indices.pb(i);
        }
    }
    counti=0;
    backtrack(0,tempbol);
    cout<<counti<<endl;


}