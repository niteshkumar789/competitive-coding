/*  Disjoint Set:
        - Two set are disjoint if they have no element in common.
        - Disjoint Set data structure is used to store such sets.
        - It does the following operations:
            1. Merging two disjoint sets to a single set using union operation.
            2. Finding the representative of a set using find operation.
            3. Check whether two elements are in the same set/components or not.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // function to find ultimate parent with path compression
    int findUltimateParent(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    // function to do union by rank
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
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same" << endl;
    } else {
        cout << "Not same" << endl;
    }

    // union 3 and 7
    ds.unionByRank(3, 7);

    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same" << endl;
    } else {
        cout << "Not same" << endl;
    }

    return 0;
}