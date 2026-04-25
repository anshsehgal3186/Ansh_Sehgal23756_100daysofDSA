#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

// Node for linked list stack
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Stack using linked list
class Stack {
public:
    Node* top;

    Stack() {
        top = NULL;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
    }

    int pop() {
        if(top == NULL) return 0;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
};

int main() {
    string input;
    getline(cin, input);

    stringstream ss(input);
    string token;

    Stack st;

    while(ss >> token) {
        // If number
        if(isdigit(token[0])) {
            st.push(stoi(token));
        }
        else {
            int b = st.pop();
            int a = st.pop();

            int result;

            if(token == "+") result = a + b;
            else if(token == "-") result = a - b;
            else if(token == "*") result = a * b;
            else if(token == "/") result = a / b;

            st.push(result);
        }
    }

    cout << st.pop();

    return 0;
}