class Solution {
public:
    //Adjacency Matrix, BFS
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<bool> visited(n, false);

        for(auto edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        queue<int> q;
        q.push(source);

        while(!q.empty()) {
            int curr = q.front();
            visited[curr] = true;
            cout<<curr<<endl;
            q.pop();
            if(curr == destination) {
                return true;
            }
            for(int i=0; i<n; i++) {
                if(!visited[i] && graph[curr][i])
                    q.push(i);
            }
        }
        return false;
    }
};