#include <iostream>
#include <stack>
using namespace std;

// Function to return precedence
int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    string infix;
    cin >> infix;

    stack<char> st;
    string postfix = "";

    for(char ch : infix) {
        // Operand
        if(isalnum(ch)) {
            postfix += ch;
        }
        // Opening bracket
        else if(ch == '(') {
            st.push(ch);
        }
        // Closing bracket
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        // Operator
        else {
            while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    // Pop remaining operators
    while(!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    cout << postfix;

    return 0;
}
