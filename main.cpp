#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "filmname.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    FilmName f("/Users/sani/video_mercante/film.txt");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("films", &f);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
