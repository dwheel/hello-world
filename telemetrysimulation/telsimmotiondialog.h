#ifndef TELSIMMOTIONDIALOG_H
#define TELSIMMOTIONDIALOG_H

#include <QDialog>
#include <QTimer>
// #include "telemetrysimudialog.h"

namespace Ui {
class telsimmotionDialog;
}

class telsimmotionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit telsimmotionDialog(QWidget *parent = nullptr);
    ~telsimmotionDialog();

private:
    Ui::telsimmotionDialog *ui;
    QTimer mainTimer;
  //  telemetrysimuDialog *frstwin;

protected slots:
        void onmainTimeLoop();

public slots:
    void toSecWindow(QString latlonFromTelSim);

signals:
    void toFirstWindow(QString position, double hdg, double speed, double alt, QString impmet, double vspd);

private slots:
    void on_startMotion_clicked();
    void on_stopMotion_clicked();
};

#endif // TELSIMMOTIONDIALOG_H
