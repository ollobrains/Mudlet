/***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "Host.h"
#include "SingleLineTextEdit.h"
#include "pre_guard.h"
#include <QKeyEvent>
#include "post_guard.h"

SingleLineTextEdit::SingleLineTextEdit(QWidget *parent)
    : QTextEdit(parent)
{
    highlighter = new TriggerHighlighter(this->document());
    highlighter->setHighlightingEnabled(true);
    setAcceptRichText(false);
    setWordWrapMode(QTextOption::NoWrap);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setTabChangesFocus(true);
}

// trap some commonly used multi-line key shortcuts
void SingleLineTextEdit::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        return;
    }
    QTextEdit::keyPressEvent(event);
}

// ensure height remains on single line
void SingleLineTextEdit::resizeEvent(QResizeEvent *event)
{
    QTextEdit::resizeEvent(event);
}

// remove selection when focus is lost
void SingleLineTextEdit::focusOutEvent(QFocusEvent* event)
{
    QTextEdit::focusOutEvent(event);
    QTextCursor cursor = textCursor();
    cursor.clearSelection();
    setTextCursor(cursor);
}

void SingleLineTextEdit::setHighlightingEnabled(bool enabled)
{
    highlighter->setHighlightingEnabled(enabled);
    rehighlight();
}

void SingleLineTextEdit::setTheme(const QString& themeName)
{
    auto edbee = edbee::Edbee::instance();
    edbee::TextTheme* theme = edbee->themeManager()->theme(themeName);

    // set the textedit background and text the same as edbee base settings
    QPalette p = palette();
    p.setColor(QPalette::Base, theme->backgroundColor()); // background
    p.setColor(QPalette::Text, theme->foregroundColor());
    setPalette(p);

    // the highlighter will perform the syntax colouring using scopes if possible
    highlighter->setTheme(themeName);
}

void SingleLineTextEdit::rehighlight()
{
    if (toPlainText().isEmpty()) {
        return;
    }

    highlighter->rehighlight();
}
