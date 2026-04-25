#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

// Push
void push(int x) {
    if(top == MAX - 1) {
        cout << "Stack Overflow" << endl;
        return;
    }
    stackArr[++top] = x;
}

// Pop
void pop() {
    if(top == -1) {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << stackArr[top--] << endl;
}

// Display
void display() {
    if(top == -1) {
        cout << "Stack is Empty" << endl;
        return;
    }
    for(int i = top; i >= 0; i--) {
        cout << stackArr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    while(n--) {
        int op;
        cin >> op;

        if(op == 1) {
            int x;
            cin >> x;
            push(x);
        }
        else if(op == 2) {
            pop();
        }
        else if(op == 3) {
            display();
        }
    }

    return 0;
}