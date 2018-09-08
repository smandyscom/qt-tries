#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace Ui {
class mywidget;
}

class mywidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool prop MEMBER m_prop NOTIFY propChanged)
public:
    explicit mywidget(QWidget *parent = nullptr);
    ~mywidget();

    bool event(QEvent* event) Q_DECL_OVERRIDE;
signals:
    void propChanged();
private:
    Ui::mywidget *ui;
    bool m_prop;
};

#endif // MYWIDGET_H
