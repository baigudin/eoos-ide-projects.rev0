/** 
 * Entry point to an operating system main program.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.hpp"
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

class A
{

public:

    A() : v_ (0)
    {
    }
    
    virtual ~A()
    {
    }    
    
    virtual void set(int32 v) = 0;

private:

    int32 v_;    

};

void A::set(int32 v)
{
    v_ = v;
}


class B : public A
{

public:

    B() : A()
    {
    }
    
    virtual ~B()
    {
    }    
    
    virtual void set(int32 v)
    {
        this->A::set(v);
    }

};

/**
 * Starts executing an operating system main program.
 *
 * @return zero, or error code if an error has been occurred.
 */   
int32 Program::start()
{  
    B  b;
    A& a = b;    
    a.set(6);
    return 0;
}
