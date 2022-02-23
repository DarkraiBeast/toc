#include <stdio.h>
#include <iostream>
#include <conio.h>
#include<string.h>
using namespace std;
#define MAX 20

class Stack
{
public:
	int top;
	char a[MAX];
	Stack()
	{
		top = -1;
	}
	void push(char x)
	{
		a[++top] = x;
	}
	void pop()
	{
		--top;
	}
	char peek()
	{
		char x = a[top];
		return x;
	}
	bool isEmpty()
	{
		return (top < 0);
	}
	void display()
	{
		for (int s = top; s >= 0; s--)
			cout << a[s];
	}
};	

void displaytransition(string state, Stack stack, char str[], int t, int l)
{
	cout << " " << state << "   | ";
	for (int k = t; k < l; k++)
		cout << str[k];
	for (int k = 0; k < (10 - l + t); k++)
		cout << " ";
	cout << " | ";
	stack.display();
	cout << endl;
}

int main()
{
	enum state { q0, q1, q2 };
	int len;
	state current_state = q0;
	char str[10];
	class Stack stack;
	//clrscr();
	cout << "Enter the string: ";
	cin >> str;
	len = strlen(str);
	cout << "Using Push Down Automata: " << endl;
	cout << "State |   Input    | Stack" << endl;
	cout << "--------------------------" << endl;
	displaytransition("q0", stack, str, 0, len);
	for (int i = 0; i <= len;)
	{
		switch (current_state)
		{
		case q0:
			if (i < len)
				if (str[i] == 'a' && stack.isEmpty())
				{
					current_state = q0;
					stack.push('a');
					displaytransition("q0", stack, str, i+1, len);
				}
				else if (str[i] == 'a' && stack.peek() == 'a')
				{
					current_state = q0;
					stack.push('a');
					displaytransition("q0", stack, str, i+1, len);
				}
				else if (str[i] == 'b' && stack.isEmpty())
				{
					current_state = q0;
					stack.push('b');
					displaytransition("q0", stack, str, i+1, len);
				}
				else if (str[i] == 'b' && stack.peek() == 'a')
				{
					current_state = q1;
					stack.pop();
					displaytransition("q1", stack, str, i+1, len);
				}
				else
				{
					cout << "--------------------------" << endl;
					cout << "String Rejected !!";
					goto end;
				}
			i++;
			break;
		case q1:
			if (i < len && str[i] == 'b' && stack.peek() == 'a')
			{
				current_state = q1;
				stack.pop();
				displaytransition("q1", stack, str, i+1, len);
			}
			else if (i == len && stack.isEmpty())
			{
				current_state = q2;
				displaytransition("q2", stack, str, i, len);
				cout << "--------------------------" << endl;
				cout << "String Accepted !!";
				goto end;
			}
			else
			{
				cout << "--------------------------" << endl;
				cout << "String Rejected !!";
				goto end;
			}
			i++;
		}
	}
end:
	_getch();
	return 0;
}
