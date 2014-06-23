#pragma once

#include "Street.h"

class City
{
private:
public:
	list< Street* > List_Street;
	City();
	~City();
	void Add();
	void Delete_Street( int Del_Number );
	Street* Get_Street( int Number );
};