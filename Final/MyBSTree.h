//////////////////////////////////////////////////////////
// Shane Burkhart
// CS153 Section A
// Final Project
// File: MyBSTree.h
// //////////////////////////////////////////////////////

#ifndef MY_BSTREE_H
#define MY_BSTREE_H

#include <iostream>
#include "abstractbstree.h"
using namespace std;

template <typename T>
struct TreeNode
{
  T m_data;
  TreeNode<T>* m_left;
  TreeNode<T>* m_right;
};

template <typename T>
class MyBSTree: public AbstractBSTree<T>
{
private:
  TreeNode<T>* m_root;
  int m_size;

  int recursive_height(TreeNode<T>* node) const;
  void recursive_insert(TreeNode<T>** node, const T& x);
  void pretty_print(TreeNode<T>* node, int pad) const;
  void recursive_post_order_print(TreeNode<T>* node) const;

public:
  MyBSTree():m_root(NULL),m_size(0){};

  int size() const;
  bool isEmpty() const;
  int height() const;
  const T& findMax() const;
  const T& findMin() const;
  int contains(const T& x) const;
  void clear();
  void insert(const T& x);
  void remove(const T& x);
  void printPreOrder() const;
  void printPostOrder() const;
  void print() const;
};

#include "MyBSTree.hpp"

#endif
