#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QIcon>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); // Our main application

    a.setWindowIcon(QIcon(":/resources/favicon.ico"));
    QTranslator translator; // Translation services
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "SariSariSleuth_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w; // Our main window
    w.show();
    return a.exec();
}
