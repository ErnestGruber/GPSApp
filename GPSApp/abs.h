#ifndef ABS_H
#define ABS_H

#include <QWidget>

namespace Ui {
class abs;
}

class abs : public QWidget
{
    Q_OBJECT

public:
    explicit abs(QWidget *parent = nullptr);
    ~abs();

private:
    Ui::abs *ui;
};

#endif // ABS_H
