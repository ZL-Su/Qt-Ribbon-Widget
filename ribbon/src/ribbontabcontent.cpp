/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#include "ribbon/include/ribbontabcontent.h"
#include "ribbon/include/ribbonbuttongroup.h"
#include "ui_ribbontabcontent.h"

RibbonTabContent::RibbonTabContent(QWidget* parent)
    : QWidget(parent), ui(new Ui::RibbonTabContent)
{
    ui->setupUi(this);
}

RibbonTabContent::~RibbonTabContent()
{
    delete ui;
}

RibbonButtonGroup* RibbonTabContent::addGroup(const QString& groupName)
{
    auto _Button_group = new RibbonButtonGroup;
    _Button_group->setTitle(groupName);
    ui->horiz_layout->addWidget(_Button_group);
	_Button_group->hide_title(groupName.isEmpty());
	return _Button_group;
}

void RibbonTabContent::removeGroup(const QString& groupName)
{
    // Find ribbon group
    for (auto i = 0; i < ui->horiz_layout->count(); ++i)
    {
        auto group = static_cast<RibbonButtonGroup*>(ui->horiz_layout->itemAt(i)->widget());
        if (group->title().toLower() == groupName.toLower())
        {
            ui->horiz_layout->removeWidget(group);
            delete group;
            break;
        }
    }
}

int RibbonTabContent::groupCount() const noexcept
{
    return ui->horiz_layout->count();
}

void RibbonTabContent::addButton(const QString& groupName, QToolButton* button)
{
    // Find ribbon group
    RibbonButtonGroup* _Button_group = nullptr;
    for (auto i = 0; i < ui->horiz_layout->count(); ++i)
    {
        auto group = static_cast<RibbonButtonGroup*>(ui->horiz_layout->itemAt(i)->widget());
        if (group->title().toLower() == groupName.toLower())
        {
            _Button_group = group;
            break;
        }
    }

    if (_Button_group != nullptr)
    {
        // Group found, add ribbon button
        _Button_group->addButton(button);
    }
    else
    {
        // Group not found, add ribbon group
        addGroup(groupName);
        // Then add ribbon button
        addButton(groupName, button);
    }
}

void RibbonTabContent::removeButton(const QString& groupName, QToolButton* button)
{
    // Find ribbon group
    RibbonButtonGroup* _Button_group = nullptr;
    for (int i = 0; i < ui->horiz_layout->count(); i++)
    {
        auto group = static_cast<RibbonButtonGroup*>(ui->horiz_layout->itemAt(i)->widget());
        if (group->title().toLower() == groupName.toLower())
        {
            _Button_group = group;
            break;
        }
    }

    if (_Button_group != nullptr)
    {
        // Group found
        // Remove ribbon button
        _Button_group->removeButton(button);

        if (_Button_group->buttonCount() == 0)
        {
            // Empty button group
            // Remove button group
            removeGroup(groupName);
        }
    }
}

RibbonButtonGroup* RibbonTabContent::getGroup(int idx) noexcept
{
    return static_cast<RibbonButtonGroup*>(ui->horiz_layout->itemAt(idx)->widget());
}

RibbonButtonGroup* RibbonTabContent::lastGroup() noexcept
{
    return getGroup(groupCount() - 1);
}

const int& RibbonTabContent::index() const noexcept
{
    return (_Myidx);
}

int& RibbonTabContent::index() noexcept
{
    return (_Myidx);
}