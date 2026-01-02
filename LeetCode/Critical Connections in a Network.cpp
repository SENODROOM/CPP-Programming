#include <iostream>
using namespace std;

// ------------------------------
// Section 1: Maximum limits
// ------------------------------

// Here we define two constants: MAXN and MAXE. These are used to fix the maximum
// size of arrays at compile-time because in +I mode we are not allowed to use STL
// containers like vector. Instead, we use static arrays, which require a known
// size ahead of time.

// MAXN = 1000
// This represents the **maximum number of nodes** our graph can have. In the context
// of the problem, nodes are labeled 0, 1, 2, ..., n-1. Setting it to 1000 means
// our program can handle graphs with up to 1000 servers or points.

// MAXE = 2000
// This represents the **maximum number of edges** (connections) in the network.
// In an undirected graph, each edge connects two nodes. The value 2000 is a safe
// upper bound for storing critical edges in a separate array later.

// These constants are crucial because we need to define static arrays in C++ for
// the adjacency representation, visited arrays, discovery times, and critical edges.
const int MAXN = 1000; // max number of nodes
const int MAXE = 2000; // max number of edges

// ------------------------------
// Section 2: Graph representation
// ------------------------------

// graph[MAXN][MAXN] is a **2D array used to represent the adjacency list of the graph**.
// Normally, in modern C++, we would use vector<vector<int>> for adjacency lists,
// but here we cannot use STL. Instead, we use a fixed-size 2D array.
//
// Each row `graph[i]` stores all the neighbors of node `i`.
// The number of neighbors is stored in deg[i] (explained in next section).
//
// For example, if node 0 is connected to nodes 1, 2, 3, then:
//   deg[0] = 3
//   graph[0][0] = 1
//   graph[0][1] = 2
//   graph[0][2] = 3
//
// This allows us to efficiently loop through neighbors of a node during DFS.
int graph[MAXN][MAXN];

// deg[MAXN] stores the **degree of each node**, i.e., the number of neighbors.
// It tells us how many valid entries exist in each row of graph[i].
// Without this array, we would not know how many neighbors each node has.
int deg[MAXN];

// ------------------------------
// Section 3: DFS tracking arrays
// ------------------------------

// discovery[MAXN] stores the **discovery time** of each node during DFS traversal.
// Discovery time is the order in which we first visit a node. For example, the
// first node visited might have discovery time 0, the second node 1, and so on.
//
// Discovery times are essential in Tarjan's algorithm for finding bridges because
// they help determine whether a neighbor has already been visited and if it can
// reach ancestors without using the current edge.
int discovery[MAXN];

// low[MAXN] stores the **lowest discovery time reachable** from a node.
// This includes the node itself, its descendants in DFS, and back edges.
// Essentially, low[node] tells us "the earliest ancestor reachable from this node."
//
// This is the key part of Tarjan's bridge-finding algorithm:
// - If low[neighbor] > discovery[node], it means neighbor cannot reach node or
//   any of node's ancestors without using the edge node-neighbor.
// - Hence, node-neighbor is a **critical edge**.
int low[MAXN];

// visited[MAXN] is a boolean flag array (0/1) to mark whether a node has been
// visited in DFS. This prevents infinite loops in cycles and ensures each node
// is processed only once.
int visited[MAXN];

// timer is a **global counter** used to assign discovery times sequentially.
// Each time a new node is visited, timer is incremented and assigned to discovery[node].
int timer = 0;

// ------------------------------
// Section 4: Storing critical edges
// ------------------------------

// criticalEdges[MAXE][2] is a 2D array that stores all **critical connections** (bridges)
// found in the graph. Each row contains a pair of nodes representing a critical edge.
//
// For example, if edge 1-2 is critical, we store:
//   criticalEdges[i][0] = 1
//   criticalEdges[i][1] = 2
//
// MAXE is set to a safe upper bound for maximum possible critical edges. Since each
// edge can potentially be critical, MAXE >= number of edges is safe.
int criticalEdges[MAXE][2];

// critCount is a counter to keep track of how many critical edges have been found.
// It is used to populate criticalEdges array and to know how many edges to output.
int critCount = 0;

// ------------------------------
// Section 5: Graph size variables
// ------------------------------

// n = number of nodes in the graph
// m = number of edges in the graph
//
// These are provided as input by the user or test case. They determine the loops
// for reading edges, initializing arrays, and running DFS traversal.
int n, m;

// DFS function
void dfs(int node, int parent)
{
    visited[node] = 1;
    discovery[node] = low[node] = timer++;

    for (int i = 0; i < deg[node]; i++)
    {
        int neighbor = graph[node][i];
        if (neighbor == parent)
            continue; // skip parent

        if (!visited[neighbor])
        {
            dfs(neighbor, node);
            if (low[neighbor] > discovery[node])
            {
                // edge node-neighbor is critical
                criticalEdges[critCount][0] = node;
                criticalEdges[critCount][1] = neighbor;
                critCount++;
            }
            if (low[neighbor] < low[node])
                low[node] = low[neighbor];
        }
        else
        {
            if (discovery[neighbor] < low[node])
                low[node] = discovery[neighbor];
        }
    }
}

int main()
{
    // Input number of nodes and edges
    cin >> n >> m;

    // Initialize adjacency info
    for (int i = 0; i < n; i++)
    {
        deg[i] = 0;
        visited[i] = 0;
    }

    // Read edges
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][deg[u]++] = v;
        graph[v][deg[v]++] = u; // undirected graph
    }

    // Run DFS from node 0 (assuming graph is connected)
    dfs(0, -1);

    // Output critical connections
    for (int i = 0; i < critCount; i++)
    {
        cout << criticalEdges[i][0] << " " << criticalEdges[i][1] << endl;
    }

    return 0;
}
