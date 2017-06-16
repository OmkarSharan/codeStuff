// C++ program to print transitive closure of a graph
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V; // No. of vertices
    bool **tc; // To store transitive closure
    list<int> *adj; // array of adjacency lists
    void DFSUtil(int u, int v);
public:
    Graph(int V); // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w) { adj[v].push_back(w); }

    // prints transitive closure matrix
    void transitiveClosure();
    int palindrome(int arr[], int left, int right);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];

    tc = new bool* [V];
    for (int i=0; i<V; i++)
    {
        tc[i] = new bool[V];
        memset(tc[i], false, V*sizeof(bool));
    }
}

// A recursive DFS traversal function that finds
// all reachable vertices for s.

int Graph::palindrome(int arr[], int low, int high){
    if(low > high) return 0;
    if(low == high) return 1+palindrome(arr, low+1, high-1);
    else{
        if(arr[low] == arr[high]) return 2+palindrome(arr, low+1, high-1);
        if(arr[low] != arr[high]){
            if(tc[low][high] == 1) return 2+palindrome(arr, low+1, high-1);
            else return max(palindrome(arr, low, high-1), palindrome(arr, low+1, high));
        }
    }
}
void Graph::DFSUtil(int s, int v)
{
    // Mark reachability from s to t as true.
    tc[s][v] = true;

    // Find all the vertices reachable through v
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (tc[s][*i] == false)
            DFSUtil(s, *i);
}

// The function to find transitive closure. It uses
// recursive DFSUtil()
void Graph::transitiveClosure()
{
    // Call the recursive helper function to print DFS
    // traversal starting from all vertices one by one
    for (int i = 0; i < V; i++)
        DFSUtil(i, i); // Every vertex is reachable from self.

    for (int i=0; i<V; i++)
    {
        for (int j=0; j<V; j++)
            cout << tc[i][j] << " ";
        cout << endl;
    }
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    int n, k, m, x, y;
    cin>>n>>k>>m;
    Graph g(n+1);
    for(int i=0; i < k; i++){
        cin>>x>>y;
        g.addEdge(x, y);
        g.addEdge(y, x);
    }
    int arr[m];
    for(int i=0; i < m; i++){
        cin>>arr[i];
    }
    //cout << "Transitive closure matrix is \n";
    g.transitiveClosure();
    int length = g.palindrome(arr, 0, m-1);
    cout<<length;
    return 0;
}
