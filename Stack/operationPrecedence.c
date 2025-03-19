#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    int *data;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    stack->data[++stack->top] = value;
}

int pop(Stack* stack) {
    return stack->data[stack->top--];
}

int evaluateEquation(char* equation) {
    Stack* stack = createStack(strlen(equation));
    
    int result = 0;
    int prev_num = 0;
    int sign = 1;
    char prev_op = '+';  // Keeps track of the last operator

    for (int i = 0; equation[i] != '\0'; i++) {
        if (isdigit(equation[i])) {
            int num = 0;
            while (isdigit(equation[i])) {
                num = num * 10 + (equation[i] - '0');
                i++;
            }
            i--;  // Adjust index

            // Handle multiplication and division immediately
            if (prev_op == '*') {
                prev_num *= num;
            } else if (prev_op == '/') {
                prev_num /= num;
            } else {
                prev_num = num;
            }
            prev_op = 0;  // Reset the operator
        }
        else if (equation[i] == '+') {
            result += sign * prev_num;
            sign = 1;
            prev_op = '+';  // Store operator
        }
        else if (equation[i] == '-') {
            result += sign * prev_num;
            sign = -1;
            prev_op = '-';
        }
        else if (equation[i] == '*') {
            prev_op = '*';
        }
        else if (equation[i] == '/') {
            prev_op = '/';
        }
        else if (equation[i] == '(') {
            push(stack, result);
            push(stack, sign);
            result = 0;
            sign = 1;
        }
        else if (equation[i] == ')') {
            result += sign * prev_num;
            result *= pop(stack);
            result += pop(stack);
            prev_num = 0;
        }
    }

    result += sign * prev_num;  // Add the last number
    free(stack->data);
    free(stack);
    return result;
}

int main() {
    char equation[] = "(3+2*4-6/2)";
    printf("Result: %d\n", evaluateEquation(equation));
    return 0;
}
