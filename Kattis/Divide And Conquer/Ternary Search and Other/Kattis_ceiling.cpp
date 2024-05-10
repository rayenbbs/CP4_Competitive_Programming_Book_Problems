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

struct node{
    int val;
    node* left;
    node* right;
};

node* createnode(int val){
    node* newnode= new struct node;
    newnode->val=val;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insert(node* node,int val){
    if (node==NULL){
        return(createnode(val));
    }
    else {
        if (val > node->val) {
            node->right=insert(node->right,val);
        } else {
            node->left=insert(node->left, val);
        }
    }
    return node;
}

void affich(node* tree){
    if (tree==NULL)
        return;
    else {
        cout << tree->val<<'\n';
        affich(tree->left);
        affich(tree->right);
    }
}

bool equal(node* tree1,node* tree2){
    if (tree1==NULL && tree2==NULL)
        return true;
    else if (tree1!=NULL && tree2!=NULL){
        return(equal(tree1->left,tree2->left) && equal(tree1->right,tree2->right));
    }
    else return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    int k;
    cin>>n; cin>>k;
    vector<node*> v;
    f(i,0,n){
        int rootval;
        cin >>rootval;
        node* root= createnode(rootval);
        f(j,0,k-1){
            int nodeval;
            cin >>nodeval;
            insert(root,nodeval);
        }
        if (v.empty())
            v.pb(root);
        else{
            bool test=false;
            f(j,0,v.size()){
                if (equal(root,v[j])){
                    test=true;
                    break;
                }
            }
            if (!test){
                v.pb(root);
            }
        }
    }
    cout<<v.size()<<'\n';
}