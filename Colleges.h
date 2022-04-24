#ifndef Colleges_h
#define Colleges_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <utility>
#include <algorithm>
#include "College.h"


using namespace std;

class Colleges{
  private:
    vector<College> collegesBySchoolType;
    vector<College> collegesByRegion;

  public:
    //read data from school by type
    void readDataFromSchoolByType(string fileDir);
    
    //read data from school by region
    void readDataFromSchoolByRegion(string fileDir);

    //print out data from school by type
    void printCollegesBySchoolType();

    //print out data from school by region
    void printCollegesByRegion();

    void printColleges(vector<College> colleges, string typeOrRegion);
    
    //Rank all the colleges that has the same school type
    vector<College> RankCollegesBySchoolType(SchoolType theType, bool output);
    
    //Rank all the colleges that has the same Region
    //which schools rank high by their regions
    vector<College> RankCollegesByRegion(Region theRegion, bool output);
    
    //Ranl all colleges by Region e.g. 1. California, 2. Northeastern,
    vector<Region> RankRegion();
 
    //Rank all colleges by school type e.g 1. Ivy League, 2. Engineering
    vector<SchoolType> RankSchoolType();

    double regionScorer(vector<College> colleges);

    double schoolTypeScorer(vector<College> colleges);

};


#endif //End of Colleges_h