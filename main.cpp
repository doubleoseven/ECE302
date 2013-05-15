#include "circuit.h"
using namespace std;
int main(int argc, const char * argv[])
{
    
     BTree<bool> reg;
    //f = ask the user to write the data
    //build(f)
    //setVar(var, value)
    //eval()
    //addGate(Gate)
    //removeGate(Gate)
    //slowPath();
    //longPath();

     std::cout << reg.insert("NOR", "X5", "X6","Y",1.5);
     std::cout << reg.insert("NAND", "X3", "X4","X6",1);
     std::cout << reg.insert("NAND", "X1", "X2","X5",1);
     std::cout << reg.insert("AND", "B", "D","X4",3);
     std::cout << reg.insert("OR", "A", "C","X3",2);
     std::cout << reg.insert("AND", "B", "C","X2",2);
    std::cout << reg.insert("OR", "A", "B","X1",2) << endl;
    reg.setVar("A", false);
    reg.setVar("B", false);
    reg.setVar("C", false);
    reg.setVar("D", false);
    std::cout <<"Y =( "<<  reg.evaluate()<<" )" <<endl;
    std::cout <<reg.equation()<<endl;

    
return 0;
} 