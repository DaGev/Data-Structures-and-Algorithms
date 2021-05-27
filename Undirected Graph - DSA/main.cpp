#include "graph.hpp"

int main() {
	
    Graph<int> g;

    // g.add_vertex("panir");
    // g.add_vertex("panir2");
    // cout << "test: " << g.get_vertices()[1] << endl;
    g.add_vertex("A");
    g.add_vertex("B");
    g.add_vertex("C");
    g.add_vertex("D");
    g.add_vertex("E");
    g.add_vertex("F");

    g.add_edge("A", "B", 7);
    g.add_edge("C", "D", 4);
    g.add_edge("C", "E", 8);
    g.add_edge("B", "E", 10);
    g.add_edge("A", "E", 6);
    g.add_edge("B", "C", 3);
    g.add_edge("B", "F", 5);
    g.add_edge("E", "F", 10);
    // g.get_edges();
    // g.get_neighbours("C");

    cout << "Number of vertices: " << g.num_vertices() << endl; // should be 5
    cout << "Number of edges: " << g.num_edges() << endl; // should be 6

    cout << "Is vertex A in the graph? " << g.contains("A") << endl; // should be 1 or true
    cout << "Is vertex B in the graph? " << g.contains("B") << endl;
    cout << "Is vertex F in the graph? " << g.contains("F") << endl; // should be 0 or false

    cout << "Is there an edge between A and B? " << g.adjacent("A", "B") << endl; // should be 1 or true
    cout << "Is there an edge between B and A? " << g.adjacent("B", "A") << endl; // should be 1 or true
    cout << "Is there an edge between E and F? " << g.adjacent("E", "F") << endl; // should be 0 or false

    cout << "Degree of C: " << g.degree("C") << endl; // should be 1

    cout << "The visiting order of DFS (starting from D):";
    for (string x : g.depth_first_traversal("D")){
        cout << " " << x;
    }
    cout << endl;


    cout << "The visiting order of BFS (starting from D):";
    for (string x : g.breadth_first_traversal("D")){
        cout << " " << x;
    }
    cout << endl;

    g.minimum_spanning_tree();

}