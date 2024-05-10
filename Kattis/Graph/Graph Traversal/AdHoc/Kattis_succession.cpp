#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
const int INF=1e9;
vector<vi> AL;

vi dfs_num;
vi in_degree;
vi in_degree1;
enum { UNVISITED = -1, VISITED = -2 }; // basic flags
// initially all UNVISITED

int main() {
    int n,m;
    cin>>n>>m;
    string king;
    cin >>king;
    unordered_map <string,double> blood;
    unordered_map <string,int> mymap;
    unordered_map <int,string> revmap;
    blood[king]=100;
    int countdistinct=0;
    while (n--)
    {
        string a,b,c;
        cin >> a>>b>>c;
        if (mymap.find(a)==mymap.end())
        {
            mymap[a]=countdistinct;
            revmap[countdistinct]=a;
            ++countdistinct;
            AL.push_back(vi());
            in_degree.push_back(0);
        }
        if (mymap.find(b)==mymap.end())
        {
            mymap[b]=countdistinct;
            revmap[countdistinct]=b;
            ++countdistinct;
            AL.push_back(vi());
            in_degree.push_back(0);
        }
        if (mymap.find(c)==mymap.end())
        {
            mymap[c]=countdistinct;
            revmap[countdistinct]=c;
            ++countdistinct;
            AL.push_back(vi());
            in_degree.push_back(0);
        }
        AL[mymap[b]].push_back(mymap[a]);
        AL[mymap[c]].push_back(mymap[a]);
        in_degree[mymap[a]]+=2;
    }
    queue<int> q;
    for(int i=0;i<countdistinct;++i)
    {
        if (in_degree[i]==0)
        {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop(); // queue: layer by layer!
        for (auto &v : AL[u]) {
            blood[revmap[v]]+=blood[revmap[u]]/2;
            in_degree[v]--;// C++17 style, w ignored
            if (in_degree[v]==0)
                q.push(v);// already visited, skip
        }
    }
    double max=-1;
    string result;
    while(m--)
    {
        string a;
        cin >>a;
        if (blood[a]>max) {
            max = blood[a];
            result=a;
        }
    }
    cout<<result<<endl;
}