#include "telemetrysimudialog.h"
#include "ui_telemetrysimudialog.h"

telemetrysimuDialog::telemetrysimuDialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::telemetrysimuDialog)
{
    ui->setupUi(this);
    mainTimer.setInterval(100);
    connect(&mainTimer,&QTimer::timeout,this,&telemetrysimuDialog::onmainTimeLoop);
    mainTimer.start();
}


void telemetrysimuDialog::onmainTimeLoop()
{



}

void telemetrysimuDialog::fromSecondWindow(QString position, double hdg, double speed, double alt, double vspd)
{
ui -> LatLon -> setText(position);
ui -> dsHeading -> setValue(hdg);
ui -> dsSpeed -> setValue(speed);
ui -> dsAlt -> setValue(alt);
ui -> dsFs -> setValue(vspd);
}


telemetrysimuDialog::~telemetrysimuDialog()
{
    delete ui;
}


void telemetrysimuDialog::on_startMotion_clicked()
{
    motionWindow = new telsimmotionDialog(this);
    mainTimer.start();
    connect(this,&telemetrysimuDialog::toMotnEmu,motionWindow,&telsimmotionDialog::toSecWindow);
    connect(motionWindow,&telsimmotionDialog::toFirstWindow,this,&telemetrysimuDialog::fromSecondWindow);
    QObject::connect(motionWindow, SIGNAL(metButtonPressed()),this, SLOT(changeToMetricText()));
    QObject::connect(motionWindow, SIGNAL(impButtonPressed()),this, SLOT(changeToImperialText()));
    QString sendToMotSim = ui ->LatLon -> text();
    emit toMotnEmu(sendToMotSim);
    mainTimer.stop();
    motionWindow->show();

}

void telemetrysimuDialog::on_LatLon_textChanged(const QString &arg1)
{
    QString sendToMotSim = ui ->LatLon -> text();
    emit toMotnEmu(sendToMotSim);
}

void telemetrysimuDialog::changeToMetricText()
{
    ui->mphLabel->setText("KPH From Motion Emulatior");
    ui -> altLabel -> setText("METERS From Motion Emulatior");
    ui -> fsLabel -> setText("M/S From Motion Emulatior");
}

void telemetrysimuDialog::changeToImperialText()
{
    ui->mphLabel->setText("MPH From Motion Emulatior");
    ui -> altLabel -> setText("FEET From Motion Emulatior");
    ui -> fsLabel -> setText("F/S From Motion Emulatior");

}
