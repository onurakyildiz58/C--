#include <iostream>
using namespace std;


struct stack
{
	char stac[10];
	int top = 0;
};
void push(struct stack* st, char veri)
{

}
char pop(struct stack* st)
{

}
int main()
{
	char stac[10];
	struct stack* yıgın;
	yıgın->top = -1;

	int i = 0;
	char ch;

	for (int i = 0; i < 10; i++)
	{
		cout << "yıgına girilecek karakteri girin\n";
		cin >> ch;
		push(yıgın, stac[i]);
	}
	for (int j = 0; j < 10; j++)
	{
		ch = pop(yıgın);
		cout << "%c" + ch <<  endl;
	}
	return 0;
}