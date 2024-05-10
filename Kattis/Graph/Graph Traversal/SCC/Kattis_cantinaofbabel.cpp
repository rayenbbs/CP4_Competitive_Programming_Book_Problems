#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vector<int>>
const int VISITED=-1;
const int UNVISITED=-2;

vector<vi> AL;
vector<vi> AL_T;
vi S;


vi dfs_num, dfs_low, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
void Kosaraju(int u, int pass,int &sizeSCC) { // pass = 1 (original), 2 (transpose)
    dfs_num[u] = 1;
    ++sizeSCC;
    vi &neighbor = (pass == 1) ? AL[u] : AL_T[u];
    for (auto v : neighbor) // C++17 style, w ignored
        if (dfs_num[v] == UNVISITED)
            Kosaraju(v, pass,sizeSCC);
    S.push_back(u);
}


int main() {
    ios_base::sync_with_stdio(false);
    int N;
    string line;
    getline(cin,line);
    stringstream l(line);
    l>>N;
    AL.assign(N, vi());
    AL_T.assign(N, vi());
    unordered_map <string,int> mymapvertex;
    unordered_map <int,string> revmapvertex;
    unordered_map <string,int> mymaplanguage;
    unordered_map <int,string> revmaplanguage;
    vector <vector<string>> speak(N,vector<string>());
    vector<vector<string>> understand(N,vector<string>());
    int count=0;
    for (int i=0;i<N;++i)
    {
        string line;
        getline(cin,line);
        stringstream l(line);
        string a;
        l>>a;
        mymapvertex[a]=i;
        revmapvertex[i]=a;
        string b;
        l>>b;
        if (mymaplanguage.find(b)==mymaplanguage.end())
        {
            mymaplanguage[b]=count;
            revmaplanguage[count]=b;
            count++;
        }

        speak[mymaplanguage[b]].push_back(a);
        understand[mymaplanguage[b]].push_back(a);
        while(l>>b)
        {

            if (mymaplanguage.find(b)==mymaplanguage.end())
            {
                mymaplanguage[b]=count;
                revmaplanguage[count]=b;
                count++;
            }
            understand[mymaplanguage[b]].push_back(a);
        }
    }
    for (int i=0;i<count;++i)
    {
        for (int j=0;j<speak[i].size();++j)
        {
            for (int k=0;k<understand[i].size();++k)
            {
                if (speak[i][j]!=understand[i][k]) {
                    AL[mymapvertex[speak[i][j]]].push_back(mymapvertex[understand[i][k]]);
                    AL_T[mymapvertex[understand[i][k]]].push_back(mymapvertex[speak[i][j]]);
                }
            }
        }
    }
    S.clear();
    dfs_num.assign(N, UNVISITED);
    int sizeSCC;
    for (int u = 0; u < N; ++u)
        if (dfs_num[u] == UNVISITED) {
            Kosaraju(u, 1,sizeSCC);
        }
    dfs_num.assign(N, UNVISITED);
    int max=-1;
    for (int i = N-1; i >= 0; --i)
        if (dfs_num[S[i]] == UNVISITED) {
            sizeSCC=0;
            Kosaraju(S[i], 2,sizeSCC);
            if (sizeSCC>max)
                max=sizeSCC;
        }
    cout<<N-max<<endl;
    return 0;
}

