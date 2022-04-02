#include <stdio.h>
#define max 101

// function that walk through the island
void isIsland(int arr[max][max], int i, int j, int row, int col){

    if(arr[i][j] == 0 || i > row || j > col  || i < 0 || j < 0) {
        return;
    }else if(arr[i][j] == 1) {
        arr[i][j] = 0;
        isIsland(arr, i - 1, j, row, col);
        isIsland(arr, i + 1, j, row, col);
        isIsland(arr, i, j - 1, row, col);
        isIsland(arr, i, j + 1, row, col);
    }
}

int main() {
    // input size
    int row, col;
    scanf("%d %d", &row, &col);
    int map[max][max];
    // input the map by the input size
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            scanf("%d", &map[i][j]);
        }
    }
    // island count
    int island = 0;
    // scan through the map if occur 1 island count plus 1
    // and go through the island function that determine the island
    // mark the place to 0 after go through
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(map[i][j] == 1){
                island++;
                isIsland(map, i, j, row, col);
            }

        }

    }
    // print the number of islands
    printf("> %d", island);



    return 0;
}
