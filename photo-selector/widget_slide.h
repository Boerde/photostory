// ====================================================================
// Copyright 2018 by Martin Rünz <contact@martinruenz.de>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>
// ====================================================================

#pragma once

#include <QFrame>
#include <functional>

namespace Ui {
class SlideWidget;
}

class SlideWidget : public QFrame{
    Q_OBJECT

public:

    enum class SlideType { GPS, PHOTO } slide_type;

    explicit SlideWidget(QWidget *parent = 0);
    virtual ~SlideWidget();

    void setName(const QString& name);
    QString getName() const;

    void setMoveCallback(const std::function<void(int)>& f);
    void setRemoveCallback(const std::function<void()>& f);

    virtual QJsonObject toJson() const;
    virtual void fromJson(const QJsonObject* json);

protected:
    Ui::SlideWidget *ui;
};
