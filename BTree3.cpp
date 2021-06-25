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
              void PreOrder(Node *);
              void LevelOrder(Node *);
             
  
};


void Btree::PreOrder(Node *head)
{
       if(head==NULL)
              return;
       cout<<head->data<<" ";
       PreOrder(head->left);
       PreOrder(head->right);
}
void Btree::LevelOrder(Node *head)
{
       queue<Node *> q;
       q.push(head);
       int level=0;
       while(!q.empty())
       {
              int cnt =q.size();
              int sum=0;
              VI v;
              for(int i=0;i<cnt;i++)
              {
                     Node *t = q.front();
                     //cout<<t->data<<" ";
                     //sum+=t->data;
                     // if(i==cnt-1)
                     //        cout<<t->data<<" ";
                     v.push_back(t->data);
                     q.pop();
                     if(t->left)
                            q.push(t->left);
                     if(t->right)
                            q.push(t->right);
              }
              if(level%2==0)
                     reverse(v.begin(),v.end());
              for(auto x:v)
                     cout<<x<<" ";
              cout<<endl;
              v.clear();
              level++;
              //cout<<"--->"<<sum<<endl;
       }
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
       t.PreOrder(t.root);
       cout<<endl;
       t.LevelOrder(t.root);
      
       return 0;
}
