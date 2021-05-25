#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <limits>
#include <utility> 
#include <algorithm>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

template <typename T> // the template allows the weight of vertex to take any numeric data type (denoted by T).
class BST {
    struct Node {
            string name;
            T weight;
    };
	public:
        vector<Node> tree;
        vector<bool> in_tree;
        size_t num_ver;
        size_t num_edg;
        T sum_w;

        /* test1 */
		BST(); // the contructor function.
		~BST(); // the destructor function.
		size_t num_vertices(); // returns the total number of vertices in the bst.
		size_t num_edges(); // returns the total number of edges in the bst.
        T sum_weight(); // return the total weight of all the vertices in the bst.

        /* test2 */
        void add_vertex(const string&, const T&); // adds a vertex, which has a weight, to the tree -- every vertex uses a string as its unique identifier.
        bool contains(const string&); // checks if a vertex is in the bst -- returns true if the bst contains the given vertex; otherwise, returns false.
        
        /* test3 */
        vector<string> get_vertices(); // returns a vector of all the vertices in the bst.
        vector<string> get_leaves(); // returns a vector of all the leaves in the bst.
                                     //     Leaves are the vertices that do not have any children in the bst.
        /* test4 */
        int get_pos(const string&); // get position in the array of a string
        bool adjacent(const string&, const string&); // check if there is an edge between the two vertices in the bst -- returns true if the edge exists; otherwise, returns false.
		
        /* test5 */
        vector<pair<string,string>> get_edges(); // returns a vector of all the edges in the bst -- each edge is represented by a pair of vertices incident to the edge.
        
        /* test6 */
        int get_parent_pos(const string&); // returns the parent of a given node
        vector<string> get_neighbours(const string&); // returns a vector of all the vertices, each of which is directly connected with the given vertex via an edge.
        size_t degree(const string&); // returns the degree of a vertex.

        /* test7 */
        void preorder(int u_pos, vector<string>& preordered_tree); // recursive helper funciton
		vector<string> preorder_traversal(); // returns a vector of all the vertices in the visiting order of a preorder traversal over the bst.
		
        /* test8 */
        void inorder(int u_pos, vector<string>& inordered_tree); // recursive helper function
        vector<string> inorder_traversal(); // returns a vector of all the vertices in the visiting order of an inorder traversal over the bst.
        
        /* test9 */
        void postorder(int u_pos, vector<string>& postordered_tree); // recursive helper function
        vector<string> postorder_traversal(); // returns a vector of all the vertices in the visiting order of a postorder traversal over the bst.
        
        /* test10 */
        vector<string> breadth_first_traversal(); // returns a vector of all the vertices in the visiting order of a breadth first traversal over the bst.
		
        /* test11 */
        bool get_path(int root, vector<string>& path, int u_pos); // recursive helper function
        vector<string> path(const string&, const string&); // returns a vector of all the vertices in the path from the first vertex to the second vertex.
                                                            //     A path should include the source and destination vertices at the begining and the end, respectively.
        /* test12 */
        int weight(vector<string>& path); // recursive helper function
        vector<string> path_with_largest_weight(); // returns a path that has the largest weight in the bst.
                                       //    The weight of a path is the sum of the weights of all the vertices (including the source and destination vertices) in the path.
        /* test13 */
        size_t height(); // returns the height of bst. Height of a tree is the number of edges that form the longest path from root to any leaf.

        /* test14 */
        void remove_vertex(const string&); // delete the given vertex from bst -- note that, all incident edges of the vertex should be deleted as well.
};

/* test1 */
template <typename T>
BST<T>::BST() {
    tree.resize(10);
    in_tree.resize(10, false);
    num_ver = 0;
    num_edg = 0;
    sum_w = 0;
}

template <typename T>
BST<T>::~BST() {}

template <typename T>
size_t BST<T>::num_vertices() {
    return num_ver;
}

template <typename T>
size_t BST<T>::num_edges() {
    return num_edg;
}

template <typename T>
T BST<T>::sum_weight() {
    return sum_w;
}

/* test2 */
template <typename T>
void BST<T>::add_vertex(const string& u, const T& w) {
    Node vertex;
    vertex.name = u;
    vertex.weight = w;

    if (contains(u) == false){
        int pos = 0;

        while (pos < tree.size() && in_tree[pos]){
            if (w < tree[pos].weight) pos = 2 * pos + 1;
            else pos = 2 * pos + 2;
        }

        while (pos >= tree.size()){
            tree.resize(2*tree.size());
            in_tree.resize(2*in_tree.size(), false);
        }
        tree[pos] = vertex; // store the vertex in the position
        in_tree[pos] = true; // set that position as occupied

        num_ver++;
        if (num_ver > 1) num_edg++;
        sum_w += w;
    }   
}

