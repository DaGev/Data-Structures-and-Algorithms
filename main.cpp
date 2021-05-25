#include "tree.hpp"

int main(){

	BST<int> t;

    t.add_vertex("C", 5);
    t.add_vertex("A", 1);
    t.add_vertex("H", 10);
    t.add_vertex("D", 3);
    t.add_vertex("G", 20);
    t.add_vertex("F", 15);
    t.add_vertex("B", 30);
    t.add_vertex("E", 17);

    cout << "test" << endl;

    // for(auto x : t.get_leaves()){
    //     cout << x << " ";
    // }

    // cout << t.contains("E") << endl;
    // t.get_vertices();
    // t.get_leaves();

    // cout << t.get_pos("G") << endl;

    // t.get_edges();
    // cout << t.get_parent_pos("G") << endl;
    // t.get_neighbours("G");
    // cout << t.degree("G") << endl;

    // t.preorder_traversal();
    // t.postorder_traversal();
    // t.inorder_traversal();
    // t.breadth_first_traversal();

    // t.path("G", "E");

    // t.path_with_largest_weight();
    
    // cout << t.num_vertices() << endl;
    // cout << t.num_edges() << endl;
    // cout << t.sum_weight() << endl;

    //cout<<t.degree("B")<<endl;
    //t.get_neighbours("C");
    //t.get_parent_pos("S");
    //t.preorder_traversal();
    //t.breadth_first_traversal();
    
    // for(auto x : t.path("C", "H")){
    //     cout << x << " ";
    // }
    
    // for(auto x : t.path("D", "F")){
    //     cout << x << " ";
    // }
    // cout << endl;

    // vector<string> path_1;
    // path_1 = t.path("D", "F");

    // for(auto x : path_1){
    //     cout << x << " ";
    // }
    //t.height();

    //t.remove_vertex("E");
    // t.remove_vertex("A");

    // cout << t.num_vertices() << endl;
    // cout << t.num_edges() << endl;
    // cout << t.sum_weight() << endl;

    // cout << endl;
    //t.path("H", "E");
}