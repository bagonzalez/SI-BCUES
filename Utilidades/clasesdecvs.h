#ifndef CLASESDECVS_H
#define CLASESDECVS_H

#include <QtGui/QMainWindow>
#include <QSqlDatabase>
namespace Ui
{
    class clasesdecvs;
}

class clasesdecvs : public QMainWindow
{
    Q_OBJECT

public:
    clasesdecvs(QWidget *parent = 0);
    ~clasesdecvs();    


private:
    Ui::clasesdecvs *ui;




private slots:
    void on_pushButton_clicked();
};

#endif // CLASESDECVS_H
