#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility> 
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

template <typename T> // the template allows the weight of an edge to take any numeric data type (denoted by T).
class Graph {

	public:
        
        /* define your data structure to represent a weighted undirected graph */

        vector< vector<T> > adj_matrix;
        vector<string> vertex;
        size_t num_ver;
        size_t num_edg;

        /* test1 */
		Graph(); // the contructor function.
		~Graph(); // the destructor function.
		size_t num_vertices(); // returns the total number of vertices in the graph.
		size_t num_edges(); // returns the total number of edges in the graph.

        /* test2 */
        void add_vertex(const string&); // adds a vertex to the graph -- every vertex uses a string as its unique identifier.
        bool contains(const string&); // checks if a vertex is in the graph -- returns true if the graph contains the given vertex; otherwise, returns false.
        
        /* test3 */
        vector<string> get_vertices(); // returns a vector of all the vertices in the graph.

        /* test4 */
        int give_position_as_int(const string& u);
        void add_edge(const string&, const string&, const T&); // adds a weighted edge to the graph -- the two strings represent the incident vertices; the third parameter represents the edge's weight.
        bool adjacent(const string&, const string&); // check if there is an edge between the two vertices in the graph -- returns true if the edge exists; otherwise, returns false.
		
        /* test5 */
        vector<pair<string,string>> get_edges(); // returns a vector of all the edges in the graph -- each edge is represented by a pair of vertices incident to the edge.
        
        /* test6 */
        vector<string> get_neighbours(const string&); // returns a vector of all the vertices, each of which is directly connected with the given vertex by an edge.
        size_t degree(const string&); // returns the degree of a vertex.

        /* test7 */
		void remove_edge(const string&, const string&); // removes the edge between two vertices, if it exists.
        
        /* test8 */
        void remove_vertex(const string&); // delete the given vertex from the graph -- note that, all incident edges of the vertex should be deleted as well.

        /* test9 */
		vector<string> depth_first_traversal(const string&); // returns a vector of all the vertices in the visiting order of a depth-first traversal from the given vertex.
		
        /* test10 */
        vector<string> breadth_first_traversal(const string&); // returns a vector of all the vertices in the visiting order of a breadth-first traversal from the given vertex.
        
        /* test11 */
        bool cycles_util(int u, bool visited[], int parent);
		bool contain_cycles(); // check if the graph contains any cycle -- returns true if there exists a path from a vertex to itself; otherwise, return false.
        
        /* test12 */
		Graph<T> minimum_spanning_tree(); // returns a spanning tree of the graph -- the returned tree is preferably a minimum spanning tree.
		
};

/* test1 */

// Constructor Function: creates graph with no verticies or edges
template <typename T>
Graph<T>::Graph() {
    num_ver = 0;
    num_edg = 0;
    int capacity = 50;

    adj_matrix.resize(capacity);
    for (int i = 0; i< adj_matrix.size(); i++){
        adj_matrix[i].resize(capacity);
        for(int j = 0; j < adj_matrix[i].size(); j++){
            adj_matrix[i][j] = 0;
        }
    }

    vertex.resize(capacity);
}

template <typename T>
Graph<T>::~Graph() {}

// Returns the number of vertecies in the graph
template <typename T>
size_t Graph<T>::num_vertices() {
    return num_ver;
}

// Returns the number of edges between the vertecies
template <typename T>
size_t Graph<T>::num_edges() {
    return num_edg;
}

/* test2 */

// Takes in a String and adds it to the vertex without any edges
template <typename T>
void Graph<T>::add_vertex(const string& u) {
    if (contains(u) == false){
        vertex[num_ver] = u;
        num_ver++;
    }
}

// Returns true if the String being checked already exists in the graph
template <typename T>
bool Graph<T>::contains(const string& u) {
    for(int i = 0; i < num_ver; i++){
        if(vertex[i] == u){
            return true;
        }
    }
    return false;
}

/* test3 */

// Returns a vector of all the vertices in the graph
template <typename T>
vector<string> Graph<T>::get_vertices() {
    vector<string> list;
    list.resize(num_ver);

    for(int i = 0; i < num_ver; i++){
        list[i] = vertex[i];
    }

    return list;
}

/* test4 */

// Gives the position of a vertex in the graph
template <typename T>
int Graph<T>::give_position_as_int(const string& u){
    for(int i = 0; i < num_ver; i++){
        if(vertex[i] == u){
            return i;
        }
    }
    return 10;
}

// Adds an edge of a given weight between a given pair of verticies
template <typename T>
void Graph<T>::add_edge(const string& u, const string& v, const T& weight) {
    if (adjacent(u, v) == false){
        adj_matrix[give_position_as_int(u)][give_position_as_int(v)] = weight;
        adj_matrix[give_position_as_int(v)][give_position_as_int(u)] = weight;
        num_edg++;
    }    
}

// Returns true if a given pair of verticies are adjacent
template <typename T>
bool Graph<T>::adjacent(const string& u, const string& v) {
    int u_position = give_position_as_int(u);
    int v_position = give_position_as_int(v);

    if(adj_matrix[u_position][v_position] != 0){
        return true;
    }
    if(adj_matrix[v_position][u_position] != 0){
        return true;
    }
    return false;
}

/* test5 */

// Returns a vector of those pairs of verticies that share an edge
template <typename T>
vector<pair<string,string>> Graph<T>::get_edges() {

    vector<pair<string,string>> list;
    list.resize(num_edg);
    int current_num_edg = 0;

    for(int i = 0; i < num_ver; i++){
        for(int j = i; j < num_ver; j++){
            if(adj_matrix[i][j] > 0){
                list[current_num_edg].first = vertex[i];
                list[current_num_edg].second = vertex[j];
                current_num_edg++;
            }
        }
    }
   
    return list;
}

