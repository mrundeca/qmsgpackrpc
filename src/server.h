#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "service.h"

namespace MsgPackRpc{

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void serve(Service *service);

signals:

public slots:
};

} // namespace MsgPackRpc

#endif // SERVER_H
