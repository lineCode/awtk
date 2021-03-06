﻿/**
 * File:   rich_text.h
 * Author: AWTK Develop Team
 * Brief:  rich_text
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
 * 2018-07-28 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_RICH_TEXT_H
#define TK_RICH_TEXT_H

#include "base/widget.h"
#include "rich_text/rich_text_render_node.h"

BEGIN_C_DECLS

/**
 * @class rich_text_t
 * @parent widget_t
 * @scriptable
 * rich_text控件，实现简单的图文混排。
 */
typedef struct _rich_text_t {
  widget_t widget;

  int32_t line_gap;
  rich_text_node_t* node;
  rich_text_render_node_t* render_node;
} rich_text_t;

/**
 * @method rich_text_create
 * @constructor
 * 创建rich_text对象
 * @param {widget_t*} parent 父控件
 * @param {xy_t} x x坐标
 * @param {xy_t} y y坐标
 * @param {wh_t} w 宽度
 * @param {wh_t} h 高度
 *
 * @return {widget_t*} 对象。
 */
widget_t* rich_text_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h);

/**
 * @method rich_text_set_text
 * 设置文本。
 * @param {widget_t*} widget 控件对象。
 * @param {char*}  text 文本。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t rich_text_set_text(widget_t* widget, const char* text);

#define RICH_TEXT(widget) ((rich_text_t*)(widget))

END_C_DECLS

#endif /*TK_RICH_TEXT_H*/
