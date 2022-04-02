/*
 Homework 1-2
 Name: Ben
 Project Title: Change infix to postfix by stack
 Student ID: 109201521
 Date: 2021_10_17
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Below are the stack structure for the infix operator
 struct Stack{
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (char*)malloc(stack -> capacity *sizeof(int));
    return stack;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}

void push(struct Stack* stack, char item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return '0';
    return stack->array[stack->top--];
}
// this is the stack function that determine which is operator
int isOperand(char ch){
    return (ch >= '0' && ch <= '9') ;
}
// this is the stack function that tells the operator's precedure
int Preced(char ch){
    switch(ch){

        case ')':
            return 1;
        case '+':
        case '-':
            return 2;

        case '*':
        case '/':
            return 3;
    }
}
// this is the stack structure that turns infix to postfix
struct Stack* toPostfix(char infix[50]){
    // print '>'
    printf(">");
    // create two stacks one for putting the operators one for putting the postfix
    struct Stack* stack = createStack(100);
    struct Stack* postfix = createStack(100);
    // in this for loop we scan the infixes individually
    // transform it into postfix by the rule of printing the operands and comparing the precedure of operands
    // also I push the postfix into a postfix stack for the later calculating
    for(int i = 0; i < strlen(infix); i++){
        if(infix[i] == '(')
            push(stack, infix[i]);
        else if(isOperand(infix[i])) {
            printf(" %c", infix[i]);
            push(postfix, infix[i]);
        }
        else if(!isOperand(infix[i]) && Preced(infix[i]) > Preced(stack -> array[stack -> top]) || isEmpty(stack) || stack -> array[stack -> top] == '(')
            push(stack, infix[i]);
        else {
            while (!isOperand(infix[i]) && Preced(infix[i]) <= Preced(stack -> array[stack -> top]) && stack -> top >= 0 && stack -> array[stack -> top] != '('){
                char x = pop(stack);
                printf(" %c", x);
                push(postfix, x);
            }
            if(infix[i] != ')')
                push(stack,infix[i]);
            if(stack -> array[stack -> top] == '(')
                pop(stack);
        }
    }
    while(!isEmpty(stack) && stack -> array[stack -> top] != ')') {
        char x = pop(stack);
        printf(" %c", x);
        push(postfix, x);
    }
    printf("\n");
    return postfix;
}
// Below are the stack structure for the operands to calculate
struct Stack1{
    int top;
    unsigned capacity;
    double* array;
};

struct Stack1* createStack1(unsigned capacity){
    struct Stack1* stack = (struct Stack1*)malloc(sizeof(struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (double*)malloc(stack -> capacity *sizeof(int));
    return stack;
}

void push1(struct Stack1* stack, double item)
{
    stack->array[++stack->top] = item;
}

double pop1(struct Stack1* stack)
{
    return stack -> array[stack -> top--];
}
// this is the function for the postfix to calculate
void calPostfix(char postfix[50]){
    // create a stack for calculating the postfix
    struct Stack1* stack = createStack1(100);
    double val, num1, num2;
    // in this for loop I put the operators into the stack
    // whenever the next item in the postfix is an operator
    // calculate the previous two operands in the stack
    for (int i = 0; i <= strlen(postfix); i++) {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            push1(stack, postfix[i] - '0');
        }else if(postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
            num2 = (double)pop1(stack);
            num1 = (double)pop1(stack);
            if(postfix[i] == '+')
                val = num1 + num2;
            else if(postfix[i] == '-')
                val = num1 - num2;
            else if(postfix[i] == '*')
                val = num1 * num2;
            else if(postfix[i] == '/')
                val = num1 / num2;
            push1(stack, val);
        }
    }
    printf("> %d", (int)round(val));
}

int main() {
    // scan the infix
    char infix[50];
    scanf("%s", infix);
    // turn infix into postfix by the toPostfix() function
    struct Stack* postfix = toPostfix(infix);
    // calculate the postfix by the calPostfix() function
    calPostfix(postfix -> array);
    return 0;
}
