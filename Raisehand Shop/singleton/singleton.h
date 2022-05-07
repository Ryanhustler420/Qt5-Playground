#ifndef _SINGLETON_H
#define _SINGLETON_H

#include <iostream>
#include <type_traits>
#include <QObject>

template <typename T, typename D = T>
class Singleton: public QObject
{
    friend D;
    static_assert(std::is_base_of<T, D>(), "T should be a base type for D");
public:
    static T& instance();

private:
    Singleton() = default;
    ~Singleton() = default;
    Singleton( const Singleton& ) = delete;
    Singleton& operator=( const Singleton& ) = delete;
};

template <typename T, typename D>
T& Singleton<T, D>::instance()
{
    static D inst;
    return inst;
}

#endif // _SINGLETON_H