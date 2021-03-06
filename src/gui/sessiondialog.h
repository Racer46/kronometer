/*
    Copyright (C) 2015 by Elvis Angelaccio <elvis.angelaccio@kde.org>

    This file is part of Kronometer.

    Kronometer is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    Kronometer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Kronometer.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SESSIONDIALOG_H
#define SESSIONDIALOG_H

#include "ui_sessiondialog.h"
#include "session.h"

#include <QDialog>

class SessionModel;

class KMessageWidget;

class QDialogButtonBox;
class QSortFilterProxyModel;
class QTableView;

/**
 * @brief Dialog for sessions interaction.
 */
class SessionDialog : public QDialog, public Ui::SessionDialog
{
    Q_OBJECT

public:

    explicit SessionDialog(QWidget *parent = nullptr);

    Session selectedSession() const;

public slots:

    virtual void accept() override;

protected:

    virtual void keyPressEvent(QKeyEvent *event) override;

private slots:

    /**
     * Call accept() if the selection's column is not editable.
     * @param index The selected index.
     */
    void slotDoubleClicked(const QModelIndex& index);

    /**
     * Disable the OK button if no session is selected.
     */
    void slotSelectionChanged();

    /**
     * Enable the OK button after the first session is added.
     */
    void slotSessionAdded();

    /**
     * Disable the OK button if no session is available.
     */
    void slotEmptyModel();

private:

    SessionModel *m_sessionModel;
    QSortFilterProxyModel *m_proxyModel;
    Session m_selectedSession;

    /**
     * @return The actual selected index in the view.
     */
    QModelIndex selectedIndex();

    /**
     * Ask confirm to the user before removing a session.
     */
    void removeDialog();

    Q_DISABLE_COPY(SessionDialog)
};

#endif
