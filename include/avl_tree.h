#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

template <typename T>
struct Node {
  T info;
  int height;
  Node *llink;
  Node *rlink;
  Node(int h = 0): llink(nullptr), height(h), rlink(nullptr) {}
  Node(T info, int h = 0) : info(info), height(h), llink(nullptr), rlink(nullptr) {}
};

template <typename T>
class AVLTree {
public:
  AVLTree() : root(nullptr) {}
  AVLTree(const AVLTree<T> &bt) { copy(root, bt.root); }
  AVLTree<T> &operator=(AVLTree<T> &bt){
    if (this != &bt) {
      destroy(root);
      copy(root, bt.root);
    }

    return *this;
  }

  bool empty() const { return root == nullptr; }

  int height(const Node<T> *node) const { return node ? node->height : 0; }

  int size() const {
    return size(root);
  }
  int size(const Node<T>* node) const {
    return node ? 1 + size(node->llink) + size(node->rlink) : 0;
  }

  void inorderTraversal(void (*showFunc)(const Node<T>*, int)) const { inorderTraversal(showFunc, root, 0); }
  void inorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const{
    if(node){
      inorderTraversal(showFunc, node->llink, depth + 1);
      showFunc(node, depth);
      inorderTraversal(showFunc, node->rlink, depth + 1);
    }
  }

  void preorderTraversal(void (*showFunc)(const Node<T>*, int)) const { preorderTraversal(showFunc, root, 0); }
  void preorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if (node){
      showFunc(node, depth);
      preorderTraversal(showFunc, node->llink, depth + 1);
      preorderTraversal(showFunc, node->rlink, depth + 1);
    }
  }

  void postorderTraversal(void (*showFunc)(const Node<T>*, int)) const { postorderTraversal(showFunc, root, 0); }
  void postorderTraversal(void (*showFunc)(const Node<T>*, int), const Node<T> *node, int depth) const {
    if(node){
      postorderTraversal(showFunc, node->llink, depth + 1);
      postorderTraversal(showFunc, node->rlink, depth + 1);
      showFunc(node, depth);
    }
  }

  Node<T>* search(T e) const{
    auto current = root;
    while(current){
      if(current->info == e) return current;
      else if(e < current->info) current = current->llink;
      else current = current->rlink;
    }

    return nullptr;
  }  

  void insert(T e){ return insert(e, root); }
  void insert(T e, Node<T>* &node){
    if(node == nullptr){
      node = new Node<T>(e);
    }else if( e < node->info) {
      insert(e, node->llink);
    }else{
      insert(e, node->rlink);
    }

    balance(node);
  } 

  void single_left_rotate(Node<T>* &node2){
    Node<T> *node1 = node2->llink;
    node2->llink = node1->rlink;
    node1->rlink = node2;
    node2->height = std::max(height(node2->llink), height(node2->rlink)) + 1;
    node1->height = std::max(height(node1->llink), node2->height) + 1;
    node2 = node1;
  }

  void single_right_rotate(Node<T>* &node2){
    Node<T> *node1 = node2->rlink;
    node2->rlink = node1->llink;
    node1->llink = node2;
    node2->height = std::max(height(node2->rlink), height(node2->llink)) + 1;
    node1->height = std::max(height(node1->rlink), node2->height) + 1;
    node2 = node1;
  }

  void double_left_rotate(Node<T>* &node3){
    single_right_rotate(node3->llink);
    single_left_rotate( node3 );
  }

  void double_right_rotate(Node<T>* &node3){
    single_left_rotate(node3->rlink);
    single_right_rotate( node3 );
  }

  void balance( Node<T>* &node ) {
    if(node){
      if((height(node->llink) - height(node->rlink)) > 1){
        if( height(node->llink->llink) >= height(node->llink->rlink)){
          single_left_rotate(node);
       } else {
          double_left_rotate(node);
       }
      }else if((height(node->rlink) - height(node->llink)) > 1){
        if( height(node->rlink->rlink) >= height(node->rlink->llink)){
          single_right_rotate(node);
        } else {
          double_right_rotate(node);
        }
      }

      node->height = std::max(height(node->llink), height(node->rlink)) + 1;
    }
  }

  void remove(T e){ remove(root, e); }
  void remove(Node<T>* &node, T e){
    if(node){
      if(e < node->info){
        remove(node->llink, e);
      }else if(e > node->info){
        remove(node->rlink, e);
      }else if(node->llink && node->rlink) {// Two children
        node->info = maximum(node->llink)->info;
        remove(node->llink, node->info);
      }else{
        Node<T> *temp = node;
        node  = (node->llink ) ? node->llink : node->rlink;
        delete temp;
      }

      balance(node);
    }
  }

  ~AVLTree(){ destroy(root); }
  
protected:
  Node<T> *root;
  void destroy(Node<T>* &node) {
    if (node){
      destroy(node->llink);
      destroy(node->rlink);

      delete node;
      node = nullptr;
    }
  }
  void copy(Node<T> *&dest, const Node<T> *src) {
    if (src){
      dest = new Node<T>(src->info);
      copy(dest->llink, src->llink);
      copy(dest->rlink, src->rlink);
    } else {
      dest = nullptr;
    }
  }

  const Node<T>* maximum() const { return maximum(root); }
  const Node<T>* maximum(Node<T>* node) const {
    if(node){
      while(node->rlink){
        node = node->rlink;
      } 
    }
    return node;
  }
};

#endif