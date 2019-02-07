//
//  Node.h
//  boostTest
//
//  Created by Edoardo Canti on 03/02/19.
//  Copyright © 2019 Edoardo Canti. All rights reserved.
//

#ifndef Node_h
#define Node_h
#include <string>

class Node {
    short int identifier;
    std::string name;
public:
    Node(); //Default c'tor
    Node(short int i_Identifier, std::string name);
    
    void setIdentifier(short int i_Identifier); //identifier setter
    short int getIdentifier(); //identifier getter
    
    void setName(std::string s_Name); //name setter
    std::string getName(); //name getter
    
    void toString();
    
};

#endif /* Node_h */
