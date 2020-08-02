#include "response.h"

using MsgPackRpc::Response;

Response::Response()
    : Message(kResponse),
      msgid_(0)
{
    error_.setValue(nullptr);
    result_.setValue(nullptr);
}

Response::Response(const QVariant &error, const QVariant &result, quint32 msgid)
    : msgid_(msgid),
      error_(error),
      result_(result)
{
}

Response::Response(const QVariantList &content)
    : Message(kResponse),
      msgid_(content.at(1).toUInt()),
      error_(content.at(2)),
      result_(content.at(3))
{
}

QVariantList Response::toVariantList() const
{
    QVariantList list;
    list << type_ << msgid_ << error_;
    list.insert(list.size(), result_);
    return list;
}
