#include <fstream>
#include <iostream>
#include <string>
#include "misc_functions.cpp"
//param filename :the name of the file to open


// script to test the read_file code in misc functions
int main()
{
	int rows = 4;//number of rows in the file
	int cols = 3;//number of columns in the file
	float** floats;//2d array
	
	//the func read_file returns null on failure, so set floats to the 
	//value returned (which should be a 2d array) and check for failure.
	//if the function failed exit main.
	if( !(floats = read_file("lines.txt",rows,cols) ) ){return 0;}

	//write out the data reading through the columns and rows
	for(int i =0;i<rows;++i)
	{
		for(int j =0;j<cols;++j){ std::cout <<floats[j][i] <<"\t"; }
		std::cout <<"\n";
	}
	//char wait;
	//std::cin >>wait;

	return 0;
}

