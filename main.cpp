#include "circuit.h"
using namespace std;
int main(int argc, const char * argv[])
{
    
     circuit<bool> reg;
    
    //f = ask the user to write the data
    //build(f)
    //setVar(var, value)
    //eval()
    //addGate(Gate)
    //removeGate(Gate)
    //slowPath();
    //longPath();

    reg.addGate("NOR", "X5", "X6","Y",1.5);
    reg.addGate("NAND", "X3", "X4","X6",1);
    reg.addGate("NAND", "X1", "X2","X5",1);
    reg.addGate("AND", "B", "D","X4",3);
    reg.addGate("OR", "A", "C","X3",2);
    reg.addGate("AND", "B", "C","X2",2);
    reg.addGate("OR", "A", "B","X1",2);
    
    reg.setVar("A", true);
    reg.setVar("B", true);
    reg.setVar("C", true);
    reg.setVar("D", true);
    
    cout <<"Y =( "<<  reg.evaluate()<<" )" <<endl;
    cout <<reg.equation()<<endl;
    cout <<reg.longPath()<<endl;
    cout <<reg.slowPath()<<endl;
    cout <<reg.slowPathTime()<<endl;


    
return 0;
} 