#include "translator.h"

#include <QDebug>

Translator::Translator(QApplication *app, const QString &source, QObject *parent) :
    QObject(parent),
    m_app(app),
    m_source(source)
{
}

void Translator::addTranslation(const QString &name, const QString &file)
{
    if (!m_translations.contains(name))
        m_translations.insert(name, file);
}

QString Translator::tr()
{
    return "";
}

void Translator::setSource(const QString &source)
{
    m_source = source;
}

void Translator::translate(const QString &language)
{
    if (language == "DEFAULT")
        removeTranslation();
    if (m_translations.contains(language))
        if (m_qtTranslator.load(m_translations.value(language).toString(), m_source)) {
            removeTranslation();
            m_app->installTranslator(&m_qtTranslator);
            emit languageChanged();
        }
}

void Translator::removeTranslation()
{
    m_app->removeTranslator(&m_qtTranslator);
    emit languageChanged();
}
