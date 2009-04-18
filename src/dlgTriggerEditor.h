/***************************************************************************
 *   Copyright (C) 2008 by Heiko Koehn                                     *
 *   KoehnHeiko@googlemail.com                                             *
 *                                                                         *
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

#ifndef DLGTRIGGEREDITOR_H
#define DLGTRIGGEREDITOR_H

#include <QFile>

#include "ui_trigger_editor.h"
#include <QDialog>
#include "TTrigger.h"
#include "TAction.h"
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexerlua.h>
#include "dlgTriggersMainArea.h"
#include "dlgTimersMainArea.h"
#include "dlgSystemMessageArea.h"
#include "dlgSourceEditorArea.h"
#include "dlgOptionsAreaTriggers.h"
#include "dlgSearchArea.h"
#include "TTreeWidget.h"
#include "TKey.h"

class dlgTimersMainArea;
class dlgSystemMessageArea;
class dlgSourceEditorArea;
class dlgTriggersMainArea;
class dlgActionMainArea;
class dlgOptionsAreaTriggers;
class dlgSearchArea;
class dlgAliasMainArea;
class dlgScriptsMainArea;
class dlgOptionsAreaAlias;
class dlgOptionsAreaScripts;
class dlgOptionsAreaTimers;
class dlgOptionsAreaAction;
class dlgKeysMainArea;
class TKey;

class dlgTriggerEditor : public QMainWindow , private Ui::trigger_editor
{
Q_OBJECT
        
public:
        
                                dlgTriggerEditor( Host * );
    void                        fillout_form();
    void                        closeEvent(QCloseEvent *event);    
    void                        showError( QString );
    void                        showWarning( QString );
    void                        showInfo( QString );
    QsciLexerLua *              mpLuaLexer;

signals:
    
    void                        signal_establish_connection( QString profile_name );
    void                        accept();
    void                        update();
    
public slots:
    void                        slot_colorizeTriggerSetBgColor();
    void                        slot_colorizeTriggerSetFgColor();
    void                        slot_itemClicked( QTreeWidgetItem * pItem, int column );
    void                        slot_choseButtonColor();
    void                        slot_export();
    void                        slot_import();
    void                        slot_debug_mode();
    void                        slot_saveTriggerAfterEdit();
    void                        slot_saveTimerAfterEdit();
    void                        slot_saveScriptAfterEdit();
    void                        slot_saveAliasAfterEdit();
    void                        slot_saveActionAfterEdit();
    void                        slot_saveKeyAfterEdit();
    void                        slot_show_timers();
    void                        slot_show_triggers();
    void                        slot_show_scripts();
    void                        slot_show_aliases();
    void                        slot_show_actions();
    void                        slot_show_keys();
    void                        slot_trigger_clicked( QTreeWidgetItem *pItem, int column );
    void                        slot_timer_clicked( QTreeWidgetItem *pItem, int column );
    void                        slot_scripts_clicked( QTreeWidgetItem *pItem, int column );
    void                        slot_alias_clicked( QTreeWidgetItem *pItem, int column );
    void                        slot_action_clicked( QTreeWidgetItem * pItem, int column );
    void                        slot_key_clicked( QTreeWidgetItem *pItem, int column );
    void                        slot_update();
    void                        slot_deleteProfile();
    void                        slot_connection_dlg_finnished();
    void                        slot_add_new();
    void                        slot_add_new_folder();
    void                        slot_addTrigger();
    void                        slot_addTriggerGroup();
    void                        slot_addTimer();
    void                        slot_addTimerGroup();
    void                        slot_addAlias();
    void                        slot_addAliasGroup();
    void                        slot_addScript();
    void                        slot_addScriptGroup();
    void                        slot_addAction();
    void                        slot_addActionGroup();
    void                        slot_addKey();
    void                        slot_addKeyGroup();
    void                        slot_toggle_active();
    void                        slot_trigger_toggle_active();
    void                        slot_action_toggle_active();
    void                        slot_timer_toggle_active();
    void                        slot_alias_toggle_active();
    void                        slot_script_toggle_active();
    void                        slot_key_toggle_active();
    void                        slot_search_triggers( const QString s );
    void                        slot_item_clicked_search_list(QTreeWidgetItem*, int);
    void                        slot_switchToExpertMonde();
    void                        slot_delete_item();
    void                        slot_deleteTrigger();
    void                        slot_deleteTimer();
    void                        slot_deleteAlias();
    void                        slot_deleteScript();
    void                        slot_deleteAction();
    void                        slot_deleteKey();
    void                        slot_save_edit();
    void                        slot_chose_action_icon();
    void                        slot_trigger_main_area_edit_regex(QListWidgetItem*);
    void                        slot_trigger_main_area_add_regex();
    void                        slot_show_search_area();
    void                        slot_trigger_main_area_delete_regex();
    void                        slot_script_main_area_delete_handler();
    void                        slot_script_main_area_add_handler();
    void                        slot_script_main_area_edit_handler(QListWidgetItem*);
    void                        slot_grab_key();
    bool                        event( QEvent * event );
    void                        grab_key_callback( int key, int modifier );
    void                        slot_profileSaveAction();
    void                        slot_profileSaveAsAction();
    
private:
    
    void                        saveOpenChanges();
    void                        saveTrigger();
    void                        saveAlias();
    void                        saveTimer();
    void                        saveKey();
    void                        saveScript();
    void                        saveAction();
    void                        readSettings();
    void                        writeSettings();
    void                        addScript( bool );
    void                        addAlias( bool );
    void                        addTimer( bool isFolder );
    void                        addTrigger( bool isFolder );
    void                        addAction( bool isFolder );
    void                        addKey( bool );
    
    void                        expand_child_triggers( TTrigger * pTriggerParent, QTreeWidgetItem * pItem );
    void                        expand_child_timers( TTimer * pTimerParent, QTreeWidgetItem * pWidgetItemParent );
    void                        expand_child_scripts( TScript * pTriggerParent, QTreeWidgetItem * pWidgetItemParent );
    void                        expand_child_alias( TAlias *, QTreeWidgetItem * );
    void                        expand_child_action( TAction *, QTreeWidgetItem * );
    void                        expand_child_key( TKey * pTriggerParent, QTreeWidgetItem * pWidgetItemParent );
    
    void                        exportTrigger( QFile & );
    void                        exportTimer( QFile & );
    void                        exportAlias( QFile & );
    void                        exportAction( QFile & );
    void                        exportScript( QFile & );
    void                        exportKey( QFile & );
    QTreeWidgetItem *           mCurrentAlias;
    QTreeWidgetItem *           mCurrentTrigger;
    QTreeWidgetItem *           mCurrentTimer;
    QTreeWidgetItem *           mCurrentAction;
    QTreeWidgetItem *           mCurrentScript;
    QTreeWidgetItem *           mCurrentKey;

    QTreeWidgetItem *           mpAliasBaseItem;
    QTreeWidgetItem *           mpTriggerBaseItem;
    QTreeWidgetItem *           mpScriptsBaseItem;
    QTreeWidgetItem *           mpTimerBaseItem;
    QTreeWidgetItem *           mpActionBaseItem;
    QTreeWidgetItem *           mpKeyBaseItem;
    
    QTreeWidgetItem *           mpCurrentActionItem;
    QTreeWidgetItem *           mpCurrentKeyItem;
    QTreeWidgetItem *           mpCurrentTimerItem;
    QTreeWidgetItem *           mpCurrentScriptItem;
    QTreeWidgetItem *           mpCurrentTriggerItem;
    QTreeWidgetItem *           mpCurrentAliasItem;
    
    int                         mCurrentView;
    static const int            cmTriggerView;
    static const int            cmTimerView;
    static const int            cmAliasView;
    static const int            cmScriptView;
    static const int            cmActionView;
    static const int            cmKeysView;
    
    dlgTriggersMainArea *       mpTriggersMainArea;
    dlgTimersMainArea *         mpTimersMainArea;
    dlgSystemMessageArea *      mpSystemMessageArea;
    dlgSourceEditorArea *       mpSourceEditorArea;
    dlgOptionsAreaTriggers *    mpOptionsAreaTriggers;
    dlgSearchArea *             mpSearchArea;
    dlgAliasMainArea *          mpAliasMainArea;
    dlgActionMainArea *         mpActionsMainArea;
    dlgScriptsMainArea *        mpScriptsMainArea;
    dlgKeysMainArea *           mpKeysMainArea;
    dlgOptionsAreaScripts *     mpOptionsAreaScripts;
    dlgOptionsAreaAction *      mpOptionsAreaActions;
    dlgOptionsAreaAlias *       mpOptionsAreaAlias;
    dlgOptionsAreaTimers *      mpOptionsAreaTimers;
    bool                        mIsTriggerMainAreaEditRegex;
    QListWidgetItem *           mpTriggerMainAreaEditRegexItem;
    bool                        mIsScriptsMainAreaEditHandler;
    QListWidgetItem *           mpScriptsMainAreaEditHandlerItem;
    bool                        mIsGrabKey;
    QsciDocument                mDocument;
    Host *                      mpHost;
};

#endif

