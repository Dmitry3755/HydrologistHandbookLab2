#include "editriverdialog.h"
#include "river.h"

EditRiverDialog::EditRiverDialog(QWidget* pwgt): QDialog(pwgt)
{
    editId = new QLineEdit();
    editName = new QLineEdit();
    editLenght = new QLineEdit();
    editFallsIn = new QLineEdit();
    editAnnualRunoff = new QLineEdit();
    editCoolArea = new QLineEdit();

    QGridLayout* mainLayout = new QGridLayout;
    mainLayout->addWidget(new QLabel("Id"),1,1);
    mainLayout->addWidget(editId,1,2);
    mainLayout->addWidget(new QLabel("Название"),2,1);
    mainLayout->addWidget(editName,2,2);
    mainLayout->addWidget(new QLabel("Длина"),3,1);
    mainLayout->addWidget(editLenght,3,2);
    mainLayout->addWidget(new QLabel("Впадает в"),4,1);
    mainLayout->addWidget(editFallsIn,4,2);
    mainLayout->addWidget(new QLabel("Годовой сток"),5,1);
    mainLayout->addWidget(editAnnualRunoff,5,2);
    mainLayout->addWidget(new QLabel("Площадь бассейна"),6,1);
    mainLayout->addWidget(editCoolArea,6,2);

    QPushButton* btnOk = new QPushButton("&ОК");
    mainLayout->addWidget(btnOk,7,1,1,2);

    QObject::connect(btnOk, SIGNAL(clicked()), this, SLOT(accept()));

    this->setLayout(mainLayout);
    this->setWindowTitle("Данные о реке");
    int gx = 100;
    int gy = 100;
    if (pwgt!=nullptr)
    {
        gx = pwgt->geometry().x();
        gy = pwgt->geometry().y();

    }
    this->setGeometry(gx+10,gy+10,300,150);
}

QString EditRiverDialog::id() const
{
    return editId->text();
}
QString EditRiverDialog::name() const
{
    return editName->text();
}
QString EditRiverDialog::lenght() const
{
    return editLenght->text();
}
QString EditRiverDialog::fallsIn() const
{
    return editFallsIn->text();
}
QString EditRiverDialog::annualRunoff() const
{
    return editAnnualRunoff->text();
}
QString EditRiverDialog::coolArea() const
{
    return editCoolArea->text();
}

void EditRiverDialog::SetUpDialog(QString id, QString name,
                                  QString lenght, QString fallsIn, QString annualRunoff, QString coolArea)
{
    editId->setText(id);
    editName->setText(name);
    editLenght->setText(lenght);
    editFallsIn->setText(fallsIn);
    editAnnualRunoff->setText(annualRunoff);
    editCoolArea->setText(coolArea);

}

