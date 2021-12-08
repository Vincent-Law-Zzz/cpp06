#ifndef CONVERSION_HPP
# define CONVERSION_HPP
# include <iostream>
# include <iomanip>

class Conversion
{
	private:
		char	*_arg;
		bool	_printable;
		bool	_num;
		int		_lit;

	public:
		Conversion(void);
		Conversion(char *arg);
		void	setArg(char *arg);
		void	setPrintable(void);
		void	setNum(void);
		void	setLit(int lit);
		bool	isPrintable(char arg);
		bool	isNum(char *arg);
		int		isLiteral(char *arg);
		char*	getArg(void) const;
		int		getPrint(void) const;
		int		getNum(void) const;
		int		getLit(void) const;
		Conversion &operator=(Conversion const  &other);
		virtual	~Conversion(void);

};

std::ostream &operator<<(std::ostream &oper, const Conversion& info);
#endif