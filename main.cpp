#include <iostream>
#include "Colleges.h"
#include "Colleges.cpp"
#include "College.h"
#include "College.cpp"
#include "EnumTypeRegion.h"
#include "EnumTypeRegion.cpp"

int main() {
    Colleges myColleges;
    /*
        Load data into class
    */
    myColleges.readDataFromSchoolByType("dataset/salaries-by-college-type.csv");
    myColleges.readDataFromSchoolByRegion("dataset/salaries-by-region.csv");
    
    /*
        Print out all colleges in a formatted way
    */
    myColleges.printCollegesBySchoolType();
    //myColleges.printCollegesByRegion();

    /*
        Rank colleges based on a formula
        Arguments take SchoolType or Region and a boolean set true to print out.
    */
    myColleges.RankCollegesBySchoolType(SchoolType::Ivy_League, true);
    myColleges.RankCollegesByRegion(Region::Northeastern, true);

    /*
        Rank region or school type using a formula
        Argument takes a boolean to set true if print out.
    */
    myColleges.RankRegion(true);
    myColleges.RankSchoolType(true);
    return 0;
}
