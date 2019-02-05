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
    
    boost::adjacency_list<>::vertex_descriptor v1 = boost::add_vertex(graph);
    boost::add_edge(0, v1, graph);
    boost::add_edge(4, v1, graph);
    
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
    
    
    
    
    
}


