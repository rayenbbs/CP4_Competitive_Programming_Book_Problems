#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;



int main() {
    int t;
    cin >>t;
    while(t--)
    {
        unordered_set<int> myset;
        int n,s;
        vi important;
        unordered_set <int> importantset;
        cin >>n>>s;
        vector <vi> AL(n,vi());

        for(int i=0;i<s;++i){
            int a;
            int b;
            cin >>a;
            if (a!=0){
                if (myset.find(a-1) != myset.end() && importantset.find(a-1)==importantset.end()) {
                    important.push_back(a-1);
                    importantset.insert(a-1);
                } else {
                    myset.insert(a-1);
                }
                cin >>b;
                if( b!=0)
                {
                    do{
                        if (myset.find(b-1) != myset.end() && importantset.find(b-1)==importantset.end()) {
                            important.push_back(b-1);
                            importantset.insert(b-1);
                        } else {
                            myset.insert(b-1);
                        }
                        AL[a-1].push_back(b-1);
                        AL[b-1].push_back(a-1);
                        a=b;
                        cin >>b;
                    }while(b!=0);
                }
                else continue;
            }
            else{
                continue;
            }
        }
        long long min=1e18;
        int result=-2;
        vector<long long> vmoy(n,1e18);
        for (int i=0;i<important.size();++i){
            long long moy=0;
            vi dist(n,INF);
            queue<int> q;
            q.push(important[i]);
            dist[important[i]]=0;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for (auto &v: AL[u]){
                    if (dist[v]!=INF) continue;
                    dist[v]=dist[u]+1;
                    if (importantset.find(v)!=importantset.end()){
                        moy+=dist[v];
                    }
                    q.push(v);
                }
            }
            vmoy[important[i]]=moy;
        }
        for (int i=0;i<n;++i){
            if (vmoy[i]<min){
                min=vmoy[i];
                result=i;
            }
        }
        cout<<"Krochanska is in: "<<result+1<<endl;
    }

}