#ifndef _KAREN_H_
# define _KAREN_H_

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>

namespace s
{
    typedef std::string str;
}

class Karen
{
private:
    void debug( void );
    void info( void );
    void warning( void );
    void error( void );
public:
    void complain( s::str level );
};


#endif