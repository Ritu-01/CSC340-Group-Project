#include "Colleges.h"
//read from the 2 data files csv.
void Colleges::readDataFromSchoolByType(string fileDir){
    vector<string> row;
    College college;
    string fileName1, word;
    
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open(fileDir, ios::in);
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
        college.setStartingMedianSalary(stod(row[2]));
        college.setMidCareerMedianSalary(stod(row[3]));
        college.setMidCareer10th(stod(row[4]));
        college.setMidCareer25th(stod(row[5]));
        college.setMidCareer75th(stod(row[6]));
        college.setMidCareer90th(stod(row[7]));
        collegesBySchoolType.push_back(college);
        }
        counter++;
    }
    cout << "salaries-by-college-type.csv successfully read" << endl;
    //close file
    fin.close();
}

//read data from school by region
void Colleges::readDataFromSchoolByRegion(string fileDir){
    vector<string> row;
    College college;
    string fileName1, word;
    
    //file pointer
    ifstream fin;

    //open an existing record
    fin.open(fileDir, ios::in);
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
        college.setMidCareer90th(stod(row[7]));
        collegesByRegion.push_back(college);
        }
        counter++;
    }
    cout << "salaries-by-region.csv successfully read" << endl;
    //close file
    fin.close();
}
