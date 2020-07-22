#include "notification.h"

#include <qmsgpack/msgpack.h>

QByteArray MsgPackRpc::Notification::pack()
{
    QVariantList list;
    list << type_ << method_;
    list.insert(list.size(), params_);
    return MsgPack::pack(list);
}
