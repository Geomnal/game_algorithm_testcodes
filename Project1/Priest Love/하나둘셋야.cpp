#include<iostream>

using namespace std;

int arr[12];


int main()
{

	int T = 3;
	int n = 0;

	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (int i = 4; i < 12; i++)
	{
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	cin >> T;

	for (int i = 0; i < T; i++) 
	{
		cin >> n;
		cout << arr[n] << endl;
	}


}