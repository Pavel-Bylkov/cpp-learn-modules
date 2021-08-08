#include "Contact.hpp"

Contact::Contact(void)
{
}

void	s::print_line(unsigned size, char fill, s::str color)
{
	s::str line;

	line.append(size, fill);
	std::cout << color << line << '\n' << s::NOCOLOR;
}

void    Contact::input_info(void)
{
	while (true)
	{
		s::print_line(50, '*');
		std::cout << "Enter First Name: ";
		std::getline(std::cin, this->_first_name);
		std::cout << "Enter Last Name: ";
		std::getline(std::cin, this->_last_name);
		std::cout << "Enter Nickname: ";
		std::getline(std::cin, this->_nickname);
		std::cout << "Enter Phone Number: ";
		std::getline(std::cin, this->_phone_number);
		std::cout << "Enter Darkest Secret: ";
		std::getline(std::cin, this->_darkest_secret);
		if (!this->validate())
			std::cout << s::RED << "Error: Incomplete info! Try again.\n" << s::NOCOLOR;
		else
		{
			s::print_line(50, '*');
			return ;
		}
	}
}

bool    Contact::validate(void)
{
    if (this->_first_name.empty() || this->_last_name.empty()
    		|| this->_phone_number.empty())
        return (false);
    return (true);
}

void	Contact::print(void)
{
	s::print_line(50, '*');
	std::cout << s::CYAN << "Current contact info:\n";
	std::cout << "First Name: " << this->_first_name << "\n";
	std::cout << "Last Name: " << this->_last_name << "\n";
	std::cout << "Nickname: " << this->_nickname << "\n";
	std::cout << "Phone Number: " << this->_phone_number << "\n";
	std::cout << "Darkest Secret: " << this->_darkest_secret << "\n";
	std::cout << s::NOCOLOR;
	s::print_line(50, '*');
}

s::str Contact::get_first_name(void) const
{
	return this->_first_name;
}

s::str Contact::get_last_name(void) const
{
	return this->_last_name;
}

s::str Contact::get_nickname(void) const
{
	return this->_nickname;
}

s::str Contact::get_phone_number(void) const
{
	return this->_phone_number;
}

s::str Contact::get_darkest_secret(void) const
{
	return this->_darkest_secret;
}
