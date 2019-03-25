
// C++ program for finding minimum cut using Ford-Fulkerson 
#include <iostream> 
#include <limits.h> 
#include <string.h> 
#include <queue> 
using namespace std; 
  
// Number of vertices in given graph 
  
/* Returns true if there is a path from source 's' to sink 't' in 
  residual graph. Also fills parent[] to store the path */
int bfs(int rGraph[100][100], int s, int t, int parent[]) 
{ 
    // Create a visited array and mark all vertices as not visited 
    bool visited[100]; 
    memset(visited, 0, sizeof(visited)); 
  
    // Create a queue, enqueue source vertex and mark source vertex 
    // as visited 
    queue <int> q; 
    q.push(s); 
    visited[s] = true; 
    parent[s] = -1; 
  
    // Standard BFS Loop 
    while (!q.empty()) 
    { 
        int u = q.front(); 
        q.pop(); 
  
        for (int v=0; v<100; v++) 
        { 
            if (visited[v]==false && rGraph[u][v] > 0) 
            { 
                q.push(v); 
                parent[v] = u; 
                visited[v] = true; 
            } 
        } 
    } 
  
    // If we reached sink in BFS starting from source, then return 
    // true, else false 
    return (visited[t] == true); 
} 
  
// A DFS based function to find all reachable vertices from s.  The function 
// marks visited[i] as true if i is reachable from s.  The initial values in 
// visited[] must be false. We can also use BFS to find reachable vertices 
void dfs(int rGraph[100][100], int s, bool visited[]) 
{ 
    visited[s] = true; 
    for (int i = 0; i < 100; i++) 
       if (rGraph[s][i] && !visited[i]) 
           dfs(rGraph, i, visited); 
} 
  
// Prints the minimum s-t cut 
void minCut(int graph[100][100], int s, int t) 
{ 
    int u, v; 
  
    // Create a residual graph and fill the residual graph with 
    // given capacities in the original graph as residual capacities 
    // in residual graph 
    int rGraph[100][100]; // rGraph[i][j] indicates residual capacity of edge i-j 
    for (u = 0; u < 100; u++) 
        for (v = 0; v < 100; v++) 
             rGraph[u][v] = graph[u][v]; 
  
    int parent[100];  // This array is filled by BFS and to store path 
  
    // Augment the flow while there is a path from source to sink 
    while (bfs(rGraph, s, t, parent)) 
    { 
        // Find minimum residual capacity of the edhes along the 
        // path filled by BFS. Or we can say find the maximum flow 
        // through the path found. 
        int path_flow = INT_MAX; 
        for (v=t; v!=s; v=parent[v]) 
        { 
            u = parent[v]; 
            path_flow = min(path_flow, rGraph[u][v]); 
        } 
  
        // update residual capacities of the edges and reverse edges 
        // along the path 
        for (v=t; v != s; v=parent[v]) 
        { 
            u = parent[v]; 
            rGraph[u][v] -= path_flow; 
            rGraph[v][u] += path_flow; 
        } 
    } 
  
    // Flow is maximum now, find vertices reachable from s 
    bool visited[100]; 
    memset(visited, false, sizeof(visited)); 
    dfs(rGraph, s, visited); 
  
    // Print all edges that are from a reachable vertex to 
    // non-reachable vertex in the original graph 
    int min=0;
    for (int i = 0; i < 100; i++) 
      for (int j = 0; j < 100; j++) 
         if (visited[i] && !visited[j] && graph[i][j]) 
              min+=graph[i][j];
  	printf("%d",min);
    return; 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Let us create a graph shown in the above example 
    int graph[100][100];
    int i,j,v,e;
    int temp1,temp2,temp3;
	for(i=0;i<100;i++)
    {
    	for(j=0;j<100;j++)
    	{
    		graph[i][j]=0;
		}
	}
  	scanf("%d %d",&v,&e);
  	for(i=0;i<v-2;i++)
  	{
  		scanf("%d %d",&temp1,&temp2);
  		graph[temp1-1][temp1+50-1]=temp2;
	}
	for(i=0;i<e;i++)
	{
		scanf("%d %d %d",&temp1,&temp2,&temp3);
		if((temp1!=1 && temp1!=v) && (temp2!=1 && temp2!=v))
		{
			graph[temp1-1+50][temp2-1]=temp3;
			graph[temp2-1+50][temp1-1]=temp3;
		}
		else if((temp1!=1 && temp1!=v) &&(temp2==v || temp2==1))
		{
			graph[temp1-1+50][temp2-1]=temp3;
			graph[temp2-1][temp1-1]=temp3;
		}
		else if((temp1==1 || temp1==v) &&(temp2!=v && temp2!=1))
		{
			graph[temp1-1][temp2-1]=temp3;
			graph[temp2-1+50][temp1-1]=temp3;
		}
		else
		{
			graph[temp1-1][temp2-1]=temp3;
			graph[temp2-1][temp1-1]=temp3;
		}
	}
	scanf("%d %d",&temp1,&temp2);
	
    minCut(graph, 0, v-1); 
  

} 

