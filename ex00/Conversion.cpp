
#include "Conversion.hpp"

Conversion::Conversion(void)
{

}

int		Conversion::isLiteral(char *arg)
{
	std::string str = arg;

	if ((str == "inf") ||(str == "+inf") || (str == "-inf") || (str == "nan"))
		return 1;
	if ((str == "inff") || (str == "+inff") || (str == "-inff") || (str == "nanf"))
		return 2;
	return 0;
}

Conversion::Conversion(char *arg) : _arg(arg), _printable(false), _num(false)
{
	double num_i = 0;
	try{
		num_i = std::stod(_arg);
	}
	catch (std::out_of_range){
		std::cout << "char :" << " " <<"impossible" <<std::endl;
		std::cout << "int :" << " " << "impossible" << std::endl;
		std::cout << "float :" << " " << "impossible" << std::endl;
		std::cout << "double :" << " " << "impossible" << std::endl;
		exit(0) ;
	}
	catch (std::invalid_argument){}
	if (isNum(_arg))
		setNum();
	if (_num && isPrintable(static_cast<char>(num_i)))
		setPrintable();
	setLit(isLiteral(_arg));

	// std::cout << "l " << _lit << "  n " << _num << " p " << _printable << std::endl;
}

Conversion::~Conversion(void)
{

}

void	Conversion::setArg(char *arg)
{
	_arg = arg;
}

void	Conversion::setPrintable(void)
{
	_printable = true;
}

void	Conversion::setNum(void)
{
	_num = true;
}

void	Conversion::setLit(int lit)
{
	this->_lit = lit;
}

char*	Conversion::getArg(void) const
{
	return this->_arg;
}

int	Conversion::getLit(void) const
{
	return this->_lit;
}

int	Conversion::getNum(void) const
{
	return this->_num;
}

int	Conversion::getPrint(void) const
{
	return this->_printable;
}

bool	Conversion::isPrintable(char arg)
{
	if ((arg > 31) && (arg < 127))
		return true;
	return false;
}

bool	Conversion::isNum(char* arg)
{
	int i = 0;
	bool sign = false;
	bool dote = false;
	while(arg[i])
	{
		if (isdigit(arg[i]))
		{
			i++;
			continue;
		}
		else if ((arg[i] == '-'|| arg[i] == '+') && !sign && i == 0)
			sign = true;
		else if (arg[i] == '.' && !dote && arg[i + 1] != 'f' && arg[i + 1] != '\0')
			dote = true;
		else if (((arg[i] == 'f') &&(arg[i + 1] != '\0')) || ((arg[i] == 'f') && !dote))
			return false;
		else if (arg[i] == 'f')
			return true;
		else
			return false;
		i++;
	}
	return true;
}

Conversion &Conversion::operator=(Conversion const  &other)
{
	this->_arg = other._arg;
	this->_lit = other._lit;
	this->_num = other._num;
	this->_printable = other._printable;
	return *this;
}

std::ostream &operator<<(std::ostream &oper, const Conversion& info)
{
	if (!info.getPrint() && !info.getLit() && !info.getNum())
	{
		std::string str = info.getArg();
		if (str.length() > 1)
		{
			oper << "Error: Wrong argument!";
			return oper;
		}
		char c = static_cast<char>(str[0]);
		oper << "char :" << " \'" << c << "\'" <<std::endl;
		oper << "int :" << " " << static_cast<int>(c) << std::endl;
		oper << "float :" << " " << static_cast<float>(c) << ".0f" << std::endl;
		oper << "double :" << " " << static_cast<double>(c) << ".0" << std::endl;
	}
	else if (info.getPrint())
	{
		char str = static_cast<int>(std::stod(info.getArg()));
		oper << "char :" << " \'" << str << "\'" <<std::endl;
	}
	else
	{
		std::string strw = info.getArg();
		if (info.getNum() && strw.length() < 11)
			oper << "char :" << " " <<"Non displayable" <<std::endl;
		else
			oper << "char :" << " " << "impossible" <<std::endl;
	}
	if (info.getLit())
	{
		std::string str = info.getArg();
		bool twof = (info.getLit() == 2)? true : false;
		oper << "int :" << " " << "impossible" << std::endl;
		oper << "float :" << " " << ((twof) ? str : str + 'f');
		oper << std::endl;
		oper << "double :" << " " << ((twof) ? str.substr(0,str.length() - 1) : str); 
	}
	if (info.getNum())
	{
		double num = std::stod(info.getArg());
		if ((num < -2147483648) || (num > 2147483647))
			oper << "int :" << " " << "impossible" << std::endl;
		else
			oper << "int :" << " " << (static_cast<int>(std::atoi(info.getArg()))) << std::endl;
		bool isZero = (static_cast<float>(std::stod(info.getArg()) - static_cast<int>(std::stod(info.getArg())) == 0) ? true : false);
		oper << "float :" << " " << (static_cast<float>(std::stod(info.getArg()))) <<  ((isZero) ? ".0f" : "f") ;
		oper << std::endl;
		oper << "double :" << " " << (static_cast<double>(std::stod(info.getArg()))) <<  ((isZero) ? ".0": "") ;
	}	
	return oper;
}

