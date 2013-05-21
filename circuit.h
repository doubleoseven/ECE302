/**
 ECE302 final project
 circuit.h
 @author Haneen Mohammed& Amal Mukhtar
 @brief This class  is the user interface
 */
#include "BNode.h"
#include "BTree.h"
#include <fstream>
#include <iostream>
#include <stdlib.h>     
#include <vector>
#include <string>
#include <sstream>

using namespace std;
template <typename Elem> class circuit
{
protected:
BTree<Elem> tree;
public:
    circuit();
    ~circuit();
    void build(string);
    void addGate(string,string,string,string,string);
    void removeGate(string,string,string,string,string);
    void equation();
    void setVar(string,Elem);
    Elem evaluate();
    void slowPath();
    void longPath();
private:
    bool stream_reader(istream&);
};

template <typename Elem> 
circuit<Elem>::circuit(){}

template <typename Elem>
circuit<Elem>::~circuit(){ }

//Reads a boolean expression in prefix form from a texttual file and builds the corresponding expression tree.
template <typename Elem>
void circuit<Elem>::build(string name){
    ifstream myfile;
    myfile.open (name);
    if (myfile.is_open()){
        while (stream_reader(myfile)){}
        myfile.close();
    }
    else{
        cout << "Unable to open file" <<endl;
    }
     
}

template <typename Elem>
bool circuit<Elem>::stream_reader(istream& stream){
    string line;
    getline (stream,line);
    string buf; // Have a buffer string
    stringstream ss(line); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    
    while (ss >> buf){
        tokens.push_back(buf);
    }
    if (tokens[0] == "end")
        return false;
    else
        addGate(tokens[0],tokens[1],tokens[2],tokens[3], tokens[4]);
    return true;
}
/**
 Function to delete Gate from the binary tree.
 @Postcondition: If a node with the same info as deleteItem
 is found, it is deleted from the binary search tree.
 @param informations of an Object type BGate.
 */
template <typename Elem>
void circuit<Elem>::removeGate(string logic,string input1,string input2,string output,string time){
    double t = atof(time.c_str());
    BGate<Elem> Gate(logic, input1, input2, output, t);
    tree.deleteNode(Gate);
}
/**
 Function to find the set of equations the data represent
 @return string
 */
template <typename Elem>
void circuit<Elem>::equation(){
    cout << "Set of equations are:" <<endl;
    cout << tree.equation() <<endl;
}
/**
 Function to initilize &then insert a Gate in the binary tree.
 @param an Object of type BGate.
 */
template <typename Elem>
void circuit<Elem>::addGate(string logic,string input1,string input2,string output,string time){
    
    double t = atof(time.c_str());
    if (!(tree.insert(logic,input1,input2, output, t)))
        cout<< logic << "Failed"<< std::endl;
}
/**
 Function to initilize the variables with the relevant data.
 @param (string variable, Elem data)
 */
template <typename Elem>
void circuit<Elem>::setVar(string var, Elem e){
    tree.setVar(var, e);
}
/**
 Function to evaluate, and output the final result
 @return the final output type Elem
 */
template <typename Elem>
Elem circuit<Elem>::evaluate(){
    return  tree.evaluate();
}
/**
 Function to find wich path took the slowest time to compute
 @return the path and the time it took
 */
template <typename Elem>
void circuit<Elem>::slowPath(){
    cout<< "The slowest path is: " <<  tree.slowPath().second<<endl;
    cout<< "It took: " <<  tree.slowPath().first << " nano seconds"<<endl;
}
/**
 Function to find wich path has the most number of Gates
 @return int, number of Gates in that path
 */
template <typename Elem>
void circuit<Elem>::longPath(){
    cout<< "The longest path has: " << tree.height() << " Gates" << endl;
}
     
