#include <stdio.h>
void main() {
    FILE *elephantSealData = fopen("elephant_seal_data", "r");
    int N = 1000;
    float average, totalWeight = 0.0;
    int *data = (int*) malloc (N * sizeof(int)); // initialize seal weight array
	free(data);
    // int data[N];

    for (int i = 0; i < N; i++)
    {
        fscanf(elephantSealData, "%d", &data[i]);
    }
    for (int i = 0; i < N; i++) {
        totalWeight += data[i];
    }
    average = totalWeight / N;
    printf("Average weight of the northern elephant seal is %f", average);
    fclose(elephantSealData);
}