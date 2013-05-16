//*************************************************************
// Author: Haneen Mohammed& Amal Mukhtar
//
// class BNode
// This class is the user interface
//*************************************************************

#include "BGate.h"

// Binary tree node abstract class
template <typename Elem> class BinNode {
public:
    virtual ~BinNode() {} 
    virtual BinNode* left() const = 0;
    virtual void setLeft(BinNode*) = 0;
    virtual BinNode* right() const = 0;
    virtual void setRight(BinNode*) = 0;
    virtual bool isLeaf() = 0;
    virtual BGate<Elem>& getGate() = 0;
};


// Simple binary tree node implementation
template <typename Elem>
class BNode : public BinNode<Elem> {
private:
    BGate<Elem> G;
    BNode* lc;  // Pointer to left child
    BNode* rc;  // Pointer to right child
public:
    // Two constructors -- with and without initial values
    BNode()
    {
        lc = rc = NULL;
    }
    BNode(BGate<Elem> e, BNode* l =NULL, BNode* r =NULL)
    {
        G = e; lc = l; rc = r;
    }
    ~BNode()
    {
    }             // Destructor
    // Functions to set and return the gate  
    inline BNode* left() const
    {
        return lc;
    }
    void setLeft(BinNode<Elem>* b)
    {
        lc = (BNode*)b;
    }
    inline BNode* right() const
    {
        return rc;
    }
    void setRight(BinNode<Elem>* b)
    {
        rc = (BNode*)b;
    }
    // Return true if it is a leaf, false otherwise
    bool isLeaf()
    {
        return (lc == NULL) && (rc == NULL);
    }
    
    /** Task: Retrieves Gate contained in the node.
     * @return object Gate */
    BGate<Elem>& getGate()
    {
        return G;
    }
  };