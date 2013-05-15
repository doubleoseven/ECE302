#include<iostream>
#include <stdlib.h>
   using namespace std;

// Binary tree node abstract class
template <typename Elem> class Tree{
public:
     
    virtual ~Tree() {}
    virtual bool isEmpty() const= 0;
    virtual void destroyTree() = 0;
    virtual bool insert(string,string,string,string,int) = 0;
    virtual bool insert(BGate<Elem>&) = 0;
    
    virtual void preorder(BNode<Elem>*) = 0;
    virtual void preorder() = 0;
    
    virtual void postorder(BNode<Elem>*) = 0;
    virtual void postorder() = 0;
    
    virtual void inorder(BNode<Elem>*) = 0;
    virtual void inorder() = 0;
    
    virtual Elem evaluate() = 0;
    virtual void setVar(string, Elem) = 0;
    virtual string equation() = 0;
  
    //virtual  void deleteNode(const BGate<Elem>& deleteGate) = 0;
private:
    virtual void setVar(string var, Elem e, BNode<Elem>* root ) = 0;
    virtual void setVar2(string var, Elem e, BNode<Elem>* root ) = 0;
    virtual bool getValue() = 0;
    virtual void evaluate(BNode<Elem>*) = 0;
    virtual bool compute(string, Elem  , Elem  ) = 0;
    virtual void destroy(BNode<Elem>* p) = 0;
    virtual string equation(BNode<Elem>*) = 0;

    //virtual void deleteFromTree(BNode<Elem>* &p) = 0;

};

 
// Simple binary tree node implementation
template <typename Elem>
class BTree : public Tree<Elem> {
protected:
    BNode<Elem> *root;
public:
    BTree() {root = NULL;}
    
    void preorder(BNode<Elem>* root) {
        if (root == NULL) return; // Empty subtree, do nothing
       // visit(root);
        // Perform desired action
        cout << root->getGate().getType()<<endl;
        preorder(root->left());
        preorder(root->right());
    }//end preorder
    
    void preorder() {preorder(root);}
    
    void postorder(BNode<Elem>* root) {
        if (root == NULL) return; // Empty subtree, do nothing
        // visit(root);
        // Perform desired action
        postorder(root->left());
        postorder(root->right());
        cout << root->getGate().getOut() << root->getGate().getData3() <<endl;
        cout << root->getGate().getIn1() << root->getGate().getData1() <<endl;
        cout << root->getGate().getIn2() << root->getGate().getData2() <<endl;
    }//end postorder
    void postorder() {postorder(root);}
    
    void inorder(BNode<Elem>* root) {
        if (root == NULL) return; // Empty subtree, do nothing
        // visit(root);
        // Perform desired action
        inorder(root->left());
        cout << root->getGate().getType()<<endl;
        inorder(root->right());
    }//end inorder
    void inorder() {inorder(root);}

    bool isEmpty() const {return (root == NULL);}
    
    bool insert(BGate<Elem>& addGate)
    {
        BNode<Elem>* current;
        BNode<Elem>* newNode;
    
        newNode = new BNode<Elem>;
        
        newNode->getGate() = addGate;
        newNode->setLeft(NULL);
        newNode->setRight(NULL);
        
        if (root == NULL)    //base condition
        {
            root = newNode;
            return true;
        }//end if
        else
        {
            current = root;
             while(current != NULL)
            {
                if (current->getGate().getIn1() == addGate.getOut() )
                {
                    current->setLeft(newNode);
                    return true;
                }//end if
                else
                    current = current->left();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn1() == addGate.getOut() )
                {
                    current->setLeft(newNode);
                    return true;
                }//end if
                else
                    current = current->right();
            }//end while
            
            current = root;
             while(current != NULL)
            {
                 if (current->getGate().getIn2() == addGate.getOut() )
                {
                    current->setRight(newNode);
                    return true;
                }//end if
                else
                    current = current->right();
            }//end while
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn2() == addGate.getOut() )
                {
                    current->setRight(newNode);
                    return true;
                }//end if
                else
                    current = current->left();
            }//end while
        }//end else
    return false;
    }//end insert(BGate<Elem>&)
    
    bool insert(string logic,string input1,string input2,string output,int time)
    {
        BGate<Elem> inGate(logic,input1,input2,output,time);
        insert(inGate);
        return true;
    }//end  insert(string,string,string,string,int)
         
    void setVar(string var, Elem e)
    {
        setVar(var, e,root );
    }//end setVar
    
    bool evaluate()
    {
        evaluate(root);
        return getValue();
    }// end evaluate
    
    
    void destroy(BNode<Elem>* p)
    {
        if (p != NULL)
        {
            destroy(p->left());
            destroy(p->right());
            delete p;
            p = NULL;
        }//end if
    }//end destroy
    
    void destroyTree() {destroy(root);}

    ~BTree() {destroy(root);}
    string equation() {
        return equation(root);
    }
private:
    string equation(BNode<Elem>* root) {
        string eq = "";
        bool output;
        BGate<Elem> gate;
        if (root == NULL)   return "";; // Empty subtree, do nothing
        eq.append(equation(root->left()));
        eq.append(equation(root->right()));
        gate = root->getGate();
        output = compute(gate.getType(),gate.getData1(), gate.getData2());
        root->getGate().setData3(output);
        setVar(root->getGate().getOut(),output );
        eq.append("( ");
        eq.append(gate.getIn1());
        eq.append(" ");
        eq.append(gate.getType());
        eq.append(" ");
        eq.append(gate.getIn2());
        eq.append(" )");
        return eq;
    }

    void setVar2(string var, Elem e, BNode<Elem>* root ){
        
        if (root == NULL)    //base condition
        {
            return ;
        }//end else if
        else if (root->getGate().getIn1() == var  )
        {
            root->getGate().setData1(e);
            return ;
        }//end else if
        else if (root->getGate().getIn2() == var)
        {
            root->getGate().setData2(e);
            return ;
        }//end else if
        else
            return ;
        
    }//end setvar2
    
    void setVar(string var, Elem e, BNode<Elem>* root ) {
        if (root == NULL) return; // Empty subtree, do nothing
        setVar2(var,e,root);
        setVar(var, e,root->left());
        setVar(var, e,root->right());
    }//end setVar
    
    bool getValue()
    {
        return root->getGate().getData3();
    } // end getValueOf
    
    void evaluate(BNode<Elem>* root) {
        bool output;
        BGate<Elem> gate;
        if (root == NULL) return; // Empty subtree, do nothing
        evaluate(root->left());
        evaluate(root->right());
        gate = root->getGate();
        output = compute(gate.getType(),gate.getData1(), gate.getData2());
        root->getGate().setData3(output);
        setVar(root->getGate().getOut(),output );
    }//end evaluate
    
    bool compute(string op, bool firstOperand, bool secondOperand)
    {
        if (op == "AND" )
            return AND(firstOperand,secondOperand);
        else if (op == "OR")
            return OR(firstOperand,secondOperand);
        else if (op == "NAND")
            return NAND(firstOperand,secondOperand);
        else
            return NOR(firstOperand,secondOperand);
    } // end compute
    
 
}; // end ExpressionTree
