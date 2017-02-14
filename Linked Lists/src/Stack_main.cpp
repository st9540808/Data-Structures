#include "Stack.h"
using namespace std;

int main()
{
	Stack myStack;
	
	myStack.push(3);
	myStack.push(7);
	myStack.push(1);
	myStack.push(2);
	myStack.push(5);
	myStack.printStack();
	cout << myStack.top() << endl;
	
	myStack.sortStack();
	myStack.printStack();

	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.pop() << endl;
	cout << myStack.isStackEmpty();

	return 0;
}
