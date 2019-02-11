//
//  main.cpp
//  boostTest
//
//  Created by Edoardo Canti on 31/01/19.
//  Copyright © 2019 Edoardo Canti. All rights reserved.
//
#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include "Node.h"
#include <boost/graph/graphviz.hpp>

int main()
{
    //definisco un tipo adjacency_list che salva la sequenza di edges in una lista, la sequenza dei nodi in un vector, non orientato
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::undirectedS> undirected_graph;
    
    /*
        0        3
         \      /
          1 -- 2
                \
                  4
     */
    undirected_graph graph;
    boost::add_edge(0, 1, graph); //Creazione arco (0,1)
    boost::add_edge(1, 2, graph); //Creazione arco (1,2)
    boost::add_edge(2, 3, graph); //Creazione arco (2,3)
    boost::add_edge(2, 4, graph); //Creazione arco (2,4)
    
    //Se utilizzo boost::adjacency_list<>::adjacency_iterator adjNode, adjNodeEnd; mi da errore di non overload dell'operatore "=" /tuple.hpp ?
    undirected_graph::vertex_iterator vIterator, vIteratorEnd;
    std::cout<<"Graph Vertices: ";
    
    for(boost::tie(vIterator, vIteratorEnd) = boost::vertices(graph); vIterator != vIteratorEnd; ++vIterator)
        std::cout<<*vIterator<<" ";
    
    std::cout<<std::endl;
    undirected_graph::adjacency_iterator adjNode, adjNodeEnd; //iteratore delle adiacenze
    for(boost::tie(vIterator, vIteratorEnd) = boost::vertices(graph); vIterator != vIteratorEnd; ++vIterator)
    {
        boost::tie(adjNode, adjNodeEnd) = boost::adjacent_vertices(*vIterator, graph);
        for(; adjNode != adjNodeEnd; ++adjNode)
            std::cout<<"Edge ("<<*vIterator<<","<<*adjNode<<")"<<std::endl;
    }
    
    //Aggiunta di un nuovo nodo e di due nuovi archi a partire da un grafo già costruito
    
    boost::adjacency_list<>::vertex_descriptor v = boost::add_vertex(graph);
    boost::add_edge(0, v, graph);
    boost::add_edge(4, v, graph);
    
    std::cout<<std::endl<<std::endl;
    
    std::cout<<"Graph Vertices (AFTER INTRODUCTION OF V1): ";
    for(boost::tie(vIterator, vIteratorEnd)=boost::vertices(graph); vIterator!=vIteratorEnd; ++vIterator)
        std::cout<<*vIterator<<" "; //Mi aspetto lo stesso output di prima con l'aggiunta di v1
    
    std::cout<<std::endl;
    for(boost::tie(vIterator, vIteratorEnd)=boost::vertices(graph); vIterator!=vIteratorEnd; ++vIterator)
    {
        for(boost::tie(adjNode, adjNodeEnd)=boost::adjacent_vertices(*vIterator, graph);
            adjNode != adjNodeEnd; ++adjNode)
        {
            std::cout<<"Edge ("<<*vIterator<<","<<*adjNode<<")"<<std::endl;
        }
    } //Mi aspetto lo stesso output di prima con l'aggiunta di: (0,v1), (v1,0), (4,v1), (v1,4)
    
    std::cout<<std::endl;
    
    //Printing out-edges for each node (N.B undirected graph means out-edges = in-edges)
    undirected_graph::out_edge_iterator outEdge, outEdgeEnd;
    for(boost::tie(vIterator, vIteratorEnd) = boost::vertices(graph); vIterator!=vIteratorEnd; ++vIterator)
    {
        for(boost::tie(outEdge, outEdgeEnd) = boost::out_edges(*vIterator, graph); outEdge!=outEdgeEnd; ++outEdge)
            std::cout<<"Out-Edge(): "<<*outEdge<<" "<<std::endl;
    }
    
    std::cout<<std::endl;
     //Printing in-edges for each node (N.B undirected graph means out-edges = in-edges)
    undirected_graph::in_edge_iterator inEdge, inEdgeEnd;
    for(boost::tie(vIterator, vIteratorEnd)=boost::vertices(graph); vIterator!=vIteratorEnd; ++vIterator)
    {
        for(boost::tie(inEdge, inEdgeEnd)=boost::in_edges(*vIterator, graph); inEdge!=inEdgeEnd; ++inEdge)
            std::cout<<"In-Edge(): "<<*inEdge<<" "<<std::endl;
    }
    
    std::cout<<std::endl;
    
    std::cout<<"[ DIRECTED GRAPH ]"<<std::endl;
    
    /*
     directG structure: 2 <--> 0 --> 1
     */
    
    //definisco un tipo di grafo diretto (orientato)
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::bidirectionalS> directed_graph;
    directed_graph directG; //definizione del tipo di grafo diretto (orientato)
    
    directed_graph::vertex_iterator d_iterator, d_iteratorEnd; //iteratore vertici (grafo diretto)
    directed_graph::adjacency_iterator d_adjNode, d_adjNodeEnd; //iteratore adiacenze (grafo diretto)
    directed_graph::in_edge_iterator d_inEdge, d_inEdgeEnd; //iteratore in-edges
    directed_graph::out_edge_iterator d_outEdge, d_outEdgeEnd; //iteratore out-edges
    
    boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(directG); //descrittore nodo1
    boost::adjacency_list<>::vertex_descriptor v2 = boost::add_vertex(directG); //descrittore nodo2
    boost::adjacency_list<>::vertex_descriptor v3 = boost::add_vertex(directG); //descrittore nodo3
    
    boost::add_edge(v1, v2, directG); //aggiunta arco(v1,v2)
    boost::add_edge(v1, v3, directG); //aggiunta arco(v1,v3)
    boost::add_edge(v3, v1, directG); //aggiunta arco (v3,v1)
    
    std::cout<<"Edge List: "<<std::endl;
    for(boost::tie(d_iterator, d_iteratorEnd) = boost::vertices(directG); d_iterator!=d_iteratorEnd; ++d_iterator)
    {
        for(boost::tie(d_adjNode, d_adjNodeEnd)=boost::adjacent_vertices(*d_iterator, directG); d_adjNode!=d_adjNodeEnd; ++d_adjNode)
            std::cout<<"Edge("<<*d_iterator<<","<<*d_adjNode<<")"<<std::endl;
    }
    
    std::cout<<"Out-Edge list for each vertex:"<<std::endl;
    for(boost::tie(d_iterator, d_iteratorEnd)=boost::vertices(directG); d_iterator!=d_iteratorEnd; ++d_iterator)
    {
        for(boost::tie(d_outEdge, d_outEdgeEnd)=boost::out_edges(*d_iterator, directG); d_outEdge!=d_outEdgeEnd; ++d_outEdge)
            std::cout<<"Out-Edge(): "<<*d_outEdge<<" "<<std::endl;
    }
    
    //Fixed using bidirectional graph
    std::cout<<"In-Edge list for each vertex:"<<std::endl;
    for(boost::tie(d_iterator, d_iteratorEnd)=boost::vertices(directG); d_iterator!=d_iteratorEnd; ++d_iterator)
    {
        for(boost::tie(d_inEdge, d_inEdgeEnd)=boost::in_edges(*d_iterator, directG); d_inEdge!=d_inEdgeEnd; ++d_inEdge)
            std::cout<<"In-Edge(): "<<*d_inEdge<<" "<<std::endl;
    }
    
    //TODO: Implementare grafo pesato
    std::cout<<std::endl;
    std::cout<<"[DIRECT WEIGHTED GRAPH]"<<std::endl;
    typedef boost::property<boost::edge_weight_t, int> EDGEWEIGHT;
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::bidirectionalS, boost::no_property ,EDGEWEIGHT> weighted_graph;
    
    weighted_graph weightedG;
    
    boost::adjacency_list<>::vertex_descriptor w1 = boost::add_vertex(weightedG);
    boost::adjacency_list<>::vertex_descriptor w2 = boost::add_vertex(weightedG);
    boost::adjacency_list<>::vertex_descriptor w3 = boost::add_vertex(weightedG);
    
    weighted_graph::vertex_iterator w_Iterator, w_IteratorEnd;
    weighted_graph::adjacency_iterator w_adjNode, w_adjNodeEnd;
    weighted_graph::in_edge_iterator w_inEdge, w_inEdgeEnd;
    weighted_graph::out_edge_iterator w_outEdge, w_outEdgeEnd;
    weighted_graph::edge_iterator w_edge, w_edgeEnd;
    
    boost::add_edge(w1, w2, -3, weightedG);
    boost::add_edge(w2, w1, 14, weightedG);
    boost::add_edge(w1, w3, 4, weightedG);
    
    std::cout<<"Vertices of weighted graph: ";
    for(boost::tie(w_Iterator, w_IteratorEnd)=boost::vertices(weightedG); w_Iterator!=w_IteratorEnd; ++w_Iterator)
        std::cout<<*w_Iterator<<" ";
    
    std::cout<<std::endl;
    std::cout<<"Edges List:"<<std::endl;
    for(boost::tie(w_edge, w_edgeEnd)=boost::edges(weightedG); w_edge!=w_edgeEnd; ++w_edge)
        std::cout<<*w_edge<<" "<<std::endl;
    
    std::cout<<std::endl;
    std::cout<<"Edges weight:"<<std::endl;
    
    /*
     Creo una property_map<tipo di grafo, tipo da salvare>::type NOME_MAPPA = ottieni (funzione_peso_arco, MIO_GRAFO)
     itero sugli archi stampando il valore della mappa per ogni arco. RETURN: peso degli archi
     */
    boost::property_map<weighted_graph, boost::edge_weight_t>::type EdgeWeightMap = get(boost::edge_weight_t(), weightedG);
     for(boost::tie(w_edge, w_edgeEnd)=boost::edges(weightedG); w_edge!=w_edgeEnd; ++w_edge)
         std::cout<<*w_edge<<" weight: "<<EdgeWeightMap[*w_edge]<<std::endl;
    
    std::cout<<std::endl<<std::endl;
    std::cout<<"[OBJECT AS VERTICES]"<<std::endl;
    
    //Grafo di puntatori ad oggetti definiti (Node*)
    typedef boost::property<boost::edge_weight_t, int> TYPE_EDGEWEIGHT; //DEFINISCO LA PROPRIETA' PESO
    typedef boost::adjacency_list<boost::listS, boost::vecS, boost::bidirectionalS, Node*, TYPE_EDGEWEIGHT> type_graph; //TIPO DI GRAFO
    type_graph userGraph; //GRAFO
    boost::property_map<type_graph, boost::edge_weight_t>::type TYPE_EDGE_WEIGHT = get(boost::edge_weight_t(), userGraph); //MAPPA
    type_graph::vertex_iterator type_Vertex, type_VertexEnd;
    type_graph::edge_iterator type_Edge, type_EdgeEnd;
    type_graph::in_edge_iterator type_inEdge, type_inEdgeEnd;
    type_graph::out_edge_iterator type_outEdge, type_outEdgeEnd;
    
    Node* userNode1 = new Node(100, "One-Hundred");
    Node* userNode2 = new Node(200, "Two-Hundred");
    
    
    //FIXED: Stampare attributi di un oggetto definito
    type_graph::vertex_descriptor node1 = boost::add_vertex(userNode1, userGraph);
    type_graph::vertex_descriptor node2 = boost::add_vertex(userNode2, userGraph);
    
    std::cout<<"Printing Object Vertices: "<<std::endl;
    boost::tie(type_Vertex, type_VertexEnd) = boost::vertices(userGraph);
    for(; type_Vertex!=type_VertexEnd; type_Vertex++)
    {
        //Itero sui vertici (Node Object) del grafo userGraph e per ognuno eseguo il metodo toString() della classe Node
        userGraph[*type_Vertex]->toString();
    }
    
    /*
        Make weighted edges in this way:
        i : Node
        j : Node
        LET E=(i,j) an edge.
        weight E = i->id - j->id.
     */
    
    boost::add_edge(node1, node2, userNode1->getIdentifier()-userNode2->getIdentifier() ,userGraph);
    boost::add_edge(node2, node1, userNode2->getIdentifier()-userNode1->getIdentifier() ,userGraph);
    for(boost::tie(type_Edge, type_EdgeEnd)=boost::edges(userGraph); type_Edge!=type_EdgeEnd; ++type_Edge)
        std::cout<<*type_Edge<<" weight: "<<TYPE_EDGE_WEIGHT[*type_Edge]<<std::endl;
    
    std::cout<<std::endl;
    
    //Printing graph
    std::ofstream file;
    file.open("userGraph.dot");
    //boost::write_graphviz(dmp,graph);
    //boost::write_graphviz(dmp, directG);
    //boost::write_graphviz(dmp, weightedG);
    boost::write_graphviz(file, userGraph);
    //TERMINAL : dot -Tpng userGraph.dot -o userG_dot.png

    
    
    
   
}
//TODO: graphviz()


