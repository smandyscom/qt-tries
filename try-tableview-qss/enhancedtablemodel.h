#ifndef ENHANCEDTABLEMODEL_H
#define ENHANCEDTABLEMODEL_H

#include <QObject>
#include <QSqlTableModel>

class enhancedTableModel : public QSqlTableModel
{
    Q_OBJECT
public:
    explicit enhancedTableModel(QObject *parent = nullptr);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    bool select() Q_DECL_OVERRIDE;
signals:

public slots:
protected:
    QVector<QVector<bool>> m_monitorRole;

};

#endif // ENHANCEDTABLEMODEL_H
