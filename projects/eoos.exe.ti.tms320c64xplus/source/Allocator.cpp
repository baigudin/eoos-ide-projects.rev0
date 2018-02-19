/** 
 * The operating system modules memory allocator.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018, Sergey Baigudin
 */
#include "global.Allocator.hpp"
#include "global.System.hpp"

namespace global
{

    /**
     * Pointer to constructed the operating systenm heap memory.
     */
    static ::api::Heap* heap_ = ::api::Constant::NULL;
    
    /**
     * Allocates memory.
     *
     * @param size number of bytes to allocate.
     * @return allocated memory address or a null pointer.
     */    
    void* Allocator::allocate(const size_t size)
    {
        if(heap_ == NULL)
        {
            heap_ = &System::call().getHeap();
        }
        return heap_->allocate(size, NULL);
    }
    
    /**
     * Frees an allocated memory.
     *
     * @param ptr address of allocated memory block or a null pointer.
     */      
    void Allocator::free(void* const ptr)
    {
        if(heap_ != NULL)
        {
            heap_->free(ptr);
        }
    }
}   

