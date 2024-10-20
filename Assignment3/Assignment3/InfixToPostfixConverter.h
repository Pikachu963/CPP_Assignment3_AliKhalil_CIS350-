#pragma once

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class InfixToPostfixConverter {
private:
	string infix;
	string postfix;

	bool isOperator(char character) {
		if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^' || character == '%') {
			return true;
		}
		return false;
	}

	int precedence(char character) {
		if (character == '^')
			return 3;
		else if (character == '/' || character == '*')
			return 2;
		else if (character == '+' || character == '-')
			return 1;
		else
			return -1;
	}

	void compactInfix() {
		string tempInfix = "";
		for (int i = 0; i < infix.length(); i++) {
			if (infix[i] != ' ') {
				tempInfix += infix[i];
			}
		}
		infix = tempInfix;
	}

public:
	InfixToPostfixConverter(string infix) {
		this->infix = infix;
	}

	void convertToPostFix() {
		stack<char> postfixOps;

		for (int i = 0; i < infix.length(); i++) {
			char value = infix[i];

			if (!isOperator(value) && value != '(' && value != ')' && value != ' ' && (value >= 0 || value <= 9)) {
				postfix += value;
				postfix += ' ';
			}

			else if (value == '(') {
				postfixOps.push('(');
			}

			else if (value == ')') {
				while (postfixOps.top() != '(') {
					postfix += postfixOps.top();
					postfix += ' ';
					postfixOps.pop();
				}
				postfixOps.pop();
			}

			else if (isOperator(value)) {
				while (!postfixOps.empty() && precedence(value) < precedence(postfixOps.top()) || !postfixOps.empty() && precedence(value) == precedence(postfixOps.top())) {
					postfix += postfixOps.top();
					postfix += ' ';
					postfixOps.pop();
				}
				postfixOps.push(value);
			}
		}
		while (!postfixOps.empty()) {
			postfix += postfixOps.top();
			postfix += ' ';
			postfixOps.pop();
		}
	}

	void printPostfix() {
		cout << "Postfix expression after infix conversion: ";
		for (int i = 0; i < postfix.length(); i++) {
			cout << postfix[i];
		}
		cout << endl;
	}

	string getPostfix() {
		return postfix;
	}
};