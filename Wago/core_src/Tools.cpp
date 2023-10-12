static const char *RcsId = "$Id: Tools.cpp,v 1.2 2014/03/28 10:42:07 perez Exp $";
/*
 * Tools.cpp
 *
 *  Created on: Apr 25, 2013
 *      Author: kowalisz
 */


#include "Tools.h"

vector<string> string2vector(string &str, const char* tokens)
{
	std::vector<std::string> fields;
	std::stringstream ss(str);
	std::string item;
	while(std::getline(ss, item, *tokens))
	{
		fields.push_back(item);
	}

	return fields;
}
