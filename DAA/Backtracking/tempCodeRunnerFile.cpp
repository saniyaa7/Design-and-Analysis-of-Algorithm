#include<bits/stdc++.h>
using namespace std;
# define V 6
bool isSafe(int v,bool graph[V][V],int path[],int pos)
{
    if(graph[path[pos-1]][v]==0)
        return false;
    for(int i=0;i<pos;i++)
        if(path[i]==v)
            return false;
    return true;
}
bool hamCycleUtil(bool graph[V][V],int path[],int pos)
{
    if(pos==V)
    {
        if(graph[path[pos-1]][path[0]]==1)
            return true;
        return false;
    }
    for(int v=1;v<V;v++)
    {
        if(isSafe(v,graph,path,pos))
        {
            path[pos]=v;
            if(hamCycleUtil(graph,path,pos+1)==true)
                return true;
            path[pos]=-1;
        }
    }
    return false;
}
void printSolution(int path[])
{
    cout<<"\nHamilton Cycle:\n";
    for(int i=0;i<V;i++)
        cout<<path[i]<<" ";
    cout<<path[0]<<endl;

}
bool hamCycle(bool graph[V][V])
{
   int *path=new int[V];
    path[0]=0;
    if(hamCycleUtil(graph,path,1)==false)
    {
        cout<<"\nSolution does not exist";
        return false;
    }
    printSolution(path);
    return true;
}

int main()
{
    bool graph[V][V]={
                        {0,1,0,0,1,1},
                         {1,0,1,1,1,0},
                          {0,1,1,0,0,0},
                           {0,1,1,0,1,1},
                            {1,1,0,1,0,1},
                            {1,0,0,1,1,0}};
hamCycle(graph);
}
