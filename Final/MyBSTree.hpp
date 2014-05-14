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
  if(m_root == NULL) throw string("PANIC : Tree is Empty!!"); // Throw error
  TreeNode<T>* t = m_root;
  while(t->m_right != NULL)
    t = t->m_right;
 return t->m_data;
}

template <typename T>
const T& MyBSTree<T>::findMin() const
{
  if(m_root == NULL) throw string("PANIC : Tree is Empty!!"); // Throw error
  TreeNode<T>* t = m_root;
  while(t->m_left != NULL)
    t = t->m_left;
  return t->m_data;
}

template <typename T>
int MyBSTree<T>::contains(const T& x) const
{
  int level = 0;
  TreeNode<T>* t = m_root;
  while(t != NULL)
  {
    if(t->m_data == x) return level;
    if(x < t->m_data)
      t = t->m_left;
    else if(x > t->m_data)
      t = t->m_right;
    level ++;
  }
  return -level;
}

template <typename T>
void MyBSTree<T>::clear()
{
  recursive_clear(&m_root);
  m_size = 0;
}

template <typename T>
void MyBSTree<T>::recursive_clear(TreeNode<T>** node)
{
  if(*node == NULL) return;
  recursive_clear(&(*node)->m_left);
  recursive_clear(&(*node)->m_right);
  delete *node;
  *node = NULL;
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
  recursive_remove(m_root, x);
}

template <typename T>
void MyBSTree<T>::recursive_remove(TreeNode<T>*& node, const T& x)
{
  if(node == NULL) return;
  if(x > node->m_data)
  {
    recursive_remove(node->m_right, x);
    return;
  }
  else if(x < node->m_data)
  {
    recursive_remove(node->m_left, x);
    return;
  }
  // Found the node
  if(node->m_right && node->m_left) // Both child nodes
  {
    TreeNode<T>* t = node->m_left;
    while(t->m_right != NULL){ t = t->m_right; }
    node->m_data = t->m_data;
    recursive_remove(node->m_left , t->m_data);
    return;
  }

  if(node->m_left == NULL && node->m_right == NULL) // No children
  {
    delete node;
    node = NULL; // Set parent pointer to NULL
    return;
  }

  // One child
  TreeNode<T>** t = &(node->m_left);
  if(*t == NULL)
    t = &(node->m_right);
  node->m_data = (*t)->m_data;
  delete *t;
  *t = NULL;
}

template <typename T>
TreeNode<T>* MyBSTree<T>::clone(const TreeNode<T>* node)
{
  if(node == NULL)
    return NULL;
  else{
    TreeNode<T>* t = new TreeNode<T>;
    t->m_data = node->m_data;
    t->m_left = clone(node->m_left);
    t->m_right = clone(node->m_right);
    return t;
  }
}

template <typename T>
void MyBSTree<T>::printPreOrder() const
{
  recursive_pre_order_print(m_root);
}

template <typename T>
void MyBSTree<T>::recursive_pre_order_print(TreeNode<T>* node) const
{
  if(node == NULL) return;
  cout << node->m_data << endl;
  recursive_post_order_print(node->m_left);
  recursive_post_order_print(node->m_right);
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

