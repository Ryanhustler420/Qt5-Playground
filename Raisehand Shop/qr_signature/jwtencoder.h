#ifndef JWTENCODER_H
#define JWTENCODER_H

#include <QString>

class JwtEncoder {
public:
    virtual QString encode() = 0;
};

#endif // JWTENCODER_H
