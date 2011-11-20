#ifndef AGREGARUSUARIO_H
#define AGREGARUSUARIO_H

#include <QtGui/QWidget>

namespace Ui {
    class agregarUsuario;
}

class agregarUsuario : public QWidget {
    Q_OBJECT
public:
    agregarUsuario(QWidget *parent = 0);
    ~agregarUsuario();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::agregarUsuario *m_ui;
};

#endif // AGREGARUSUARIO_H
