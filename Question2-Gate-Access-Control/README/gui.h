#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include "gate.h"
class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = 0);
    ~Gui();
public slots:
    void buttonsPressed();
private:
    QLabel *gateDesLabel;
    QLabel *gateLabel;
    QPushButton *buttons[11];
    Gate *gate;
    QString pass;

};
#endif // GUI_H
