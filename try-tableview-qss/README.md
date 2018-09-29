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
