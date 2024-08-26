#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

int adj[MAX_SIZE][MAX_SIZE]; // Adjacency matrix representation
bool visited[MAX_SIZE];

void DFS(int start) {
  if (visited[start]) {
    return;
  }

  visited[start] = true;
  printf("%d ", start); // Print the current node

  for (int i = 0; i < MAX_SIZE; i++) {
    if (adj[start][i] == 1 && !visited[i]) { // Check for connection and unvisited node
      DFS(i);
    }
  }
}

int main() {
  int nodes, edges, n1, n2;

  printf("Total Nodes: ");
  scanf("%d", &nodes);

  printf("Total Edges: ");
  scanf("%d", &edges);

  // Initialize adjacency matrix with zeros (no connections)
  for (int i = 0; i < nodes; i++) {
    for (int j = 0; j < nodes; j++) {
      adj[i][j] = 0;
    }
  }

  for (int i = 0; i < edges; i++) {
    scanf("%d %d", &n1, &n2);
    adj[n1][n2] = 1; // Mark connection in both directions for undirected graph
    adj[n2][n1] = 1;
  }

  DFS(1);

  return 0;
}
