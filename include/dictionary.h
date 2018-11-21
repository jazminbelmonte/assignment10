#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
#include <vector>
#include "avl_tree.h"

// PART 1

template <typename K, typename V>
struct Pair {
  K key;
  V value;
};

template <typename K, typename V>
class Dictionary: private AVLTree {
private:

public:
  //returns true if the dictionary is empty
  bool empty const()​​{

  }

  //returns the number of pairs in the dictionary
  int size()​​ const {

  }

  //returns a pointer to the value associated with key or null otherwise
  V* get(K key)​​ const{

  }

  //inserts the pair of key and value into the dictionary if it does not
  //exist or change the value of the pair with key to value
  void put(K key, V value)​​{

  }

  //removes the pair with key from the dictionary
  void remove(K key)​​{

  }

  //remove all the pairs from the dictionary
  void clear()​​{

  }

  //returns a vector of all the keys in the dictionary in no particular order
  std::vector<K> keys()​​{

  }

  //returns a vector of all the values in the dictionary in no particular order.
  std::vector<V> values()​​{

  }
};

#endif