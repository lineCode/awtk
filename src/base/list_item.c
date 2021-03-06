﻿/**
 * File:   list_item.h
 * Author: AWTK Develop Team
 * Brief:  list_item
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
 * 2018-07-05 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "base/mem.h"
#include "base/timer.h"
#include "base/list_item.h"

static ret_t list_item_on_paint_self(widget_t* widget, canvas_t* c) {
  return widget_paint_helper(widget, c, NULL, NULL);
}

static ret_t list_item_on_timer(const timer_info_t* info) {
  widget_t* widget = WIDGET(info->ctx);
  list_item_t* list_item = LIST_ITEM(widget);

  if (list_item->dragged) {
    widget_set_state(widget, WIDGET_STATE_NORMAL);
  } else {
    widget_set_state(widget, WIDGET_STATE_PRESSED);
  }
  list_item->timer_id = TK_INVALID_ID;

  return RET_REMOVE;
}

static ret_t list_item_on_event(widget_t* widget, event_t* e) {
  uint16_t type = e->type;
  list_item_t* list_item = LIST_ITEM(widget);

  switch (type) {
    case EVT_POINTER_DOWN: {
      list_item->timer_id = timer_add(list_item_on_timer, widget, 50);
      break;
    }
    case EVT_POINTER_DOWN_ABORT: {
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      if (list_item->timer_id != TK_INVALID_ID) {
        timer_remove(list_item->timer_id);
        list_item->timer_id = TK_INVALID_ID;
      }
      break;
    }
    case EVT_POINTER_UP: {
      if (!list_item->dragged) {
        pointer_event_t evt = *(pointer_event_t*)e;
        evt.e = event_init(EVT_CLICK, widget);
        widget_dispatch(widget, (event_t*)&evt);
      }

      list_item->dragged = FALSE;
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      break;
    }
    case EVT_POINTER_MOVE: {
      if (list_item->timer_id != TK_INVALID_ID) {
        list_item->dragged = TRUE;
      }
      break;
    }
    case EVT_POINTER_LEAVE:
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      break;
    case EVT_POINTER_ENTER:
      if (list_item->dragged) {
        widget_set_state(widget, WIDGET_STATE_NORMAL);
      } else {
        widget_set_state(widget, WIDGET_STATE_OVER);
      }
      break;
    default:
      break;
  }

  return RET_OK;
}

static const widget_vtable_t s_list_item_vtable = {.size = sizeof(list_item_t),
                                                   .type_name = WIDGET_TYPE_LIST_ITEM,
                                                   .create = list_item_create,
                                                   .on_event = list_item_on_event,
                                                   .on_paint_self = list_item_on_paint_self};

widget_t* list_item_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  widget_t* widget = NULL;
  list_item_t* list_item = TKMEM_ZALLOC(list_item_t);
  return_value_if_fail(list_item != NULL, NULL);

  widget = WIDGET(list_item);
  widget->vt = &s_list_item_vtable;
  widget_init(widget, parent, WIDGET_LIST_ITEM);
  widget_move_resize(widget, x, y, w, h);

  list_item->timer_id = TK_INVALID_ID;
  widget_set_state(widget, WIDGET_STATE_NORMAL);

  return widget;
}
