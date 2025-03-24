#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;


void floydWarshall(vector<vector<int>> &adj, int n)
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if( ((adj[i][j] == -1) || (adj[i][j] > adj[i][k] + adj[k][j])) && (adj[k][j] != -1 && adj[i][k] != -1) )
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
}
int main() {
    int n=4 ;
    // -1 in graph represents there is no direct edge between that two vertices
    // weights in graph can be negative but not -1(as it represents INFINITY)
    vector<vector<int>> graph = {
        {0,9,-4,-1},
        {6,0,-1,2},
        {-1,5,0,-1},
        {-1,-1,1,0}
    };
    floydWarshall(graph,n);
    
    for(int i = 0; i<graph.size(); i++) {
        for(int j = 0; j<graph.size(); j++) {
            cout<<graph[i][j]<<" \t ";
        }
        cout<<endl;
    }
    return 0;
}