#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;
 
int main()
{
	string fname = "dataset/salaries-by-college-type.csv";
 
	vector<string> row;
	string line, word;
 
	fstream file (fname, ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
		{
      //College college;
			row.clear();
 
			stringstream str(line);
 
			while(getline(str, word, ',')){
        row.push_back(word);
        //college.set
      } 
      //college.setName(row[0]);
      //college.setType(row[1]);
      //college.setStartingSalary(stod(row[2]));
      //...

      //CollegesBySchoolType.push_back(college);
		}
	}
	else
		cout<<"Could not open the file\n";
 
	
	return 0;
}