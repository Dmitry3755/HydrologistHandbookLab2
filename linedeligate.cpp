#include "linedeligate.h"
#include "editriverdialog.h"
#include "QtWidgets"
#include "QStyledItemDelegate"

LineDelegate::LineDelegate(QObject *parent): QStyledItemDelegate(parent)
{

}

QWidget *LineDelegate::createEditor(QWidget *parent,
    const QStyleOptionViewItem &,
    const QModelIndex & ) const
{
    QLineEdit* edt = new QLineEdit(parent);
    return edt;
}

void LineDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    QLineEdit *myeditor = static_cast<QLineEdit*>(editor);
    QString value = myeditor->text();
    model->setData(index, value, Qt::EditRole);
}

void LineDelegate::setEditorData(QWidget *editor,
                                    const QModelIndex &index) const
{
    QLineEdit *myeditor = qobject_cast<QLineEdit *>(editor);
    const QString currentText =  index.data(Qt::DisplayRole).toString();
    myeditor->setText(currentText);
}


void LineDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  if (option.state & QStyle :: State_MouseOver)
  {
      QRect rect = option.rect;
      QBrush brush(QColor(123, 104, 238, 150));
      painter->setBrush(brush);
      painter->drawRect(rect);
  }
  QStyledItemDelegate::paint(painter, option, index);
}
