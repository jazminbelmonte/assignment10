#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <vector>
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
  int count = 0;

public:

  bool empty(){
    return AVLTree<Pair<K,V>>::empty();
  }

  int size(){
    return AVLTree<Pair<K,V>>::size();
  }

  V* get(K key){ ;
    return search(key)->info.value;
  }

  void put(K key, V value){
    auto newPair = new Pair<K,V>(key, value);
    if (search(key) == nullptr) {
      insert(newPair);
    }
  }

  void remove(K key){
    if (search(key) == nullptr){
      return;
    }
    V value = *search(key);
    auto temporary = new Pair<K,V>(key, value);
    AVLTree<Pair<K,V>>::remove(temporary);
  }

  void clear(){
    AVLTree<Pair<K,V>>::destroy();
  }

  std::vector<K> keys(){

    std::vector<K> keyVector;
  }

  std::vector<V> values(){
    Pair<K, V> root = AVLTree<Pair<K, V>>::root;
    std::vector<V> valuesVector;

  }

};

#endif

//dictionary is an avl tree of pairs
//create a pair <k,v> data struct

//info is now a pair
//inside AVL tree we have T e, search is e == another info
//implement operator ==
//implement operator !=
//implement operator <
//implement operator >
//implement operator >=
//implement operator <=
//only compare pair.key to pair2.key
//two pairs are the same if their keys are the same
