#include "timer.h"

Timer::Timer(QObject *parent) : QObject(parent)
{
    number = 0;
    timer.setInterval(1000);
    connect(&timer, &QTimer::timeout, this, &Timer::timeout);
}

void Timer::simple_message()
{
    qInfo() << "Thanks you for waiting!";
}

void Timer::wait_once(int ms)
{
    QTimer::singleShot(ms, this, &Timer::simple_message);
}

void Timer::wait_once(int ms, function<void()> callback)
{
    QTimer::singleShot(ms, this, [=](){callback();});
}

void Timer::startInterval()
{
    timer.start();
}

void Timer::timeout()
{
    number++;
    qInfo() << QTime::currentTime().toString(Qt::DateFormat::SystemLocaleLongDate);
    if (number == 5) {
        timer.stop();
        qInfo() << "Complete!";
    }
}

function<void ()> Timer::debounced(function<void ()> &f, int period)
{
    static auto created = high_resolution_clock::now();
    // "=" allow to pass by copy all used variables (created and period)
    // "&f" allow to pass by reference f variable
    function<void()> fn = [=,&f](){
        auto now = high_resolution_clock::now();
        if (duration_cast<milliseconds>(now - created).count() > period){
            f();
        }
    };
    return fn;

    // **************************
    // USE CASE:
    // **************************

    //    #include "utility/timer.h"

    //    Timer *t = new Timer();
    //    int x = 0;

    //    function<void()> f = [&x](){ qInfo() << "Working" << QString::number(x++); };
    //    auto dbf = t->debounced(f, 5000);

    //    for (int i = 0; i < 10; ++i) { dbf(); }
    //    if (x != 0) { throw std::runtime_error("Expected x not to change since it's debounced for 500ms"); }

    //    std::this_thread::sleep_for(milliseconds(6000));

    //    for (int i = 0; i < 10; ++i) { dbf(); }
    //    if (x != 10) { throw std::runtime_error("Expected x to be incremented 10 times"); }

}

