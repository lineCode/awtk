﻿/**
 * File:   list_view_h.h
 * Author: AWTK Develop Team
 * Brief:  list_view_h
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
 * 2018-07-04 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "base/mem.h"
#include "base/utils.h"
#include "base/layout.h"
#include "base/list_view_h.h"
#include "base/scroll_view.h"

static ret_t list_view_h_on_add_child(widget_t* widget, widget_t* child);

static ret_t list_view_h_on_paint_self(widget_t* widget, canvas_t* c) {
  return widget_paint_helper(widget, c, NULL, NULL);
}

static ret_t list_view_h_get_prop(widget_t* widget, const char* name, value_t* v) {
  list_view_h_t* list_view_h = LIST_VIEW_H(widget);
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, WIDGET_PROP_ITEM_WIDTH)) {
    value_set_int(v, list_view_h->item_width);
    return RET_OK;
  } else if (tk_str_eq(name, WIDGET_PROP_SPACING)) {
    value_set_bool(v, list_view_h->spacing);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t list_view_h_set_prop(widget_t* widget, const char* name, const value_t* v) {
  list_view_h_t* list_view_h = LIST_VIEW_H(widget);
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, WIDGET_PROP_ITEM_WIDTH)) {
    list_view_h->item_width = value_int(v);
    return RET_OK;
  } else if (tk_str_eq(name, WIDGET_PROP_SPACING)) {
    list_view_h->spacing = value_bool(v);
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static ret_t list_view_h_on_event(widget_t* widget, event_t* e) {
  uint16_t type = e->type;
  list_view_h_t* list_view = LIST_VIEW_H(widget);

  switch (type) {
    case EVT_POINTER_DOWN:
      widget_layout(list_view->scroll_view);
      break;
    case EVT_POINTER_UP: 
      widget_layout(list_view->scroll_view);
      break;
    default:break;
  }

  return RET_OK;
}

static const widget_vtable_t s_list_view_h_vtable = {.type_name = WIDGET_TYPE_LIST_VIEW_H,
                                                   .set_prop = list_view_h_set_prop,
                                                   .get_prop = list_view_h_get_prop,
                                                   .on_event = list_view_h_on_event,
                                                   .on_add_child = list_view_h_on_add_child,
                                                   .on_paint_self = list_view_h_on_paint_self};

static ret_t list_view_h_on_scroll_view_layout_children(widget_t* widget) {
  int32_t virtual_w = widget->w;
  list_view_h_t* list_view_h = LIST_VIEW_H(widget->parent);
  int32_t spacing = list_view_h->spacing;
  int32_t item_width = list_view_h->item_width;

  if (widget->children != NULL) {
    int32_t i = 0;
    int32_t x = 0;
    int32_t y = 0;
    int32_t w = item_width;
    int32_t h = widget->h;
    int32_t n = widget->children->size;
    widget_t** children = (widget_t**)(widget->children->elms);

    for (i = 0; i < n; i++) {
      widget_t* iter = children[i];
       
      widget_move_resize(iter, x, y, w, h);
      widget_layout(iter);

      x = iter->x + iter->w + spacing;
    }

    if(x > virtual_w) {
      virtual_w = x;
    }
  }

  scroll_view_set_virtual_w(list_view_h->scroll_view, virtual_w);
  scroll_view_set_xslidable(list_view_h->scroll_view, TRUE);
  scroll_view_set_yslidable(list_view_h->scroll_view, FALSE);

  return RET_OK;
}

static ret_t list_view_h_on_add_child(widget_t* widget, widget_t* child) {
  list_view_h_t* list_view_h = LIST_VIEW_H(widget);

  if (child->type == WIDGET_SCROLL_VIEW) {
    scroll_view_t* scroll_view = SCROLL_VIEW(child);

    list_view_h->scroll_view = child;
    scroll_view->on_layout_children = list_view_h_on_scroll_view_layout_children;
  }

  return RET_CONTINUE;
}

widget_t* list_view_h_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  widget_t* widget = NULL;
  list_view_h_t* list_view_h = TKMEM_ZALLOC(list_view_h_t);
  return_value_if_fail(list_view_h != NULL, NULL);

  widget = WIDGET(list_view_h);
  widget->vt = &s_list_view_h_vtable;
  widget_init(widget, parent, WIDGET_LIST_VIEW_H);
  widget_move_resize(widget, x, y, w, h);

  widget_set_state(widget, WIDGET_STATE_NORMAL);

  return widget;
}

ret_t list_view_h_set_item_width(widget_t* widget, int32_t item_width) {
  list_view_h_t* list_view_h = LIST_VIEW_H(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  list_view_h->item_width = item_width;

  return RET_OK;
}

ret_t list_view_h_set_spacing(widget_t* widget, bool_t spacing) {
  list_view_h_t* list_view_h = LIST_VIEW_H(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  list_view_h->spacing = spacing;

  return RET_OK;
}
