#include <iostream>
using namespace std;

#define MAX 5
int stack[MAX];
int top = -1;

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == MAX - 1);
}

void push(int val) {
    if (isFull()) {
        cout << "Stack Overflow\n";
        return;
    }
    stack[++top] = val;
    cout << val << " pushed to stack.\n";
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return;
    }
    cout << stack[top--] << " popped from stack.\n";
}

int getmin() {
    if (isEmpty()) {
        cout << "Stack Underflow\n";
        return -1;  
    }

    int minVal = stack[0];
    for (int i = 1; i <= top; i++) {
        if (stack[i] < minVal) {
            minVal = stack[i];
        }
    }
    return minVal;
}

int main() {
    push(10);
    push(20);
    push(5);
    push(15);

    cout << "Minimum element: " << getmin() << endl;
    
}
