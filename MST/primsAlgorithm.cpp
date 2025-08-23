#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
class Solution {
    public:
    // Prim's Algorithm: To Find Minimum Spanning Tree
	// Time: O(E*logE)
	// Space: O(E) + O(V)
	
    int spanningTree(int V, vector<vector<int>>& edges) {
        // construct adjacenty list
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // min-heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(V, false); // used "visited" instead of "mst" name for tracking nodes
        
        pq.push({0, 0}); // {wt, node}
        int sum = 0;
        
        while (!pq.empty()) {
            // get minimum value node form key
            auto [currwt, node] = pq.top();
            pq.pop();
            
            if (visited[node] == true) {
                continue;
            }
            
            // add it to the mst
            visited[node] = true;
            sum += currwt;
            
            // process all adjacent node to u
            for (auto& nbr : adj[node]) {
                int v = nbr.first;
                int wt = nbr.second;
                
                if (!visited[v]) {
                    pq.push({wt, v});
                }
            }
        }
        
        return sum;
    }
};