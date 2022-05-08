#ifndef SINGLETON_WIDGET_H
#define SINGLETON_WIDGET_H

#include <iostream>
#include <type_traits>
#include <functional>
#include <QWidget>

template <typename T, typename D = T>
class WSingleton: public QWidget
{
    friend D;
    static_assert(std::is_base_of<T, D>(), "T should be a base type for D");
public:
    static T& instance();

private:
    WSingleton() = default;
    ~WSingleton() = default;
    WSingleton( const WSingleton& ) = delete;
    WSingleton& operator=( const WSingleton& ) = delete;
};

template <typename T, typename D>
T& WSingleton<T, D>::instance()
{
    static D inst;
    return inst;
}

#endif // SINGLETON_WIDGET_H
