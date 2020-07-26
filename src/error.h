#ifndef ERROR_H
#define ERROR_H

#include <QString>

namespace MsgPackRpc {

class Error
{
public:
    Error();

private:
    QString message_;
    int code_;
};

} // namespace MsgPackRpc

#endif // ERROR_H
