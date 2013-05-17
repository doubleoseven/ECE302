/**
 ECE302 final project
 circuit.h
 @author Haneen Mohammed& Amal Mukhtar
 @brief This class  is the user interface
 */
#include "BNode.h"
#include "Logic.h"
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

/**
 @brief The function be called when the application enter background
 @param the file name with the directory sprcified
 */
template <typename Elem>
void circuit<Elem>::build(string name)
{
    string line;
    ifstream myfile;
    myfile.open (name);
    if (myfile.is_open())
    {
        while (stream_reader(myfile)){}
        myfile.close();
    }
    else
    {
        cout << "Unable to open file" <<endl;
    }
     
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
bool circuit<Elem>::stream_reader(istream& stream)
{
    string line;
    getline (stream,line);
    string buf; // Have a buffer string
    stringstream ss(line); // Insert the string into a stream
    vector<string> tokens; // Create vector to hold our words
    
    while (ss >> buf)
    {
        tokens.push_back(buf);
    }
    if (tokens[0] == "end")
        return false;
    else
        addGate(tokens[0],tokens[1],tokens[2],tokens[3], tokens[4]);
    return true;
}

/**
 @brief remove the 
 @param the pointer of the application
 */
template <typename Elem>
void circuit<Elem>::removeGate(string logic,string input1,string input2,string output,string time)
{
    double t = atof(time.c_str());
    BGate<Elem> Gate(logic, input1, input2, output, t);
    tree.deleteNode(Gate);
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
void circuit<Elem>::equation()
{
    cout << "Set of equations are:" <<endl;
    cout << tree.equation() <<endl;
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
void circuit<Elem>::addGate(string logic,string input1,string input2,string output,string time)
{
    
    double t = atof(time.c_str());
    if (!(tree.insert(logic,input1,input2, output, t)))
        cout<< logic << "Failed"<< std::endl;
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
void circuit<Elem>::setVar(string var, Elem e)
{
    tree.setVar(var, e);
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
Elem circuit<Elem>::evaluate()
{
    return  tree.evaluate();
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
void circuit<Elem>::slowPath()
{
    cout<< "The slowest path is: " <<  tree.slowPath().second<<endl;
    cout<< "It took: " <<  tree.slowPath().first << " nano seconds"<<endl;
}

/**
 @brief The function be called when the application enter background
 @param the pointer of the application
 */
template <typename Elem>
void circuit<Elem>::longPath()
{
    cout<< "The longest path has: " << tree.height() << " Gates" << endl;
}
     
