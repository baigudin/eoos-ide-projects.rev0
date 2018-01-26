/** 
 * User main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Main.hpp"
#include "library.Memory.hpp"
#include "library.Buffer.hpp"
#include "library.String.hpp"

using namespace library;

/**
 * User method which will be stated as first.
 *
 * @return error code or zero.
 */   
int32 Main::main()
{
    String<char,0> s1 = "Goodbye, everyone!";
    ::api::String<char>& is1 = s1;
        
    String<char,0> s2 = "See you later.";    
    ::api::String<char>& is2 = s2;
        
    String<char,0> s3 = s1;
    ::api::String<char>& is3 = s3;
        
    String<char,0> s4 = "Goodbye, everyone!See you later."; 
    ::api::String<char>& is4 = s4;       
    
    s3 += is2; 
    
    if(s3.compare(is4) != 0)
    {
        return -1;
    }
    
    return 0;
}

