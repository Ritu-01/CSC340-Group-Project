#ifndef Colleges_h
#define Colleges_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include "College.h"

using namespace std;

class Colleges{
  private:
    vector<College> collegesBySchoolType;
    vector<College> collegesByRegion;

  public:
    //read data from school by region
    void readDataFromSchoolByType(string fileDir);
    
    //read data from school by region
    void readDataFromSchoolByRegion(string fileDir);
    
    //Rank all the colleges that has the same school type
    vector<pair<int,College>> RankCollegesBySchoolType(SchoolType theType);
    
    //Rank all the colleges that has the same Region
    //which schools rank high by their regions
    vector<pair<int,College>> RankCollegesByRegion(Region theRegion);
    
    //Ranl all colleges by Region e.g. 1. California, 2. Northeastern,
    vector<pair<int, Region>> RankRegion();
 
    //Rank all colleges by school type e.g 1. Ivy League, 2. Engineering
    vector<pair<int, SchoolType>> RankSchoolType();

};


#endif //End of Colleges_h