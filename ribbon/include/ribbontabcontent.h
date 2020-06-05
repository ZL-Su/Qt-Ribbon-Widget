/*
 * Copyright (C) Martijn Koopman
 * All Rights Reserved
 *
 * This software is distributed WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.
 *
 */

#ifndef RIBBONTABCONTENT_H
#define RIBBONTABCONTENT_H

#include <QWidget>
#include <QToolButton>
#include "forward.hpp"

class RibbonTabContent : public QWidget
{
    Q_OBJECT;
    using _Myt = RibbonTabContent;
public:
    explicit RibbonTabContent(QWidget* parent = nullptr);
    virtual ~RibbonTabContent();

    /**
     *\brief Get and set the index of the tab page.
     */
    const int& index() const noexcept;
    int& index() noexcept;

    /// Add a group to the tab content.
    ///
    /// \param[in] groupName Name of the group
    RibbonButtonGroup* addGroup(const QString& groupName);

    /// Remove a group from the tab content.
    ///
    /// \param[in] groupName Name of the group
    void removeGroup(const QString& groupName);

    /// Get the number of button groups in this tab content.
    ///
    /// \return The number of button groups
    int groupCount() const noexcept;

    /// Add a button to the specified group.
    /// The group is created if it does not exist.
    ///
    /// \param[in] groupName Name of the group
    /// \param[in] button The button
    void addButton(const QString& groupName, QToolButton* button);

    /// Remove a button from the specified group.
    /// The group is also removed if it's empty.
    ///
    /// \param[in] groupName Name of the group
    /// \param[in] button The button
    void removeButton(const QString& groupName, QToolButton* button);

    /**
     * \brief Get idx-th button group
     */
    RibbonButtonGroup* getGroup(int idx) noexcept;
    /**
     * \brief Get the last button group
     */
    RibbonButtonGroup* lastGroup() noexcept;
private:
    Ui::RibbonTabContent* ui;
    int _Myidx = 0;
};

#endif // RIBBONTABCONTENT_H
