#include "addingmode.h"
#include "ui_addingmode.h"
#include "eventplanner.h"
//#include <QHBoxLayout>
#include <QDebug>

AddingMode::AddingMode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AddingMode)
{
    ui->setupUi(this);
    setWindowTitle("Adding Mode");
    person_name = "";
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    /*
    Load Event class here, and use the event's name to make a List
    Using: ui->listWidget->addItem(QString Event_Name); to Make List_Item
    Example:
    */
    ui->listWidget->addItem(QString::number(23) + ". Event_TT");
    ui->listWidget->addItem(QString::number(2) + ". Other example");
    ui->listWidget->item(0)->setBackgroundColor(Qt::red);
    ui->listWidget->item(1)->setTextColor(Qt::blue);
   // ui->listWidget->item(0)->setSizeHint(23);
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
AddingMode::~AddingMode()
{
    delete ui;
}

void AddingMode::on_pushButton_2_clicked()
{
    this->hide();
    person_name = "";
    EventName = "";
    emit showEventPlanner();
}

void AddingMode::receiveshow()
{this->show();}

void AddingMode::on_lineEdit_textChanged(const QString &arg1)
{
    EventName = arg1; // get input
}

void AddingMode::on_pushButton_clicked()
{
    //search name

}

void AddingMode::on_pushButton_3_clicked()
{
    //search free days
}

void AddingMode::on_spinBox_valueChanged(int arg1)
{ // (if)-(else if)-(else) use to check "fake date .e.g: Feb 30, Nov 66"
    if((arg1 == 4)||(arg1 == 6)||(arg1 == 9)||(arg1 == 11))
    {ui->spinBox_2->setMaximum(30);}
    else if(arg1 == 2)
    {ui->spinBox_2->setMaximum(28);}
    else
    {ui->spinBox_2->setMaximum(31);}
    month = arg1;
}

void AddingMode::on_spinBox_2_valueChanged(int arg1)
{
    day = arg1;
}


void AddingMode::on_listWidget_doubleClicked(const QModelIndex &index)
{
    int index_of_list = 0;
    index_of_list = index.row();
    qDebug() << index <<index_of_list;
    switch(QMessageBox::question(this,"Adding","Do you want to join it?",
                                 QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Cancel)){
    case QMessageBox::Ok:
        //After you click Ok,this case will work, it means customer will be adding to an event
        // and the event_list will return an index and you can get the position(index_of_list)
        // it should be the same as the position in the Data_List
        break;
    case QMessageBox::Cancel:
        break;
    default:
        break;}
}

void AddingMode::on_lineEdit_2_textChanged(const QString &arg1)
{
    person_name = arg1;
}

void AddingMode::on_pushButton_4_clicked() // this button will be optional
{
    // reload list, and reload data
}
