/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.hpp"
#include "Thread.hpp"
#include "Mutex.hpp"
#include "Semaphore.hpp"

/**
 * User thread class.
 */   
class TestThread : public Thread
{
  
public:
    
    /** 
     * Constructor.
     *
     * @param sem   a semaphore of critical area.
     * @param index an index of this thread.   
     * @param time  some working time in critical section in seconds.  
     * @param name  a name of this thread.
     */
    TestThread(::api::Semaphore& sem, int32 index, int32 permits, int32 time) :
        sem_     (sem),
        index_   (index),    
        permits_ (permits),    
        time_    (time * 1000){
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
        volatile bool exe = true;
        while(exe) 
        {
            sem_.acquire(permits_);
            Thread::sleep(time_);
            sem_.release(permits_);
        }
        return 0;
    }
    
    /**
     * The semaphore of critical area.
     */
    ::api::Semaphore& sem_;
    
    /**
     * The index of this thread.
     */
    int32 index_;
    
    /**
     * The permits of this thread.
     */
    int32 permits_;    
    
    /**
     * The working time in critical area in seconds.
     */
    int32 time_;

};

/**
 * Starts executing an operating system main program.
 *
 * @return zero, or error code if an error has been occurred.
 */   
int32 Program::start()
{
    // Create and check one semaphore of all threads
    Semaphore sem(2, true);
    if(!sem.isConstructed()) return 1;
    // Create test threads
    TestThread thr1(sem, 1, 2, 5);
    TestThread thr2(sem, 2, 1, 2);  
    TestThread thr3(sem, 3, 1, 1);  
    // Check the threads
    if(!thr1.isConstructed() || 
       !thr2.isConstructed() || 
       !thr3.isConstructed()) return 1;
    // Start the threads
    thr1.start();  
    thr2.start();
    thr3.start();  
    // Wait the threads will be completed
    thr1.join();
    thr2.join();  
    thr3.join();    
    return 0;
}
