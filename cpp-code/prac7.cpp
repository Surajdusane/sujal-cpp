
#include <iostream>     // For cin and cout
#include <stack>        // For using stack
#include <string>       // For using string
#include <algorithm>    // For using reverse()
#include <cctype>       // For using isalnum()
using namespace std;


// FUNCTION 1: Check whether character is an operator
bool isOperator(char c) {

    // If c matches any operator, return true
    return (c == '+' || c == '-' || c == '*' ||
            c == '/' || c == '^');
}


// FUNCTION 2: Find priority of operators
int priority(char c) {

    // ^ has highest priority
    if (c == '^')
        return 3;

    // * and / have second priority
    if (c == '*' || c == '/')
        return 2;

    // + and - have lowest priority
    if (c == '+' || c == '-')
        return 1;

    // Return 0 for other characters like brackets
    return 0;
}


// Forward declaration (used by infixToPrefix)
string postfixToPrefix(string s);


// FUNCTION 3: INFIX TO POSTFIX
string infixToPostfix(string s) {

    // Stack stores operators
    stack<char> st;

    // Stores the final postfix expression
    string result = "";

    // Read expression one character at a time
    for (char c : s) {

        // If character is an operand, add directly to result
        if (isalnum(c)) {
            result += c;
        }

        // If opening bracket comes, push it into stack
        else if (c == '(') {
            st.push(c);
        }

        // If closing bracket comes
        else if (c == ')') {

            // Pop operators until opening bracket is found
            while (!st.empty() && st.top() != '(') {

                // Add top operator to result
                result += st.top();

                // Remove that operator from stack
                st.pop();
            }

            // Remove opening bracket
            if (!st.empty())
                st.pop();
        }

        // If character is an operator
        else {

            // Remove higher priority operators.
            // Equal priority is removed only for left-associative operators
            // ('^' is right-associative, so it stays on the stack).
            while (!st.empty() && st.top() != '(' &&
                   (priority(c) < priority(st.top()) ||
                    (priority(c) == priority(st.top()) && c != '^'))) {

                // Add operator to result
                result += st.top();

                // Remove operator from stack
                st.pop();
            }

            // Push current operator into stack
            st.push(c);
        }
    }

    // Remove all remaining operators from stack
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Return final postfix expression
    return result;
}


// FUNCTION 4: INFIX TO PREFIX
string infixToPrefix(string s) {

    // Step 1: Convert the infix expression into postfix
    string postfix = infixToPostfix(s);

    // Step 2: Convert the postfix expression into prefix
    return postfixToPrefix(postfix);
}


// FUNCTION 5: PREFIX TO INFIX
string prefixToInfix(string s) {

    // Stack stores strings because expressions are combined
    stack<string> st;

    // Prefix is processed from right to left
    reverse(s.begin(), s.end());

    // Read each character
    for (char c : s) {

        // If it is an operand
        if (!isOperator(c)) {

            // Convert character into string and push it
            st.push(string(1, c));
        }

        // If it is an operator
        else {

            // Take first popped operand
            string a = st.top();
            st.pop();

            // Take second popped operand
            string b = st.top();
            st.pop();

            // Combine in infix form and push back
            st.push("(" + a + c + b + ")");
        }
    }

    // Return final infix expression
    return st.top();
}


// FUNCTION 6: PREFIX TO POSTFIX
string prefixToPostfix(string s) {

    // Stack stores operands and partial expressions
    stack<string> st;

    // Read prefix from right to left
    reverse(s.begin(), s.end());

    for (char c : s) {

        // If character is an operand
        if (!isOperator(c)) {

            // Convert character into string and push
            st.push(string(1, c));
        }

        // If character is an operator
        else {

            // Get first operand
            string a = st.top();
            st.pop();

            // Get second operand
            string b = st.top();
            st.pop();

            // Combine with operator at the end (postfix)
            st.push(a + b + c);
        }
    }

    // Return final postfix expression
    return st.top();
}


// FUNCTION 7: POSTFIX TO INFIX
string postfixToInfix(string s) {

    // Stack stores strings
    stack<string> st;

    // Read postfix from left to right
    for (char c : s) {

        // If character is an operand
        if (!isOperator(c)) {

            // Convert character into string and push
            st.push(string(1, c));
        }

        // If character is an operator
        else {

            // First popped element is second operand
            string b = st.top();
            st.pop();

            // Second popped element is first operand
            string a = st.top();
            st.pop();

            // Combine in infix form and push back
            st.push("(" + a + c + b + ")");
        }
    }

    // Return final infix expression
    return st.top();
}


// FUNCTION 8: POSTFIX TO PREFIX
string postfixToPrefix(string s) {

    // Stack stores strings
    stack<string> st;

    // Read postfix from left to right
    for (char c : s) {

        // If character is an operand
        if (!isOperator(c)) {

            // Convert character into string and push
            st.push(string(1, c));
        }

        // If character is an operator
        else {

            // Get second operand first
            string b = st.top();
            st.pop();

            // Get first operand
            string a = st.top();
            st.pop();

            // Combine with operator at the beginning (prefix)
            st.push(c + a + b);
        }
    }

    // Return final prefix expression
    return st.top();
}


// MAIN FUNCTION
int main() {

    // Stores user's menu choice
    int choice;

    // Stores the expression entered by user
    string exp;

    // Display menu repeatedly until user exits
    do {

        cout << "\n--- EXPRESSION CONVERSION ---\n";
        cout << "1. Infix to Prefix\n";
        cout << "2. Prefix to Postfix\n";
        cout << "3. Prefix to Infix\n";
        cout << "4. Postfix to Infix\n";
        cout << "5. Postfix to Prefix\n";
        cout << "6. Exit\n";

        // Take user's choice
        cout << "Enter choice: ";
        cin >> choice;

        // Execute selected operation
            switch (choice) {

                case 1:
                    cout << "Enter Infix: ";
                    cin >> exp;

                    // Call infixToPrefix function
                    cout << "Prefix: " << infixToPrefix(exp);
                    break;


                case 2:
                    cout << "Enter Prefix: ";
                    cin >> exp;

                    // Call prefixToPostfix function
                    cout << "Postfix: " << prefixToPostfix(exp);
                    break;


                case 3:
                    cout << "Enter Prefix: ";
                    cin >> exp;

                    // Call prefixToInfix function
                    cout << "Infix: " << prefixToInfix(exp);
                    break;


                case 4:
                    cout << "Enter Postfix: ";
                    cin >> exp;

                    // Call postfixToInfix function
                    cout << "Infix: " << postfixToInfix(exp);
                    break;


                case 5:
                    cout << "Enter Postfix: ";
                    cin >> exp;

                    // Call postfixToPrefix function
                    cout << "Prefix: " << postfixToPrefix(exp);
                    break;


                case 6:
                    cout << "Program Ended!";
                    break;


                // If user enters an invalid option
                default:
                    cout << "Invalid Choice!";
            }

        } while (choice != 6);

        // End program successfully
        return 0;
    }
