#include "principal.h"

#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // Objeto para manejar las traducciones
    QTranslator traducion;
    // Solicitando al usuario que seleccione un idioma
    QStringList idiomas;
    idiomas << "Francés" << "Inglés" << "Español" << "Portugués";
    QString idiomaSeleccionado = QInputDialog::getItem(NULL,
                               "Idioma",
                               "Seleccione un idioma",
                               idiomas);
    // Dependiendo del idioma seleccionado, carga el archivo de rtaducción
    if (idiomaSeleccionado == "Francés"){
        traducion.load(":/Calculadora_fr_FR.qm");
    }else if (idiomaSeleccionado == "Inglés"){
        traducion.load(":/Calculadora_en.qm");
    }else if (idiomaSeleccionado == "Portugués"){
        traducion.load(":/Calculadora_pr.qm");
    }
    // Si es diferente de español, se instala la traducción en TODA la aplicación
    if (idiomaSeleccionado != "Español"){
        a.installTranslator(&traducion);
    }
    // Muestra la ventana principal
    Principal w;
    w.show();
    return a.exec();
}
