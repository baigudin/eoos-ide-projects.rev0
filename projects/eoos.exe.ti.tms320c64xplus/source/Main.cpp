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
    Buffer<int>*  b = new Buffer<int>(5);
    String<char>* s = new String<char>("Hello, world!");

    delete s;    
    delete b;
    return 0;
}

