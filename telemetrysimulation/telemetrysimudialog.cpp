#include "telemetrysimudialog.h"
#include "ui_telemetrysimudialog.h"
//#include "telsimmotiondialog.cpp"

telemetrysimuDialog::telemetrysimuDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::telemetrysimuDialog)
{
    ui->setupUi(this);
    mainTimer.setInterval(100);
    connect(&mainTimer,&QTimer::timeout,this,&telemetrysimuDialog::onmainTimeLoop);
 //   mainTimer.start();
}

void telemetrysimuDialog::onmainTimeLoop()
{

}

//void telsimmotionDialog::toFirstWindow(QString position, double hdg, double speed, double alt, QString impmet, double vspd)
//{

//}


telemetrysimuDialog::~telemetrysimuDialog()
{
    delete ui;
}


void telemetrysimuDialog::on_startMotion_clicked()
{
    dlg = new telsimmotionDialog(this);
 //   frstwin = new telemetrysimuDialog(this);
    mainTimer.start();
    connect(this,&telemetrysimuDialog::toMotnEmu,dlg,&telsimmotionDialog::toSecWindow);
    QString sendToMotSim = ui ->LatLon -> text();
    emit toMotnEmu(sendToMotSim);
    mainTimer.stop();
    dlg->show();

}

void telemetrysimuDialog::on_LatLon_textChanged(const QString &arg1)
{
    QString sendToMotSim = ui ->LatLon -> text();
    emit toMotnEmu(sendToMotSim);
}
