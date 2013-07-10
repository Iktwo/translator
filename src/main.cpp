#include <QtWidgets/QApplication>
#include <QQuickView>
#include <QQmlContext>

#include "translator.h"

int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(new QApplication(argc, argv));

    Translator translator(app.data(), ":/translations/");
    translator.addTranslation("ES", "translator_sp.qm");
    translator.addTranslation("FR", "translator_fr.qm");

    QScopedPointer<QQuickView> view(new QQuickView);

    view->rootContext()->setContextProperty("translator", &translator);
    view->setSource(QUrl("qrc:/qml/qml/main.qml"));

    view->show();

    return app->exec();
}
