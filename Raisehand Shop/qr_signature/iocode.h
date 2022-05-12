#ifndef IOCODE_H
#define IOCODE_H

#include <QString>

class IOCode {
public:
    virtual QString getEncryptedData() = 0;
    virtual QList<int> getActionTypes() = 0;

public:
    typedef struct ActionType {
        int IMPORT = 1;
        int BOOKMARK = 2;
        int SEARCH = 3;
        int BILLING = 4;
    } _action_type;
};

#endif // IOCODE_H
