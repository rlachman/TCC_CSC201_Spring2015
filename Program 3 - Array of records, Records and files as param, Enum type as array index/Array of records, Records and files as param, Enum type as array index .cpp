//Ryan Lachman 
//CSC 201 - April 28 2015
//Project: Array of records, Records and files as param, Enum type as array index 

/* This program will use data text files which include each band and their 
corresponding resistances, it will also use data text files that include the 
three determined colors of band which are to be totaled togther within the 
program, the output also is in text*/
/* The purpose of this program is two parts, part one is to take three weight
resistance bands of three different colors and resistances and figure out their 
total resistance. Part two is to enter your desired weight for resistance and 
the appropriate bands will be determined for you. */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

enum bandtype  {YELLOW, GREEN, RED, BLUE, BLACK};//Creates the data type

 struct bandrecord
 //Creates the struct with information for each color of the band
 {
    string bandcolor;
 	int weight;
 	bool is_used;//If color is used, set to true (1), otherwise set to false (0)
 };
 
void setup(ifstream& input,bandrecord[]);
 	// reads in string and band resistance
 	// sets flag to false
void getbands (istream& input, bandrecord mylist[]);
 	// requests bands from user and sets flag to true
bandtype str_to_color (const string &);
	// converts string to a color
	// used in getbands procedure
 void printbands (ostream& output, const bandrecord[]);
 	// prints name of each band and resistance
    // for each band selected
  int totalresistance (const bandrecord[]);
 	// returns total resistance for all bands selected
 void resetbands (bandrecord[]);
	// sets the is_used flags to false
 void weight_to_bands(bandrecord[],int weight_required);
	// for part II of the program
	// calculates the bands used and sets the is_used flag
	
int main()
{
	
	bandrecord mylist[BLACK + 1]; 
    // To declare an array of type struct bandrecord of size 5.
	int weight_required;
	ifstream input("Setupbands.txt", std::ifstream::in);		
    // input stream declaration.
	ifstream input2("inputbands.txt",std::ifstream::in);
	ofstream output("output.txt", std::ofstream::out);		
    // output stream declaration.
	
	/* Part 1 of the program */
	output << "Part1 Output " << endl << endl;
	setup(input,mylist);			// Call the setup function
	getbands(input2,mylist);		// Call the getbands function
	printbands(output,mylist);		// print the output bands		
    output << "The total resistance is " << totalresistance(mylist) << endl 
	<< endl;
    cout << "(Part 1) The total resistance is " << totalresistance(mylist) 
    << endl;
    // Display the total resistance
	
	/* Part 2 of the program */
	output << "Part2 Output "<< endl << endl;
    output << "It has been determined that you should use the following bands" 
    <<endl <<endl;
	cout << "(Part 2) Enter the weight and the bands will be determined"<<endl;
	cin >> weight_required;	// Get the user input for the weight
	resetbands(mylist);		// Reset the bands
	weight_to_bands(mylist,weight_required);
    // Find appropriate bands for the given weight
	printbands(output,mylist);		// output the bands
	cout << "The total resistace is " << totalresistance(mylist) << endl;		
    // Display the output
	
	system ("pause");
    return 0;
    
}

void setup(ifstream& input,bandrecord mylist[])
{
	bandtype i = YELLOW;
	string bandcolor;					
	int weight;
	input >> bandcolor >> weight;	
	while(!input.eof())				// eof loop
	{
			
		mylist[i].bandcolor = bandcolor;		// store the bandcolor
		mylist[i].weight = weight;				// store the weight
		mylist[i].is_used = false;				// set the is_used flag to false
		i = (bandtype) (i+1);
		input >> bandcolor >> weight;				
	}
	
} 

 void getbands (istream& input, bandrecord mylist[])
 {
    bandtype color;
	string S;
	input >> S;
	
	while(S != "stop")							// Sentinel loop
	{
			color = str_to_color(S);			// get the color
			mylist[color].is_used = true;		// set that color to true
			input >> S;
	}
}

int totalresistance (const bandrecord mylist[])
{
	int ans = 0;
	
	for(bandtype i=YELLOW;i<=BLACK;i = (bandtype)(i+1))
    // Iterate through all colors
	{
		if(mylist[i].is_used == true)	       // Total resistance is calculated
		ans = ans + mylist[i].weight;
	}
	return (ans*2);
}

void resetbands(bandrecord mylist[])
 {
     for(bandtype i=YELLOW;i<=BLACK;i = (bandtype)(i+1))
     // Iterate through all colors
     {
       mylist[i].is_used = false;				// Set the is_used band to true
     }
 }
 
void printbands(ostream& output, const bandrecord mylist[])
{           
    for(bandtype i=YELLOW;i<=BLACK;i = (bandtype)(i+1))
    {
            if(mylist[i].is_used == true)
            {
				output << mylist[i].weight << " pound "<< mylist[i].bandcolor <<
                " band is used" << endl;
            }
    }
	output << endl;
}

bandtype str_to_color(const string &S)
{
	bandtype B;
	// Return the corresponding bandtype for the particular string
	if(S == "yellow")
		B = YELLOW;
	else if(S == "green")
		B = GREEN;
	else if(S == "red")
		B = RED;
	else if(S == "blue")
		B = BLUE;
	else
		B = BLACK;
	
	
	return B;
}
void weight_to_bands(bandrecord mylist[], int weight_required)
{
	weight_required = weight_required/2;
	
	for(bandtype i=BLACK;i>=YELLOW;i= (bandtype) (i-1))		
    // Iterate through all colors till we find the appropriate color combination
	{
		if(weight_required >= mylist[i].weight)
		{
			mylist[i].is_used = true;
			weight_required = weight_required - mylist[i].weight;
		}
	}
	cout << "It has been determined that you should use the following bands" 
    << endl;
	for(bandtype i=YELLOW;i<=BLACK;i = (bandtype)(i+1))
	{
		if(mylist[i].is_used == true)
		{
			cout << mylist[i].bandcolor << " ";	
            // Output the appropriate color combination
		}
	}
	cout << endl;
	
}
