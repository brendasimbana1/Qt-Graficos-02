#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    m_lienzo = QPixmap(500,500);
    this->dibujar(m_n1,m_n2,m_n3,promedio());

    ui->outCuadro->setPixmap(m_lienzo);

}

Principal::~Principal()
{
    delete ui;
}

float Principal::promedio()
{
    bool ok;
    QString nota1 = ui->inNota1->text();
    m_n1 = nota1.split(" ")[0].toFloat(&ok);
    qDebug() << nota1;
    QString nota2 = ui->inNota2->text();
    m_n2 = nota2.split(" ")[0].toFloat(&ok);
    QString nota3 = ui->inNota3->text();
    m_n3 = nota3.split(" ")[0].toFloat(&ok);

    float promedio = (m_n1 + m_n2 + m_n3)/3.0;
    qDebug() << promedio;
    return promedio;
}

/*void Principal::dibujarProm()
{
    QPainter painter(this);
    int x = 0;
    QPen pencil;
    pencil.setWidth(5);
    QColor color(223,13,180);
    pencil.setColor(color);
    painter.setPen(pencil);
    QLine line(x, promedio()+300, x+390, promedio()+300);
    painter.drawLine(line);
    qDebug()<<"llego";

}*/

void Principal::dibujar(int, int, int, float)
{
    m_lienzo.fill(Qt::white);//lena de blanco, si no se hace esto el lienzo es transparente

    QPainter painter(&m_lienzo);

    int x = 30;
    //int y = 0;
    int tam1 = 4*m_n1;
    int tam2 = 4*m_n2;
    int tam3 = 4*m_n3;
    int promedio = 4*((m_n1 + m_n2 + m_n3)/3.0);

    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Dibujar primera barra
    painter.drawRect(x+50, (400-tam1+50),100, tam1);

    // Crear un objeto color para el relleno
    QColor colorRelleno(190,120,162);
    // Crear otro objeto color para el borde
    QColor colorBorde(78,3,48);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno);

    // Dibujar segunda barra
    painter.drawRect(x+170, (400-tam2+50), 100, tam2);

    // Creando los colores de la tercera barra
    QColor cRellenoBarra3(253, 253, 115);
    QColor cBordeBarra3(174, 174, 51);

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Dibujar tercera barra
    painter.drawRect(x+290,(400-tam3+50),100, tam3);
     //dibujar linea
    pincel.setWidth(5);
    QColor color(223,13,180);
    pincel.setColor(color);
    painter.setPen(pincel);
    QLine line(x+50, (400-promedio+50), x+390, (400-promedio+50));
    painter.drawLine(line);
    qDebug()<<"llego";


}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (m_lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_Promediar_clicked()
{

    dibujar(m_n1, m_n2, m_n3, promedio());
    ui->outCuadro->setPixmap(m_lienzo);
}

