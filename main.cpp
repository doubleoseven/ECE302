#include "circuit.h"
using namespace std;
int main(int argc, const char * argv[])
{
    
     circuit<string> reg;
    
    //f = ask the user to write the data
    //build(f)
    //setVar(var, value)
    //eval()
    //addGate(Gate)
    //removeGate(Gate)
    //longPath();
    //slowPathTime();

    reg.addGate("NOR", "X5", "X6","Y",7);
    reg.addGate("NAND", "X3", "X4","X6",6);
    reg.addGate("NAND", "X1", "X2","X5",5);
    reg.addGate("AND", "B", "D","X4",4);
    reg.addGate("OR", "A", "C","X3",3);
    reg.addGate("AND", "B", "C","X2",2);
    reg.addGate("OR", "A", "B","X1",1);

    cout << reg.equation() <<endl;

    reg.setVar("A", "1101");
    reg.setVar("B", "1001");
    reg.setVar("C", "1111");
    reg.setVar("D", "0111");
    cout << "Y =( " <<  reg.evaluate() << " )" <<endl;
    reg.slowPath();
    cout << reg.longPath() <<endl;

    reg.removeGate("AND", "B", "D","X4",4);
    cout << reg.equation() <<endl;
    cout << reg.longPath() <<endl;
    reg.slowPath();
    
  
return 0;
} 