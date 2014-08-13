/*
    Copyright (C) 2014 by Elvis Angelaccio <elvis.angelaccio@kdemail.net>

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

#ifndef LAP_H
#define LAP_H

#include <QTime>
#include <QString>

/**
 * @brief A Lap is a specific time instant.
 * This class is a wrapper for a QTime object and some strings, which are useful to describe it.
 */
class Lap
{

public:

    explicit Lap(const QTime& lap = QTime());

    /**
     * The specific lap's time
     * @return The underlying lap's time object
     */
    QTime time() const;

    /**
     * Set the lap's relative time
     * @param rel The string to be set as relative time
     */
    void setRelativeTime(const QString& rel);

    /**
     * The relative lap time
     * @return String representation of the relative lap time
     */
    QString relativeTime() const;

    /**
     * Set the lap's absolute time
     * @param abs The string to be set as absolute lap time
     */
    void setAbsoluteTime(const QString& abs);

    /**
     * The absolute lap time
     * @return String representation of the absolute lap time
     */
    QString absoluteTime() const;

    /**
     * Set the lap's annotation
     * @param note The note to be set
     */
    void setNote(const QString& note);

    /**
     * The lap's annotation
     * @return The lap's annotation
     */
    QString note() const;

private:

    QTime lapTime;      /**  The specific lap time */
    QString relTime;    /** String representation of the relative lap time, i.e. compared to another lap */
    QString absTime;    /** String representation of the specific (absolute) lap time */
    QString lapNote;    /** Custom lap annotation */
};

#endif
