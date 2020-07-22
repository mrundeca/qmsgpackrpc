#include "response.h"

#include <qmsgpack/msgpack.h>

inline MsgPackRpc::Response::Response() :
    msgid_(0)
{
    error_.setValue(nullptr);
}

QByteArray MsgPackRpc::Response::pack() const
{
    QVariantList list;
    list << type_ << msgid_ << error_;
    list.insert(list.size(), result_);
    return MsgPack::pack(list);
}
