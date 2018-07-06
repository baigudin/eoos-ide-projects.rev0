/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.hpp"
#include "library.String.hpp"

namespace global
{
    /**
     * Starts executing an operating system main program.
     *
     * @return zero, or error code if an error has been occurred.
     */   
    int32 Program::start()
    {  
        library::String<char,  0, Allocator> str1("Hello");
        library::String<char, 10, Allocator> str2("World");        
        return 0;
    }
}
