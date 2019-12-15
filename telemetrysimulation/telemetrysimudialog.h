#ifndef TELEMETRYSIMUDIALOG_H
#define TELEMETRYSIMUDIALOG_H

#include <QDialog>
#include <QTimer>
#include "telsimmotiondialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class telemetrysimuDialog; }
QT_END_NAMESPACE

class telemetrysimuDialog : public QDialog
{
    Q_OBJECT

public:
    telemetrysimuDialog(QWidget *parent = nullptr);
    ~telemetrysimuDialog();

private:
    Ui::telemetrysimuDialog *ui;
    QTimer mainTimer;
    telsimmotionDialog *dlg;
 //   telemetrysimuDialog *frstwin;


protected slots:
        void onmainTimeLoop();

public slots:
  //      void toFirstWindow(QString position, double hdg, double speed, double alt, QString impmet, double vspd); // //////////////////


private slots:
        void on_startMotion_clicked();

        void on_LatLon_textChanged(const QString &arg1);

signals:
    void toMotnEmu(QString msgToMotionWindow);

};
#endif // TELEMETRYSIMUDIALOG_H
