#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>

using namespace std;
struct list
{
    int val;
    list *next;
    list(int x) : val(x), next(NULL) {}
};
void dfs(int s,vector<list*> adj_list,vector<int> &parent, vector<int> &st, vector<int> &et)
{
    list *t=adj_list[s];
    while(t!=NULL)
    {
        if(st[t->val]==1)
            cout<<"back edge between "<<s<<" and "<<t->val<<endl;
        if(st[t->val]==2)
            cout<<"forward dege betwwen "<<s<<" and "<<t->val<<endl;
        if(parent[t->val]==-1)
        {
            st[t->val]=1;
            cout<<t->val<<" ";
            parent[t->val]=s;
            dfs(t->val,adj_list,parent,st,et);
            st[t->val]=2;
        }
        t=t->next;
    }
}
int main()
{
    int v;
    cin>>v;
    int e;
    cin>>e;
    vector<list*> adj_list(v+1);
    for(int i=0;i<=v;i++)
        adj_list[i]=NULL;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        list *ul=new list(u);
        list *vl=new list(v);
        vl->next=adj_list[u];
        adj_list[u]=vl;
    }
    for(int i=1;i<=v;i++)
    {
        cout<<i<<"->";
        list *temp=adj_list[i];
        while(temp!=NULL)
        {
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    vector<int> parent(v+1,-1);
    vector<int> st(v+1,-1);
    vector<int> et(v+1,-1);
    for(int i=1;i<=v;i++)
    {
        if(parent[i]==-1)
        {
            st[i]=1;
            cout<<i<<" ";
            parent[i]=0;
            dfs(i,adj_list,parent,st,et);
            st[i]=2;
        }
    }
    cout<<endl;
}
