#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    :QAbstractTableModel(parent)
{
    River* std1 = new River("1","Волга","3530","Каспийское море"
                            ,"254","1360000", this);
    River* std2 = new River("2","Енисей","3487","Енисейский залив"
                            ,"624,41","2580000", this);
    River* std3 = new River("3","Лена","4480","Море Лаптевых"
                            ,"516,6","2490000", this);
    AddRiver(std1);
    AddRiver(std2);
    AddRiver(std3);
}

int TableModel::rowCount(const QModelIndex &) const
{
   return rivers.count();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 6;
}


QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        QString Value = "";
        River* riv = rivers.at(index.row());
        if (index.column() == 0){Value = riv->Id();}
        else if (index.column() == 1){Value = riv->Name();}
        else if (index.column() == 2){Value = riv->Lenght();}
        else if (index.column() == 3){Value = riv->FallsIn();}
        else if (index.column() == 4){Value = riv->AnnualRunoff();}
        else if (index.column() == 5){Value = riv->CoolArea();}
        else {Value = "";};
       return Value;
    }
    return QVariant();
}


QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("Id");
            case 1:
                return QString("Название");
            case 2:
                return QString("Длина");
            case 3:
                return QString("Впадает в");
            case 4:
                return QString("Годовой сток");
            case 5:
                return QString("Площадь бассейна");
            }
        }
    }
    return QVariant();
}


bool TableModel::setData(const QModelIndex & index, const QVariant & value, int role)
{
   if (role == Qt::EditRole)
    {
        River* riv = rivers.at(index.row());
        if (index.column() == 0){riv->setId(value.toString());}
        else if (index.column() == 1){riv->setName(value.toString());}
        else if (index.column() == 2){riv->setLenght(value.toString());}
        else if (index.column() == 3){riv->setFallsIn(value.toString());}
        else if (index.column() == 4){riv->setAnnualRunoff(value.toString());}
        else if (index.column() == 5){riv->setCoolArea(value.toString());}
    }
    return true;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &) const
{
    return Qt::ItemIsSelectable |  Qt::ItemIsEditable | Qt::ItemIsEnabled;
}




void TableModel::AddRiver(River* river)
{
    beginInsertRows(QModelIndex(),rivers.size(),rivers.size());
    rivers.append(river);
    endInsertRows();
}

void TableModel::DeleteRiver(int row)
{
    beginRemoveRows(QModelIndex(),row,row);
    rivers.removeAt(row);
    endRemoveRows();
}
