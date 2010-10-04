#ifndef MODELEDIT_H
#define MODELEDIT_H

#include <QDialog>
#include "pers.h"

namespace Ui {
    class ModelEdit;
}

class ModelEdit : public QDialog
{
    Q_OBJECT

public:
    explicit ModelEdit(EEPFILE *eFile, uint8_t id, QWidget *parent = 0);
    ~ModelEdit();

private:
    Ui::ModelEdit *ui;
    EEPFILE *eeFile;

    EEGeneral g_eeGeneral;
    ModelData g_model;
    int       id_model;

    void updateSettings();
    void tabModelEditSetup();
    void tabExpo();
    void tabMixes();
    void tabLimits();
    void tabCurves();
    void tabSwitches();
    void tabTrims();

signals:
    void modelValuesChanged();


private slots:
    void curvePointEdited();
    void limitEdited();
    void switchesEdited();
    void expoEdited();
    void mixesEdited();

    void on_spinBox_S1_valueChanged(int value);
    void on_spinBox_S2_valueChanged(int value);
    void on_spinBox_S3_valueChanged(int value);
    void on_spinBox_S4_valueChanged(int value);

    void on_bcRUDChkB_toggled(bool checked);
    void on_bcELEChkB_toggled(bool checked);
    void on_bcTHRChkB_toggled(bool checked);
    void on_bcAILChkB_toggled(bool checked);
    void on_bcP1ChkB_toggled(bool checked);
    void on_bcP2ChkB_toggled(bool checked);
    void on_bcP3ChkB_toggled(bool checked);

    void on_thrExpoChkB_toggled(bool checked);
    void on_thrTrimChkB_toggled(bool checked);
    void on_ppmDelaySB_editingFinished();
    void on_numChannelsSB_editingFinished();
    void on_timerValTE_editingFinished();
    void on_protocolCB_currentIndexChanged(int index);
    void on_pulsePolCB_currentIndexChanged(int index);
    void on_trimSWCB_currentIndexChanged(int index);
    void on_trimIncCB_currentIndexChanged(int index);
    void on_timerDirCB_currentIndexChanged(int index);
    void on_timerModeCB_currentIndexChanged(int index);
    void on_modelNameLE_editingFinished();
    void on_modelNameLE_textEdited(QString txt);
    void on_tabWidget_currentChanged(int index);
};

#endif // MODELEDIT_H