#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1
class DisjointSet {
    vector<int> rank, parent, size;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0); // initialize rank to 0
        parent.resize(n + 1); // Resize to (n + 1) for 1-based indexing
        size.resize(n + 1, 1); // initialize size to 1

        // Initially, each node is its own parent (self root)
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // function to find the ultimate parent (root) of a node with path compression
    int findUltimateParent(int node) {
        if (node == parent[node]) return node;

        // Path compression: Flatten the tree by pointing directly to root
        return parent[node] = findUltimateParent(parent[node]);
    }

    // Unions two sets by rank (attach smaller depth tree under larger depth tree)
    void unionByRank(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v) return; // already in same component

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; // increase the rank of the new ultimate parent
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v) return; // already in same component

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u]; // increase the size of the new ultimate parent
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; // increase the size of the new ultimate parent
        }
    }
};

class Solution {
    public:
    // Kruskal's algorithm (using striver disJoint set class)
    // Time Complexity: O(E log E)
    // Space Complexity: O(V + E)
    
    // Custom comparator to sort edges by weight (ascending)
    static bool mycmp(const vector<int>& edge1, const vector<int>& edge2) {
        return edge1[2] < edge2[2];
    }
    
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // Sort according to their weight
        sort(edges.begin(), edges.end(), mycmp);
    
        // Process edges in increasing order of weight
        DisjointSet ds(V);
        int totalWeight = 0;
        
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            int uParent = ds.findUltimateParent(u);
            int vParent = ds.findUltimateParent(v);

            // If u and v are in different sets, include this edge in MST
            if (uParent != vParent) {
                ds.unionByRank(u, v);
                totalWeight += wt;
            }
        }

        return totalWeight;
    }
};