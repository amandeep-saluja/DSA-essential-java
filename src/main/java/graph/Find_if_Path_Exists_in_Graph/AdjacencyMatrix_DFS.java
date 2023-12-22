package graph.Find_if_Path_Exists_in_Graph;
import java.util.Arrays;

class Solution {
    //adj matrix, dfs

    private boolean dfs(int n, int[][] graph, int src, int desc, boolean[] visited) {
        if(src==desc) return true;

        visited[src] = true;

        for(int i=0; i<n; i++) {
            if(graph[src][i] == 1 && !visited[i]) {
                if(dfs(n, graph, i, desc, visited))
                    return true;
            }
        }
        return false;
    }

    public boolean validPath(int n, int[][] edges, int source, int destination) {
        //create adj matrix - if n is no. of vertices -> size will be n*n
        int [][] graph = new int[n][n];
        boolean[] visited = new boolean[n];
        //initialize Adj. matrix
        for(int [] row: graph) {
            Arrays.fill(row, 0);
        }

        //make the graph
        for(int[] edge: edges) {
            int u = edge[0], v = edge[1];
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        return dfs(n, graph, source, destination, visited);
    }
}