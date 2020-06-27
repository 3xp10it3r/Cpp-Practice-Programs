//Minimum Spanning Tree –digvijay
#include<bits/stdc++.h> 
using namespace std; 
  
typedef  pair<int, int> iPair; // ipair user defined type for integer pair
  
struct Graph 
{ 
    int V, E; 
    vector< pair<int, iPair> > edges; 
    Graph(int V, int E) { this->V = V; this->E = E; } //constructor 
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 
  
    int kruskalMST(); // to use Kruskal's algorithm
}; 
  
struct DisjointSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    DisjointSets(int n) 
    { 
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; // initially all ranks 0 
            parent[i] = i; 
        } 
    } 
  
    int find(int u) // to find parent of node u 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
  
    void merge(int x, int y) // union by rank
    { 
        x = find(x), y = find(y); 
  
        if (rnk[x] > rnk[y]) // sub tree of samller height
            parent[y] = x; 
        else  
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 
  
int Graph::kruskalMST() 
{ 
    int mst_wt = 0; // Initialize result 
    sort(edges.begin(), edges.end()); // sorting edges on weights
    DisjointSets ds(V); // create disjoint sets
    vector< pair<int, iPair> >::iterator it; //iterate through sorted edges
    for (it=edges.begin(); it!=edges.end(); it++) 
    { 
        int u = it->second.first, v = it->second.second; 
        int set_u = ds.find(u), set_v = ds.find(v); 
  
        if (set_u != set_v) // check any cycle is created
        { 
            cout << u << " - " << v << " with cost "<< it->first << endl; 
            mst_wt += it->first; // adding cost
            ds.merge(set_u, set_v); //merging sets
        } 
    } 
  
    return mst_wt; 
} 
  
int main() 
{ 
    int V = 7, E = 12; 
    Graph g(V, E); 
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 3, 2); 
    g.addEdge(0, 5, 7); 
    g.addEdge(1, 2, 4); 
    g.addEdge(1, 4, 1); 
    g.addEdge(2, 4, 3); 
    g.addEdge(2, 7, 2); 
    g.addEdge(3, 6, 3); 
    g.addEdge(4, 6, 5); 
    g.addEdge(4, 7, 4); 
    g.addEdge(5, 6, 3); 
    g.addEdge(6, 7, 6); 
    
    cout << "Edges with cost of MST are: \n"; 
    int mst_wt = g.kruskalMST(); 
  
    cout << "\nTotal cost (Weight) of MST is " << mst_wt; 
  
    return 0; 
} 

/* output
Edges with cost of MST are: 
1 - 4 with cost 1
0 - 3 with cost 2
2 - 7 with cost 2
2 - 4 with cost 3
3 - 6 with cost 3
5 - 6 with cost 3
0 - 1 with cost 4

Total cost (Weight) of MST is 18
*/
