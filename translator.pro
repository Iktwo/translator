QT += quick printsupport

SOURCES += \
    src/main.cpp \
    src/translator.cpp

RESOURCES += \
    resources.qrc

HEADERS += \
    src/translator.h

OTHER_FILES += \
    qml/main.qml \
    qml/Button.qml

TRANSLATIONS = translator_fr.ts \
	       translator_sp.ts
