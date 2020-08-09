#include "pendingcall.h"
#include <QEventLoop>
#include <QTimer>

using MsgPackRpc::PendingCall;

PendingCall::PendingCall(const MsgPackRpc::Request &request, QObject *parent)
    : QObject(parent),
      request_(request)
{
}

void PendingCall::finishRequest(const Response &response)
{
    response_ = response;
    emit finished();
}

bool PendingCall::waitForFinished(int msecs)
{
    QTimer timer;
    timer.setSingleShot(true);
    QEventLoop loop;
    connect(this, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
    timer.start(msecs);
    loop.exec();

    if (timer.isActive()) return false;
    else return true;
}
