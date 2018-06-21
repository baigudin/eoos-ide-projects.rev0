#ifndef MISRA_TEST_HPP_
#define MISRA_TEST_HPP_

namespace user
{

    class Interface
    {
    public:
        
        virtual ~Interface(){}
        
        virtual bool isConstructed() const = 0;        
    
    };
    
    //------------------------------    
    template <class T>
    class Object : public Interface
    {
        
    public:
    
        Object(const T v) : v_(v)
        {
        }
        
        virtual ~Object(){}
        
        int32 get() const
        {
            return v_;
        }                
        
    private:
    
        T v_;        
    
    };
    
    //------------------------------
    template <typename T1, typename T2>
    class Test : public Object<T2>
    {
        typedef Object<T2> Parent;
    
    public:
    
        explicit Test(const T1 v1, const T2 v2) : Parent(v2), v1_ (v1)
        {
        }
        
        virtual ~Test()
        {
        }
   
        virtual bool isConstructed() const
        {
            return true;
        }
        
        int32 get1() const
        {
            return v1_;
        }        
        
        int32 get2() const
        {
            return this->get();
        }
    
    private:
    
        T1 v1_;   
    
    };
    
    int32 execute()
    {
        const user::Test<int32,int32> t(1, 2);
        return t.get1() + t.get2();
    }    
}
#endif // MISRA_TEST_HPP_

