#ifndef SINGLETON_H
#define SINGLETON_H

template <class T>
class Singleton
{
public:
    static T& Instance ()
    {
        static T instance;
        return instance;
    }   
private:
    Singleton (const Singleton&);
    Singleton& operator= (const Singleton&);

};// class Singleton

#endif // SINGLETON_H
