#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <math.h>
#include <stdio.h>

using namespace std;

class PostfixEvaluator {
private:
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

	void compactPostfix() {
		string tempPostfix = "";
		for (int i = 0; i < postfix.length(); i++) {
			if (postfix[i] != ' ') {
				tempPostfix += postfix[i];
			}
		}
		postfix = tempPostfix;
	}

public:
	PostfixEvaluator(string postfix) {
		this->postfix = postfix;
		compactPostfix();
	}

	int evaluatePostfix() {
		stack<char> nums;

		for (int i = 0; i < postfix.length(); i++) {
			char value = postfix[i];

			if (!isOperator(value) && (value >= 0 || value <= 9)) {
				nums.push(value - '0');
			}
			else if (isOperator(value)) {
				int tempNum1 = nums.top();
				nums.pop();
				int tempNum2 = nums.top();
				nums.pop();
				if (value == '^') {
					nums.push(pow(tempNum2, tempNum1));
				}
				else if (value == '*') {
					nums.push(tempNum2 * tempNum1);
				}
				else if (value == '/') {
					nums.push(tempNum2 / tempNum1);
				}
				else if (value == '+') {
					nums.push(tempNum2 + tempNum1);
				}
				else if (value == '-') {
					nums.push(tempNum2 - tempNum1);
				}
			}
		}
		cout << "Evaluation of postfix: ";
		return nums.top();
	}
};