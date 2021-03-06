#include "Picture.h"

Picture::Picture()
{
	data = "";
}

Picture::Picture(const std::string &file)
{
	getPictureFromFile(file);
}

Picture::~Picture()
{
}

bool Picture::getPictureFromFile(const std::string &file)
{
	std::ifstream ifs(file.c_str());
	if (ifs.is_open()) 
	{
		getline (ifs, data, (char) ifs.eof());
		return (true);
	}
	else 
	{
		data = "ERROR";
		return (false);
	}
}

std::string	Picture::getData() const
{
	return (data);
}
