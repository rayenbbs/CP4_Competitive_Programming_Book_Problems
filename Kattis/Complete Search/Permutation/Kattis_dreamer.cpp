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


uset month31={1,3,5,7,8,10,12};
uset month30={4,6,9,11};

bool valid(int day,int month, int year){
    if (year<2000 || month>12 || day>31 || day<=0|| month<=0){
        return false;
    }
    if (month30.find(month)!=month31.end()){
        return (day<=30);
    }
    if (month==2){
        if (year%400==0 ||(year %4==0 && year%100!=0)){
            return (day<=29);
        }
        else return (day<=28);
    }
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >>t;
    vector<char> v(8);
    while(t--){
        f(i,0,8){
            cin >>v[i];
        }
        sort(v.begin(),v.end());
        pair<int,pair<int,int>> mindate={30,{12,99999}};
        int count=0;
        do{
            int day;
            int month;
            int year;
            day=(v[0]-'0')*10+(v[1]-'0');
            month=(v[2]-'0')*10+(v[3]-'0');
            year=(v[4]-'0')*1000+(v[5]-'0')*100+(v[6]-'0')*10+(v[7]-'0');
            if (valid(day,month,year)){
                ++count;
                if (year<mindate.second.second){
                    mindate={day,{month,year}};
                }
                else if (year==mindate.second.second){
                    if (month<mindate.second.first){
                        mindate={day,{month,year}};
                    }
                    else if (month==mindate.second.first){
                        if (day<mindate.first){
                            mindate={day,{month,year}};
                        }
                    }
                }
            }
        }while(next_permutation(v.begin(),v.end()));
        if (count==0)
            printf("0\n");
        else
            printf("%d %02d %02d %04d\n",count,mindate.first,mindate.second.first,mindate.second.second);
    }
}
