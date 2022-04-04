#include "dialogdelegate.h"
#include "QtWidgets"
#include "editriverdialog.h"

DialogDelegate::DialogDelegate(QObject *parent, QWidget* parentWidget): QStyledItemDelegate(parent)
{
    dparentWidget = parentWidget;
}

bool DialogDelegate::editorEvent(QEvent *event, QAbstractItemModel *model,
                 const QStyleOptionViewItem &, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonDblClick)
    {
        EditRiverDialog* editDialog = new EditRiverDialog(dparentWidget);

        QString ID = model->data(model->index(index.row(),0,index)).toString();
        QString Name = model->data(model->index(index.row(),1,index)).toString();
        QString Lenght = model->data(model->index(index.row(),2,index)).toString();
        QString FallsIn = model->data(model->index(index.row(),3,index)).toString();
        QString AnnualRunoff = model->data(model->index(index.row(),4,index)).toString();
        QString CoolArea = model->data(model->index(index.row(),5,index)).toString();


        editDialog->SetUpDialog(ID, Name, Lenght, FallsIn, AnnualRunoff, CoolArea);
        if (editDialog->exec() == QDialog::Accepted)
        {
            model->setData(model->index(index.row(),0,index),editDialog->id());
            model->setData(model->index(index.row(),1,index),editDialog->name());
            model->setData(model->index(index.row(),2,index),editDialog->lenght());
            model->setData(model->index(index.row(),3,index),editDialog->fallsIn());
            model->setData(model->index(index.row(),4,index),editDialog->annualRunoff());
            model->setData(model->index(index.row(),5,index),editDialog->coolArea());
        }

         editDialog->deleteLater();
         //QStyledItemDelegate::editorEvent(event, model, option, index);
    }
    return false;

}

QWidget *DialogDelegate::createEditor(QWidget* /*parent */,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
{
    return nullptr;
}
