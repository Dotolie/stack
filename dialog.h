#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setLabel(int num);

private slots:
    void on_pb_vibration_clicked();

    void on_pb_settings_clicked();

    void on_pb_back_clicked();

    void on_pb_setitem_clicked();

    void on_pb_gateway_clicked();

    void on_pb_datatrend_clicked();

    void on_pb_ok_gateway_clicked();

    void on_pb_ok_trend_clicked();

    void on_pb_ok_item_clicked();

    void on_pb_factoryReset_clicked();

private:
    Ui::Dialog *ui;
    void resizeEvent(QResizeEvent*);
    QThread *m_pThread;

};
#endif // DIALOG_H
