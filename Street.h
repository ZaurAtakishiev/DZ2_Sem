#pragma once

#include "House.h"

class Street
{
private:
public:
	list< House* > List_House;
	CString Name;
	Street();
	~Street();
	void Add();
	void Delete_House( int Del_Number );
	House* Get_House( int Number );
	void Change_Name( CString In );
};
