#ifndef _SINGLETON_OBJ_H
#define _SINGLETON_OBJ_H

#include <iostream>
#include <type_traits>
#include <QObject>

template <typename T, typename D = T>
class OSingleton: public QObject
{
    friend D;
    static_assert(std::is_base_of<T, D>(), "T should be a base type for D");
public:
    static T& instance();

private:
    OSingleton() = default;
    ~OSingleton() = default;
    OSingleton( const OSingleton& ) = delete;
    OSingleton& operator=( const OSingleton& ) = delete;
};

template <typename T, typename D>
T& OSingleton<T, D>::instance()
{
    static D inst;
    return inst;
}

#endif // _SINGLETON_OBJ_H
