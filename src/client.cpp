#include "client.h"

using MsgPackRpc::Client;

Client::Client(QIODevice *device, QObject *parent)
    : AbstractSocket (device, parent)
{
}
