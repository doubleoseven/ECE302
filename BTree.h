#include<iostream>
#include <stdlib.h>
   using namespace std;

// Binary tree node abstract class
template <typename Elem>
class Tree{
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
  

    //virtual  void deleteNode(const BGate<Elem>& deleteGate) = 0;
private:
    virtual void setVar(string var, Elem e, BNode<Elem>* root ) = 0;
    virtual void setVar2(string var, Elem e, BNode<Elem>* root ) = 0;
    virtual bool getValue() = 0;
    virtual void evaluate(BNode<Elem>*) = 0;
    virtual bool compute(string, Elem  , Elem  ) = 0;
    virtual void destroy(BNode<Elem>* p) = 0;
    //virtual void deleteFromTree(BNode<Elem>* &p) = 0;

};

 
// Simple binary tree node implementation
template <typename Elem>
class BTree : public Tree<Elem> {
protected:
    BNode<Elem> *root;
public:
    void preorder(BNode<Elem>* root) {
        if (root == NULL) return; // Empty subtree, do nothing
       // visit(root);
        // Perform desired action
        cout << root->getGate().getType()<<endl;
        preorder(root->left());
        preorder(root->right());
    }
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


    }
    void postorder() {postorder(root);}
    
    void inorder(BNode<Elem>* root) {
        if (root == NULL) return; // Empty subtree, do nothing
        // visit(root);
        // Perform desired action
        inorder(root->left());
        cout << root->getGate().getType()<<endl;
        inorder(root->right());
    }
    void inorder() {inorder(root);}

    bool isEmpty() const {return (root == NULL);}
    
    BTree() {root = NULL;}
    
    void destroy(BNode<Elem>* p)
    {
        if (p != NULL)
        {
            destroy(p->left());
            destroy(p->right());
            delete p;
            p = NULL;
        }
    }
    
    void destroyTree() {destroy(root);}
    
    ~BTree() {destroy(root);}
    
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
        }
        else
        {
            current = root;
             while(current != NULL)
            {
                if (current->getGate().getIn1() == addGate.getOut() )
                {
                    current->setLeft(newNode);
                    return true;
                }
                else
                    current = current->left();
            }
            
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn1() == addGate.getOut() )
                {
                    current->setLeft(newNode);
                    return true;
                }
                else
                    current = current->right();
            }
            
            current = root;
             while(current != NULL)
            {
                 if (current->getGate().getIn2() == addGate.getOut() )
                {
                    current->setRight(newNode);
                    return true;
                }
                else
                    current = current->right();
            }
            current = root;
            while(current != NULL)
            {
                if (current->getGate().getIn2() == addGate.getOut() )
                {
                    current->setRight(newNode);
                    return true;
                }
                else
                    current = current->left();
            }
        }
    return false;
    }
    
    bool insert(string logic,string input1,string input2,string output,int time)
    {
        BGate<Elem> inGate(logic,input1,input2,output,time);
        insert(inGate);
        return true;
    }
         
    
    void setVar(string var, Elem e) {setVar(var, e,root );}
    
    bool evaluate()
    {
        evaluate(root);
        return getValue();
    }   // end evaluate
    /*void preorder(BNode<Elem>* root) {
        if (root == NULL) return; // Empty subtree, do nothing
       
        cout <<  root->getGate().getOut()<<evaluate()<<endl;
        // Perform desired action
        cout << root->getGate().getType()<<endl;
        preorder(root->left());
        preorder(root->right());
    } */
private:
    void setVar2(string var, Elem e, BNode<Elem>* root ){
        
        if (root == NULL)    //base condition
        {
            return ;
        }
        else if (root->getGate().getIn1() == var  )
        {
            root->getGate().setData1(e);
            return ;
        }
        else if (root->getGate().getIn2() == var)
        {
            root->getGate().setData2(e);
            return ;
        }
        else
            return ;
        
    }
    
    void setVar(string var, Elem e, BNode<Elem>* root ) {
        if (root == NULL) return; // Empty subtree, do nothing
        // visit(root);
        // Perform desired action
        setVar2(var,e,root);
        setVar(var, e,root->left());
        setVar(var, e,root->right());
        
    }
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
        
    }
 ///
    
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
