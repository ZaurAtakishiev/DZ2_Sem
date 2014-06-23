#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <list>								// пдкулючаем список, для массива - <vector>
using namespace std;

class House
{
private:
public:
	int Account;	
	bool Paid;	
	CString Number;
	int Number_Of_Inhabitants;
	House();
	~House();

	void Set_Number( CString In );
	void Set_Number_Of_Inhabitants( int In );
	void Set_Account( int In );
	void Set_Paid( bool In );

	CString Get_Number();
	int Get_Number_Of_Inhabitants();
	int Get_Account();
	bool Get_Paid();

	bool Pay();
};