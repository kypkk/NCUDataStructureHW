/*
 Homework 1-1
 Name: Ben
 Project Title: Print the triplet form & its transform triplet form of a sparse matrix
 Student ID: 109201521
 Date: 2021_10_21
 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

int main(){
    // mat is the input matrix and mat_t is the transpose of the input matrix
    int mat[MAXSIZE][MAXSIZE];
    int mat_t[MAXSIZE][MAXSIZE];
    // inputting the size of the matrix
    int row, col;
    scanf("%d %d", &row, &col);
    int capacity = row * col;
    // i is the row of the matrix, j is the column of the matrix
    // totals helps me to count how many input numbers
    // temp is the temporary value that the input get
    int i = 0, j = 0;
    int totals = 0;
    int temp;
    // basicly the while loop stop when there is no more inputs
    // everytime the while loop run total will plus 1
    while(scanf("%d", &temp) != EOF){
        mat[i][j] = temp;
        j++;
        if(j == col){
            i++;
            j = 0;
        }
        totals++;
    }
    // if total is not as same as the size of the matrix then it is a nonlegal input
    // else it print the triplet form of the matrix and the transpose triplet form of the matrix
    if(totals != capacity)
        printf("Input matrix has wrong size. Please input again.\n");
    else{
        int vals = 0;
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                if(mat[i][j] != 0){
                    vals++;
                }
            }
        }
        printf("Sparse matrix by triplet form:");
        printf("\n%d %d %d", row, col, vals);
        for(i = 0; i < row; i++){
            for(j = 0; j < col; j++){
                if(mat[i][j] != 0){
                    printf("\n%d %d %d", i, j, mat[i][j]);
                }
                mat_t[j][i] = mat[i][j];
            }
        }
        printf("\nTranspose of the sparse matrix:");
        printf("\n%d %d %d", col, row, vals);
        for(i = 0; i < col; i++){
            for(j = 0; j < row; j++){
                if(mat_t[i][j] != 0){
                    printf("\n%d %d %d", i, j, mat_t[i][j]);
                }
            }
        }
    }
    return 0;
}