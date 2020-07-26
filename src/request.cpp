#include "request.h"

#include <qmsgpack/msgpack.h>

using MsgPackRpc::Request;

Request::Request(const QVariantList &content)
    : Message(kRequest),
      msgid_(content.at(1).toUInt()),
      method_(content.at(2).toString()),
      params_(content.at(3).toList())
{
}

QByteArray Request::pack() const
{
    QVariantList list;
    list << type_ << msgid_ << method_;
    list.insert(list.size(), params_);
    return MsgPack::pack(list);
}
