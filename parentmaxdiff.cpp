#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data)
{
  struct Node* node = (struct Node*)
                       malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
// int maxDiff(Node *root);

void help(Node *root,int &ans,stack<int> &s,stack<int> &maxi,stack<int> &mini)
{
    if(root->left)
    {
        // cout<<"inleft"<<" max is "<<maxi.top()<<" node is "<<root->left->data<<" min is "<<mini.top()<<" ans is "<<ans<<endl;
        ans=max(ans,abs(maxi.top()-root->left->data));
        ans=max(ans,abs(mini.top()-root->left->data));
        s.push(root->left->data);
        if(root->left->data>maxi.top())
            maxi.push(root->left->data);
        else if(root->left->data<maxi.top())
            maxi.push(maxi.top());
        if(root->left->data<mini.top())
            mini.push(root->left->data);
        else if(root->left->data>mini.top())
            mini.push(mini.top());
        help(root->left,ans,s,maxi,mini);
        cout<<maxi.size()<<mini.size()<<s.size()<<endl;
        if(!s.empty())
            s.pop();
        if(!maxi.empty())
            maxi.pop();
        if(!mini.empty())
            mini.pop();
    }

    if(root->right)
    {
        // cout<<"inright"<<" max is "<<maxi.top()<<" node is "<<root->right->data<<" min is "<<mini.top()<<" ans is "<<ans<<endl;
        ans=max(ans,abs(maxi.top()-root->right->data));
        ans=max(ans,abs(mini.top()-root->right->data));
        s.push(root->right->data);
        if(root->right->data>maxi.top())
            maxi.push(root->right->data);
        else
            maxi.push(maxi.top());
        if(root->right->data<mini.top())
            maxi.push(root->right->data);
        else
            maxi.push(mini.top());
        help(root->right,ans,s,maxi,mini);
        if(!s.empty())
            s.pop();
        if(!maxi.empty())
            maxi.pop();
        if(!mini.empty())
            mini.pop();
    }
    // if(!s.empty())
    //     s.pop();
    // if(!maxi.empty())
    //     maxi.pop();
    // if(!mini.empty())
    //     mini.pop();

}
int maxDiff(Node* root)
{
    // Your code here
    stack<int> s;
    stack<int> maxi;
    stack<int> mini;
    int ans=0;
    if(root==NULL)
        return 0;
    s.push(root->data);
    maxi.push(root->data);
    mini.push(root->data);
    help(root,ans,s,maxi,mini);
    return ans;
}

int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;

     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
          {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
          }
        else
        parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
         }
   cout<<maxDiff(root)<<endl;
 }
  return 0;
}
