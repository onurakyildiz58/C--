#include <iostream>
using namespace std;
#define size 10

int queue[100],n=100, front = -1, rear = -1;
void insert()
{
    int deger;
	if (rear==n-1)
	{
		cout << "kuyruk dolur\n";
	}
	else
	{
		if (front==-1)
		{
			front = 0;
		}
		cout << "eleman gir:\n";
		cin >> deger;
		rear++;
		queue[rear] = deger;
	}
}

void Delete()
{
	if (front == -1 || front > rear)
	{
        cout << "kuyruk boştur\n";
	     return;
	}	
	else
	{
		cout << "bi eleman silindi: " << queue[front] << endl;
	}
	
}

void Display()
{
	if (front==-1)
	{
		cout << "kuyruk bostur\n";
	}
	else
	{
		cout << "dizi elemanlari :";
		for (int i = front; i < rear; i++)
		{
			cout << queue[i] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	int ch;
	cout << "1-insert" << endl;
	cout << "2-delete" << endl;
	cout << "3-display" << endl;
	cout << "4-quit" << endl;

	do
	{
		cout << "birini seçiniz\n";
		cin >> ch;
		switch (ch)
		{
		case 1:insert();
			break;
		case 2:Delete();
			break;
		case 3:Display();
			break;
		case 4:cout << "quit" << endl;
			break;
		default:
			cout << "geçersiz seçim\n";
		}

	} while (ch!=4);

	return 1903;

}