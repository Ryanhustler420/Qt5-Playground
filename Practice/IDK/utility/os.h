#ifndef OS_H
#define OS_H

#include "parents/commonsuperclass.h"
#include <QProcess>
#include <QSysInfo>

class Os : public CommonSuperClass
{
    Q_OBJECT
public:
    explicit Os(CommonSuperClass *parent = nullptr);
    bool openIPConfig();
    void systemInfo();

signals:

};

#endif // OS_H
