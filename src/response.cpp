#include "response.h"

#include <qmsgpack/msgpack.h>

using MsgPackRpc::Response;

inline Response::Response()
    : Message(kResponse),
      msgid_(0)
{
    error_.setValue(nullptr);
    result_.setValue(nullptr);
}

QByteArray Response::pack() const
{
    QVariantList list;
    list << type_ << msgid_ << error_;
    list.insert(list.size(), result_);
    return MsgPack::pack(list);
}
