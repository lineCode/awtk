﻿/**
 * File:   widget_consts.h
 * Author: AWTK Develop Team
 * Brief:  widget property names
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-04-19 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_WIDGET_CONSTS_H
#define TK_WIDGET_CONSTS_H

#include "base/types_def.h"

BEGIN_C_DECLS

/*widget props*/
#define WIDGET_PROP_X "x"
#define WIDGET_PROP_Y "y"
#define WIDGET_PROP_W "w"
#define WIDGET_PROP_H "h"
#define WIDGET_PROP_MIN_W "min_w"
#define WIDGET_PROP_MAX_W "max_w"
#define WIDGET_PROP_LAYOUT_W "layout_w"
#define WIDGET_PROP_LAYOUT_H "layout_h"
#define WIDGET_PROP_VIRTUAL_W "virtual_w"
#define WIDGET_PROP_VIRTUAL_H "virtual_h"
#define WIDGET_PROP_NAME "name"
#define WIDGET_PROP_VALUE "value"
#define WIDGET_PROP_TEXT "text"
#define WIDGET_PROP_TR_TEXT "tr_text"
#define WIDGET_PROP_STYLE "style"
#define WIDGET_PROP_ENABLE "enable"
#define WIDGET_PROP_MARGIN "margin"
#define WIDGET_PROP_SPACING "spacing"
#define WIDGET_PROP_LEFT_MARGIN "left_margin"
#define WIDGET_PROP_RIGHT_MARGIN "right_margin"
#define WIDGET_PROP_TOP_MARGIN "top_margin"
#define WIDGET_PROP_BOTTOM_MARGIN "bottom_margin"
#define WIDGET_PROP_STEP "step"
#define WIDGET_PROP_VISIBLE "visible"
#define WIDGET_PROP_ANIM_HINT "anim_hint"
#define WIDGET_PROP_OPEN_ANIM_HINT "open_anim_hint"
#define WIDGET_PROP_CLOSE_ANIM_HINT "opne_anim_hint"
#define WIDGET_PROP_MIN "min"
#define WIDGET_PROP_MAX "max"
#define WIDGET_PROP_TIPS "tips"
#define WIDGET_PROP_INPUT_TYPE "input_type"
#define WIDGET_PROP_READONLY "readonly"
#define WIDGET_PROP_ACTIVE "active"
#define WIDGET_PROP_VERTICAL "vertical"
#define WIDGET_PROP_SHOW_TEXT "show_text"
#define WIDGET_PROP_XOFFSET "xoffset"
#define WIDGET_PROP_YOFFSET "yoffset"
#define WIDGET_PROP_AUTO_PLAY "auto_play"
#define WIDGET_PROP_AUTO_FIX "auto_fix"
#define WIDGET_PROP_X_MIN "x_min"
#define WIDGET_PROP_X_MAX "x_max"
#define WIDGET_PROP_Y_MIN "y_min"
#define WIDGET_PROP_Y_MAX "y_max"
#define WIDGET_PROP_MAX "max"
#define WIDGET_PROP_ROW "row"
#define WIDGET_PROP_THEME "theme"
#define WIDGET_PROP_SCRIPT "script"
#define WIDGET_PROP_ITEM_WIDTH "item_width"
#define WIDGET_PROP_ITEM_HEIGHT "item_height"
#define WIDGET_PROP_DEFAULT_ITEM_HEIGHT "default_item_height"
#define WIDGET_PROP_XSLIDABLE "xslidable"
#define WIDGET_PROP_YSLIDABLE "yslidable"
#define WIDGET_PROP_REPEAT "repeat"
#define WIDGET_PROP_ANIMATABLE "animatable"
#define WIDGET_PROP_AUTO_HIDE_SCROLL_BAR "auto_hide_scroll_bar"
#define WIDGET_PROP_IMAGE "image"
#define WIDGET_PROP_DRAW_TYPE "draw_type"
#define WIDGET_PROP_SELECTABLE "selectable"
#define WIDGET_PROP_CLICKABLE "clickable"
#define WIDGET_PROP_SCALE_X "scale_x"
#define WIDGET_PROP_SCALE_Y "scale_y"
#define WIDGET_PROP_ANCHOR_X "anchor_x"
#define WIDGET_PROP_ANCHOR_Y "anchor_y"
#define WIDGET_PROP_ROTATION "rotation"
#define WIDGET_PROP_SUB_THEME "sub_theme"
#define WIDGET_PROP_COMPACT "compact"
#define WIDGET_PROP_ICON "icon"
#define WIDGET_PROP_OPTIONS "options"
#define WIDGET_PROP_SELECTED "selected"
#define WIDGET_PROP_ACTIVE_ICON "active_icon"
#define WIDGET_PROP_OPEN_WINDOW "open_window"
#define WIDGET_PROP_SELECTED_INDEX "selected_index"
#define WIDGET_PROP_CLOSE_WHEN_CLICK "close_when_click"
#define WIDGET_PROP_CLOSE_WHEN_CLICK_OUTSIDE "close_when_click_outside"
#define WIDGET_PROP_LINE_GAP "line_gap"

