#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "dictionary.h"

// PART 3

TEST_CASE("Dictionary test with int key and string value") {
  Dictionary<int, std::string> BestPicture;
  //make sure we have a clean tree
  CHECK(BestPicture.empty() == 1);

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

  //check if all inputs worked
  CHECK(BestPicture.empty() == 0);
  CHECK(BestPicture.size() == 10);

  //get winners
  CHECK(BestPicture.get(2012) == "The Artist");
  CHECK_THROWS(BestPicture.get(2004));

  //duplicate
  BestPicture.put(2017, "La La Land");
  CHECK(BestPicture.size() == 10);

  //vector
  std::vector keysVector = BestPicture.keys();
  CHECK(keysVector.size() == 10);
  std::vector valuesVector = BestPicture.values();
  CHECK(valuesVector.size() == 10);

  //remove
  BestPicture.remove(2013);
  CHECK(BestPicture.size() == 9);
  BestPicture.remove(1992);
  CHECK(BestPicture.size() == 9);

  //clear
  BestPicture.clear();
  CHECK(BestPicture.empty() == 1);
}


TEST_CASE("Dictionary test with string key and double value") {
  Dictionary<std::string, double> blackFridayShopping;
  //make sure we have a clean tree
  CHECK(blackFridayShopping.empty() == 1);

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

  //check if all inputs worked
  CHECK(blackFridayShopping.empty() == 0);
  CHECK(blackFridayShopping.size() == 10);

  //get prices
  CHECK(blackFridayShopping.get("Xbox") == 429.99);
  CHECK_THROWS(blackFridayShopping.get("Sony TV"));

  //duplicate
  blackFridayShopping.put("Amazon Echo", 99999.99);
  CHECK(blackFridayShopping.size() == 10);

  //vector
  std::vector keysVector = blackFridayShopping.keys();
  CHECK(keysVector.size() == 10);
  std::vector valuesVector = blackFridayShopping.values();
  CHECK(valuesVector.size() == 10);

  //remove
  blackFridayShopping.remove("iPad Pro");
  CHECK(blackFridayShopping.size() == 9);
  blackFridayShopping.remove("Apple Watch");
  CHECK(blackFridayShopping.size() == 9);

  //clear
  blackFridayShopping.clear();
  CHECK(blackFridayShopping.empty() == 1);
}
