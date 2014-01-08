/*
	Copyright (C) 20014 by Elvis Angelaccio <angelaccioelvis@gmail.com>

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

#ifndef LAP_MODEL_H
#define LAP_MODEL_H

#include <QAbstractTableModel>
#include <QTime>

class LapModel : public QAbstractTableModel
{
	
public:
	
    LapModel(QObject* parent);
	LapModel(QObject* parent, const QString& format);
	
	int rowCount(const QModelIndex& parent) const ;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role) const;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const;
	
	void addLap(const QTime& lapTime);
	void clear();
	
private:

	static const int LAP_TAG_NUMBER = 3;	/** Number of tag/header in the model */
	
	enum LapTag
	{
		INDEX = 0,
		REL_TIME = 1,
		ABS_TIME = 2,
	};
	
	QList<QTime> timeList;		/** Absolute lap times */
	QString timeFormat;
	
	QString lapTime(int lapIndex) const;
};


#endif