/* test6 */

// Retrun a vector of vertecies adjacent to a given vertex
template <typename T>
vector<string> Graph<T>::get_neighbours(const string& u) {

    vector<string> list;
    list.resize(degree(u));
    
    int current_len = 0;
    
    int pos = give_position_as_int(u);

    for(int i = 0; i < num_ver; i++){
        if(adj_matrix[i][pos] > 0){
            //cout << vertex[i] << endl;
            list[current_len] = vertex[i];
            current_len++;
        }
    }

    return list;
}

// Returns the number of edges a vertex is a part of
template <typename T>
size_t Graph<T>::degree(const string& u) {
    int pos = give_position_as_int(u);
    size_t count = 0;

    for(int i = 0; i < num_ver; i++){
        if(adj_matrix[i][pos] > 0){
            count++;
        }
    }
    return count;
}

/* test7 */

// Removes an edge, if one exists, between 2 given vertices
template <typename T>
void Graph<T>::remove_edge(const string& u, const string& v) {
	if(adjacent(u,v) == true){

        int u_position = give_position_as_int(u);
        int v_position = give_position_as_int(v);

        adj_matrix[u_position][v_position] = 0;
        adj_matrix[v_position][u_position] = 0;

        num_edg--;
    }
}

/* test8 */

// Removes a given vertex and all of it's edges
template <typename T>
void Graph<T>::remove_vertex(const string& u) {

    int u_pos = give_position_as_int(u);

    if(contains(u) == true){

        int amount_edges_removed = degree(u);

        for (int i = 0; i < adj_matrix.size(); i++){
            adj_matrix[i].erase(adj_matrix[i].begin() + u_pos);
        }

        adj_matrix.erase(adj_matrix.begin() + u_pos);

        vertex.erase(vertex.begin() + u_pos);

        num_ver--;
        num_edg -= amount_edges_removed;
    }
}

/* test9 */

// Returns a vector of all the vertices in the visiting order of a depth-first traversal from the given vertex.
template <typename T>
vector<string> Graph<T>::depth_first_traversal(const string& u) {
    
    int u_pos = give_position_as_int(u);

    bool visited[num_ver];
    for(int i = 0; i < num_ver; i++){
        visited[i] = false;
    }

    stack<int> s;
    s.push(u_pos);

    vector<string> ordered;

    while(!s.empty()){
        int n = s.top();
        s.pop();
        if(!visited[n]){
            visited[n] = true;
            ordered.push_back(vertex[n]);
            for(int i = num_ver; i != 0; i--){
                if (adj_matrix[n][i-1] > 0){
                    s.push(i-1);
                }
            }
        }
    }

    return ordered;
}

/* test10 */

// Returns a vector of all the vertices in the visiting order of a breadth-first traversal from the given vertex.
template <typename T>
vector<string> Graph<T>::breadth_first_traversal(const string& u) {

    int u_pos = give_position_as_int(u);

    bool visited[num_ver];
    for(int i = 0; i < num_ver; i++){
        visited[i] = false;
    }

    queue<int> q;
    q.push(u_pos);

    vector<string> ordered;

    while (!q.empty()){
		int n = q.front();
		q.pop();
		if (!visited[n]){
			visited[n] = true;
			ordered.push_back(vertex[n]);
			for (int i = 0; i < num_ver; i++){
				if (adj_matrix[n][i]){
					q.push(i);
				}
			}
		}
	}    

    return ordered;
}

/* test11 */

// Return true it finds a vertex that has an edge with an already visited vertex that isn't its parent
template <typename T>
bool Graph<T>::cycles_util(int u, bool visited[], int parent){
    visited[u] = true;

    for(int q = 0; q < num_ver; q++){
        if (adjacent(vertex[u],vertex[q])){
            if(!visited[q]){
                if(cycles_util(q, visited, u)){
                    return true;
                }
            }
            else if (q != parent){
                return true;
            }
        }
    }
    return false;
}

// Returns true if the graph contains a cycle
template <typename T>
bool Graph<T>::contain_cycles() {

    bool *visited = new bool[num_ver];
    for(int i = 0; i < num_ver; i++){
        visited[i] = false;
    }

    for(int j = 0; j < num_ver; j++){
        if(!visited[j]){
            if(cycles_util(j, visited, -1)){
                return true;
            }
        }
    }
    return false;
}

/* test12 */

// Returns a spanning tree of the graph
template <typename T>
Graph<T> Graph<T>::minimum_spanning_tree() {

    Graph<T> g;

    vector<pair<string,string>> edges = get_edges();

    vector<int> edge_weights;
    edge_weights.resize(num_edg);

    for(int i = 0; i < edge_weights.size(); i++){
        edge_weights[i] = adj_matrix[give_position_as_int(edges[i].first)][give_position_as_int(edges[i].second)];
    }

    for(int j = 0; j < num_ver-1; j++){
        if(!g.contains(edges[j].first)){
            g.add_vertex(edges[j].first);
        }
        if(!g.contains(edges[j].second)){
            g.add_vertex(edges[j].second);
        }
        g.add_edge(edges[j].first, edges[j].second, edge_weights[j]);
        
        if(g.contain_cycles()){
            g.remove_edge(edges[j].first, edges[j].second);
        }
    }
    return g;
}