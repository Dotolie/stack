#include <QDebug>
#include <QDialog>
#include "threadtest.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

ThreadTest::ThreadTest(QObject *parent) :
    QThread(parent)
{
    m_bRun = true;
    m_pDialog = (Dialog*)parent;
}

void ThreadTest::run()
{
    int high_count=0;
    int low_count;

    while(m_bRun)
    {
        msleep(1000);
        qDebug() << "h=" << high_count;
        m_pDialog->setLabel(high_count);

        high_count++;
    }

    emit FinishCount(high_count);
}
