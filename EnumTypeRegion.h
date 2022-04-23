#ifndef EnumTypeRegion_h
#define EnumTypeRegion_h

#include<iostream>
using namespace std;

//enum class school type
enum class SchoolType{
    Engineering, Party, Liberal_Arts, Ivy_League, State};

//enum class school region
enum class Region{California, Western, Midwestern, Southern, Northeastern};

string toStrSchoolType(SchoolType type);
string toStrSchoolRegion(Region region);
SchoolType toEnumSchoolType(string type);
Region toEnumRegion(string region);

#endif //end of enum