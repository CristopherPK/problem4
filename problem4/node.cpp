//
//  node.cpp
//  wsn-project
//
//  Created by Cristopher Freitas on 8/3/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include "node.hpp"

Node::Node(){
    this->table.push_back({0,0,0});
    this->table.push_back({0,0,0});
    this->table.push_back({0,0,0});
    this->score = f();
}

Node::Node(const Node & other){
    this->table = other.table;
    this->children = other.children;
    this->score = f();
}

Node::Node(vector<vector<int>> table){
    this->table = table;
    this->score = f();
}

void Node::setState(bool state){
    this->state = state;
}

bool Node::getState(){
    return this->state;
}

int Node::setChildren(vector<Node *> children){
    this->children = children;
    if(this->children.size() > 0){
        return 1;
    } else {
        return 0;
    }
}

vector<Node *> Node::getChildren(){
    return this->children;
}

void Node::setScore(int score){
    this->score = score;
}

int Node::getScore(){
    return this->score;
}

void Node::setPrev(Node *prev){
    this->prev = prev;
}

Node * Node::getPrev(){
    return this->prev;
}

string Node::toString(){
    string result;
    for(int i = 0; i < this->table.size(); i++){
        result += '[';
        for(int j = 0; j < this->table[i].size(); j++){
            result += to_string(this->table[i][j]);
            if(j < this->table.size() - 1){
                result += '|';
            }
        }
        result += "]\n";
    }
    return result;
}

int Node::play(int x, int y, bool flag){
    if(this->table[x][y] == 0){
        if(!flag){
            this->table[x][y] = 1;
        } else {
            this->table[x][y] = -1;
        }
        this->score = f();
        return 1;
    } else {
        return 0;
    }
}

// function to evaluate the node score.
int Node::f(){
    int score = 0;
    int count = 0;
    vector<int> result;
    // horizontal evaluation
    for(int i = 0; i < this->table.size(); i++){
        for(int j = 0; j < this->table[i].size(); j++){
            if(table[i][j] > 0){
                count++;
            } else if(table[i][j] < 0){
                count = 0;
                break;
            }
        }
        if(count == 3){
            score += 100;
            //return score;
        } else if(count > 0){
            score++;
            count = 0;
        }
    }
    
    // vertical evaluation
    for(int i = 0; i < this->table.size(); i++){
        for(int j = 0; j < this->table[i].size(); j++){
            if(table[j][i] > 0){
                count++;
            } else if(table[j][i] < 0){
                count = 0;
                break;
            }
        }
        if(count == 3){
            score += 100;
            //return score;
        } else if(count > 0){
            score++;
            count = 0;
        }
    }
    
    // diagonal evaluation
    if(this->table[1][1] >= 0){
        vector<vector<int>> d1;
        d1.push_back({0,0});
        d1.push_back({1,1});
        d1.push_back({2,2});
    
        for(int i = 0; i < d1.size(); i++){
            vector<int> t = d1[i];
            if(table[t[0]][t[1]] > 0){
                count++;
            } else if(table[t[0]][t[1]] < 0){
                count = 0;
                break;
            }
        }
        
        if(count == 3){
            score += 100;
            //return score;
        } else if(count > 0){
            score++;
            count = 0;
        }
        
        vector<vector<int>> d2;
        d2.push_back({0,2});
        d2.push_back({1,1});
        d2.push_back({2,0});
        for(int i = 0; i < d2.size(); i++){
            vector<int> t = d2[i];
            if(table[t[0]][t[1]] > 0){
                count++;
            } else if(table[t[0]][t[1]] < 0){
                count = 0;
                break;
            }
        }
        
        if(count == 3){
            score += 100;
            //return score;
        } else if(count > 0){
            score++;
            count = 0;
        }
    }
    
    return score;
}


// return the complement of the actual table.
vector<vector<int>> Node::comp(){
    vector<vector<int>> _table;
    for(int i = 0; i < this->table.size(); i++){
        vector<int> line;
        for(int j = 0; j < this->table[i].size(); j++){
            if(this->table[i][j] == 1){
                line.push_back(-1);
            } else if(this->table[i][j] == -1){
                line.push_back(1);
            } else {
                line.push_back(0);
            }
        }
        _table.push_back(line);
    }
    return _table;
}