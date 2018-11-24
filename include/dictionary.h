#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <vector>
#include <stdexcept>
#include "avl_tree.h"

// PART 1

template <typename K, typename V>
struct Pair {
  K key;
  V value;

  //overloading key comparison operators
  bool operator == (Pair& p) const{ return key == p.key; }
  bool operator != (Pair& p) const{ return key != p.key; }
  bool operator < (Pair& p) const{ return key < p.key; }
  bool operator > (Pair& p) const{ return key > p.key; }
  bool operator <= (Pair& p) const{ return key <= p.key; }
  bool operator >= (Pair& p) const{ return key >= p.key; }
};

template <typename K, typename V>
class Dictionary: private AVLTree<Pair<K,V>> {
protected:
  std::vector<Pair<K,V>> keyValueVector;

  //function used to make vectors later
  void makeVector(Node<Pair<K,V>>* node){
    if (node){
      keyValueVector.push_back(node->info);
      makeVector(node->llink);
      makeVector(node->rlink);
    }
  }

public:
  //since dictionary inherits all of AVL tree's functions
  //we can just use the empty() function from the AVL tree
  bool empty(){
    return AVLTree<Pair<K,V>>::empty();
  }

  //here we can also use the size() function from the AVL tree
  int size(){
    return AVLTree<Pair<K,V>>::size();
  }


  V get(K key){
    //check if the key exists, if not throw error
    if (this->search(Pair<K,V>{key}) == nullptr){
      throw std::runtime_error("That key does not exist");
    }
    return this->search(Pair<K,V>{key})->info.value;
  }

  void put(K key, V value){
    //check if the key already exists
    //if not you cannot insert a repeat
    if (this->search(Pair<K,V>{key})){
      return;
    }
    this->insert(Pair<K,V>{key,value},this->root);
  }

  void remove(K key){
    //check if key exists, if not there is nothing to remove
    if (this->search(Pair<K,V>{key}) == nullptr){
      return;
    }
    //get the value for the given key
    V value = this->search(Pair<K,V>{key})->info.value;
    //remove it as a whole pair
    AVLTree<Pair<K,V>>::remove(Pair<K,V>{key,value});
  }

  //use the destroy function from the AVL tree
  void clear(){
    AVLTree<Pair<K,V>>::destroy(this->root);
  }


  std::vector<K> keys(){
    keyValueVector.clear();

    std::vector<K> keyVector;

    //make a key and values vector
    makeVector(this->root);

    //from this key and values vector only take
    //the keys and push them onto the new keyVector
    for(Pair<K,V> info: keyValueVector){
      keyVector.push_back(info.key);
    }

    return keyVector;
  }

  std::vector<V> values(){
    keyValueVector.clear();

    std::vector<V> valuesVector;

    //make a key and values vector
    makeVector(this->root);

    //from this key and values vector only take
    //the keys and push them onto the new keyVector
    for(Pair<K,V> info: keyValueVector){
      valuesVector.push_back(info.value);
    }

    return valuesVector;
  }

};

#endif
