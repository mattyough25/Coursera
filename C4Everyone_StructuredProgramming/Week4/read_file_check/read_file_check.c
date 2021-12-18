#include <stdio.h>
#include <stdlib.h> 

void read_data(FILE *ptr, int d[], int *size)
{
    
    *size = 0;
    while (fscanf(ptr, "%d", &d[*size]) == 1) //&d- get the addres of this thing so it can be updated
        (*size)++;
}

void print_data(int d[], int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", d[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

double average(int d[], int size)
{
    int i;
    double avg = 0.0;

    for (i = 0; i < size; i++)
        avg += d[i];
    return (avg / size);
}

int max(int d[], int size){
    int i, max = 0;

    for (i = 0; i < size; i++){
        //for each value in array d
        if(d[i]>max) //if value in pos i of array is bigger than the max defined the we right in variable max
            max = d[i];
    }

    return max;
}
int print_file(FILE *fptr, int d[], int size, double average, int max)
{
    fptr = fopen("answer-hw3", "w"); //create a file with write permissions
    if (fptr == NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(fptr, "\n Array output:");
    for (int i = 0; i < size; i++)
    {
        fprintf(fptr, "\n %d\t", d[i]);
    }
   
    fprintf(fptr, "\n Average: %f", average);
    fprintf(fptr, "\n Max : %d", max);
    return 0;
}

    int main()
{
    int size = 1, data[20] ={100,0};
    FILE *ifp, *ofp;
   
    ifp = fopen("File", "r"); //it will be open for reading(r)

    read_data(ifp, data, &size); //read the values into a array
    size = data[0]; //make sure that the size of the printing array is just data[0]


    print_data(data, size); 
    fclose(ifp);
//average
    double avg = average(data, size);
    printf("\n Average: %f", avg);
//max
    printf("\n Max: %d", max(data, size));

    print_file(ofp, data,size,avg, max(data, size));
    return 0;
}