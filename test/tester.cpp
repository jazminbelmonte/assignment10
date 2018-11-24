#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dictionary.h"

// PART 3

TEST_CASE("Dictionary test with int key and string value") {
  Dictionary<int, std::string> BestPicture;

  //make sure we have a clean tree
  CHECK(BestPicture.empty() == 1);

  //put some keys and values in the dictionary
  BestPicture.put(2018, "The Shape of Water");
  BestPicture.put(2017, "Moonlight");
  BestPicture.put(2016, "Spotlight");
  BestPicture.put(2015, "Birdman");
  BestPicture.put(2014, "12 Years a Slave");
  BestPicture.put(2013, "Argo");
  BestPicture.put(2012, "The Artist");
  BestPicture.put(2011, "The Kings Speech");
  BestPicture.put(2010, "The Hurt Locker");
  BestPicture.put(2009, "Slumdog Millionaire");

  //check if all inputs worked and the tree is no longer empty
  CHECK(BestPicture.empty() == 0);
  CHECK(BestPicture.size() == 10);

  //get winner
  CHECK(BestPicture.get(2012) == "The Artist");
  //get winner for a non-existent key
  CHECK_THROWS(BestPicture.get(2004));

  //try to input a duplicate key
  BestPicture.put(2017, "La La Land");
  CHECK(BestPicture.size() == 10);

  //test vectors
  std::vector keysVector = BestPicture.keys();
  std::vector valuesVector = BestPicture.values();
  //make sure all the values are in the vectors by checking sizes of both
  CHECK(keysVector.size() == 10);
  CHECK(valuesVector.size() == 10);

  //test remove
  BestPicture.remove(2013);
  CHECK(BestPicture.size() == 9);
  //test removing a non-existent key
  BestPicture.remove(1992);
  CHECK(BestPicture.size() == 9);

  //test clear
  BestPicture.clear();
  CHECK(BestPicture.empty() == 1);
}


TEST_CASE("Dictionary test with string key and double value") {
  Dictionary<std::string, double> blackFridayShopping;

  //make sure we have a clean tree
  CHECK(blackFridayShopping.empty() == 1);

  //put some keys and values in the dictionary
  blackFridayShopping.put("iPad Pro", 249);
  blackFridayShopping.put("Nintendo Switch", 299.99);
  blackFridayShopping.put("AirPods", 160);
  blackFridayShopping.put("Nest Cam", 130);
  blackFridayShopping.put("Drone", 649);
  blackFridayShopping.put("Xbox", 429.99);
  blackFridayShopping.put("Video Games", 19.99);
  blackFridayShopping.put("BluRay", 14.99);
  blackFridayShopping.put("Beats Wireless", 180);
  blackFridayShopping.put("Amazon Echo", 24);

  //check if all inputs worked and the tree is no longer empty
  CHECK(blackFridayShopping.empty() == 0);
  CHECK(blackFridayShopping.size() == 10);

  //get price
  CHECK(blackFridayShopping.get("Xbox") == 429.99);
  //get price for non-existent key
  CHECK_THROWS(blackFridayShopping.get("Sony TV"));

  //try to input a duplicate key
  blackFridayShopping.put("Amazon Echo", 99999.99);
  CHECK(blackFridayShopping.size() == 10);

  //test vectors
  std::vector keysVector = blackFridayShopping.keys();
  std::vector valuesVector = blackFridayShopping.values();
  //make sure all the values are in the vectors by checking sizes of both
  CHECK(keysVector.size() == 10);
  CHECK(valuesVector.size() == 10);

  //test remove
  blackFridayShopping.remove("iPad Pro");
  CHECK(blackFridayShopping.size() == 9);
  //test removing a non-existent key
  blackFridayShopping.remove("Apple Watch");
  CHECK(blackFridayShopping.size() == 9);

  //test clear
  blackFridayShopping.clear();
  CHECK(blackFridayShopping.empty() == 1);
}
