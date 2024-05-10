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


vector<vector<char>> input;
vector<vector<char>> output;
int countchar1;
string target;


bool check1(int r1,int c1,int r2,int c2){
    f(i,r1,r2+1){
        f(j,c1,c2+1){
            if (input[i][j]!='1')
                return false;
        }
    }
    return true;
}

bool check0(int r1,int c1,int r2,int c2){
    f(i,r1,r2+1){
        f(j,c1,c2+1){
            if (input[i][j]!='0')
                return false;
        }
    }
    return true;
}

void inchar(){
    countchar1++;
    if (countchar1==50) {
        countchar1=0;
        printf("\n");
    }
}
void affiche(bool b1,bool b2){
    if (b1) {
        printf("0");
        inchar();
    }
    else {
        printf("1");
        inchar();
    }
}


void split(int r1,int c1,int r2,int c2){
    int nr1=floor((double)(r2-r1)/2)+r1;
    int nc1=floor((double)(c2-c1)/2)+c1;
    bool temp00,temp01,temp10,temp11,temp20,temp21,temp30,temp31;
    temp00=check0(r1,c1,nr1,nc1);
    temp01=check1(r1,c1,nr1,nc1);
    if(!temp00 && !temp01){
        printf( "D");
        inchar();
        split(r1,c1,nr1,nc1);
    }
    else{
        affiche(temp00,temp01);
    }
    if (nc1+1<=c2) {
        temp10 = check0(r1, nc1 + 1, nr1, c2);
        temp11 = check1(r1, nc1 + 1, nr1, c2);
        if (!temp10 && !temp11) {
            printf( "D");
            inchar();
            split(r1, nc1 + 1, nr1, c2);
        } else {
            affiche(temp10,temp11);
        }
    }
    if (nr1+1<=r2) {
        temp20 = check0(nr1 + 1, c1, r2, nc1);
        temp21 = check1(nr1 + 1, c1, r2, nc1);
        if (!temp20 && !temp21) {
            printf( "D");
            inchar();
            split(nr1 + 1, c1, r2, nc1);
        } else {
            affiche(temp20,temp21);
        }
    }
    if (nr1+1<=r2 && nc1+1<=c2) {
        temp30 = check0(nr1 + 1, nc1 + 1, r2, c2);
        temp31 = check1(nr1 + 1, nc1 + 1, r2, c2);
        if (!temp30 && !temp31) {
            printf( "D");
            inchar();
            split(nr1 + 1, nc1 + 1, r2, c2);
        } else {
            affiche(temp30,temp31);
        }
    }
}


void color(int r1,int c1,int r2,int c2,char c){
    f(i,r1,r2+1){
        f(j,c1,c2+1){
            output[i][j]=c;
        }
    }
}
void outsplit(int r1,int c1,int r2,int c2,int& ind){
    int nr1 = floor((double) (r2 - r1) / 2) + r1;
    int nc1 = floor((double) (c2 - c1) / 2) + c1;
    if (ind<target.size()) {
        if (target[ind] == '1') {
            ++ind;
            color(r1, c1, nr1, nc1, '1');
        } else if (target[ind] == '0') {
            ++ind;
            color(r1, c1, nr1, nc1, '0');
        } else {
            ++ind;
            outsplit(r1, c1, nr1, nc1, ind);
        }
    }
    if (nc1 + 1 <= c2 && ind<target.size()) {
        if (target[ind] == '1') {
            ++ind;
            color(r1, nc1 + 1, nr1, c2, '1');
        } else if (target[ind] == '0') {
            ++ind;
            color(r1, nc1 + 1, nr1, c2, '0');
        } else {
            ++ind;
            outsplit(r1, nc1 + 1, nr1, c2, ind);
        }
    }
    if (nr1 + 1 <= r2 && ind<target.size()) {
        if (target[ind] == '1') {
            ++ind;
            color(nr1 + 1, c1, r2, nc1, '1');
        } else if (target[ind] == '0') {
            ++ind;
            color(nr1 + 1, c1, r2, nc1, '0');
        } else {
            ++ind;
            outsplit(nr1 + 1, c1, r2, nc1, ind);
        }
    }
    if (nr1 + 1 <= r2 && nc1 + 1 <= c2 && ind<target.size()) {
        if (target[ind] == '1') {
            ++ind;
            color(nr1 + 1, nc1 + 1, r2, c2, '1');
        } else if (target[ind] == '0') {
            ++ind;
            color(nr1 + 1, nc1 + 1, r2, c2, '0');
        } else {
            ++ind;
            outsplit(nr1 + 1, nc1 + 1, r2, c2, ind);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string type;
    while(cin >>type) {
        if (type=="#")
            break;
        if (type == "B") {
            countchar1=0;
            int r, c;
            cin >> r >> c;
            printf("D%4d%4d\n",r,c);
            input.assign(r, vector<char>(c, '0'));
            f(i, 0, r * c) {
                char a;
                cin >> a;
                input[i / c][i % c] = a;
            }
            bool temp0, temp1;
            temp0 = check0(0, 0, r - 1, c - 1);
            temp1 = check1(0, 0, r - 1, c - 1);
            if (!temp0 && !temp1) {
                printf( "D");
                inchar();
                split(0, 0, r - 1, c - 1);
            } else {
                affiche(temp0,temp1);
            }
            if (countchar1!=0)
                printf("\n");
        }
        else{
            int r,c;
            cin >>r>>c;
            cin >>target;
            countchar1=0;
            printf("B%4d%4d\n", r, c);
            output.assign(r, vector<char>(c, '0'));
            int ind=0;
            if (target[ind]=='D') {
                ++ind;
                outsplit(0, 0, r - 1, c - 1, ind);
            }
            else if(target[ind]=='0'){
                color(0,0,r-1,c-1,'0');
            }
            else color(0,0,r-1,c-1,'1');

            f(i,0,r){
                f(j,0,c){
                    printf("%c",output[i][j]);
                    inchar();
                }
            }
            if(countchar1!=0)
                printf("\n");
        }
    }
}