/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"

/**
 * User thread class.
 */   
class TestThread : public Thread
{
  
public:
  
    /** 
     * Constructor.
     *
     * @param index an index of this thread.   
     */
    TestThread(int32 index) :
        index_   (index){
    }
    
    /**
     * Destructor.
     */
    virtual ~TestThread()
    {
    }
    
    /**
     * Starts executing an operating system prorgam in itsself context.
     *
     * @return zero, or error code if an error has been occurred.         
     */  
    virtual int32 start()
    {
        volatile uint32 v = 0;  
        volatile bool exe = true;
        while(exe) 
        {
            v = v + 1;
        }
        return 0;
    }
    
    /**
     * Returns size of thread stack.
     *
     * The method returns size of thread stack in bytes which should be allocated for the task.
     *
     * @return stack size in bytes.
     */  
    virtual int32 stackSize() const
    {
        return 0x80;
    }  
    
    /**
     * The index of this thread.
     */
    int32 index_;
  
};

/**
 * Starts executing an operating system main program.
 *
 * @return zero, or error code if an error has been occurred.
 */
int32 Program::start()
{
    // Create test threads
    TestThread thr1(1);
    TestThread thr2(2);  
    TestThread thr3(3);  
    // Check the threads
    if(!thr1.isConstructed() || 
       !thr2.isConstructed() || 
       !thr3.isConstructed()) return 1;
    // Start the threads
    thr1.start();  
    thr2.start();
    thr3.start();
    Thread::getCurrent().sleep(3000);
    // Wait the threads will be completed
    thr1.join();
    thr2.join();  
    thr3.join();    
    return 0;
}
