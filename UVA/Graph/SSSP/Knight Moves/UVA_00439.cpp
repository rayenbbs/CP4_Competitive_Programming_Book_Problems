#include <bits/stdc++.h>

using namespace std;



typedef vector<int> vi;
typedef vector<vector<int>> vii;
const int INF=1e9;
int R,C;
vector<vector<char>> grid;

int knightr[]{2, 2, -2 , -2, 1,-1 ,1 ,-1 };
int knightc[]{1, -1, 1 , -1, 2, 2, -2,-2 };


int main()
{
    R=8;
    C=8;
    string line;
    getline(cin,line);
    while(!line.empty()){
        stringstream s(line);
        string s1,s2;
        s>>s1>>s2;
        char rs1=s1[1],cs1=s1[0],rd1=s2[1],cd1=s2[0];
        int rs='8'-rs1;
        int cs=cs1-'a';
        int rd='8'-rd1;
        int cd=cd1-'a';
        max
        cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<dist[rd][cd]<<" knight moves."<<endl;
        getline(cin,line);
    }

}

/*

e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

 */