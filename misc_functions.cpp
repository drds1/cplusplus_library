#include <fstream>
#include <iostream>
#include <string>

/*param filename :the name of the file to open
param rows       :number of rows in the file data
param cols       :number of columns in the files data
return float**   :a 2d float array holding the read in values
			or NULL on failure.*/

float** read_file(std::string filename,int rows,int cols)
{
	std::fstream file;//create a stream for the file
	file.open(filename.c_str(), std::ios::in);//open the file to read in
	if(!file.is_open()){return 0;}//if the file failed to open return NULL

        //float** is just a 2d array like float values[cols][rows]
	//create the column pointers
	float** floats = new float*[cols+1];
	
	//create the row pointers
	for(int i = 0; i <cols;++i){ floats[i] = new float[rows+1]; }

	//read each through each row
	for(int i =0;i<rows;++i)
	{
		//read the values in this row and push into the correct
		//column.floats is [cols][rows]
		for(int j =0;j<cols;++j)//push into the col
		{ file >>floats[j][i]; }
	}
	file.close();//close the file

	return floats;//return the 2d array
}

