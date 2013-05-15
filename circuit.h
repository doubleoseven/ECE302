
#include "BNode.h"
#include "Logic.h"
#include "BTree.h"
#include <fstream>
#include <iostream>

using namespace std;

template <typename Elem> class circuit{
protected:
    BTree<Elem> tree;
public:
    
    circuit(){}//end circuit constructor
    
    //function circuit.build(f)
    void build()
    {
        /*
         string line;
        ifstream input ( "logic_ex.txt" );
        for(line; getline( input, line ); )
        {
           // ...for each line in input...
                }
         */
        return;
    }
    
    //circuit.removeGate(Gate)
    void removeGate(string logic,string input1,string input2,string output,int time)
    {
        BGate<Elem> Gate(logic, input1, input2, output, time);
        tree.deleteNode(Gate);
    }
    
    string equation()
    {
        return tree.equation();
    }//end equation
    
    void addGate(string logic,string input1,string input2,string output,int time)
    {
        if (!(tree.insert(logic,input1,input2, output, time)))
            std::cout<< logic << "failed"<< std::endl;
    }//end  addGate
    
    void setVar(string var, Elem e)
    {
        tree.setVar(var, e);
    }//end setVar
    
    bool evaluate()
    {
        return  tree.evaluate();

    }// end evaluate
    
    string longPath()
    {
        return "d";
    }//end longPath
    
    string slowPath()
    {
        return "d";
    }//end slowPath
    
    int slowPathTime()
    {
        return 31;
    }//end slowPathTime
    
}; // end circuit