/*widget type name*/
#define WIDGET_TYPE_NONE "widget"
#define WIDGET_TYPE_WINDOW_MANAGER "window_manager"
#define WIDGET_TYPE_NORMAL_WINDOW "window"
#define WIDGET_TYPE_TOOL_BAR "tool_bar"
#define WIDGET_TYPE_DIALOG "dialog"
#define WIDGET_TYPE_POPUP "popup"
#define WIDGET_TYPE_SPRITE "sprite"
#define WIDGET_TYPE_KEYBOARD "keyboard"
#define WIDGET_TYPE_DND "dnd"
#define WIDGET_TYPE_LABEL "label"
#define WIDGET_TYPE_BUTTON "button"
#define WIDGET_TYPE_IMAGE "image"
#define WIDGET_TYPE_EDIT "edit"
#define WIDGET_TYPE_PROGRESS_BAR "progress_bar"
#define WIDGET_TYPE_GROUP_BOX "group_box"
#define WIDGET_TYPE_CHECK_BUTTON "check_button"
#define WIDGET_TYPE_RADIO_BUTTON "radio_button"
#define WIDGET_TYPE_DIALOG_TITLE "dialog_title"
#define WIDGET_TYPE_DIALOG_CLIENT "dialog_client"
#define WIDGET_TYPE_SLIDER "slider"
#define WIDGET_TYPE_VIEW "view"
#define WIDGET_TYPE_COMBO_BOX "combo_box"
#define WIDGET_TYPE_COMBO_BOX_ITEM "combo_box_item"
#define WIDGET_TYPE_SLIDE_VIEW "slide_view"
#define WIDGET_TYPE_PAGES "pages"
#define WIDGET_TYPE_TAB_BUTTON "tab_button"
#define WIDGET_TYPE_TAB_CONTROL "tab_control"
#define WIDGET_TYPE_TAB_BUTTON_GROUP "tab_button_group"
#define WIDGET_TYPE_BUTTON_GROUP "button_group"
#define WIDGET_TYPE_CANDIDATES "candidates"
#define WIDGET_TYPE_SPIN_BOX "spin_box"
#define WIDGET_TYPE_DRAGGER "dragger"
#define WIDGET_TYPE_SCROLL_BAR "scroll_bar"
#define WIDGET_TYPE_SCROLL_BAR_DESKTOP "scroll_bar_d"
#define WIDGET_TYPE_SCROLL_BAR_MOBILE "scroll_bar_m"
#define WIDGET_TYPE_SCROLL_VIEW "scroll_view"
#define WIDGET_TYPE_LIST_VIEW "list_view"
#define WIDGET_TYPE_LIST_VIEW_H "list_view_h"
#define WIDGET_TYPE_LIST_ITEM "list_item"

/**
 * @enum widget_type_t
 * @scriptable
 * 控件类型常量定义。
 */
