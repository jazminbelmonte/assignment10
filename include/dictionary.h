#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <vector>
#include "avl_tree.h"

// PART 1

template <typename K, typename V>
struct Pair {
  K key;
  V value;
  Pair<K,V>*;
};

template <typename K, typename V>
class Dictionary: private AVLTree {

public:
  //returns true if the dictionary is empty
  bool empty const()​​{
    AVLTree::empty();
  }

  //returns the number of pairs in the dictionary
  int size()​​ const {
    AVLTree::size();
  }

  //returns a pointer to the value associated with key or null otherwise
  V* get(K key)​​ const{
    AVLTree::search(K key);
  }

  //inserts the pair of key and value into the dictionary if it does not exist
  //or change the value of the pair with key to value???
  void put(K key, V value)​​{
    if (AVLTree::search(K key) == nullptr) {
      insert(Pair<key, value>);
    }
  }

  //removes the pair with key from the dictionary
  void remove(K key)​​{
    AVLTree::remove(K key);
  }

  //remove all the pairs from the dictionary
  void clear()​​{
    AVLTree::~AVLTree();
  }

  //returns a vector of all the keys in the dictionary in no particular order
  std::vector<K> keys()​​{
    //creating vector of keys
    std::vector<K> keyVector(size());
  }

  //returns a vector of all the values in the dictionary in no particular order.
  std::vector<V> values()​​{
    //creating vector of values
    std::vector<V> valuesVector(size());
  }
};

#endif