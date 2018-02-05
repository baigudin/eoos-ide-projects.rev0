/** 
 * User main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Main.hpp"
#include "Allocator.hpp"
#include "Interrupt.hpp"
#include "Mutex.hpp"
#include "Semaphore.hpp"
#include "System.hpp"
#include "Thread.hpp"
#include "library.Align.hpp"
#include "library.Buffer.hpp"
#include "library.CircularList.hpp"
#include "library.LinkedList.hpp"
#include "library.Memory.hpp"
#include "library.String.hpp"
#include "library.Toggle.hpp"


/**
 * User method which will be stated as first.
 *
 * @return error code or zero.
 */   
int32 Main::main()
{  
    int a = 7;
    for(int i=0; i<5; i++)
    {
        const int I = i + a;
        if(I > 8)
        {
            break;
        }
    }
    return 0;
}
