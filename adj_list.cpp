#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;
struct list
{
    int val;
    list *next;
    list(int x) : val(x), next(NULL) {}
};

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
}
