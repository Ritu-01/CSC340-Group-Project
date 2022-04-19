//
//  main.cpp
//  group 6 project
//
//  Created by
//  Angel Lopez
//  Kimheng Peng
//  Ritu Pun
//  Rabin Karki
//  on 4/15/22.
//
/*
 /Users/angellopez/Documents/SFSU/CSC 340/group 6 project/group 6 project.xcodeproj
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

//enum class school type
enum class SchoolType{
    Engineering, Party, Liberal_Arts, Ivy_League, States};

//enum class school region
enum class Region{California, Western, Midwestern, Southern, Northeastern};

//college class
class College{
public:
    //set school name
    void setSchoolName(string theSchoolName){
        schoolName = theSchoolName;
    }
    
    //set school type string
    void setSchoType(string theType){
        schoolType = theType;
    }
    
    //set school type
    void setSchoolType(SchoolType schoolType){
        type = schoolType;
    }
    
    //set school region
    void setSchoolRegion(Region theRegion){
        region = theRegion;
    }
    
    //set starting median salary
    void setStartingMedianSalary(double startingMed){
        StartingMedianSalary = startingMed;
    }
    
    //set mid career median salary
    void setMidCareerMedianSalary(double midCareer){
        MidCareerMedianSalary = midCareer;
    }
    
    //set mid 10th
    void setMidCareer10th(double mid10th){
        MidCareer10th = mid10th;
    }
    
    //set mid 25th
    void setMidCareer25th(double mid25th){
        MidCareer25th = mid25th;
    }
    
    //set mid 75th
    void setMidCareer75th(double mid75th){
        MidCareer75th = mid75th;
    }
    
    //set mid 90th
    void setMidCareer90th(double mid90th){
        MidCareer90th = mid90th;
    }
    
    //get school name
    string getSchoolName() const{
        return schoolName;
    }
    
    //get school type string
    string getSchoType() const{
        return schoolType;
    }
    
    //get school type
    SchoolType getSchoolType() const{
        return type;
    }
    
    //get school region
    Region getSchoolRegion() const{
        return region;
    }
    
    //get starting salary
    double getStartingMedianSalary() const{
        return StartingMedianSalary;
    }
    
    //get mid career salary
    double getMidCareerMedianSalary() const{
        return MidCareerMedianSalary;
    }
    
    //get mid 10th
    double getMidCareer10th() const{
        return MidCareer10th;
    }
    
    //get mid 25th
    double getMidCareer25th() const{
        return MidCareer25th;
    }
    
    //get mid 75th
    double getMidCareer75th() const{
        return MidCareer75th;
    }
    
    //get mid 90th
    double getMidCareer90th() const{
        return MidCareer90th;
    }
private:
    string schoolName;
    string schoolType;
    SchoolType type;
    Region region;
    double StartingMedianSalary;
    double MidCareerMedianSalary;
    double MidCareer10th;
    double  MidCareer25th;
    double MidCareer75th;
    double MidCareer90th;
    //Double Difference;
    
};

//class colleges: college type and college region functions
class Colleges{
    
    vector<College> CollegesBySchoolType;
    vector<College> CollegesByRegion;
    
    //read from the 2 data files csv.
    void readFromDataset();
    
    //Rank all the colleges that has the same school type
    vector<pair<int,College>> RankCollegesBySchoolType(SchoolType theType);
    
    //Rank all the colleges that has the same Region
    vector<pair<int,College>> RankCollegesByRegion(Region theRegion);
    
    //Ranl all colleges by Region e.g. 1. California, 2. Northeastern,
    vector<pair<int, Region>> RankRegion();
 
    //Rank all colleges by school type e.g 1. Ivy League, 2. Engineering
    vector<pair<int, SchoolType>> RankSchoolType();

};


//read from the 2 data files csv.
void readFromDataset(vector<College>& collegeList){
    vector<string> row;
    College currCollege;
    string theSchoolName;
    string schoolType;
    //SchoolType theType;
    //Region theRegion;
    double theStartingMedianSalary;
    double theMidCareerMedianSalary;
    double theMidCareer10th;
    double  theMidCareer25th;
    double theMidCareer75th;
    double theMidCareer90th;
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open("/Users/angellopez/Documents/SFSU/CSC 340/salaries-by-college-type.xls", ios::in);
    if (!fin.is_open()){
        cout << "Could not open file salaries-by-college-type.csv" << endl;
        return;
    }
    
    //traverse file
    while(!fin.eof()){
        row.clear();
        
        fin >> theSchoolName;
        fin >> schoolType;
        fin >> theStartingMedianSalary;
        fin >> theMidCareerMedianSalary;
        fin >> theMidCareer10th;
        fin >> theMidCareer25th;
        fin >> theMidCareer75th;
        fin >> theMidCareer90th;
        
        if (!fin.fail()){
            currCollege.setSchoolName(theSchoolName);
            currCollege.setSchoType(schoolType);
            currCollege.setStartingMedianSalary(theStartingMedianSalary);
            currCollege.setMidCareerMedianSalary(theMidCareerMedianSalary);
            currCollege.setMidCareer10th(theMidCareer10th);
            currCollege.setMidCareer25th(theMidCareer25th);
            currCollege.setMidCareer75th(theMidCareer75th);
            currCollege.setMidCareer90th(theMidCareer90th);
            collegeList.push_back(currCollege);
        }
    }
    
    //close file
    fin.close();
}

//display colleges by type
void displayCollegesByType(vector<College>& collegeType){
    cout << "COLLEGES BY TYPE \n" << endl;
    
    for (int i = 0; i < collegeType.size(); i++){
        cout << "School Name : " << collegeType.at(i).getSchoolName() << endl;
        cout << "School Type : " << collegeType.at(i).getSchoType() << endl;
        cout << "Starting Median Salary : " << collegeType.at(i).getStartingMedianSalary() << endl;
        cout << "Mid Career Median Salary : " << collegeType.at(i).getMidCareerMedianSalary() << endl;
        cout << "Mid Career 10th : " << collegeType.at(i).getMidCareer10th() << endl;
        cout << "Mid Career 25th : " << collegeType.at(i).getMidCareer25th() << endl;
        cout << "Mid Career 75th : " << collegeType.at(i).getMidCareer75th() << endl;
        cout << "Mid Career 90th : " << collegeType.at(i).getMidCareer90th() << endl;
    }
}
int main() {
    // insert code here...
    cout << "Hello, World!\n";
    
    vector<College> schoolList;
    
    //read from dateset
    readFromDataset(schoolList);
    
    //display college list by type
    displayCollegesByType(schoolList);
    
    cout << " \n \n \n test pass \n " << endl;
    return 0;
}

