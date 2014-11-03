#include "everything.h"
#include "ui_everything.h"
#include "Searcher.h"
#include <QDesktopServices>
EveryThing::EveryThing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EveryThing)
{
    ui->setupUi(this);
    this->setFixedSize(400,311);
}

EveryThing::~EveryThing()
{
    delete ui;
}

void EveryThing::on_pushButton_clicked()
{
   ui->listWidget->clear();
   searcher *search=new searcher();
  // search->Rsearch("/home/");
 //  qDebug()<<"creating index file";
   //search->CreateIndex("index.idx");
   QFileInfoList lists=search->SearchText(ui->lineEdit->text());
   foreach(QFileInfo file,lists)
   {
      ui->listWidget->addItem(file.fileName());
   }
}


void EveryThing::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    QString filename=ui->listWidget->currentItem()->text();

}
