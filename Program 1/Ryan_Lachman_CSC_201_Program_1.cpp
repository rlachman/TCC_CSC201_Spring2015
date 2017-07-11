#include<iostream>
#include<fstream>
#include<iomanip>
#include<climits>

using namespace std;


int main()
{
	int sum = 0,i=0,j=0,count=0,iter = 0;
	int sentinel,num,max,min;
	float avg,outer_sum=0;
	
	ifstream input_file;
	input_file.open("Input.txt");
	
	ofstream output_file;
	output_file.open("Output.txt");
	output_file.precision(4);
	cout.precision(4);
	
    while(num !=EOF)
	{
		if(i == 0)		// Read the file for the first time.
		{
			output_file <<"Section"<<"\t"<<"Maximum "<<"\t"<<"Minimum "<<"\t"<<"Average(Column Heading)"<<endl;
			cout <<"Section"<<"\t"<<"Maximum"<<"\t"<<"Minimum"<<"\t"<<"Average (Column Heading)"<<endl;
			input_file >> num;
			output_file << " " << "0" << num << "\t";
			cout << " " << "0" << num << "\t";
			i = 1;
		}
		else			// Write the output
		{
			output_file << " 0" << num << "\t";
			cout << " 0" << num << "\t";
		}
		count = 0;				// Variables for each iteration.
		sum = 0;
		max = INT_MIN;			// Max as lowest value.
		min = INT_MAX;			// Min as highest value.
		j = 0;
		while(num!=sentinel)		// Preform the inner loop till we encouter a negative number.
		{
			
			if(j == 0)
			{
				input_file >> num;		// Take each number as input.
				j = 1;
			}
			sum += num;				// Calculate the sum of numbers.
			count++;
			
			if(num > max)			// Compute max
				max = num;
			if(num < min)			// Compute min
				min = num;
				
			input_file >> num;
			if(num < 0)
				sentinel = num;
		}
		avg = (float)sum / count;			// Calculate average for each class.
		outer_sum += avg;
		iter ++;						// Count the number of iterations
		output_file << max << "\t\t" << min << "\t\t " << avg << endl;		// Print the max,min and avg for each class.
		cout << max << "\t " << min << "\t " << avg << endl;
		input_file >> num;
	}
	
	
	output_file << endl << "Average for all sections = " << (outer_sum / iter) << endl;		// Print the final averages in the end.
	cout << endl << "Average for all sections = " << (outer_sum / iter) << endl;
    
    system ("pause");
    return 0;
}
