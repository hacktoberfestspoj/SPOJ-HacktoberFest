#include<bits/stdc++.h>
using namespace std;

int limit,start,goal,up,down;

bool vis[1000006];
int dis[1000006];

void bfs(int vertex,int depth)
{
    vis[vertex] = true;
    dis[vertex] = depth;
    queue<int> q;
    q.push(vertex);
    while(!q.empty())
    {
        vertex = q.front();
        q.pop();
        if(vertex == goal)
        return;
        if(vertex + up <= limit && !vis[vertex + up])
        {
            q.push(vertex+up);
            dis[vertex+up] = dis[vertex] + 1;
            vis[vertex+up] = true;
        }
        if(vertex - down > 0 && !vis[vertex-down])
        {
            q.push(vertex-down);
            dis[vertex-down] = dis[vertex] + 1;
            vis[vertex-down] = true;
        }
    }
}

int main()
{
    cin >> limit >> start >> goal >> up >> down;
    bfs(start,0);
    if(vis[goal])
    {
        cout << dis[goal] << endl;
    }
    else
    {
        cout << "use the stairs" << endl;
    }
}