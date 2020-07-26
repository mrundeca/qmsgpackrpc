#include "pendingcall.h"
#include <QEventLoop>
#include <QTimer>

using MsgPackRpc::PendingCall;

PendingCall::PendingCall(QObject *parent) : QObject(parent)
{
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
