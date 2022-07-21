//i19-0542, Mohammad Shazil Mahmood, CS-E
//i19-2172, Hannan Ali, CS-E
//k19-1257, Umer Rashid, CS-E

#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main()
{
	int data_size = 1000000;
	srand(time(0));
	
    ofstream MyFile("final_training.csv");
    ofstream MyFile1("pre_training.csv");
    ofstream MyFile2("final_test.csv");
    ofstream MyFile3("pre_test.csv");
    
    MyFile << "Level,Area,Floor,Rooms,Pool,Garage,Garden,Age,Theater,Price(Million-USD)" << endl;
    MyFile1 << "Level,Area,Floor,Rooms,Pool,Garage,Garden,Age,Theater,Price(Million-USD)" << endl;
    MyFile2 << "Level,Area,Floor,Rooms,Pool,Garage,Garden,Age,Theater,Price(Million-USD)" << endl;
    MyFile3 << "Level,Area,Floor,Rooms,Pool,Garage,Garden,Age,Theater,Price(Million-USD)" << endl;
    
    for(int i=0; i<data_size; i++)
    {
    	int level = 1 + rand()%3;
    	int area = 1500;
    	if (level>=2)
    	{
    		area = 1500 + rand()%25000;
		}
    	else
    	{
    		area = 1500 + rand()%10000;
		}
    	int floor = 1 + rand()%3;
    	int pool=0, rooms=3, garage=1,garden=0,theater=0;
    	if(area>5500)
    	{
    		pool = rand()%2;
    		garden = rand()%2;
    		theater = rand()%2;
    		rooms = (3 + rand()%3);
    		garage = 1 + rand()%3;
   		}
   		if (area>15000)
   		{
   			pool=1;
			garage=3;
			garden=1;
			theater=1;
		}
		int age= rand()%50;
		
    	double price = ((area*1.0)*28.37);
    	price = price * level;
    	price = price + (pool*20000)+(floor*40000)+(garden*10000)+(theater*15000);
    	price = price/(1000000.0);
    	
    	if (age>=40)
    		price = price * 0.8;
    	else if (age>=30 && age<40)
    		price = price * 0.9;
    	else if (age>=20 && age<30)
    		price = price * 1.0;
    	else if (age>=10 && age<20)
    		price = price * 1.1;
    	else if (age>=5 && age<10)
    		price = price * 1.2;
    	else if (age<5)
    		price = price * 1.3;
    	
    	string pre_level="";
		string pre_pool="";
		string pre_garden="";
		string pre_theater="";
    	
    	if (level == 1)
    		pre_level = "Rural Area";
    	else if (level == 2)
    		pre_level = "Middle Class";
    	else if (level == 3)
    		pre_level = "Upper Class";
    		
    	if (pool == 0)
    		pre_pool = "No";
		else if (pool == 1)
    		pre_pool = "Yes";
    		
    	if (garden == 0)
    		pre_garden = "No";
		else if (pool == 1)
    		pre_garden = "Yes";
    		
    	if (theater == 0)
    		pre_theater = "No";
		else if (pool == 1)
    		pre_theater = "Yes";
    	
    	int boundary=int(0.8*data_size);
    	
    	if (i<boundary)
    	{
    		MyFile << level <<","<< area <<","<< floor <<","<< rooms <<","<< pool <<","<<garage<<","<<garden<<","<<age<<","<<theater<<","<< price << endl;
    		MyFile1 << pre_level <<","<< area <<","<< floor <<","<< rooms <<","<< pre_pool <<","<< garage<<","<<pre_garden<<","<<age<<","<<pre_theater<<","<< price << endl;
    	}
		else if (i>=boundary)
    	{
    		MyFile2 << level <<","<< area <<","<< floor <<","<< rooms <<","<< pool <<","<<garage<<","<<garden<<","<<age<<","<<theater<<","<< price << endl;
    		MyFile3 << pre_level <<","<< area <<","<< floor <<","<< rooms <<","<< pre_pool <<","<< garage<<","<<pre_garden<<","<<age<<","<<pre_theater<<","<< price << endl;
    	}
    	cout << i << endl;
	}

	MyFile.close();
	MyFile1.close();
	MyFile2.close();
	MyFile3.close();
}


