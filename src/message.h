#ifndef QMSGPACKRPC_MESSAGE_H
#define QMSGPACKRPC_MESSAGE_H

#include <QByteArray>
#include <QVariantList>
#include "error.h"

namespace MsgPackRpc
{

const quint8 kRequest = 0;
const quint8 kResponse = 1;
const quint8 kNotification = 2;

class Message
{
public:
    Message() : type_(kRequest) {}
    Message(quint8 type) : type_(type) {}
    virtual ~Message();
    virtual QVariantList toVariantList() const = 0;

protected:
    quint8 type_;
};

class Request : public Message
{
public:
    Request() : Message(kRequest), msgid_(0) {}
    Request(const QVariantList &content);
    Request(quint32 msgid, const QString &method, const QVariantList &params);

    quint32 msgid() const { return msgid_; }
    const QString &method() const { return method_; }
    const QVariantList &params() const { return params_; }

    QVariantList toVariantList() const override;

private:
    quint32 msgid_;
    QString method_;
    QVariantList params_;
};

class Response : public Message
{
public:
    Response();
    Response(quint32 msgid, const QVariant &result, const Error &error = Error());
    Response(const QVariantList &content);

    quint32 msgid() const { return msgid_; }
    Error error() const { return error_; }
    QVariant result() const { return result_; }

    QVariantList toVariantList() const override;

private:
    quint32 msgid_;
    Error error_;
    QVariant result_;
};

class Notification : public Message
{
public:
    Notification() : Message(kNotification) {}
    Notification(const QVariantList &content);
    Notification(const QString &method, const QVariantList &params);

    const QString &method() const { return method_; }
    const QVariantList &params() const { return params_; }

    QVariantList toVariantList() const override;

private:
    QString method_;
    QVariantList params_;
};

}; // namespace MsgPackRpc

#endif // QMSGPACKRPC_MESSAGE_H
