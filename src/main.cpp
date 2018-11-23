#include <iostream>
#include "dictionary.h"
#include <vector>
using namespace std);

//PART 2
int main(){

  //creating states dictionary
  Dictionary<string, string> statesUSA;

  //entering two-letter code as the key
  //and the full name as the value
  statesUSA.put("AL", "Alabama");
  statesUSA.put("AK", "Alaska");
  statesUSA.put("AZ", "Arizona");
  statesUSA.put("CA", "California");
  statesUSA.put("CO", "Colorado");
  statesUSA.put("CT", "Connecticut");
  statesUSA.put("DE", "Delaware");
  statesUSA.put("FL", "Florida");
  statesUSA.put("GA", "Georgia");
  statesUSA.put("HI", "Hawaii");
  statesUSA.put("ID", "Idaho");
  statesUSA.put("IL", "Illinois");
  statesUSA.put("IN", "Indiana");
  statesUSA.put("IA", "Iowa");
  statesUSA.put("KS", "Kansas");
  statesUSA.put("KY", "Kentucky");
  statesUSA.put("LA", "louisiana");
  statesUSA.put("ME", "Maine");
  statesUSA.put("MD", "Maryland");
  statesUSA.put("MA", "Massachusetts");
  statesUSA.put("MI", "Michigan");
  statesUSA.put("MN", "Minnesota");
  statesUSA.put("MS", "Mississippi");
  statesUSA.put("MO", "Missouri");
  statesUSA.put("MT", "Montana");
  statesUSA.put("NE", "Nebraska");
  statesUSA.put("NV", "Nevada");
  statesUSA.put("NH", "New Hampshire");
  statesUSA.put("NJ", "New Jersey");
  statesUSA.put("NM", "New Mexico");
  statesUSA.put("NY", "New York");
  statesUSA.put("NC", "North Carolina");
  statesUSA.put("ND", "North Dakota");
  statesUSA.put("OH", "Ohio");
  statesUSA.put("OK", "Oklahoma");
  statesUSA.put("OR", "Oregon");
  statesUSA.put("PA", "Pennsylvania");
  statesUSA.put("RI", "Rhode Island");
  statesUSA.put("SC", "South Carolina");
  statesUSA.put("SD", "South Dakota");
  statesUSA.put("TN", "Tennessee");
  statesUSA.put("TX", "Texas");
  statesUSA.put("UT", "Utah");
  statesUSA.put("VT", "Vermont");
  statesUSA.put("VA", "Virginia");
  statesUSA.put("WA", "Washington");
  statesUSA.put("WV", "West Virginia");
  statesUSA.put("WI", "Wisconsin");
  statesUSA.put("WY", "Wyoming");
  
  return 0;
}