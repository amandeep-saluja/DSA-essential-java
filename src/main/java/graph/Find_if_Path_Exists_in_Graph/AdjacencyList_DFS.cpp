class Solution {
public:
    //Adj List and dfs

    bool dfs(vector<vector<int>>& graph, int src, int desc, vector<bool> visited) {
        if(src == desc) return true;

        visited[src] = true;

        for(int neighbour : graph[src]) {
            if(!visited[neighbour] && dfs(graph, neighbour, desc, visited))
                return true;
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>());
        //(cpp) map of arrays or (java) hashmap of list
        //(cpp) array of arrays or list of list
        vector<bool> visited(n, false);

        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(graph, source, destination, visited);
    }
};