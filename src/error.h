#ifndef ERROR_H
#define ERROR_H

#include <QString>
#include <QVariantList>

namespace MsgPackRpc {

class Error
{
public:
    Error(const QString &message = QString(), int code = 0);
    Error(const QVariantList &content);

    QVariantList toVariantList() const;
    const QString &message() const { return message_; }
    int code() const { return code_; }
    bool isValid() const { return code_ != 0; }

protected:
    QString message_;
    int code_;
};

class ParseError : public Error
{
public:
    ParseError() : Error("Parse error", -EBADMSG) {}
};

class RequestError : public Error
{
public:
    RequestError() : Error("Invalid request", -EPROTO) {}
};

class NoMethodError : public Error
{
public:
    NoMethodError() : Error("Method not found", -ENOSYS) {}
};

class ParameterError : public Error
{
public:
    ParameterError() : Error("Invalid params", -EINVAL) {}
};

class InternalError : public Error
{
public:
    InternalError() : Error("Internal error", -EFAULT) {}
};

} // namespace MsgPackRpc

#endif // ERROR_H
