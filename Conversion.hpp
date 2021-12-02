#ifndef CONVERSION_HPP
# define CONVERSION_HPP
# include <iostream>
# include <iomanip>

class Conversion
{
	private:
		char *_arg;
		bool _printable;
		bool _num;
	public:
		Conversion(void);
		Conversion(char *arg);
		void	setArg(char *arg);
		void	setPrintable(bool flag);
		void	setNum(bool flag);
		bool	isPrintable(char *arg);
		bool	isNum(char *arg);
		std::string	getArg() const;
	// Conversion &operator=(const Conversion &other);
		virtual	~Conversion(void);

};
#endif