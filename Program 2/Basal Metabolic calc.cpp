//Ryan Lachman 
//CSC 201 - March 23 2015
//Project: Basal Metabolic calc

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

float BasalMetabolic (int weight,int height,int age,char gender);		
// To Calculate the BMR
float TotalCalories (float BMR, int ActivityLevel);			
// To find total calories from BMR
void getdata (ifstream & input2,int & weight, int& height,int & age,char & gender, int & activeLevel);	
// To read data from input stream values passed as reference
void putdata (ofstream & output2 , int  weight, int height,int age, char gender, int activeLevel);	
// To write to the output stream.

int main()
{
	int weight,height,age,activeLevel;		// Declaring variables.
	char gender;
	float BMR,Total_Calories;		
	string s;
	
	ifstream input2 ("input.txt", std::ifstream::in);		
    // input stream declaration.
	ofstream output2("output.txt", std::ofstream::out);		
    // output stream declaration.
	
	getline(input2,s);
	output2 << s <<"   BMR  " << "Total Calories  "<<endl;
	cout << s <<"   BMR  " << "Total Calories  "<<endl;
	cout.precision(4);
	output2.precision(4);
	while(!input2.eof())			// EOF loop
	{
			getdata(input2,weight,height,age,gender,activeLevel);	
            // Get the current data from file.
			BMR = BasalMetabolic(weight,height,age,gender);			
            // Calculate BMR
			Total_Calories = TotalCalories(BMR,activeLevel);		
            // Calculate Total_Calories using the above BMR
			putdata(output2 ,weight,height,age,gender,activeLevel);	
            // Output the data to the file.
			output2 << BMR << "      " << Total_Calories <<endl;
			cout << BMR << "     " << Total_Calories <<endl;			
	}
	system ("pause");
    return 0;
}
float BasalMetabolic (int weight,int height,int age,char gender)
{
	float BMR;
	if(gender == 'M')			// Finding BMR using Harris Benedict Equation.
		BMR = (float) 66 + (6.23 * weight) + (12.7 * height) - (6.76 * age);
	else
		BMR = (float) 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
		
	return BMR;
}

float TotalCalories (float BMR, int ActivityLevel)
{
	if(ActivityLevel == 1)		// To  find the Total Calories needed by 
		return BMR*1.2;         // applying the Harris Benedict Equation for 
	else if(ActivityLevel == 2) // different activity levels.
		return BMR*1.375;
	else if(ActivityLevel == 3)
		return BMR*1.55;
	else if(ActivityLevel == 4)
		return BMR*1.725;
	else
		return BMR*1.9;
}

void getdata (ifstream & input2,int & weight, int& height, int & age, char & gender, int & activeLevel)
{
		input2 >> weight >> height >> age >> gender >> activeLevel;			
        // Read input from input2 stream.
}

void putdata (ofstream & output2 , int  weight, int height,int age, char gender, int activeLevel)
{
	output2 << weight << "     " << height << "       " << age << "     " << gender << "     " << activeLevel << "                " ;		
    // output the result in the output2 stream txt file.
	cout << weight << "     " << height << "       " << age << "     " << gender << "     " << activeLevel << "                " ;          
    // output to command window
}
