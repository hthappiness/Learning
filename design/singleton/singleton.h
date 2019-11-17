#ifndef __MUTEX_H__  
    #define __MUTEX_h__  
    #include <pthread.h>  
      
    class Mutex{    
    private:  
            pthread_mutex_t m_mutex;  
        public:  
            Mutex();  
            virtual ~Mutex();  
        private:  
            Mutex(const Mutex&){};  
            Mutex& operator=(const Mutex&){};  
        public:  
            int lock();  
            int unlock();  
            int trylock();  
      
    };  
    #endif //__MUTEX_H__  
    //Mutex.h  
      
      
    #include "Mutex.h"  
      
    Mutex::Mutex()  
    {  
        pthread_mutex_init(&m_mutex, NULL);  
    }  
      
    Mutex::~Mutex()  
    {  
        pthread_mutex_destroy(&m_mutex);  
    }  
      
    int Mutex::lock()  
    {  
        return  pthread_mutex_lock(&m_mutex);  
    }  
      
    int Mutex::unlock()  
    {  
        return pthread_mutex_unlock(&m_mutex);  
    }  
      
    int Mutex::trylock()  
    {  
        return pthread_mutex_trylock(&m_mutex);  
    }  
    //Mutex.cpp  
      
    //单例类  
    #ifndef __SINGLETON_H__  
    #defile __SINGLETON_H__  
    #include "Mutex.h"  
    class Singleton{  
      
    public:  
        static Singleton *instance();  
        static void destroy();  
      
    private:  
        Singleton();  
        virtual ~Singleton();  
         Singleton(const Singleton&){};  
         Singleton& operator=(const Singleton&){};  
          
    private:  
        static Singleton *m_pInstance;  
        static Mutex m_Mutex;  
    };  
    #endif //__SINGLETON_H__  
    //Singleton.h  
      
      
    Singleton* Singleton::m_pInstance = NULL;  
    Mutex Singleton::m_Mutex;  
      
    Singleton::Singleton()  
    {  
    //do something  
    }  
      
    Singleton::~Singleton()  
    {  
    //do something  
    }  
      
    Singleton* Singleton::instance()  
    {  
         if(NULL == m_pInstance){  
              m_Mutex.lock();  
              if(NULL == m_pInstance){  
                   m_pInstance = new Singleton();  
              }  
              m_Mutex.unlock();  
         }  
         return m_pInstance;  
    }  
      
    void Singleton::destroy()  
    {  
         if(m_pInstance){  
              m_Mutex.lock();  
              if(m_pInstance){  
                   delete m_pInstance;  
                   m_pInstance = NULL;  
              }  
              m_Mutex.unlock();  
         }  
    }  