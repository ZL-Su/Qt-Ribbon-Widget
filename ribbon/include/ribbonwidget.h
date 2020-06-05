/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#ifndef RIBBONTABWIDGET_H
#define RIBBONTABWIDGET_H

#include <QTabWidget>
#include <QToolButton>
#include "forward.hpp"

class RibbonWidget : public QTabWidget
{
    Q_OBJECT;
#define DEFAULT_QTUI_FONT \
QString::fromUtf8("Segoe UI")
    using _Myt = RibbonWidget;
public:
    using TabPage = RibbonTabContent;
    using ButtonGroup = RibbonButtonGroup;

    explicit RibbonWidget(QWidget* parent = nullptr);

    /**
     *\brief Add a tab page to the ribbon widget.
     */
    _Myt& add_tabpage(const QString& name) noexcept;

    /// Add a tab to the ribbon.
    ///
    /// \param[in] tabName Name of the tab
    void addTab(const QString& tabName, const QString& font = DEFAULT_QTUI_FONT);

    /// Add a tab to the ribbon.
    ///
    /// \param[in] tabIcon Icon of the tab
    /// \param[in] tabName Name of the tab
    void addTab(const QIcon& tabIcon, const QString& tabName, const QString& font = DEFAULT_QTUI_FONT);

    // Remove a tab from the ribbon.
    //
    // \param[in] tab - Name of the tab
    void removeTab(const QString& tab);

    /// Add a group to the specified tab.
    /// The specified tab is created if it does not exist.
    ///
    /// \param[in] tabName Name of the tab
    /// \param[in] groupName Name of the group
    ButtonGroup* addGroup(const QString& tab, const QString& group="");

    /// Add a button to the specified group.
    /// The specified group and tab are created if they do not exist.
    ///
    /// \param[in] tabName Name of the tab
    /// \param[in] groupName Name of the group
    /// \param[in] button The button
    void addButton(const QString& tabName, const QString& groupName, QToolButton* button);

    /// Remove a button from the specified group.
    /// Do nothing if the button, group or tab doesn't exist.
    /// The button group and tab are also removed if they become empty due to
    /// the removal of the button.
    ///
    /// \param[in] tabName Name of the tab
    /// \param[in] groupName Name of the group
    /// \param[in] button The button
    void removeButton(const QString& tabName, const QString& groupName, QToolButton* button);

    RibbonButtonGroup* lastGroup(const QString& tabName) noexcept;

    /**
     *\brief Set icon to the latest tab page.
     */
    _Myt& icon(const QString& iconname) noexcept;

    /**
     *\brief Set font to the tab widget.
     */
    _Myt& font(const QString& fontname) noexcept;
    /**
     *\brief Get font of the tab widget.
     */
    const QFont& font() const noexcept;

private:
    // pointer to the latest tab page instance.
    TabPage* _Mycurtab = nullptr;
};

#endif // RIBBONTABWIDGET_H
