
#include "BNode.h"
#include "Logic.h"
#include "BTree.h"
 #include <iostream>

using namespace std;

template <typename Elem> class circuit{
protected:
    BTree<Elem> tree;
public:
    //function circuit.build(f)
    //circuit.removeGate(Gate)
    
    circuit(){}//end circuit constructor
    string equation() {
        return tree.equation();
    }
    bool insert(string logic,string input1,string input2,string output,int time)
    {
        tree.insert(logic,input1,input2, output, time);
        return true;
    }//end  insert
    
    void setVar(string var, Elem e)
    {
        tree.setVar(var, e);
    }//end setVar
    
    bool evaluate()
    {
        return  tree.evaluate();

    }// end evaluate
    
    string longPath() {
        return "d";
    }
    string slowPath() {
        return "d";
    }
    int slowPathTime(){
        return 31;
    }
    
}; // end circuit
