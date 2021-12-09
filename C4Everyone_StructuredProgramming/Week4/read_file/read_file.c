/*
Compute Average and Max
of an Array Read from File
December 7, 2021
*/

#include <stdio.h>
#include <stdlib.h>

void print_file(FILE * fptr)
{
	int c;
	rewind(fptr);
	while((c = getc(fptr)) != EOF)
	{
		//putchar(c);
		putc(c, stdout);
	}
}

void new_file(FILE *ifp, FILE *ofp, int d[])
{
	int c;
	rewind(ifp);
	while((c = getc(ifp)) != EOF)
	{
		
		//putchar(c); for debugging purposes
		//if (c == '\n')
			//putc('\n', ofp);
	}
}

int count_file(FILE * ifp)
{
	int c, size = 0;
	rewind(ifp);
	while((c = getc(ifp)) != EOF)
	{
		size++;
	}
	return(size);
}

int read_file(FILE * ifp, int size)
{
	int i, c;
	int *d = (int*) malloc (size * sizeof(int));
	free(d);

	rewind(ifp);
	c = getc(ifp);
	
	for(i = 0; i < size; i++ )
	{
		 
		d[i] = getc(ifp);
		printf("%d\n\n", d[i]);
	}

	return (*d);

}

void write_file(FILE *ofp, int d[], int size)
{
int i;

	for(i = 0; i < size + 2; i++)
	{
		putc(d[i], ofp);
	}
		
}

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

 int maximum(int d[], int size)
{
	int i, max;
    
    // Initialize maximum element
    max = d[0];
 
    // Traverse array elements from second and
    // compare every element with current max 
    for (i = 1; i < size; i++)
    {
        if (d[i] > max)
            max = d[i];
    }
	return(max);
}

int add_element(int d[], int size, int avg, int max)
{
	int i, avg_pos, max_pos;

	avg_pos = size + 1;
	max_pos = size + 2;

	size = size + 2;

	// shift elements forward
    for (i = size-1; i >= max_pos; i--)
    {
        d[i] = d[i - 1];
    }
 
    // insert avg at avg_pos
    d[avg_pos - 1] = avg;

    // insert max at max_pos
    d[max_pos - 1] = max;

    return(*d);
}
 

int main(int argc, char *argv[])
{
	FILE *ifp, *ofp;
	int size, max;
	double avg;

	if(argc != 3)
	{
		printf("Need executable inputfile outputfile\n");
		exit(1);
	}

	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");

	size = 10 ;//count_file(ifp);

	int *data = (int*) malloc (size * sizeof(int));
	free(data);

	print_file(ifp);
	new_file(ifp, ofp, data);
	/*data[size] = read_file(ifp, size);
	
	avg = average(data, size);
	//printf("%lf", avg);
	max = maximum(data, size);
	//printf("\n\n%d", max);

	data[size + 2] = add_element(data, size, avg, max);

	write_file(ofp, data, size);
	*/
	fclose(ifp);
	fclose(ofp);

	system("pause");
	return 0;	

}