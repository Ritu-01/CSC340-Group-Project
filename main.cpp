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
    void setSchoolType(string theType){
        schoolType = theType;
    }
    
    //set school type
    void setSchoType(SchoolType schoolType){
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
    string getSchoolType() const{
        return schoolType;
    }
    
    //get school type
    SchoolType getSchoType() const{
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
    
    //read data from school by region
    void readDataFromSchoolByType(vector<College> CollegesBySchoolType);
    
    //read data from school by region
    void readDataFromSchoolByRegion(vector<College> CollegesByRegion);
    
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


//read from the 2 data files csv.
void readDataFromSchoolBytype(vector<College>& CollegesBySchoolType){
    vector<string> row;
    College college;
    string fileName1, word;
    
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open("dataset/salaries-by-college-type.csv", ios::in);
    if (!fin.is_open()){
        cout << "Could not open file salaries-by-college-type.csv ###" << endl;
        return;
    }
    
    //fin >> fileName1;
    //getline(fin, fileName1);
    int counter = 0;
    while (getline(fin, fileName1)){
        if (counter > 0){
        row.clear();
        stringstream str(fileName1);
        
        while (getline(str, word, ',')){
            row.push_back(word);
        }
        college.setSchoolName(row[0]);
        college.setSchoolType(row[1]);
            cout << row[2] << endl;
        college.setStartingMedianSalary(stod(row[2]));
        college.setMidCareerMedianSalary(stod(row[3]));
        college.setMidCareer10th(stod(row[4]));
        college.setMidCareer25th(stod(row[5]));
        college.setMidCareer75th(stod(row[6]));
        college.setMidCareer90th(stod(row[7]));
        CollegesBySchoolType.push_back(college);
        }
        counter++;
    }
    cout << endl;
    cout << CollegesBySchoolType.at(8).getSchoolName() << endl;
    cout << endl;
    
    //close file
    fin.close();
}

//read data from school by region
void readDataFromSchoolByRegion(vector<College> CollegesByRegion){
    vector<string> row;
    College college;
    string fileName1, word;
    
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open("dataset/salaries-by-region.csv", ios::in);
    if (!fin.is_open()){
        cout << "Could not open file salaries-by-college-type.csv ###" << endl;
        return;
    }
    
    //getline(fin, fileName1);
    int counter = 0;
    while (getline(fin, fileName1)){
        if (counter > 0){
        row.clear();
        stringstream str(fileName1);
        
        while (getline(str, word, ',')){
            row.push_back(word);
        }
        college.setSchoolName(row[0]);
        college.setSchoolType(row[1]);
        college.setStartingMedianSalary(stod(row[2]));
        college.setMidCareerMedianSalary(stod(row[3]));
        college.setMidCareer10th(stod(row[4]));
        college.setMidCareer25th(stod(row[5]));
        college.setMidCareer75th(stod(row[6]));
            cout << row[7] << endl;
        college.setMidCareer90th(stod(row[7]));
        CollegesByRegion.push_back(college);
        }
        counter++;
    }
    
    cout << endl;
    cout << CollegesByRegion.at(16).getSchoolName() << endl;
    cout << endl;
    
    //close file
    fin.close();
}

int main() {
    // insert code here...
    cout << "Hello, World!\n";
    
    vector<College> collegeListByType;
    vector<College> collegeListByRegion;

    //read dataset from college by type
    readDataFromSchoolBytype(collegeListByType);
    
    //read dataset from college by region
    readDataFromSchoolByRegion(collegeListByRegion);
    
    cout << " \n \n test pass \n " << endl;
    return 0;
}
