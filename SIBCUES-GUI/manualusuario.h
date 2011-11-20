#ifndef MANUALUSUARIO_H
#define MANUALUSUARIO_H

#include <QtGui/QWidget>

namespace Ui {
    class manualUsuario;
}

class manualUsuario : public QWidget {
    Q_OBJECT
public:
    manualUsuario(QWidget *parent = 0);
    ~manualUsuario();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::manualUsuario *m_ui;
};

#endif // MANUALUSUARIO_H
