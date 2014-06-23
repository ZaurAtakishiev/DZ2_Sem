#include "stdafx.h"
#include "House.h"

House::House()
{
	Number = "¬ведите дом";
	Number_Of_Inhabitants = 0;
	Paid = false;
	Account = 0;
}

void House::Set_Number( CString In ) 
{
	Number = In;
}
void House::Set_Number_Of_Inhabitants( int In ) 
{
	Number_Of_Inhabitants = In;
}
void House::Set_Paid( bool In )
{
	Paid = In;
}
void House::Set_Account( int In )
{
	Account = In;
}

CString House::Get_Number()
{
	return Number;
}
int House::Get_Account()
{
	return Account;
}
bool House::Get_Paid()
{
	return Paid;
}
int House::Get_Number_Of_Inhabitants()
{
	return Number_Of_Inhabitants;
}

bool House::Pay()
{
	Paid = true;
	return true;
}