template <typename T>
bool BST<T>::contains(const string& u) {
    for (int i = 0; i < tree.size(); i++){
        if(in_tree[i]) if (tree[i].name == u) return true;
    }
    return false;
}

/* test3 */
template <typename T>
vector<string> BST<T>::get_vertices() {
    vector<string> vertices; // create a vector

    for (int i = 0; i < tree.size(); i++){
        if(in_tree[i]) vertices.push_back(tree[i].name); // if it's in the tree, push its string into the tree
    }
    return vertices;
}

template <typename T>
vector<string> BST<T>::get_leaves() {
    vector<string> vertices; // create a vector;

    for (int i = 0; i < tree.size(); i++){
        if(in_tree[i]){ // if it's in the tree and both of it's sides are empty, it's a leaf, so add its string to the vector
            if(in_tree[2*i+1] == false && in_tree[2*i+2] == false) vertices.push_back(tree[i].name);
        }
    }
    return vertices;
}

/* test4 */
template <typename T>
int BST<T>::get_pos(const string& u){ // helper to get the postion in the vector of a given name of a node
    
    if(contains(u)){
        for(int i = 0; i < tree.size(); i++){
            if (in_tree[i]){
                if(tree[i].name == u) return i;
            }
        }
    }
    return 0;
}

template <typename T>
bool BST<T>::adjacent(const string& u, const string& v) { // if v is a right or left child of u OR u is a right or left child of u, return true
    if ((get_pos(v) == 2 * get_pos(u) + 1 || get_pos(v) == 2 * get_pos(u) + 2) || (get_pos(u) == 2 * get_pos(v) + 1 || get_pos(u) == 2 * get_pos(v) + 2)) return true;
    return false;
}

/* test5 */
template <typename T>
vector<pair<string,string>> BST<T>::get_edges() {
    vector<pair<string, string>> edges;

    for(int i = 0; i < tree.size(); i++){ // for every position in the tree vector
        if(in_tree[i]){ // if it is not empty, check if it has children
            if(in_tree[2*i+1]){ // if it has a left child, add it and it's left child to the list of edges
                pair<string,string> my_pair;
                my_pair.first = tree[i].name;
                my_pair.second = tree[2*i+1].name;
                edges.push_back(my_pair);
            }
            if(in_tree[2*i+2]){ // if it has a right child, add it and it's right child to the list of edges
                pair<string,string> my_pair;
                my_pair.first = tree[i].name;
                my_pair.second = tree[2*i+2].name;
                edges.push_back(my_pair);
            }
        }
    }
    return edges;
}

/* test6 */
template <typename T>
int BST<T>::get_parent_pos(const string& u){ // returns the parent position of a given node
    int u_pos = get_pos(u);

    if(u_pos == 0) return 0;
    if(u_pos % 2 == 0) return ((u_pos - 2) / 2);
    else return ((u_pos - 1) / 2);
}

template <typename T>
vector<string> BST<T>::get_neighbours(const string& u) {
    vector<string> neighbours;

    int u_pos = get_pos(u);
    if(in_tree[u_pos]){ // if something exists in that position
        if(u_pos != 0){ // if it's not the root
            int u_parent_pos = get_parent_pos(u);
            neighbours.push_back(tree[u_parent_pos].name); // add their parent to the vector
        }
        if(in_tree[2*u_pos+1]){ // if it has a left child
            neighbours.push_back(tree[2*u_pos+1].name); // add their left kid to the vector
        }
        if(in_tree[2*u_pos+2]){ // if it has a right child
            neighbours.push_back(tree[2*u_pos+2].name); // add their right child to the vector
        }
    }
    return neighbours;
}

template <typename T>
size_t BST<T>::degree(const string& u) {
    return get_neighbours(u).size();
}

/* test7 */
template <typename T> // recursive helper function
void BST<T>::preorder(int u_pos, vector<string>& preordered_tree){ 
    if(in_tree[u_pos]){
        preordered_tree.push_back(tree[u_pos].name); // first, push to the vector
        if(in_tree[(2*u_pos+1)]) preorder((2*u_pos+1), preordered_tree); // if left exists, do the same for it
        if(in_tree[(2*u_pos+2)]) preorder((2*u_pos+2), preordered_tree); // if right exists, do the same for it
    }
}

template <typename T>
vector<string> BST<T>::preorder_traversal() {
    vector<string> preordered_tree;

    if(in_tree[0]) preorder(0, preordered_tree); // if root, exists, start from it
    return preordered_tree;
}