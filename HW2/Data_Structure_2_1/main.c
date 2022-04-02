/*
 Homework 2-2
 Name: Ben
 Project Title: Queue commands
 Student ID: 109201521
 Date: 2021_10_31
 */

#include <stdio.h>
#include <stdlib.h>
// A queue is a first in first out structure
// So I gave it a rear and a front to tell me
// the first added in element and the newest added in element
// size is the temporary numbers of elements
// capacity is the max size of the Queue
// array is basicly the Queue
struct Queue{
    int rear, front, size;
    unsigned capacity;
    int *array;
};

// I initialize the queue in this function
// letting queue capacity be the capacity I give when I call the function
// the front be 0, rear be -1, which is the initial location of front & rear
// the initial size is obviously 0
// and give the array a memory location
struct Queue* createQueue(unsigned capacity){
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue -> capacity = capacity;
    queue -> front = 0;
    queue -> size = 0;
    queue -> rear = capacity - 1;
    queue -> array = (int*)malloc(queue -> capacity * sizeof(int));
    return queue;
}

// tell me whether the queue is full
int isFull(struct Queue* queue){
    return (queue -> size == queue -> capacity);
}

// tell me whether the queue is empty
int isEmpty(struct Queue* queue){
    return (queue -> size == 0);
}

// add a element to the queue
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// delete the first added in element from the array
void deQueue(struct Queue* queue){
    if(isEmpty(queue))
        return;
    int item;
    item = queue -> array[queue -> front];
    queue -> front = (queue -> front + 1) % (queue -> capacity);
    queue -> size -= 1;
}

// return the front element for me (this one is optional though I still used it in main program)
int front(struct Queue *queue){
    return queue -> array[queue -> front];
}

int main() {
    // create a max size 100 queue
    struct Queue* queue = createQueue(100);

    // int cmd is the command that should be input which will be '1', '2', '3', '-1'
    int cmd;
    printf(">");

    // in the do while loop it basicly do what the command tell it to do
    // if input 1 you should input another element into the queue
    // if input 2 display the front element
    // if input 3 delete the first added element from queue
    // when input -1 the do while loop break and the program stops
    do{
        int item;
        scanf("%d", &cmd);
        if(cmd == 1) {
            scanf("%d", &item);
            enqueue(queue,item);
        }else if(cmd == 2){
            if(isEmpty(queue))
                printf(" -2");
            else{
                printf(" %d", front(queue));
            }
        }else if(cmd == 3) {
            if (isEmpty(queue))
                printf(" -3");
            deQueue(queue);
        }
    }while(cmd!= -1);
    return 0;
}

