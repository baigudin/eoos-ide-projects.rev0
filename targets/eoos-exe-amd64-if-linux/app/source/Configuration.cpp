/** 
 * The configuration of a target processor.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2019, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Configuration.hpp"

namespace local
{
    /** 
     * Constructor.
     */     
    Configuration::Configuration() :
        stackSize   (0x00000000),
        #ifdef EOOS_NO_STRICT_MISRA_RULES        
        heapAddr    (0x00000000),
        heapSize    (0x00000000),
        #endif // EOOS_NO_STRICT_MISRA_RULES
        sourceClock (0x00000000),
        cpuClock    (0x00000000){
    }
}
    
