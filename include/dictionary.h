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
};

#endif