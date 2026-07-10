#include "gui.h"
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

Gui::Gui(QWidget *parent)
    : QWidget(parent),
    gateDesLabel(new QLabel),
    gateLabel(new QLabel("Gate:")),
    gate(new Gate("CXX : Gate 90",9846))
{
    setWindowTitle("Access Control");

    qDebug() << "Password:9846(for testing)";

    gateDesLabel->setText(gate->getDescription());
    QStringList buttonList;
            buttonList.append("0");
            buttonList.append("1");
            buttonList.append("2");
            buttonList.append("3");
            buttonList.append("4");
            buttonList.append("5");
            buttonList.append("6");
            buttonList.append("7");
            buttonList.append("8");
            buttonList.append("9");
            buttonList.append("#");


    for(int i = 0 ; i < 11 ; i++){
        buttons[i] = new QPushButton(buttonList[i]);
        connect(buttons[i],SIGNAL(clicked()),this,SLOT(buttonsPressed()));
}


    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(gateLabel,0,0);
    mainLayout->addWidget(gateDesLabel,0,1);
    mainLayout->addWidget(buttons[0],1,0);
    mainLayout->addWidget(buttons[1],1,1);
    mainLayout->addWidget(buttons[2],1,2);
    mainLayout->addWidget(buttons[3],2,0);
    mainLayout->addWidget(buttons[4],2,1);
    mainLayout->addWidget(buttons[5],2,2);
    mainLayout->addWidget(buttons[6],3,0);
    mainLayout->addWidget(buttons[7],3,1);
    mainLayout->addWidget(buttons[8],3,2);
    mainLayout->addWidget(buttons[9],4,0);
    mainLayout->addWidget(buttons[10],4,1);

    setLayout(mainLayout);




}

Gui::~Gui() {

    delete gate;
}

void Gui::buttonsPressed()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString btnText = button->text();

    if(btnText == "0"|| btnText == "1"|| btnText == "2"
        || btnText == "3"|| btnText == "4"|| btnText == "5"
        || btnText == "6" || btnText == "7"  || btnText == "8"
        || btnText == "9"
        )
        pass += btnText;
    else
    {
        if(gate->checkPassword(pass.toInt()))
            QMessageBox::information(this,"Password correct","Password entered is correct");
        else{
            pass = "";
            QMessageBox::warning(this,"Password incorrect","Password entered is incorrect");
    }

    }



}

