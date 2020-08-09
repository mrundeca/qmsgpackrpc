#include <QCoreApplication>
#include <QTcpSocket>
#include "client.h"

using MsgPackRpc::Client;
using MsgPackRpc::PendingCall;
using MsgPackRpc::Response;
using MsgPackRpc::Error;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    QTcpSocket tcp_socket;
    tcp_socket.connectToHost("127.0.0.1", 12345);
    if (!tcp_socket.waitForConnected()) {
        return -ETIMEDOUT;
    }

    Client client(&tcp_socket);
    PendingCall *pending_call = client.call("add", QVariantList() << 1 << 2);
    QObject::connect(pending_call, &PendingCall::finished,
            &app, &QCoreApplication::quit);

    return app.exec();
}
