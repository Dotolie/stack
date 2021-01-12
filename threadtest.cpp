#include <QDebug>
#include <QDialog>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include "threadtest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE


#define ZMQ_ADD_SERVER      "tcp://127.0.0.1:3333"


ThreadTest::ThreadTest(QObject *parent) :
    QThread(parent)
{
    m_bRun = true;
    m_pDialog = (Dialog*)parent;
}

void ThreadTest::run()
{
    int nCount = 0;
    char szBuff[2048];
    QJsonDocument json_doc;

    zmq::context_t context(1);
    zmq::socket_t subscriber (context, ZMQ_SUB);
    subscriber.connect(ZMQ_ADD_SERVER);
    subscriber.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    while(m_bRun)
    {
        memset(szBuff, 0, sizeof(szBuff));
        subscriber.recv(szBuff, sizeof(szBuff), 0);
        json_doc = QJsonDocument::fromJson(szBuff);
        QJsonObject obj = json_doc.object();
        QJsonValue var = obj.value("data");
        QJsonArray arry = obj["data"].toArray();
 //       qDebug() << szBuff;



        qDebug() << "obj=" << obj;
        qDebug() << "var=" << var;
        qDebug() << "arry=" << arry;

        m_pDialog->setLabel(nCount);

        nCount++;
    }

    subscriber.close();
}
