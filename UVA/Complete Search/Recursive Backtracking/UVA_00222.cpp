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

void backtrack(double currentDist,vector<pair<double,double>> &stations,double cost,double indice,double &result,double finalDist,double currentGallons,double capacity, double rateConsumption,double prevDist,double prevcost){
    currentGallons-=(currentDist-prevDist)/rateConsumption;
    if (currentGallons<0)
        return;
    if (currentDist==finalDist){
        result=min(result,cost);
        return ;
    }
    else {
        f(i, indice+1, stations.size())
        {
            double nextdist=stations[i].first;
            double nextcost=stations[i].second;
            if (currentGallons>capacity/2) {
                double distToGo=nextdist-currentDist;
                if (distToGo > currentGallons*rateConsumption) {
                    double tempcost=cost;
                    double temp=currentGallons;
                    cost+=prevcost*(capacity-currentGallons);
                    cost+=200;
                    cost=round(cost);
                    currentGallons=capacity;
                    backtrack(nextdist,stations,cost,i,result,finalDist,currentGallons,capacity,rateConsumption,currentDist,nextcost);
                    cost=tempcost;
                    currentGallons=temp;
                }
                backtrack(nextdist,stations,cost,i,result,finalDist,currentGallons,capacity,rateConsumption,currentDist,nextcost);
            }
            else
            {
                double tempcost=cost;
                double temp=currentGallons;
                cost+=prevcost*(capacity-currentGallons);
                cost+=200;
                cost=round(cost);
                currentGallons=capacity;
                backtrack(nextdist,stations,cost,i,result,finalDist,currentGallons,capacity,rateConsumption,currentDist,nextcost);
                cost=tempcost;
                currentGallons=temp;
                backtrack(nextdist,stations,cost,i,result,finalDist,currentGallons,capacity,rateConsumption,currentDist,nextcost);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    double distSourcetoDest;
    cin >>distSourcetoDest;
    int testcase=1;
    while (distSourcetoDest>=0) {
        printf("Data Set #%d\n",testcase++);
        double capacity, milesPerGallon, costSource;
        cin >> capacity >> milesPerGallon >> costSource;
        double numberStations;
        cin >> numberStations;
        vector<pair<double,double> > stations(numberStations);
        f(i, 0, numberStations) {
            double distSourcetoStation, costStation;
            cin >> distSourcetoStation >> costStation;
            stations[i] = {distSourcetoStation, costStation};
        }
        stations.eb(distSourcetoDest, 0);
        ++numberStations;
        double cost =(costSource * 100);
        double result = INF;
        backtrack(0, stations, cost, -1, result, distSourcetoDest, capacity,capacity,milesPerGallon,0,0);
        printf("minimum cost = $%.2lf\n",result/100);
        cin >>distSourcetoDest;
    }
}