int Solution::solve(const vector<int> &A) 
{
    int n=A.size();
    if(n<=2)
        return n;
    int len=INT_MIN;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
        m[A[i]]=i;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int count=2;
            int temp=A[j];
            int diff=temp-A[i];
            while(m.find(temp+diff)!=m.end()&&m[temp+diff]>m[temp])
            {
                // cout<<A[i]<<" "<<temp<<" "<<A[m[temp+diff]]<<endl;
                count++;
                temp=A[m[temp+diff]];
            }
            len=max(len,count);
        }
    }
    return len;
}
