#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define MP make_pair
#define PB push_back
#define MOD 1000000007
#define fi first
#define se second
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
struct Node{
       int data;
       Node *left, *right;
       Node(int k)
       {
              data =k;
              left=right=NULL;
       }
};
class Btree{
       public:
              Node *root;
              int ans=0;
              int InfectTree(Node *,int leaf,int &dis);
};
int Btree::InfectTree(Node *head,int leaf,int &dis)
{
       if(head==NULL)
              return 0;
       if(head->data==leaf)
       {
              dis=0;
              return 1;
       }
       int ld=-1,rd=-1;
       int leftHeight = InfectTree(head->left,leaf,ld);
       int rightHeight = InfectTree(head->right,leaf,rd);
       if(ld!=-1)
       {
              dis=ld+1;
              ans = max(ans, dis+rightHeight);
       }
       else if(rd!=-1)
       {
              dis=rd+1;
              ans = max(ans, dis+leftHeight);
       }
       return max(leftHeight,rightHeight)+1;
}



int32_t main()
{
       ios_base::sync_with_stdio(false);
       cin.tie(NULL);
       #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
       freopen("output.txt","w",stdout);
       #endif
       Btree t;
       t.root = new Node(0);
       t.root->left = new Node(1);
       t.root->right = new Node(2);
       t.root->left->left = new Node(3);
       t.root->left->right = new Node(4);
       t.root->right->left = new Node(5);
       t.root->right->right = new Node(6);
       t.root->left->left->left = new Node(7);
       t.root->left->left->right = new Node(8);
       int dis=0;
       t.InfectTree(t.root,7,dis);
       cout<<"Infection time : "<<t.ans<<endl;
       
       return 0;
}