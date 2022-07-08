#include <iostream>
using namespace std;

int main()
{
	//Onur Akildiz 191307026
	
	int a = 41;
	
	int *ptr1 = &a;
	int **ptr2 = &ptr1;
	int ***ptr3 = &ptr2;
	int ****ptr4 = &ptr3;

	
	
	
	cout << &ptr1 << "\t" << &ptr2 << "\t" << &ptr3 << "\t" << &ptr4 << "\t" << a << endl;
	ptr2 = &ptr1;
	cout << &ptr2 << "\t" << &ptr3 << "\t" << &ptr4 << "\t" << a << endl;
	ptr3 = &ptr2;
	cout << &ptr3 << "\t" << &ptr4 << "\t" << a << endl;
	ptr4 = &ptr3;
	cout << &ptr4 << "\t" << a << endl;
	cout << &ptr4;

	return 0;

}