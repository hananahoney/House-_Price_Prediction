//i19-0542, Mohammad Shazil Mahmood, CS-E
//i19-2172, Hannan Ali, CS-E
//k19-1257, Umer Rashid, CS-E

#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;

void combinationUtil(string arr[], string data[],
					int start, int end,
					int index, int r);

void printCombination(string arr[], int n, int r)
{
	string data[r];
	combinationUtil(arr, data, 0, n-1, 0, r);
}

void combinationUtil(string arr[], string data[], int start, int end, int index, int r)
{
	if (index == r)
	{
		for (int j = 0; j < r; j++)
			if (j<r-1)
			{
				if(j==0)	
					cout << "['" << data[j] << "',";
				else
					cout << "'" << data[j] << "',";
			}
			else
				cout << "'" << data[j] << "']";	
		cout << "," << endl;
		return;
	}
	
	for (int i = start; i <= end &&
		end - i + 1 >= r - index; i++)
	{
		data[index] = arr[i];
		combinationUtil(arr, data, i+1,
						end, index+1, r);
	}
}

int main()
{
	string arr[] = {"Level","Area","Floor","Rooms","Pool","Garage","Garden","Age","Theater"};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int r=1; r<=n; r++)
		printCombination(arr, n, r);
}


