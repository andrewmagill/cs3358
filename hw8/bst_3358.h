
/*  BST_3358.h
  CS 3358 Spring 2015
  Assignment 8 - Tree Search

  Binary Search Tree header and implementation, with the exception of
  the BreadthFirstSearch method, written by Dr. Priebe

  BreadthFirstSearch method and Queue implementation written by
  Andrew Magill for assignment 8, CS 3358 251 Spring 2015

*/

#ifndef BST_3358_H
#define BST_3358_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include "queue_3358.h"

using namespace std;

template<class ItemType>
class BST_3358 {
 public:

    BST_3358();

    //Copy constructor
    BST_3358(const BST_3358 & src);

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
 	void insertItem(const ItemType &);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const ItemType& newItem);

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: prints the preOder (Node, Left, Right) traversal to standard output
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    void preOrderTraversal();

/****************************
inOrderTraversal

Function: prints the inOder (Left, Node, Right) traversal to standard output
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    void inOrderTraversal();

/****************************
postOrderTraversal

Function: prints the postOder (Left, Right, Node) traversal to standard output
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    void postOrderTraversal();

/****************************
breadthFirstSearch

Function: finds item by passing through the rows in the BST
Preconditions: BST has been initialized
Postcondidions: returns true if the item is found in the BST
*****************************/
   bool breadthFirstSearch( ItemType item );


  private:
    struct TreeNode {
       ItemType data;
       TreeNode *left;
       TreeNode *right;
    };

    TreeNode * root;


    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& node);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const ItemType& newItem);
    void getPredecessor(TreeNode* t, ItemType& data);
    void preOrderTraversal(TreeNode* t) const;
    void postOrderTraversal(TreeNode* t) const;
    void copyTree(TreeNode*& copy, const TreeNode* originalTree);

	//New for this assignment
    bool breadthFirstSearch( TreeNode* t, ItemType item );

};

/*******************************
/ Function implementations
********************************/

template<class ItemType>
BST_3358<ItemType>::BST_3358 ()
{
 root = NULL;
}

template<class ItemType>
BST_3358<ItemType>::BST_3358(const BST_3358 & src)
{

   copyTree(root, src.root);

}

template<class ItemType>
void BST_3358<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
   if (originalTree == NULL)
      copy = NULL;
   else
   {
      copy = new TreeNode;
      copy->data=originalTree->data;
      copyTree(copy->left, originalTree->left);
      copyTree(copy->right, originalTree->right);
   }
}

template<class ItemType>
void BST_3358 <ItemType>::deleteNode(TreeNode*& t)
{
   ItemType info;
   TreeNode * tempPtr;

   tempPtr = t;

   if (t->left == NULL)
   {
      t = t->right;
      delete tempPtr;
   }
   else if (t->right == NULL)
   {
      t = t->left;
      delete tempPtr;
   }
   else
   {
      getPredecessor(t->left, info);
      t->data = info;
      deleteItem(t->left, info);
   }

}



//find largest in left subtree
template<class ItemType>
void BST_3358 <ItemType>::getPredecessor(TreeNode* t, ItemType& data)
{
   while (t->right != NULL)
      t = t->right;

   data = t->data;

}


template<class ItemType>
void BST_3358 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
   if (t == NULL)
      return;
   else if (newItem < t->data)
      deleteItem(t->left, newItem);
   else if (newItem > t->data)
      deleteItem(t->right, newItem);
   else
      deleteNode(t);

}


template<class ItemType>
void BST_3358 <ItemType>::deleteItem(const ItemType& newItem)
{
   deleteItem(root, newItem);

}

template<class ItemType>
void BST_3358 <ItemType>::makeEmpty(TreeNode*& t)
{
   if (t != NULL)
   {
      makeEmpty (t->left);
      makeEmpty (t->right);
      delete t;
   }
}

template<class ItemType>
void BST_3358 <ItemType>::makeEmpty()
{
   makeEmpty(root);
   root = NULL;
}

template<class ItemType>
bool BST_3358 <ItemType>::isEmpty() const
{
   return (root == NULL);

}

template<class ItemType>
bool BST_3358 <ItemType>::isFull() const
{
   try
   {
      TreeNode *temp = new TreeNode;
      delete temp;
      return false;
   }
   catch (std::bad_alloc)
   {
      return true;
   }

}


template<class ItemType>
void BST_3358 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
   if (t == NULL)
   {
      TreeNode *p = new TreeNode;
      p->data = newItem;
      p->left = NULL;
      p->right = NULL;
cout << "inserting node" << newItem << endl;
      t = p;
   }
   else if (t->data > newItem)
      insertItem(t->left, newItem);
   else
      insertItem(t->right, newItem);
}

template<class ItemType>
void BST_3358 <ItemType>::insertItem(const ItemType& newItem)
{
   insertItem(root, newItem);
}



template<class ItemType>
int BST_3358 <ItemType>::countNodes(TreeNode* t) const
{

   if (t == NULL)
      return 0;
   else
      return countNodes(t->left) + countNodes(t->right) +1;
}


template<class ItemType>
int BST_3358 <ItemType>::countNodes()
{
   return countNodes(root);
}

template<class ItemType>
void BST_3358 <ItemType>::preOrderTraversal(TreeNode* t) const
{
   if  (t != NULL)
   {
      cout << t->data << endl;
      preOrderTraversal(t->left);
      preOrderTraversal(t->right);
   }
}


template<class ItemType>
void BST_3358 <ItemType>::preOrderTraversal()
{

   preOrderTraversal(root);
}

template<class ItemType>
void BST_3358 <ItemType>::inOrderTraversal(TreeNode* t) const
{
   if (t != NULL)
   {
      inOrderTraversal(t->left);
      cout << t->data << endl;
      inOrderTraversal(t->right);
   }

}

template<class ItemType>
void BST_3358 <ItemType>::inOrderTraversal()
{
   inOrderTraversal(root);
}

template<class ItemType>
void BST_3358 <ItemType>::postOrderTraversal(TreeNode* t) const
{
   if (t !=NULL)
   {
      postOrderTraversal(t->left);
      postOrderTraversal(t->right);
      cout << t->data << endl;
   }
}

template<class ItemType>
void BST_3358 <ItemType>::postOrderTraversal()
{
   postOrderTraversal(root);
}

#endif
