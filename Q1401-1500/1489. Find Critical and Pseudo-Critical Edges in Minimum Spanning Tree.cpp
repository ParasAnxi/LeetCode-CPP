class UnionFind {
private:
    int numSets;
    vector<int> parent;
    vector<int> rank;
public:
    UnionFind(int n) {
        numSets = n;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int getSets() {
        return numSets;
    }

    int getParent(int u) {
        if(parent[u] != u) {
            return getParent(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int p1 = getParent(u), p2 = getParent(v);
        if(p1 == p2) {
            return;
        }
        if(rank[p1] > rank[p2]) {
            parent[p2] = p1;
        }
        else if(rank[p1] < rank[p2]) {
            parent[p1] = p2;
        }
        else {
            parent[p2] = p1;
            rank[p1]++;
        }
        numSets--;
    }
};

class Solution {
private:
    int getMST(int n, vector<vector<int>>& treeEdges, vector<int> includedEdge, vector<int> excludedEdge) {
        UnionFind uf(n);
        int cost = 0;
        if(!includedEdge.empty()) {
            uf.unionSets(includedEdge[1], includedEdge[2]);
            cost += includedEdge[0];
        }
        for(auto edge : treeEdges) {
            if(uf.getSets() == 1) {
                break;
            }
            if(edge == excludedEdge || edge == includedEdge || uf.getParent(edge[1]) == uf.getParent(edge[2])) {
                continue;
            }
            uf.unionSets(edge[1], edge[2]);
            cost += edge[0];
        }
        return uf.getSets() == 1 ? cost : INT_MAX;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(2);
        vector<vector<int>> treeEdges;
        int x = 0;
        for(auto edge : edges) {
            treeEdges.push_back({edge[2], edge[0], edge[1], x++});
        }
        sort(treeEdges.begin(), treeEdges.end());
        int mstCost = getMST(n, treeEdges, {}, {});
        for(auto edge : treeEdges) {
            if(mstCost < getMST(n, treeEdges, {}, edge)) {
                result[0].push_back(edge[3]);
            }
            else if(mstCost == getMST(n, treeEdges, edge, {})) {
                result[1].push_back(edge[3]);
            }
        }
        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());
        return result;
    }
};