/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#include <QFrame>
#include <QToolButton>
#include "qribbonwidget/include/ribbonbuttongroup.h"
#include "ui_ribbonbuttongroup.h"

RibbonButtonGroup::RibbonButtonGroup(QWidget *parent)
  : QWidget(parent), 
    ui(new Ui::RibbonButtonGroup), m_title(tr(""))
{
  ui->setupUi(this);
  ui->horiz_line->hide();
}

RibbonButtonGroup::~RibbonButtonGroup() noexcept
{
  delete ui;
}

void RibbonButtonGroup::setTitle(const QString &title) noexcept
{
  m_title = title;
  ui->label->setText(m_title);
}

QString RibbonButtonGroup::title() const noexcept
{
  return m_title;
}

int RibbonButtonGroup::buttonCount() const noexcept
{
  return ui->horiz_layout->count();
}

void RibbonButtonGroup::addButton(QToolButton *button)
{
  button->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
  button->setMinimumSize(48, 48);
  button->setAutoRaise(true);
  button->setIconSize(QSize(32,32));
  button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

  ui->horiz_layout->addWidget(button);
}

void RibbonButtonGroup::removeButton(QToolButton *button)
{
  ui->horiz_layout->removeWidget(button);
}

const QFrame* RibbonButtonGroup::separator() const noexcept
{
    return ui->vert_line;
}

QFrame* RibbonButtonGroup::separator() noexcept
{
    return ui->vert_line;
}
