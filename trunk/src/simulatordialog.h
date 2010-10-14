#ifndef SIMULATORDIALOG_H
#define SIMULATORDIALOG_H

#include <QDialog>
#include "node.h"
#include <inttypes.h>
#include "pers.h"

namespace Ui {
    class simulatorDialog;
}

class simulatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit simulatorDialog(QWidget *parent = 0);
    ~simulatorDialog();

    void loadParams(EEGeneral *gg, ModelData *gm);

private:
    Ui::simulatorDialog *ui;
    Node *nodeLeft;
    Node *nodeRight;
    QTimer *timer;

    quint16 g_tmr10ms;
    qint16  chanOut[NUM_CHNOUT];
    qint16  calibratedStick[7];
    qint16  g_ppmIns[8];
    qint16  ex_chans[NUM_CHNOUT];
    qint8   trim[4];

    ModelData g_model;
    EEGeneral g_eeGeneral;

    void setupSticks();
    void setupTimer();
    void resizeEvent(QResizeEvent *event  = 0);

    void getValues();
    void setValues();
    void perOut();
    void centerSticks();

    bool keyState(EnumKeys key);
    bool getSwitch(int swtch, bool nc);

    int16_t intpol(int16_t x, uint8_t idx);
private slots:
    void timerEvent();


};

#endif // SIMULATORDIALOG_H
