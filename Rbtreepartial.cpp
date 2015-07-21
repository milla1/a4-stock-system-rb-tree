// File:        rbtreepartial.cpp
// Author:      Geoffrey Tien
// Date:        2015-07-07
// Description: Contains implementation of some RedBlackTree functions.
//              This file does not require modification.

#ifdef _REDBLACKTREE_H_

// performs BST insertion and returns pointer to inserted node
// Note that this should only be called if item does not already exist in the tree
// Does not increase tree size.
template <class T>
Node<T>* RedBlackTree<T>::BSTInsert(T item)
{
  Node<T>* refnode; // will be pointer to parent of inserted node
  Node<T>* newnode; // will be pointer to inserted node
  // special case: empty tree
  if (size <= 0)
  {
    root = new Node<T>(item);
    newnode = root;
  }
  else // general case: non-empty tree
  {
    refnode = root;
    // find the insertion location
    while ((item < refnode->data && refnode->left != NULL) || (item > refnode->data && refnode->right != NULL))
    {
      if (item < refnode->data)
        refnode = refnode->left;
      else if (item > refnode->data)
        refnode = refnode->right;
    }
    // exited while loop, refnode points to the parent of the insertion location and has a null location to insert
    newnode = new Node<T>(item);
    newnode->p = refnode;
    if (item < refnode->data)
      refnode->left = newnode;
    else
      refnode->right = newnode;
  }

  return newnode;
}

// Returns existence of item in the tree.
// Return true if found, false otherwise.
template <class T>
bool RedBlackTree<T>::Search(T item) const
{
  Node<T>* node = root;

  while (node != NULL)
  {
    if (item == node->data)
      return true;
    else if (item < node->data)
      node = node->left;
    else
      node = node->right;
  }
  // if exit while loop, item is not found
  return false;
}

// Searches for item and returns a pointer to the node contents so the
//   value may be accessed or modified within the tree
// Use with caution! Do not modify the item's key value such that the
//   red-black /BST properties are violated.
template <class T>
T* RedBlackTree<T>::Retrieve(T item)
{
  T* value = NULL;

  // search for the item
  Node<T>* node = root;

  while (node != NULL)
  {
    if (item == node->data)
    {
      value = &(node->data);
      break; // item has been found, exit while loop
    }
    else if (item < node->data)
      node = node->left;
    else
      node = node->right;
  }
  // if exit while loop without breaking, item is not found
  return value;
