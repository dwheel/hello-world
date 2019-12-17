#include "telsimmotiondialog.h"
#include "ui_telsimmotiondialog.h"
#include "telemetrysimudialog.h"

telsimmotionDialog::telsimmotionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::telsimmotionDialog)
{
    ui->setupUi(this);
    mainTimer.setInterval(250);
    connect(&mainTimer,&QTimer::timeout,this,&telsimmotionDialog::onmainTimeLoop);
  //  mainTimer.start();
}

void telsimmotionDialog::onmainTimeLoop()
{
    bool a = false;
    a = ui -> LatLon -> text().contains(",");
    if(not a)
    {
        ui -> LatLon -> setText("Format must be lat,lon");
        ui ->stopMotion ->click();
    }
    else
    {
    QStringList lalo = (ui -> LatLon -> text()).split(",");
    QString flat = lalo[0];
    QString flon = lalo[1];
    double dflat = flat.toDouble() + .00000034;
    double dflon = flon.toDouble() + .00000034;
    QString dfa = QString::number(dflat, 'f', 8);
    QString dfo = QString::number(dflon, 'f', 8);
    QString writeback = dfa + "," + dfo;
    ui ->LatLon ->setText(writeback);
    double hdgtoFirstWin = ui -> dsHeading -> value();
    double speedtoFirstWin = ui ->dsSpeed -> value();
    double alttoFirstWin = ui -> dsAlt -> value();
    QString impmettoFirstWin = ui -> mphLabel -> text();
    double vspdtoFirstWin = ui ->mSecond -> value();
    QString positiontoFirstWindow = writeback;
    emit toFirstWindow(positiontoFirstWindow, hdgtoFirstWin, speedtoFirstWin, alttoFirstWin, vspdtoFirstWin);
    }

}

void telsimmotionDialog::toSecWindow(QString latlonFromTelSim)
{
    ui -> LatLon -> setText(latlonFromTelSim);
}


telsimmotionDialog::~telsimmotionDialog()
{
    delete ui;
}

void telsimmotionDialog::on_startMotion_clicked()
{
    mainTimer.start();
}

void telsimmotionDialog::on_stopMotion_clicked()
{
    mainTimer.stop();
}

void telsimmotionDialog::on_metricButton_clicked()
{
    ui->mphLabel->setText("KPH To Telsim Window");
    ui -> altLabel -> setText("METERS To Telsim Window");
    ui -> fsLabel -> setText("M/S To Telsim Window");
    emit metButtonPressed();
}

void telsimmotionDialog::on_imperialButton_clicked()
{
    ui->mphLabel->setText("MPH To Telsim Window");
    ui -> altLabel -> setText("FEET To Telsim Window");
    ui -> fsLabel -> setText("F/S To Telsim Window");
    emit impButtonPressed();
}
