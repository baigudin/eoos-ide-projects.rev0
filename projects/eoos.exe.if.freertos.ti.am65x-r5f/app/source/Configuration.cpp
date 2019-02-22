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
        // 25 MHz crystal 0 clocks the SoC by using WKUP_HFOSC0
        sourceClock (25000000),
        cpuClock    (400000000){
    }
}
    
