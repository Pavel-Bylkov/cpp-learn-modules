#ifndef PHONE_HPP
# define  PHONE_HPP

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		void add(void);
		void search(void);
		int count;
	private:
		void _print_contact(int index);
		void _print_column(s::str field);
		void _print_tabl(void);
		int _input_index(void);
		Contact _book[8];
};

#endif