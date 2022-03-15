class Solution {
    int hash[200005];
    vector<int> eg[200005];

public:
    bool dfs(int s, int e) {
        if (s == e) { return true; }
        if (hash[s]) { return false; }
        hash[s] = true;
        for (int i = eg[s].size() - 1; i >= 0; --i) {
            if (dfs(eg[s][i], e)) {
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        for (int i = 0; i < n; ++i) {
            eg[i].clear();
        }
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            eg[u].push_back(v);
            eg[v].push_back(u);
        }
        memset(hash, 0, sizeof(hash));
        return dfs(source, destination);
    }
};