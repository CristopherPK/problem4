//
//  node.hpp
//  wsn-project
//
//  Created by Cristopher Freitas on 8/3/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

class Node {
    Node * prev;
    vector<Node *> children;
    bool state; // 0 is min, 1 is max.
    int score;
    
public:
    Node();
    Node(vector<vector<int>> table);
    Node(const Node & other);
    vector<vector<int>> table;
    int f();
    void setScore(int score);
    int getScore();
    void setState(bool state);
    bool getState();
    void setPrev(Node * prev);
    Node * getPrev();
    string toString();
    int play(int x, int y, bool flag);
    vector<vector<int>> comp();
    int setChildren(vector<Node *> children);
    vector<Node *> getChildren();
};

#endif /* node_hpp */
