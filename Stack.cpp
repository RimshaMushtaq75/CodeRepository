#include<iostream>
using namespace std;
template<typename T>
class Stack
{
	T* stack;
	int capacity;
	int top;
public:
	Stack(int cap)
	{
		if (cap <= 0)
		{
			cout << "Capacity should be greater than 0";
			capacity = 0;
			stack = nullptr;
			top = -1;
		}
		else
		{
			capacity = cap;
			stack = new T[capacity];
			top = -1;
		}
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isFull()
	{
		if (top == capacity - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(T element)
	{
		if (!isFull())
		{
			top = top + 1;
			stack[top] = element;
		}
		else
		{
			cout << "The stack is Full";
		}
	}
	T pop()
	{
		T val = -11111;
		if (!isEmpty())
		{
			val = stack[top];
			top = top - 1;
		}
		else
		{
			cout << "The stack is Empty";
		}
		return val;
	}
	T peek()
	{
		T val = -11111;
		if (!isEmpty())
		{
			val = stack[top];
		}
		else
		{
			cout << "The stack is Empty";
		}
		return val;
	}
	T size()
	{
		return top + 1;
	}
};
bool isBalanced(string exp)
{
	int len = exp.length();
	Stack<char> k{ len };
	char r;
	int i = 0;
	while (len>0)
	{
		if (exp[i] == '[' || exp[i] == '(' || exp[i] == '{')
		{
			k.push(exp[i]);
		}
		else if (exp[i] == ']' || exp[i] == ')' || exp[i] == '}')
		{
			if (exp[i] == ')' && k.pop()!='('&& exp[i] == '}' && k.pop() != '{' && exp[i] == ']' && k.pop() != '[')
			{
				return false;
			}
		}
		i++;
		len--;
	}
	return true;
 }
int main()
{
	string s{ "((()())" };
	cout << isBalanced(s);
}