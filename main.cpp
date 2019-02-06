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
    
    //Aggiunita di un nuovo nodo e di due nuovi archi a partire da un grafo già costruito
    
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
    
    
    
    
    
    
}


