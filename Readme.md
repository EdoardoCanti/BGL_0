**Fundamentals of Boost Graph Library** :octocat:

1. Definition of **undirected graph** using **adjacency list**.
   - Definition of vertices and edges.
   - Use of **vertex iterators** and **adjacency iterators**.
   - Use of *boost::tie()* function.
   - Insert a new vertex, and eventually edges, on a built graph.

2. Understanding **directional graph**.
   - Understanding **in-edges** and **out-edges iterators**.
   - Solved issue using in-edges on a directional graph.
   - Implementation of a **bidirectional graph**.

3. Learn **property-maps**.
   - Implementation of **weighted graph**.
   - Printing out weights for each edge.

4. **Classes instances used as graph vertices**.
   - Printing their own values with *graph_name[pointer_vertex_iterator]*.
   - Created new **property** for weighted edges on Object-Graph.
   - Created new **property map** for those weight.
   - Weight are defined as difference between nodes id.
   - Print those weight.

5. **Graph View**
   - Implementing **boost::graphviz()**.
   - Using an **std::ofstream** file to encode the graph.
   - *boost::write_graphviz(<std::ofstream_name>, <graph_name>);*
   - **What to do next: **
   	- Use *boost::make_label_writer()*.
   	- Print weight.