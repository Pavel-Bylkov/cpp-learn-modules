#ifndef CONTACT_HPP
# define  CONTACT_HPP

# include <iostream>  // std::cout, std::endl
# include <string>    // std::string type
# include <iomanip>   // std::setw, std::setfill

namespace s
{
	typedef std::string str;
	const str NOCOLOR = "\033[0m";
	const str RED = "\033[0;31m";
	const str CYAN = "\033[0;36m";
	const str YELLOW = "\033[1;33m";
	void	print_line(unsigned size, char fill, str color = NOCOLOR);
}

class Contact
{
	public:
		Contact(void);
		void input_info(void);
		void print(void);
		bool validate(void);
		s::str get_first_name(void) const;
		s::str get_last_name(void) const;
		s::str get_nickname(void) const;
		s::str get_phone_number(void) const;
		s::str get_darkest_secret(void) const;
	private:
		s::str _first_name;
		s::str _last_name;
		s::str _nickname;
		s::str _phone_number;
		s::str _darkest_secret;
};

#endif