typedef enum _widget_type_t {
  /**
   * @const WIDGET_NONE
   * 无效类型。
   */
  WIDGET_NONE = 0,
  /**
   * @const WIDGET_WINDOW_MANAGER
   * 窗口管理器。
   */
  WIDGET_WINDOW_MANAGER,
  /**
   * @const WIDGET_NORMAL_WINDOW
   * 窗口。
   */
  WIDGET_NORMAL_WINDOW,
  /**
   * @const WIDGET_TOOL_BAR
   * 工具条。
   */
  WIDGET_TOOL_BAR,
  /**
   * @const WIDGET_DIALOG
   * 对话框。
   */
  WIDGET_DIALOG,
  /**
   * @const WIDGET_POPUP
   * 弹出框。
   */
  WIDGET_POPUP,
  /**
   * @const WIDGET_SPRITE
   * 精灵窗口如鼠标指针。
   */
  WIDGET_SPRITE,
  /**
   * @const WIDGET_KEYBOARD
   * 软键盘。
   */
  WIDGET_KEYBOARD,
  /**
   * @const WIDGET_DND
   * drag & drop icon。
   */
  WIDGET_DND,
  /**
   * @const WIDGET_LABEL
   * 简单文本。
   */
  WIDGET_LABEL,
  /**
   * @const WIDGET_BUTTON
   * 按钮。
   */
  WIDGET_BUTTON,
  /**
   * @const WIDGET_IMAGE
   * 图片。
   */
  WIDGET_IMAGE,
  /**
   * @const WIDGET_EDIT
   * 文本编辑器。
   */
  WIDGET_EDIT,
  /**
   * @const WIDGET_PROGRESS_BAR
   * 进度条。
   */
  WIDGET_PROGRESS_BAR,
  /**
   * @const WIDGET_GROUP_BOX
   * 分组框。
   */
  WIDGET_GROUP_BOX,
  /**
   * @const WIDGET_CHECK_BUTTON
   * 多选按钮。
   */
  WIDGET_CHECK_BUTTON,
  /**
   * @const WIDGET_RADIO_BUTTON
   * 单选按钮。
   */
  WIDGET_RADIO_BUTTON,
  /**
   * @const WIDGET_DIALOG_TITLE
   * 对话框的标题。
   */
  WIDGET_DIALOG_TITLE,
  /**
   * @const WIDGET_DIALOG_CLIENT
   * 对话框的客户区。
   */
  WIDGET_DIALOG_CLIENT,
  /**
   * @const WIDGET_SLIDER
   * 滑块。
   */
  WIDGET_SLIDER,
  /**
   * @const WIDGET_VIEW
   * 通用容器和自绘控件。
   */
  WIDGET_VIEW,
  /**
   * @const WIDGET_SLIDE_VIEW
   * Slide View。
   */
  WIDGET_SLIDE_VIEW,
  /**
   * @const WIDGET_PAGES
   * Pages。
   */
  WIDGET_PAGES,
  /**
   * @const WIDGET_TAB_BUTTON
   * Tab Button。
   */
  WIDGET_TAB_BUTTON,
  /**
   * @const WIDGET_TAB_CONTROL
   * Tab Control。
   */
  WIDGET_TAB_CONTROL,
  /**
   * @const WIDGET_TAB_BUTTON_GROUP
   * Tab Button Group。
   */
  WIDGET_TAB_BUTTON_GROUP,
  /**
   * @const WIDGET_BUTTON_GROUP
   * Button Group。
   */
  WIDGET_BUTTON_GROUP,
  /**
   * @const WIDGET_CANDIDATES
   * Input method words candidates。
   */
  WIDGET_CANDIDATES,
  /**
   * @const WIDGET_SPIN_BOX
   * Spin Box。
   */
  WIDGET_SPIN_BOX,
  /**
   * @const WIDGET_DRAGGER
   * Dragger。
   */
  WIDGET_DRAGGER,
  /**
   * @const WIDGET_SCROLL_BAR
   * Scroll Bar。
   */
  WIDGET_SCROLL_BAR,
  /**
   * @const WIDGET_SCROLL_BAR_DESKTOP
   * Scroll Bar Desktop。
   */
  WIDGET_SCROLL_BAR_DESKTOP,
  /**
   * @const WIDGET_SCROLL_BAR_MOBILE
   * Scroll Bar Mobile。
   */
  WIDGET_SCROLL_BAR_MOBILE,
  /**
   * @const WIDGET_SCROLL_VIEW
   * Scroll View。
   */
  WIDGET_SCROLL_VIEW,
  /**
   * @const WIDGET_LIST_VIEW
   * List View。
   */
  WIDGET_LIST_VIEW,
  /**
   * @const WIDGET_LIST_VIEW_H
   * List View Horizontal。
   */
  WIDGET_LIST_VIEW_H,
  /**
   * @const WIDGET_LIST_ITEM
   * List Item。
   */
  WIDGET_LIST_ITEM,
  /**
   * @const WIDGET_COMBO_BOX
   * Combo Box。
   */
  WIDGET_COMBO_BOX,
  /**
   * @const WIDGET_COMBO_BOX_ITEM
   * Combo Box Item。
   */
  WIDGET_COMBO_BOX_ITEM,

  WIDGET_NR,
  WIDGET_USER_START = 100

} widget_type_t;

END_C_DECLS

#endif /*TK_WIDGET_CONSTS_H*/
