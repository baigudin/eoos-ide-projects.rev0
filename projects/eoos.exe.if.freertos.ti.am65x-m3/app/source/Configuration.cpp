/** 
 * The configuration of a target processor.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
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
        sourceClock (24768000),
        cpuClock    (400000000){
    }
}
    
