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
              VI v;
              int res=0;
              int ans=0;
              map<int,int> mp;
              void diameter(Node *);
};

void Btree::RootToLeaf(Node *head)
{
       if(head==NULL)
              return;
       v.push_back(head->data);
       if(head->left==NULL && head->right==NULL)
       {
              int sum=0;
              for(auto x:v)
              {
                     sum+=x;
                     cout<<x<<" ";
              }
              cout<<"--->"<<sum<<endl;
       }
       RootToLeaf(head->left);
       RootToLeaf(head->right);
       auto it =v.end();
       it--;
       v.erase(it);
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
      t.RootToLeaf(t.root);
      
       return 0;
}
