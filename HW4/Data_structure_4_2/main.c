#include <stdio.h>
#include <stdbool.h>
#define Max 100
int main() {

    // input the size of the graph & the graph
    int size;
    int matrix[Max][Max];
    scanf("%d", &size);
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    // test the input matrix
/*    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
*/

    // initial the sum of the minimum spanning tree
    // set a counter for the edges
    // the array for marking the passed point
    // initial we start from point 1
    int sum = 0;
    int num_edge = 0;
    int selected[Max] = {0};
    selected[0] = 1;

    // in the while loop we walk through the graph from the point we walk through
    // then find the smallest edge and mark the point true
    while(num_edge < size-1) {
        int smallest = 100000;
        int x = 0;
        int y = 0;
        for (int i = 0; i < size; i++) {
            if (selected[i]) {
                for (int j = 0; j < size; j++) {
                    if (matrix[i][j] < smallest && !selected[j] && matrix[i][j]) {
                        smallest = matrix[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (smallest != 100000){
            sum += smallest;
            selected[y] = true;
        }
        num_edge++;
    }

    // determine if it is no connected by counting the edges
    int counter = 0;
    selected[0] = 0;
    for(int i = 0; i < size; i++){
        if (selected[i]){
            counter++;
        }
    }
    if(counter >= size - 1 && size != 1){
        printf("> %d", sum);
    }else{
        printf("> NO connected");
    }
    return 0;
}


