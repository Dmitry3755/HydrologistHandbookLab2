#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtWidgets"
#include "QGridLayout"
#include "tablemodel.h"
#include "editriverdialog.h"
#include "dialogdelegate.h"
#include "linedeligate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tableView = new QTableView();
    tableModel = new TableModel(this);
    tableView->setModel( tableModel );

    DialogDelegate* ddel = new DialogDelegate(nullptr,this);

    LineDelegate* ldel = new LineDelegate();
    tableView->setItemDelegateForColumn(0,ddel);
    tableView->setItemDelegateForColumn(1,ldel);
    tableView->viewport()->setAttribute(Qt::WA_Hover);

    QGridLayout* glay= new QGridLayout();
    glay->addWidget(tableView,1,1,1,2);

    QPushButton* pb1 = new QPushButton("Добавить");
    QPushButton* pb2 = new QPushButton("Удалить");

    glay->addWidget(pb1,2,1);
    glay->addWidget(pb2,2,2);

    QObject::connect(pb1,SIGNAL(clicked(bool)),this,SLOT(AddRow()));
    QObject::connect(pb2,SIGNAL(clicked(bool)),this,SLOT(DeleteRow()));


    QWidget* wdg=new QWidget();
    wdg->setLayout(glay);

    this->setCentralWidget(wdg);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AddRow()
{
    EditRiverDialog* addDialog = new EditRiverDialog(this);
    if (addDialog->exec() == QDialog::Accepted)
    {
        River* river = new River(addDialog->id(),addDialog->name(),addDialog->lenght(),
                               addDialog->fallsIn(), addDialog->annualRunoff(),
                                 addDialog->coolArea(),this);
        tableModel->AddRiver(river);
    }

    addDialog->deleteLater();
}

void MainWindow::DeleteRow()
{
    QModelIndex selList = tableView->currentIndex();
    tableModel->DeleteRiver(selList.row());
}
