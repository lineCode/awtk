/**
 * File:   combo_box_item.h
 * Author: AWTK Develop Team
 * Brief:  combo_box_item
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
 * 2018-07-25 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#include "base/mem.h"
#include "base/combo_box_item.h"

static ret_t combo_box_item_on_paint_self(widget_t* widget, canvas_t* c) {
  return widget_paint_helper(widget, c, NULL, NULL);
}

static ret_t combo_box_item_on_event(widget_t* widget, event_t* e) {
  uint16_t type = e->type;
  combo_box_item_t* combo_box_item = COMBO_BOX_ITEM(widget);

  switch (type) {
    case EVT_POINTER_DOWN: {
      combo_box_item->point_down_aborted = FALSE;
      widget_set_state(widget, WIDGET_STATE_PRESSED);
      break;
    }
    case EVT_POINTER_DOWN_ABORT: {
      combo_box_item->point_down_aborted = TRUE;
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      break;
    }
    case EVT_POINTER_UP: {
      widget_ungrab(widget->parent, widget);
      if (!combo_box_item->point_down_aborted) {
        pointer_event_t evt = *(pointer_event_t*)e;
        evt.e = event_init(EVT_CLICK, widget);
        widget_set_state(widget, WIDGET_STATE_NORMAL);
        widget_dispatch(widget, (event_t*)&evt);
        combo_box_item_set_selected(widget, TRUE);
      }
      break;
    }
    case EVT_POINTER_LEAVE:
      widget_set_state(widget, WIDGET_STATE_NORMAL);
      break;
    case EVT_POINTER_ENTER:
      widget_set_state(widget, WIDGET_STATE_OVER);
      break;
    default:
      break;
  }

  return RET_OK;
}

static ret_t combo_box_item_set_prop(widget_t* widget, const char* name, const value_t* v) {
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, WIDGET_PROP_VALUE)) {
    return combo_box_item_set_value(widget, value_int(v));
  } else if (tk_str_eq(name, WIDGET_PROP_SELECTED)) {
    return combo_box_item_set_selected(widget, value_bool(v));
  }

  return RET_NOT_FOUND;
}

static ret_t combo_box_item_get_prop(widget_t* widget, const char* name, value_t* v) {
  combo_box_item_t* combo_box_item = COMBO_BOX_ITEM(widget);
  return_value_if_fail(widget != NULL && name != NULL && v != NULL, RET_BAD_PARAMS);

  if (tk_str_eq(name, WIDGET_PROP_VALUE)) {
    value_set_int(v, combo_box_item->value);
    return RET_OK;
  } else if (tk_str_eq(name, WIDGET_PROP_SELECTED)) {
    value_set_bool(v, combo_box_item->selected);
    return RET_OK;
  } else if (tk_str_eq(name, WIDGET_PROP_SUB_THEME)) {
    value_set_str(v, combo_box_item->selected ? "_selected" : "");
    return RET_OK;
  }

  return RET_NOT_FOUND;
}

static const widget_vtable_t s_combo_box_item_vtable = {
    .size = sizeof(combo_box_item_t),
    .type_name = WIDGET_TYPE_COMBO_BOX_ITEM,
    .on_paint_self = combo_box_item_on_paint_self,
    .on_event = combo_box_item_on_event,
    .get_prop = combo_box_item_get_prop,
    .set_prop = combo_box_item_set_prop,
    .create = combo_box_item_create};

widget_t* combo_box_item_create(widget_t* parent, xy_t x, xy_t y, wh_t w, wh_t h) {
  widget_t* widget = NULL;
  combo_box_item_t* combo_box_item = TKMEM_ZALLOC(combo_box_item_t);
  return_value_if_fail(combo_box_item != NULL, NULL);

  widget = WIDGET(combo_box_item);
  widget->vt = &s_combo_box_item_vtable;
  widget_init(widget, parent, WIDGET_COMBO_BOX_ITEM);
  widget_move_resize(widget, x, y, w, h);

  widget_set_state(widget, WIDGET_STATE_NORMAL);

  return widget;
}

ret_t combo_box_item_set_value(widget_t* widget, int32_t value) {
  combo_box_item_t* combo_box_item = COMBO_BOX_ITEM(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  combo_box_item->value = value;

  return RET_OK;
}

static ret_t combo_box_item_set_selected_only(widget_t* widget, bool_t selected) {
  combo_box_item_t* combo_box_item = COMBO_BOX_ITEM(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  if (combo_box_item->selected != selected) {
    event_t e = event_init(EVT_VALUE_CHANGED, widget);
    combo_box_item->selected = selected;
    widget_dispatch(widget, &e);
  }

  widget_update_style(widget);

  return RET_OK;
}

ret_t combo_box_item_set_selected(widget_t* widget, bool_t selected) {
  combo_box_item_t* combo_box_item = COMBO_BOX_ITEM(widget);
  return_value_if_fail(widget != NULL, RET_BAD_PARAMS);

  combo_box_item_set_selected_only(widget, selected);
  if (widget->parent != NULL) {
    widget_t* parent = widget->parent;

    WIDGET_FOR_EACH_CHILD_BEGIN(parent, iter, i)
    if (iter != widget) {
      combo_box_item_set_selected_only(iter, !selected);
    }
    WIDGET_FOR_EACH_CHILD_END();
  }

  return RET_OK;
}
