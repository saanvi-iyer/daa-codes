#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 100

int n;

int min(int a, int b) {
    return a < b ? a : b;
}

bool bfs(int rGraph[n][n], int s, int t, int parent[]) {
    bool visited[n];
    for (int i = 0; i < n; ++i)
        visited[i] = false;

    int queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (front != rear) {
        int u = queue[front++];
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    return visited[t];
}

int edmondsKarp(int graph[n][n], int s, int t) {	 	  	 	  	   	 		  	     	  	 	
    int u, v;
    int rGraph[n][n];

    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
             rGraph[u][v] = graph[u][v];

    int parent[n];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    scanf("%d", &n);
    int graph[n][n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &graph[i][j]);

    int source, sink;
    scanf("%d %d", &source, &sink);

    printf("Max Flow: %d\n", edmondsKarp(graph, source, sink));

    return 0;
}	 	  	 	  	   	 		  	     	  	 	
