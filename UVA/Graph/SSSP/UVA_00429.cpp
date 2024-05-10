#include <bits/stdc++.h>
using namespace std;


typedef  vector<int> vi;

const int INF=1e9;

bool diff(string a,string b){
    if (a.size()!=b.size())
        return false;
    int count=0;
    for (int i=0;i<a.size();++i){
        if (a[i]!=b[i])
            count++;
    }
    return (count==1);
}

int main(){
    int t;
    string line;
    getline(cin,line);
    stringstream ss(line);
    ss >>t;
    getline(cin,line);
    while(t--){
        unordered_map <string,int> mymap;
        unordered_map<int,string> revmap;
        vector<string> vs;
        string a;
        getline(cin,line);
        stringstream ss(line);
        ss >>a;
        int count=0;
        while(a!="*"){
            mymap[a]=count;
            revmap[count]=a;
            ++count;
            vs.push_back(a);
            getline(cin,line);
            stringstream ss(line);
            ss >>a;
        }
        vector<vi> AL(count,vi());
        for(int i=0;i<vs.size();++i){
            for(int j=i+1;j<vs.size();++j){
                if (diff(vs[i],vs[j]))
                {
                    AL[mymap[vs[i]]].push_back(mymap[vs[j]]);
                    AL[mymap[vs[j]]].push_back(mymap[vs[i]]);
                }
            }
        }
        getline(cin,line);

        while (!line.empty()) {
            stringstream ss(line);
            string s, d;
            ss >> s >> d;
            vi dist(count, INF); dist[mymap[s]] = 0; // INF = 1e9 here
            queue<int> q; q.push(mymap[s]);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (u == mymap[d]) break; // addition: destination t
                for (auto &v : AL[u]) { // C++17 style, w ignored
                    if (dist[v] != INF) continue; // already visited, skip
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
            cout<<s<<" "<<d<<" "<<dist[mymap[d]]<<endl;
            getline(cin,line);
        }
        if (t!=0)
            cout<<endl;
    }
}

/*
2

dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

dip
lip
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

*/