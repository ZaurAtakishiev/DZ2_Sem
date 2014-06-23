#include "stdafx.h"
#include "Street.h"

Street::Street()
{
	Name = "¬ведите название";
}

Street::~Street()
{

}

void Street::Add()
{
	House * Add_House;
	Add_House = new House;
	List_House.push_back( Add_House );	
}

void Street::Delete_House( int Del_Number )
{
	list< House* >::iterator it = List_House.begin();
	int i;
	for( i = 1; i < Del_Number; i++ )
	{
		it ++;
	}
	List_House.erase( it );
}

House* Street::Get_House( int Number )
{
	House* TMP_House;
	list< House* >::iterator it = List_House.begin();
	int i;
	for( i = 1; i < Number; i++ )
	{
		it ++;
	}
	TMP_House = *it;
	return TMP_House;
}

void Street::Change_Name( CString In )
{
	Name = In;
}