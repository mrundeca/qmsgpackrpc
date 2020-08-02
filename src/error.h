#ifndef ERROR_H
#define ERROR_H

#include <QString>
#include <QVariantList>

namespace MsgPackRpc {

class Error
{
public:
    Error(const QString &message = QString(), int code = 0);

    QVariantList toVariantList() const;

private:
    QString message_;
    int code_;
};

} // namespace MsgPackRpc

#endif // ERROR_H
