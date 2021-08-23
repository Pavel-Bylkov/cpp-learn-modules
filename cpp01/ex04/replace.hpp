#ifndef _REPLACE_H_
# define _REPLACE_H_

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>

namespace s
{
    typedef std::string str;
}


int replace_infile(s::str const & fname, s::str const & s1, s::str const & s2);

#endif