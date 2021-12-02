
#include "Conversion.hpp"

Conversion::Conversion(void)
{

}

Conversion::Conversion(char *arg)
{
	setArg(arg);
}

Conversion::~Conversion(void)
{

}

void	Conversion::setArg(char *arg)
{
	_arg = arg;
}

std::string	Conversion::getArg() const
{
	return(this->_arg);
}

void	Conversion::setPrintable(bool flag)
{
	_printable = flag;
}

void	Conversion::setNum(bool flag)
{
	_num = flag;
}

bool	Conversion::isPrintable(char* arg)
{
	arg[0] = '0';
	return true;
}

bool checkAlpha(char* arg)
{
	bool sign = false;
	bool dote = false;
	while(arg)
	{
		if (isdigit(*arg))
		{
			arg++;
			continue;
		}
		else if ((*arg == '-'|| *arg == '+') && !sign )
			sign = true;
		else if (*arg == '.' && !dote)
			dote = true;
		else if (*arg == 'f' && ++arg != '\0')
			return false;
		++arg;
	}
	return true;
}

bool	Conversion::isNum(char* arg)
{
	bool sign = false;
	std::string valid_str = arg;
	int i = std::atoi(arg);
	int counter = 0;
	if (arg[0] == '-' || arg[0] == '+')
		sign = true;
	if (arg[0] == '0' && !arg[1])
		return true;
	else if ( i != 0)
	{
		while (i/= 10)
			counter++;
		// return ((counter == (valid_str.length())) || (((counter + 1) == valid_str.length()) && (valid_str[0] == '-' || valid_str[0] == '+'))) ? true : false;
	}
	return false;
}

// Conversion &Conversion::operator=(const Conversion &other)
// {
// 	*this = other;
// 	return *this;
// }

