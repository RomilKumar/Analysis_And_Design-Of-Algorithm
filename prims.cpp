#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Graph {
public:
    void prims(int edges[][3], int cost[][3], int n, int t[][2]) {
        vector<int> near(n, 0);
        int minCost = INT_MAX;
        int k = 0, l = 0;

       
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (edges[i][j] && cost[i][j] < minCost) {
                    minCost = cost[i][j];
                    k = i;
                    l = j;
                }
            }
        }

        t[0][0] = k;
        t[0][1] = l;
        
       
        for (int i = 0; i < n; ++i) {
            if (i != k && i != l) {
                near[i] = (cost[i][k] < cost[i][l]) ? k : l;
            } else {
                near[i] = 0; // Mark the vertices already in MST
            }
        }

        minCost = cost[k][l];

        // Step 4: Construct MST with `n-1` edges
        for (int j = 1; j < n - 1; ++j) {
            int u = Min(near, cost, n);
            t[j][0] = u;
            t[j][1] = near[u];
            minCost += cost[u][near[u]];
            near[u] = 0;

            for (int k = 0; k < n; ++k) {
                if (near[k] != 0 && cost[k][near[k]] > cost[u][k]) {
                    near[k] = u;
                }
            }
        }

        cout << "Minimum cost of MST: " << minCost << endl;
    }

private:
    int Min(vector<int>& near, int cost[][3], int n) {
        int minCost = INT_MAX, minVertex = 0;
        for (int i = 0; i < n; ++i) {
            if (near[i] != 0 && cost[i][near[i]] < minCost) {
                minCost = cost[i][near[i]];
                minVertex = i;
            }
        }
        return minVertex;
    }
};

int main() {
    int n = 3;
    int edges[3][3] = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    int cost[3][3] = {
        {0, 2, 3},
        {2, 0, 5},
        {3, 5, 0}
    };
    int t[2][2]; // `n-1` edges in MST

    Graph g;
    g.prims(edges, cost, n, t);

    // Print the Minimum Spanning Tree (MST)
    cout << "Edges in MST:" << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << t[i][0] << " - " << t[i][1] << endl;
    }

    return 0;
}
