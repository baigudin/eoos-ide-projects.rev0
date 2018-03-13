/** 
 * The operating system modules memory allocator.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018, Sergey Baigudin
 */
#include "Allocator.hpp"

namespace global
{
    /**
     * Allocates memory.
     *
     * @param size number of bytes to allocate.
     * @return allocated memory address or a null pointer.
     */    
    void* Allocator::allocate(const size_t)
    {
        return NULL;
    }
    
    /**
     * Frees an allocated memory.
     *
     * @param ptr address of allocated memory block or a null pointer.
     */      
    void Allocator::free(void* const)
    {
    }
}   

