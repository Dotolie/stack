#ifndef THREADTEST_H
#define THREADTEST_H
#include <QThread>
#include "dialog.h"

class ThreadTest : public QThread
{
    Q_OBJECT
public:
    explicit ThreadTest(QObject *parent = 0);

private:
    void run();
    bool m_bRun;
    Dialog *m_pDialog;

signals:
    void FinishCount(const int value);

public slots:

};

#endif // THREADTEST_H
