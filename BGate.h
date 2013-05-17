/**
 ECE302 final project
 BGate.h
 @author Haneen Mohammed& Amal Mukhtar
 @brief
 */

#include <iostream>
using namespace std;
 
template <typename Elem>
class BGate
{
private:
    string type;    //Type
    string in1;     //input1
    string in2;     //input2
    string output;  //output
    double time;    //time
    Elem x;     //input1(var) = data1 (value)
    Elem y;     //input2(var) = data2 (value)
    Elem z;     //output(var) = data3 (value)
public:
    BGate(string e,string input1,string input2,string o,double t)
    {type =  e; in1 = input1; in2 = input2; output = o;time = t;}
    BGate(){}
    string getType() const { return type; }
    void setType(const string& e) {type = e;}
    string getIn1() const { return in1; }
    void setIn1(const string& e) {in1 = e;}
    string getIn2() const{ return in2; }
    void setIn2(const string& e) { in2 = e; }
    string getOut() const { return output; }
    void setOut(const string& e) { output = e; }
    double getTime() const { return time; }
    void setTime(const double& e) { time = e; }
    Elem getDataX()const { return x; }
    void setDataX(const Elem& b) { x = b; }
    Elem getDataY()const { return y; }
    void setDataY(const Elem& b){ y = b; }
    Elem getDataZ() const{ return z; }
    void setDataZ(const Elem& b){ z = b; }
};
