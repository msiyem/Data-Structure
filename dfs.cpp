#include <bits/stdc++.h>
using namespace std;

#define MAX 100 // Define the maximum number of nodes

int st[MAX]; // Stack for DFS
int top = -1; // Top of the stack
int adj[MAX][MAX]; // Adjacency matrix for the graph
bool visited[MAX]; // Array to keep track of visited nodes

// Function to push an element onto the stack
void push(int data) {
    st[++top] = data;
}

// Function to pop an element from the stack
int pop() {
    return st[top--];
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to perform DFS traversal
void dfs(int nodes, int start) {
    push(start); // Push the starting node onto the stack
    while (!isEmpty()) { // While the stack is not empty
        int u = pop(); // Pop a node from the stack
        if (!visited[u]) { // If the node has not been visited
            visited[u] = true; // Mark the node as visited
            cout << u << " "; // Print the node
            for (int v = nodes; v >= 1; v--) { // Visit all adjacent nodes
                if (adj[u][v] && !visited[v]) { // If there is an edge and the node is not visited
                    push(v); // Push the adjacent node onto the stack
                }
            }
        }
    }
}

int main() {
    // Define the number of nodes and edges
    int nodes = 5;
    int edges = 4;

    // Initialize adjacency matrix with 0
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj[i][j] = 0;
        }
    }

    // Initialize visited array with false
    for (int i = 0; i < MAX; i++) {
        visited[i] = false;
    }

    // Example edges of the graph (undirected)
    // Edge list: (1-2), (1-3), (2-4), (3-5)
    int edgeList[4][2] = {{1, 2}, {1, 3}, {2, 4}, {3, 5}};

    // Build the adjacency matrix from the edge list
    for (int i = 0; i < edges; i++) {
        int u = edgeList[i][0];
        int v = edgeList[i][1];
        adj[u][v] = 1;
        adj[v][u] = 1; // Since the graph is undirected
    }

    // Output the DFS traversal starting from node 1
    cout << "DFS traversal starting from node 1: ";
    dfs(nodes, 1); // Start DFS from node 1
    
    return 0;
}