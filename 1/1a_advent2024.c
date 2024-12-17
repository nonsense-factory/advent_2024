#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
    return(*(int*)a - *(int*)b);
}
int main(void){
    // Open the file
    char line[15];
    FILE *fin;
    int left[1000];
    int right[1000];
    int dist = 0;
    int i = 0;
    fin = fopen("1_in_advent2024.txt", "r");
    if (fin == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets (line, sizeof(line), fin) != NULL) {
        char* cursor = line;
        if (*cursor  == '\0'){
            continue;
        }
        left[i] = strtol(cursor, NULL, 10);
        cursor += 6;
        right[i] = strtol(cursor, NULL, 10);
        i++;
    }
    qsort(left, i, sizeof(int), compare);
    qsort(right, i, sizeof(int), compare);

    
    for (int iter = 0; iter < i; iter++){
        dist += abs(right[iter] - left[iter]);
    }
    printf("\n%d\n", dist);
    char throw_away = getchar();
    return dist;
}