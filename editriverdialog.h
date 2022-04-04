#ifndef EDITRIVERDIALOG_H
#define EDITRIVERDIALOG_H

#include <QDialog>
#include <QtWidgets>
#include "river.h"

class EditRiverDialog: public QDialog
{
     Q_OBJECT

private:
    QLineEdit* editId;
    QLineEdit* editName;
    QLineEdit* editLenght;
    QLineEdit* editFallsIn;
    QLineEdit* editAnnualRunoff;
    QLineEdit* editCoolArea;

public:
    EditRiverDialog(QWidget* pwgt = nullptr);

    QString id() const;
    QString name() const;
    QString lenght() const;
    QString fallsIn() const;
    QString annualRunoff() const;
    QString coolArea() const;

   public: void SetUpDialog(QString id, QString name,QString lenght,
                    QString fallsIn, QString annualRunoff,QString coolArea );
};

#endif // EDITRIVERDIALOG_H
