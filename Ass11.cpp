#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    // Constructor: Initializes a graph with a given number of vertices
    Graph(int vertices) {
        adjacencyList.resize(vertices); // Create an adjacency list
    }

    // Adds a directed edge from `src` to `dst`
    void addEdge(int src, int dst) {
        adjacencyList[src].push_back(dst);
    }

    // Counts all paths from `start` to `end`
    int countPaths(int start, int end) {
        int pathCount = 0; // Stores the total number of paths
        vector<bool> visited(adjacencyList.size(), false); // Tracks visited nodes
        countPathsHelper(start, end, pathCount, visited);
        return pathCount;
    }

private:
    vector<vector<int>> adjacencyList; // Adjacency list representation of the graph

    // Helper function to recursively count paths
    void countPathsHelper(int current, int destination, int& pathCount, vector<bool>& visited) {
        // If the current node is the destination, increment path count
        if (current == destination) {
            pathCount++;
            return;
        }

        // Mark the current node as visited
        visited[current] = true;

        // Recur for all unvisited neighbors
        for (int neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                countPathsHelper(neighbor, destination, pathCount, visited);
            }
        }

        // Backtrack: Mark the current node as unvisited
        visited[current] = false;
    }
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 4);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 1);
    graph.addEdge(3, 2);

    // Count paths from vertex 0 to vertex 4
    cout << "Number of paths from 0 to 4: " << graph.countPaths(0, 4) << endl;

    return 0;
}
