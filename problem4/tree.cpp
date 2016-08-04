//
//  tree.cpp
//  wsn-project
//
//  Created by Cristopher Freitas on 8/3/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include "tree.hpp"

Tree::Tree(bool state){
    this->root = new Node();
    this->root->setPrev(NULL);
    this->root->setState(state);
}

Node * Tree::move(Node * node){
    node = getMinMax(node);
    return node;
}

bool Tree::check(){
    Node * _root = new Node(root->comp());
    
    if(root->getScore() >= 100 || _root->getScore() >= 100){
        return 0;
    } else {
        return 1;
    }
    
}

int Tree::play(int x, int y){
    vector<Node *> children = root->getChildren();
    vector<Node *>::iterator itc = children.begin();
    while(itc!=children.end()){
        // hoping he plays where he didn't.
        if((*itc)->table[x][y] == -1){
            root = *itc;
            break;
        }
        itc++;
    }
    return 0;
}

vector<Node *> Tree::getNext(Node * node){
    vector<Node *> children;
    Node * nodeCopy = new Node(*node);
    
    for(int i=0; i < 3; i++){
        for(int j=0; j < 3; j++){
            if(nodeCopy->play(i, j, node->getState())){
                Node * n = new Node(*nodeCopy);
                n->setState(!node->getState());
                n->setPrev(node);
                children.push_back(n);
                getNext(n);
                // keeping node reference safe.
                nodeCopy = 0;
                delete nodeCopy;
                nodeCopy = new Node(*node);
            }
        }
    }
    
    
    node->setChildren(children);
    
    return children;
}

Node * Tree::getMinMax(Node * node){
    
    if(node == NULL){
        return NULL;
    }
    
    if(node->getChildren().size() == 0){
        return node;
    }
    
    vector<Node *> children = node->getChildren();
    vector<Node *>::iterator itn = children.begin();
    Node * best = *itn;
    itn++;
    
    while(itn != children.end()){
        // evaluates winning option
        if(!node->getState()){
            if(best->getScore() <= (*itn)->getScore()){
                best = *itn;
            }
        } else {
            if(best->getScore() >= (*itn)->getScore()){
                best = *itn;
            }
        }
        itn++;
    }
    
    int score = best->getScore();
    best->getPrev()->setScore(score);
    
    return best;
}

int Tree::start(){
    cout << root->toString() << endl;
    
    root->setChildren(getNext(root));
    
    return 0;
}

int Tree::run(){
    
    if(!check()){
        return 0;
    }
    
    root = move(root);
    
    cout << root->toString() << endl;
    cout << root->getScore() << endl;
    
    if(!check()){
        return 0;
    }
    
    return 1;
}