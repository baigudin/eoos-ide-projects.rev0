/** 
 * User main class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2017, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Main.hpp"

class IO
{

public:

    virtual ~IO()
    {
    }
    
    virtual int32 getError() = 0;
    
    virtual int32 getConst() const = 0;    

};

class IC
{

public:

    virtual ~IC()
    {
    }
    
    virtual int32 getMultiplier() const = 0;

};

class O : public IO
{

public:


    O(int32 v) :
        v_ (v){
    }
    
    virtual ~O()
    {
    }
    
    virtual int32 getError()
    {
        return v_;    
    }
    
    virtual int32 getConst() const
    {
        return 2;
    }
    
private:
    
    int32 v_;
};

class C : public O, public IC
{

public:

    C(int32 v) : O (v)
    {
    }
    
    virtual ~C()
    {
    }
    
    virtual int32 getMultiplier() const
    {
        return 3;
    }    

private:
    

};


/**
 * User method which will be stated as first.
 *
 * @return error code or zero.
 */   
int32 Main::main()
{
    C c(7);
    IC& ic = c;    
    IO& io = c;        
    int32 err = io.getError();
    int32 con = io.getConst();    
    int32 mul = ic.getMultiplier();    
    return err * con * mul;
}
