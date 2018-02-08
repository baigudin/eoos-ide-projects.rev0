/** 
 * User main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Main.hpp"
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
 * User method which will be stated as first.
 *
 * @return error code or zero.
 */   
int32 Main::main()
{  
    B  b;
    A& a = b;    
    a.set(6);
    return 0;
}
