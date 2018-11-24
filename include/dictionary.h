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

  void makeVector(Node<Pair<K,V>>* node){
    if (node){
      keyValueVector.push_back(node->info);
      makeVector(node->llink);
      makeVector(node->rlink);
    }
  }

public:
  bool empty(){
    return AVLTree<Pair<K,V>>::empty();
  }

  int size(){
    return AVLTree<Pair<K,V>>::size();
  }

  V get(K key){
    if (this->search(Pair<K,V>{key}) == nullptr){
      throw std::runtime_error("That key does not exist");
    }
    return this->search(Pair<K,V>{key})->info.value;
  }

  void put(K key, V value){
    if (this->search(Pair<K,V>{key})){
      return;
    }
    this->insert(Pair<K,V>{key,value},this->root);
  }

  void remove(K key){
    if (this->search(Pair<K,V>{key}) == nullptr){
      return;
    }
    V value = this->search(Pair<K,V>{key})->info.value;
    auto temporary = Pair<K,V>{key,value};
    AVLTree<Pair<K,V>>::remove(temporary);
  }

  void clear(){
    this->destroy(this->root);
  }

  std::vector<K> keys(){
    keyValueVector.clear();
    std::vector<K> keyVector;

    makeVector(this->root);

    for(Pair<K,V> info: keyValueVector){
      keyVector.push_back(info.key);
    }

    return keyVector;
  }

  std::vector<V> values(){
    keyValueVector.clear();
    auto root = this->root;
    std::vector<V> valuesVector;

    makeVector(this->root);

    for(Pair<K,V> info: keyValueVector){
      valuesVector.push_back(info.value);
    }

    return valuesVector;
  }

};

#endif
