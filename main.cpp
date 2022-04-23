#include <iostream>
#include "Colleges.h"
#include "Colleges.cpp"
#include "College.h"
#include "College.cpp"
#include "EnumTypeRegion.h"
#include "EnumTypeRegion.cpp"

int main() {
    Colleges myColleges;
    myColleges.readDataFromSchoolByType("dataset/salaries-by-college-type.csv");
    myColleges.readDataFromSchoolByRegion("dataset/salaries-by-region.csv");
    myColleges.printCollegesBySchoolType();
    myColleges.printCollegesByRegion();
    return 0;
}
