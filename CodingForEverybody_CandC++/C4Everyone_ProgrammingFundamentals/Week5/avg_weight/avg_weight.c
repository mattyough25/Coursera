/*
Computing the average weight of of the northern elephant seal
November 20, 2021
*/

#include <stdio.h> // include the standard library

int main(void)
{
	int size, sum = 0, i; // initialize variables

	FILE *weights;
	weights = fopen("seal_data.txt", "r"); // read in data file

 if (weights== NULL)
    printf("Cannot open file \n"); // check to make sure file is open
 else

	fseek(weights, 0, SEEK_END); // set file to its end
	size = ftell(weights)/6; // use ftell to get the size of the file. (1000)
	fseek(weights, 0, SEEK_SET); // reset file to beginning

	int *seal_weights = (int*) malloc (size * sizeof(int)); // initialize seal weight array
	free(seal_weights);
	
	for(i = 0; i < size; i++)
	{
		fscanf(weights,"%d", &seal_weights[i]); // read each value in the file
		
		sum = sum + seal_weights[i]; // sum all the weights
	
	}
	
	printf("\nAverage weight of the northern elephant seal is %d\n\n", sum/size); // divide by the size to get the average and print

	fclose(weights); // close file

	system("pause");
	return 0;
}