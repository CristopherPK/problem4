//
//  main.cpp
//  wsn-project
//
//  Created by Cristopher Freitas on 8/2/16.
//  Copyright © 2016 Cristopher Freitas. All rights reserved.
//

#include <iostream>
#include "tree.hpp"

int main(int argc, const char * argv[]) {
    
    // First case.
    Tree * t = new Tree(false);
    t->start();
    while(t->run()){
        int x, y;
        cout << "enter your x and y: " << endl;
        cin >> y;
        cin >> x;
        t->play(x, y);
    }
    
//    Tree * t2 = new Tree(true);
//    t2->start();
//    do {
//        int x, y;
//        cout << "enter your x and y: " << endl;
//        cin >> y;
//        cin >> x;
//        t2->play(x, y);
//    } while(t2->run());
//    
    return 0;
}
