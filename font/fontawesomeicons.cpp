// fontawesomeicons.cpp
#include "fontawesomeicons.h"
#include <QFontDatabase>
#include <qstringlist.h>

FontAwesomeIcons &FontAwesomeIcons::Instance()
{
    static FontAwesomeIcons _instance;
    return _instance;
}

QFont FontAwesomeIcons::getFont()
{
    return this->font;
}

QChar FontAwesomeIcons::getIconChar(FontAwesomeIcons::IconIdentity code)
{
    return QChar((int)code);
}

FontAwesomeIcons::FontAwesomeIcons()
{
    // add font file
    int fontId = QFontDatabase::addApplicationFont(":/res/font/fontawesome-webfont.ttf");
    QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
    Q_ASSERT_X(fontFamilies.size()==1,"font","font not exist.");
    this->font.setFamily(fontFamilies.at(0));
}
