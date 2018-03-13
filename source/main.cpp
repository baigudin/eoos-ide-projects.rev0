/** 
 * The main file.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#include "Program.hpp"

/*
class A
{

public:

    A()
    {
    }
    
    virtual ~A()
    {
    }
    
    void add(int v)
    {
        int sum = getSum();
        sum += v;
        setSum(sum);
    }
    
private:

    virtual int getSum() = 0;
    
    virtual void setSum(int sum) = 0;    
    
};

class B : public A
{
    
public:
    
    B() :
        sum_ (0){
    }
    
    virtual ~B()
    {
    }
    
private:

    virtual int getSum()
    {
        return sum_;
    }
    
    virtual void setSum(int sum)
    {
        sum_ = sum;
    }
    
    int sum_;
};

class C : public B
{
    
public:
    
    C() : B()
    {
    }
    
    virtual ~C()
    {
    }
    
    void add(int v)
    {
        int sum = getSum();
        sum += v;
        setSum(sum);
    }    
    
private:
    
    virtual int getSum()
    {
        return 6;
    }   
    
    virtual void setSum(int sum)
    {
    }    

};
*/
/**
 * The main function.
 * 
 * The following tasks must be done before the function called:
 * 1. Stack has been set.
 * 2. CPU registers have been set.
 * 3. Run-time initialization has been completed.
 * 4. Global variables have been set.
 * 5. Global constructors have been called.
 * 
 * @return error code or zero.
 */   
int main()
{
    //B  b;
    //B& br = b;    
    //br.add(7);
    return ::global::Program::start();
}

