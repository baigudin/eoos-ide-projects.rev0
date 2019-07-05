/** 
 * The configuration of a target processor.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2016-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Configuration.hpp"

namespace local
{
    /** 
     * Constructor.
     */     
    Configuration::Configuration() :
        stackSize   (0x00002000),
        #ifdef EOOS_NO_STRICT_MISRA_RULES        
        heapAddr    (0x00881000),
        heapSize    (0x0007f000),
        #endif // EOOS_NO_STRICT_MISRA_RULES
        sourceClock (50000000),
        cpuClock    (1000000000){
    }
}
    
