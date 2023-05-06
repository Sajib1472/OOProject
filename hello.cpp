// C++ code to convert infix expression to postfix

#include<iostream>
#include<string>
using namespace std;

int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }
	bool push(int x);
	void pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

void Stack::pop()
{
	if (top < 0) {
		cout << "Stack Underflow";
		//return 0;
	}
	else {
		int x = a[top--];
		//return x;
        cout << x << " pop from stack\n";
	}
}
int Stack::peek()
{
	if (top < 0) {
		cout << "Stack is Empty";
		return 0;
	}
	else {
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty()
{
	return (top < 0);
}


// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{

	Stack st;
	string result;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		// If the scanned character is an
		// ‘(‘, push it to the stack.
		else if (c == '(')
			st.push('(');

		// If the scanned character is an ‘)’,
		// pop and add to output string from the stack
		// until an ‘(‘ is encountered.
		else if (c == ')') {
			while (st.peek() != '(') {
				result += st.peek();
				st.pop();
			}
			st.pop();
		}

		// If an operator is scanned
		else {
			while (!st.isEmpty()
				&& prec(s[i]) <= prec(st.peek())) {
				result += st.peek();
				st.pop();
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.isEmpty()) {
		result += st.peek();
		st.pop();
	}

	cout << result << endl;
}

// Driver code
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";

	// Function call
	infixToPostfix(exp);
	
	return 0;
}
