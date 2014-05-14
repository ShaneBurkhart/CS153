//////////////////////////////////////////////////////////
// Shane Burkhart
// CS153 Section A
// Final Project
// File: MyBSTree.cpp
// //////////////////////////////////////////////////////


template <typename T>
int MyBSTree<T>::size() const
{
  return m_size;
}

template <typename T>
bool MyBSTree<T>::isEmpty() const
{
  return m_size == 0;
}

template <typename T>
int MyBSTree<T>::height() const
{
  return recursive_height(m_root);
}

template <typename T>
int MyBSTree<T>::recursive_height(TreeNode<T>* node) const
{
  int lh = 0; int rh = 0;
  if(node == NULL) return 0;
  if(node->m_left != NULL) lh = recursive_height(node->m_left);
  if(node->m_right != NULL) rh = recursive_height(node->m_right);
  return lh > rh ? lh + 1 : rh + 1;
}

template <typename T>
const T& MyBSTree<T>::findMax() const
{
 return NULL;
}

template <typename T>
const T& MyBSTree<T>::findMin() const
{
  return NULL;
}

template <typename T>
int MyBSTree<T>::contains(const T& x) const
{
  return 0;
}

template <typename T>
void MyBSTree<T>::clear()
{

}

template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  recursive_insert(&m_root, x);
}

template <typename T>
void MyBSTree<T>::recursive_insert(TreeNode<T>** node, const T& x)
{
  if(*node == NULL)
  {
    *node = new TreeNode<T>;
    (*node)->m_left = NULL;
    (*node)->m_right = NULL;
    (*node)->m_data = x;
    m_size ++;
  }
  if(x < (*node)->m_data)
    recursive_insert(&(*node)->m_left, x);
  else if(x > (*node)->m_data)
    recursive_insert(&(*node)->m_right, x);
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{

}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{

}

template <typename T>
void MyBSTree<T>::printPostOrder() const
{
  recursive_post_order_print(m_root);
}

template <typename T>
void MyBSTree<T>::recursive_post_order_print(TreeNode<T>* node) const
{
  if(node == NULL) return;
  recursive_post_order_print(node->m_left);
  recursive_post_order_print(node->m_right);
  cout << node->m_data << endl;
}

template <typename T>
void MyBSTree<T>::print() const
{
  pretty_print(m_root, 0);
}

template <typename T>
void MyBSTree<T>::pretty_print(TreeNode<T>* node, int pad) const
{
  string s(pad, ' ');
  if (node == NULL)
    cout << endl;
  else
  {
    pretty_print(node->m_right, pad+4);
    cout << s << node->m_data << endl;
    pretty_print(node->m_left, pad+4);
  }
}

