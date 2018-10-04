# Change specific background color of cell on QTableView by QSS
* * *

## Idea
Use UserRole to transmit boolean state for each item of Model, translate UserRole data to Alternate state of QStyle, so that QSS can use it as selector then change style properties.

## 3 main step included
- QSS end , select item
- Delegate , override paint() method , mark-up Alternate flag of QStyleOption by state of data of incoming QModelIndex
- Model , setData to UserRole

### Selector of QSS (select the item on psuedo-state of alternate)
```css
QAbstractItemView::item:alternate
{
    background: #FFB934;
}
```
- - -
### Attach customed QStyledItemDelegate on QTableView with following paint()
```cpp
void MyDelegate::paint(QPainter *painter,
                            const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //!
    //! \brief opt
    //! Set Style option by UserRole
    QStyleOptionViewItem opt = option;
    opt.features.setFlag(QStyleOptionViewItem::Alternate,index.data(Qt::UserRole).toBool());
    QStyledItemDelegate::paint(painter,opt,index);
}
```
- - -
### Set model data of UserRole on specifc QModelIndex
```cpp
model->setData(index,
                   !index.data(Qt::UserRole).toBool(),
                   Qt::UserRole); //use UserRole to transmit On/Off state
```

- - -

### Note that, not all QAbstractItemModel implemented UserRole , i.e QSqlTableModel

#### Implementing QSqlTableModel with UserRole data

* sub-class QSqlTableModel , i.e EntenedSqlTableModel
* create storage for UserRole inside EntenedSqlTableModel
```cpp
QVector<QVector<bool>> m_userRole;
``` 
* overriden select() , setData() , data()
```cpp
bool EntenedSqlTableModel::select()
{
    QSqlTableModel::select();
    //! claim storage
    for(int rowIndex = 0;rowIndex < rowCount();rowIndex++)
    {
        m_monitorRole.append(QVector<bool>(columnCount()));
    }
}

bool EntenedSqlTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //! Intercept UserRole and handling
    if(role==Qt::UserRole)
    {
        m_monitorRole[index.row()][index.column()] = value.toBool();
        //! emit signal to inform view re-paint
        emit dataChanged(index,index);
        return true;
    }

   return QSqlTableModel::setData(index,value,role);
}

QVariant EntenedSqlTableModel::data(const QModelIndex &index, int role ) const
{
    if(role==Qt::UserRole)
    {
        return m_monitorRole[index.row()][index.column()];
    }
    return QSqlTableModel::data(index,role);
}
```
