//*************************************************************
// Author: Haneen Mohammed& Amal Mukhtar
//
// class circuit
// This class  is the user interface
//*************************************************************


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
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */    void build()
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
    
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    void removeGate(string logic,string input1,string input2,string output,int time)
    {
        BGate<Elem> Gate(logic, input1, input2, output, time);
        tree.deleteNode(Gate);
    }
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    string equation() 
    {
        return tree.equation();
    }//end equation
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    void addGate(string logic,string input1,string input2,string output,int time)
    {
        if (!(tree.insert(logic,input1,input2, output, time)))
            std::cout<< logic << "failed"<< std::endl;
    }//end  addGate
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    void setVar(string var, Elem e)
    {
        tree.setVar(var, e);
    }//end setVar
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    Elem evaluate() 
    {
        return  tree.evaluate();

    }// end evaluate
    
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    void slowPath()
    {
        cout<< "the slowest path is: " <<  tree.slowPath().second<<endl;
        cout<< "it took: " <<  tree.slowPath().first << " nano seconds"<<endl;
    }//end longPath
      
    /** Task: Retrieves the right child of the node.
     * @return the node that is this nodeÕs left (right) child */
    int longPath()
    {
        return tree.height();
    }
    
    
     
}; // end circuit
