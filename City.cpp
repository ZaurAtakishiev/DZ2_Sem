#include "stdafx.h"

#include "City.h"

City::City()
{

}

City::~City()
{

}

void City::Add()
{
	Street* Add_Street;
	Add_Street = new Street;
	List_Street.push_back( Add_Street );	
}

void City::Delete_Street( int Del_Number )
{
	list< Street* >::iterator it = List_Street.begin();
	int i;
	for( i = 1; i < Del_Number; i++ )
	{
		it ++;
	}
	List_Street.erase( it );
}

Street* City::Get_Street( int Number )
{
	Street* TMP_Street;
	list< Street* >::iterator it = List_Street.begin();
	int i;
	for( i = 1; i < Number; i++ )
	{
		it ++;
	}
	TMP_Street = *it;
	return TMP_Street;
}