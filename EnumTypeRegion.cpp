#include "EnumTypeRegion.h"


//Engineering, Party, Liberal_Arts, Ivy_League, States

string toStrSchoolType(SchoolType type){
  switch(type){
    case SchoolType::Engineering:
      return "Engineering";
    case SchoolType::Ivy_League:
      return "Ivy League";
    case SchoolType::Liberal_Arts:
      return "Liberal Arts";
    case SchoolType::Party:
      return "Party";
    default:
      return "State";
  }
}

//California, Western, Midwestern, Southern, Northeastern

string toStrSchoolRegion(Region region){
  switch(region){
    case Region::California:
      return "California";
    case Region::Western:
      return "Western";
    case Region::Midwestern:
      return "Midwestern";
    case Region::Southern:
      return "Southern";
    default:
      return "Northeastern";
  }
}

SchoolType toEnumSchoolType(string type){
  if(type == "Engineering"){
    return SchoolType::Engineering;
  }else if(type == "Ivy League"){
    return SchoolType::Ivy_League;
  }else if(type == "Party"){
    return SchoolType::Party;
  }else if(type == "Liberal Arts"){
    return SchoolType::Liberal_Arts;
  }else{
    return SchoolType::State;
  }
}

Region toEnumRegion(string region){
  if(region == "California"){
    return Region::California;
  }else if(region == "Western"){
    return Region::Western;
  }else if(region == "Midwestern"){
    return Region::Midwestern;
  }else if(region == "Southern"){
    return Region::Southern;
  }else{
    return Region::Northeastern;
  }
}