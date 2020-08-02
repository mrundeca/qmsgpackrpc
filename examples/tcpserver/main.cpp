#include <QCoreApplication>
#include <QTcpServer>
#include <tcpserver.h>
#include <error.h>

using MsgPackRpc::Error;
using MsgPackRpc::Notification;
using MsgPackRpc::Response;
using MsgPackRpc::Request;
using MsgPackRpc::Service;
using MsgPackRpc::TcpServer;

class TestService : public Service
{
public:
    int add(int a, int b);
    QVariant add(const QVariant &a, const QVariant &b);
    Response dispatch(const Request &request) override;
};

int TestService::add(int a, int b)
{
    return a + b;
}

QVariant TestService::add(const QVariant &a, const QVariant &b)
{
    return a.toInt() + b.toInt();
}

Response TestService::dispatch(const Request &request)
{
    quint32 msgid = request.msgid();
    QString method = request.method();
    QVariantList params = request.params();

    if (method == "add") {
        QVariant result = add(params.at(0), params.at(1));
        QVariant error;
        error.setValue(nullptr);
        return Response(error, result, msgid);
    }

    Error error("Method not found", -32601);
    QVariant result;
    result.setValue(nullptr);
    return Response(error.toVariantList(), result, msgid);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestService service;
    TcpServer server;
    server.serve(&service);
    server.listen(QHostAddress("127.0.0.1"), 12345);
    return a.exec();
}
