/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.hpp"

#include "library.Align.hpp"
#include "library.Buffer.hpp"

namespace global
{
    using namespace library;

    /**
     * Tests the Align class interface.
     */
    template<typename T>
    bool testAlign(const T& illegal)
    {
        Align<T> o1(5U);
        Align<T> o2(o1);
        Align<T> o3;        
        if( o2.equal(o1) || o2 == o3 || o1 != o2 )
        {
            if( o3.equal(7) )
            {
                o3 = 15;
            }
            o2 = o3;
        }
        bool res;
        const T v = o1;
        if( v == illegal )
        {
            res = false;
        }
        else
        {
            res = true;
        }
        return res;
    }
    
    /**
     * Tests the Buffer class interface.
     */
    template<typename T>
    T testIllegalValue(api::IllegalValue<T>& obj, const T& val)
    {
        if( obj.isIllegal(val) == true )
        {
            obj.setIllegal(val);            
        }
        return obj.getIllegal();
    }
    
    /**
     * Tests the Buffer class interface.
     */
    template<typename T>
    bool testBuffer(const T& illegal)
    {
        T buf[7];
        // Static buffer class        
        const Buffer<T,7> bs0;         
        const Buffer<T,5> bs1(illegal);
        // Dynamic buffer class.
        const Buffer<T,0> bd0(7);
        const Buffer<T,0> bd1(7, illegal);        
        const Buffer<T,0> bd2(7, buf);
        Buffer<T,0> bd3(7, buf, illegal);        
          /*     
        const T ill = testIllegalValue<T>(bd3, 3);
        if(ill == illegal)
        {
            return true;
        }
        else
        {
            return false;
        }
        */
        return false;
    }
    

    /**
     * Starts executing an operating system main program.
     *
     * "library.Align.hpp"
     * "library.Buffer.hpp"
     * "library.CircularList.hpp"
     * "library.Heap.hpp"
     * "library.LinkedList.hpp"
     * "library.Memory.hpp"
     * "library.Stack.hpp"
     * "library.String.hpp"
     * "library.Toggle.hpp"
     *
     * @return zero, or error code if an error has been occurred.
     */   
    int32 Program::start()
    {  
        do
        {
            // Test the Align interface
            if( not testAlign<uint32>(7U) )
            {
                break;
            }
            // Test the Buffer interface            
            if( not testBuffer<int32>(-1) )
            {
                break;
            }
        }
        while(false);
        return 0;
    }
}
    
