//
//  tree.hpp
//  wsn-project
//
//  Created by Cristopher Freitas on 8/3/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <iostream>
#include <vector>
#include "node.hpp"

using namespace std;

class Tree {
    Node * root;
    vector<Node *> getNext(Node * node);
    Node * getMinMax(Node * node);
    Node * move(Node * node);
    bool check();
public:
    Tree(bool state);
    int run();
    int start();
    int play(int x, int y);
};

#endif /* tree_hpp */
