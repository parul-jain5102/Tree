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
              int height(Node *);
              void diameter(Node *);
            
};

int Btree::height(Node *head)
{
       if(head==NULL)
              return 0;
       int lh=height(head->left);
       int rh = height(head->right);
       return max(lh,rh)+1;
}
void Btree::diameter(Node *head)
{
       if(head==NULL)
              return;
       int lh = height(head->left);
       int rh= height(head->right);
       res=max(res,lh+rh);
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
       t.diameter(t.root);
       cout<<"Diameter is : "<<t.res;
       cout<<endl;
      
       return 0;
}
