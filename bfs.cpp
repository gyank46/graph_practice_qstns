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
void bfs(int s,vector<list*> adj_list,vector<int> &parent,vector<int> &level)
{
    queue<int> q;
    level[s]=0;
    parent[s]=-1;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        list *t=adj_list[x];
        while(t!=NULL)
        {
            if(level[t->val]==-1)
            {
                level[t->val]=level[x]+1;
                parent[t->val]=x;
                q.push(t->val);
            }
            t=t->next;
        }
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
        ul->next=adj_list[v];
        adj_list[v]=ul;
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
    vector<int> level(v+1,-1);
    int s;
    cin>>s;
    bfs(s,adj_list,parent,level);
    for(int i=0;i<=v;i++)
        cout<<i<<" "<<level[i]<<endl;
    for(int i=0;i<=v;i++)
        cout<<i<<" "<<parent[i]<<endl;
}
