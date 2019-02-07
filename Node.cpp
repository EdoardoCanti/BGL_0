//
//  Node.cpp
//  boostTest
//
//  Created by Edoardo Canti on 04/02/19.
//  Copyright © 2019 Edoardo Canti. All rights reserved.
//

#include <stdio.h>
#include "Node.h"
#include <iostream>

Node::Node(){};
Node::Node(short int i_Identifier, std::string s_name)
{
    this->identifier = i_Identifier;
    this->name = s_name;
}

void Node::setName(std::string s_name)
{
    this->name = s_name;
}

std::string Node::getName()
{
    return this->name;
}

void Node::setIdentifier(short i_Identifier)
{
    this->identifier = i_Identifier;
}

short int Node::getIdentifier()
{
    return this->identifier;
}

void Node::toString(){
    std::cout<<"Node: { [ID : "<<this->identifier<<"] [LABEL : "<<this->name<<"] }"<<std::endl;
}
