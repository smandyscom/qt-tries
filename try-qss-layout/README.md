## Autofill Background
1. [Auto-expanding layout with Qt-Designer](https://stackoverflow.com/questions/3492739/auto-expanding-layout-with-qt-designer)
* Use layout on the grid in the background
* * *
## Adding Custom Widget and Fit the container
1. Adding new UI designer form with QFooWidget.h
* constructor should be without args except parent
2. Promote QWidget to QFooWidget  
3. Build and run , would showed embbeded QWidget
* * *
## Use Property to Update UI
### On QSS
* use [] to indicate which associated property
```css
QWidget#widget[enabled="true"] .QPushButton
{
    color : blue;
}
```
### On Logic
1. the style changed QWidget should be polish()
```cpp
style()->polish(ui->pushButton);
```
2. put polish() on event()