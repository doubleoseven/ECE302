#include <iostream>
using namespace std;
//Node ADT
template <typename Elem>
class Gate{
public:
	virtual  string getType() = 0;              // Return the node’s Type
    virtual void setType(string) = 0;    // Set the node’s Type
    
    virtual  string getIn1() = 0;               // Return the node’s input1
    virtual void setIn1(string) = 0;            // Set the node’s input1
    
    virtual  string getIn2() = 0;               // Return the node’s input1
    virtual void setIn2(string) = 0;            // Set the node’s input1

    virtual  bool getData1() = 0;               // Return the node’s data1
    virtual  void setData1(bool) = 0;           // Set the node’s data1
    
    virtual  bool getData2() = 0;               // Return the node’s data2
    virtual void setData2(bool) = 0;            // Set the node’s data2

    virtual  string getOut() = 0;                // Return the node’s Output
    virtual void setOut(string) = 0;       // Set the node’s Output
    
    virtual  bool getData3() = 0;               // Return the node’s data2
    virtual void setData3(bool) = 0;            // Set the node’s data2

    virtual  int getTime() = 0;                // Return the node’s Time
    virtual void setTime(const int&) = 0;       // Set the node’s Time
};

template <typename Elem>
class BGate: public Gate<Elem>{
private:
    string type;            //Type
    string in1;             //in1
    string in2;             //in2
    string output;            //out
    int time;               //time
    bool data1;
    bool data2;
    bool data3;

public:
    // Two constructors -- with and without initial values
    BGate(string e,string input1,string input2,string o,int t)
    {
        type =  e;
        in1 = input1;
        in2 = input2;
        output = o;
        time = t;
    }
    BGate(){};
    // Functions to set and return the value and key
    string getType() { return type; }
    void setType(string e) {type = e;}
    
    string getIn1() { return in1; }
    void setIn1(string e) {in1 = e;}
    
    string getIn2() { return in2; }
    void setIn2(string e) {in2 = e;}
    
    void setOut(string e) {output = e;}
    string getOut() { return output; }
    
    void setTime(const int& e) {time = e;}
    int getTime() { return time; }
    
    bool getData1(){
        return data1;
    }
    void setData1(bool b) {
        data1 = b;
    }
    
    bool getData2(){
        return data2;
    }
    void setData2(bool b){
        data2 = b;
    }
    
    bool getData3(){
        return data3;
    }
    void setData3(bool b){
        data3 = b;
    }
};
