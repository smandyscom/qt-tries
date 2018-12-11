#include "enhancedtablemodel.h"

enhancedTableModel::enhancedTableModel(QObject *parent) :
    QSqlTableModel(parent)
{

}

bool enhancedTableModel::select()
{
    QSqlTableModel::select();

    for(int rowIndex = 0;rowIndex < rowCount();rowIndex++)
    {
        m_monitorRole.append(QVector<bool>(columnCount()));
    }
}

bool enhancedTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role==Qt::UserRole)
    {
        m_monitorRole[index.row()][index.column()] = value.toBool();
        //! emit signal to inform view re-paint
        emit dataChanged(index,index);
        return true;
    }

   return QSqlTableModel::setData(index,value,role);
}

QVariant enhancedTableModel::data(const QModelIndex &index, int role ) const
{
    if(role==Qt::UserRole)
    {
        return m_monitorRole[index.row()][index.column()];
    }
    return QSqlTableModel::data(index,role);
}

