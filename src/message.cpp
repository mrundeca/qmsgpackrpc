#include "message.h"

using MsgPackRpc::Message;
using MsgPackRpc::Request;
using MsgPackRpc::Response;
using MsgPackRpc::Notification;

Message::~Message()
{
}

Request::Request(const QVariantList &content)
    : Message(kRequest),
      msgid_(content.at(1).toUInt()),
      method_(content.at(2).toString()),
      params_(content.at(3).toList())
{
}

Request::Request(quint32 msgid, const QString &method, const QVariantList &params)
    : Message(kRequest),
      msgid_(msgid),
      method_(method),
      params_(params)
{
}

QVariantList Request::toVariantList() const
{
    QVariantList list;
    list << type_ << msgid_ << method_;
    list.insert(list.size(), params_);
    return list;
}

Response::Response()
    : Message(kResponse),
      msgid_(0)
{
    result_.setValue(nullptr);
}

Response::Response(quint32 msgid, const QVariant &result, const Error &error)
    : Message(kResponse),
      msgid_(msgid),
      error_(error),
      result_(result)
{
}

Response::Response(const QVariantList &content)
    : Message(kResponse),
      msgid_(content.at(1).toUInt()),
      error_(content.at(2).toList()),
      result_(content.at(3))
{
}

QVariantList Response::toVariantList() const
{
    QVariantList list;
    list << type_ << msgid_;

    if (error_.isValid()) {
        list.insert(list.size(), error_.toVariantList());
    } else {
        // no error
        QVariant var;
        var.setValue(nullptr);
        list << var;
    }

    list.insert(list.size(), result_);
    return list;
}

Notification::Notification(const QVariantList &content)
    : Message(kNotification),
      method_(content.at(1).toString()),
      params_(content.at(2).toList())
{
}

QVariantList Notification::toVariantList() const
{
    QVariantList list;
    list << type_ << method_;
    list.insert(list.size(), params_);
    return list;
}
