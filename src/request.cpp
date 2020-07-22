#include "request.h"

#include <qmsgpack/msgpack.h>

inline MsgPackRpc::Request::Request() :
    msgid_(0)
{
}

QByteArray MsgPackRpc::Request::pack() const
{
    QVariantList list;
    list << type_ << msgid_ << method_;
    list.insert(list.size(), params_)
    return MsgPack::pack(list);
}
