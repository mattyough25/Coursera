/*
Compute Average and Max
of an Array Read from File
December 13, 2021
*/

#include <stdio.h>
#include <stdlib.h>

// Function to read the elements of the input file
// and place them into a data array
int read_file(FILE * ifp, int data[], int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		fscanf(ifp, "%d", &data[i]);
	}
	
	return(*data);
}

// Generate output file with the average and maximum hw scores
// added to the end of the data read from the input file
void new_file(FILE *ofp, int size, int d[], double avg, int max)
{
	int i;

	d[size] = avg;
	d[size + 1] = max;

	for(i = 0; i < size + 2; i++)
	{
		fprintf(ofp, "%d ", d[i]);
	}
}

// Read first element of the input file
// Return this value to indicate how many values to 
// read from the file
int count_file(FILE * ifp)
{
	int size;
	
	rewind(ifp);
	fscanf(ifp, "%d", &size);

	return(size);
}

// Compute the average
double average(int d[], int size)
{
	int i;
	double avg = 0.0;

	for(i = 0; i < size; i++)
	{
		avg += d[i];
	}
	return(avg/size);
}

// Find the maximum
int maximum(int d[], int size)
{
	int i, max;
    
    max = d[0];
 
    for (i = 1; i < size; i++)
    {
        if (d[i] > max)
            max = d[i];
    }
	return(max);
}
 
// Main Function 
int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int size, max, i;
	double avg;

	if(argc != 3)
	{
		printf("Need executable inputfile outputfile\n");
		exit(1);
	}

	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");

	size = count_file(ifp);

	int *data = (int*) malloc (size * sizeof(int));
	free(data);
	
	data[size] = read_file(ifp, data, size);

	printf("\nThe Homework Scores Are: ");
	for(i = 0; i < size; i++)
	{
		printf("%d ", data[i]);
	}

	avg = average(data, size);
	printf("\n\nThe Average Homework Score is: %lf\n\n", avg);
	max = maximum(data, size);
	printf("The Maximum Homework Score is: %d\n\n", max);

	new_file(ofp, size, data, avg, max);
	
	fclose(ifp);
	fclose(ofp);

	system("pause");
	return 0;	

}