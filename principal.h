#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    float promedio();

private slots:
    void on_actionGuardar_triggered();

    void on_Promediar_clicked();

private:
    Ui::Principal *ui;
    QPixmap m_lienzo;
    float m_n1, m_n2, m_n3;
    void dibujar(int, int, int, float);
};
#endif // PRINCIPAL_H
