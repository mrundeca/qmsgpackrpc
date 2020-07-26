#include "notification.h"
#include <qmsgpack/msgpack.h>

using MsgPackRpc::Notification;

Notification::Notification(const QVariantList &content)
    : Message(kNotification),
      method_(content.at(1).toString()),
      params_(content.at(2).toList())
{
}

QByteArray Notification::pack() const
{
    QVariantList list;
    list << type_ << method_;
    list.insert(list.size(), params_);
    return MsgPack::pack(list);
}
