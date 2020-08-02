#include "error.h"

using MsgPackRpc::Error;

Error::Error(const QString &message, int code)
    : message_(message),
      code_(code)
{
}

QVariantList Error::toVariantList() const
{
    QVariantList list;
    list << message_ << code_;
    return list;
}
