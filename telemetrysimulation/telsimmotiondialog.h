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
    void toFirstWindow(QString position, double hdg, double speed, double alt, double vspd);
    void metButtonPressed(); // to mainwindow changeToMetric()
    void impButtonPressed(); // to mainwindow changeText()

private slots:
    void on_startMotion_clicked();
    void on_stopMotion_clicked();
    void on_metricButton_clicked();
    void on_imperialButton_clicked();
};

#endif // TELSIMMOTIONDIALOG_H
