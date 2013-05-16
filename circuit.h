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

template <typename Elem> class circuit
{
protected:
BTree<Elem> tree;
public:
    circuit();
    void file_reader();
    void stream_reader(istream& stream);
    void build();
    void addGate(string logic,string input1,string input2,string output,int time);
    void removeGate(string logic,string input1,string input2,string output,int time);
    void equation();
    void setVar(string var, Elem e);
    Elem evaluate();
    void slowPath();
    void longPath();
};

template <typename Elem> 
circuit<Elem>::circuit(){} 
template <typename Elem>
void circuit<Elem>::file_reader()
{
    string line;
    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            stream_reader(myfile);
        }
        myfile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
}
template <typename Elem>
void circuit<Elem>::stream_reader(istream& stream)
{
    string line;
    getline (stream,line);
    cout << line << endl;
}
/** Task: 
* */
template <typename Elem>
void circuit<Elem>::build()
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
/** Task: 
 * */
template <typename Elem>
void circuit<Elem>::removeGate(string logic,string input1,string input2,string output,int time)
{
    BGate<Elem> Gate(logic, input1, input2, output, time);
    tree.deleteNode(Gate);
}
/** Task: 
* @return*/
template <typename Elem>
void circuit<Elem>::equation()
{
    cout << "Set of equations are:" <<endl;
    cout << tree.equation() <<endl;
}//end equation
/** Task: 
 * @return */
template <typename Elem>
void circuit<Elem>::addGate(string logic,string input1,string input2,string output,int time)
{
    if (!(tree.insert(logic,input1,input2, output, time)))
        std::cout<< logic << "Failed"<< std::endl;
}//end  addGate

/** Task: 
*  */
template <typename Elem>
void circuit<Elem>::setVar(string var, Elem e)
{
    tree.setVar(var, e);
}//end setVar

/** Task: 
 * @return  */

template <typename Elem>
Elem circuit<Elem>::evaluate()
{
    return  tree.evaluate();
}// end evaluate

/** Task: 
 **/
template <typename Elem>
void circuit<Elem>::slowPath()
{
    cout<< "The slowest path is: " <<  tree.slowPath().second<<endl;
    cout<< "It took: " <<  tree.slowPath().first << " nano seconds"<<endl;
}//end longPath

/** Task: 
 */
template <typename Elem>
void circuit<Elem>::longPath()
{
    cout<< "The longest path has: " << tree.height() << " Gates" << endl;
}
     
