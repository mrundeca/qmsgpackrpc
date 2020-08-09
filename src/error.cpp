#include "error.h"

using MsgPackRpc::Error;

Error::Error(const QString &message, int code)
    : message_(message),
      code_(code)
{
}

Error::Error(const QVariantList &content)
    : message_(content.value(0).toString()),
      code_(content.value(1).toInt())
{
}

QVariantList Error::toVariantList() const
{
    QVariantList list;
    list << message_ << code_;
    return list;
}
