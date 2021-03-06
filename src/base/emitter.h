﻿/**
 * File:   emitter.h
 * Author: AWTK Develop Team
 * Brief:  emitter dispatcher
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
 * 2018-01-13 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_EMITTER_H
#define TK_EMITTER_H

#include "base/events.h"

BEGIN_C_DECLS

struct _emitter_item_t;
typedef struct _emitter_item_t emitter_item_t;

struct _emitter_item_t {
  void* ctx;
  uint32_t id;
  uint32_t type;
  event_func_t handler;

  emitter_item_t* next;
};

/**
 * @class emitter_t
 * @scriptable no
 * 事件分发器, 用于实现观察者模式。
 */
typedef struct _emitter_t {
  /**
   * @property {emitter_item_t*} items
   * @private
   * 注册的回调函数集合。
   */
  emitter_item_t* items;
  /**
   * @property {uint32_t} next_id
   * @private
   * 下一次emitter_on返回的ID，emitter_on成功后会自动增加next_id。
   */
  uint32_t next_id;
  /**
   * @property {bool_t} enable
   * @readonly
   * 禁用标志。禁用时dispatch无效。
   */
  bool_t enable;
  /**
   * @property {bool_t} remove_curr_iter
   * @private
   * 如果在回调函数中，emitter_off当前正在dispatch的回调函数，我们只是设置remove_curr_iter为TRUE，在分发完成后才执行。
   * XXX: 如果要注销当前正在dispatch的回调函数，直接返回RET_REMOVE是最好的选择。
   */
  bool_t remove_curr_iter;
  /**
   * @property {emitter_item_t*} curr_iter
   * @private
   * 当前正在dispatch的项。
   */
  emitter_item_t* curr_iter;
} emitter_t;

/**
 * @method emitter_create
 * @constructor
 * 创建emitter对象。
 *
 * @return {emitter_t*} 对象。
 */
emitter_t* emitter_create(void);

/**
 * @method emitter_init
 * @constructor
 * 初始化emitter对象。
 * @param {emitter_t*} emitter emitter对象。
 *
 * @return {emitter_t*} 对象。
 */
emitter_t* emitter_init(emitter_t* emitter);

/**
 * @method emitter_dispatch
 * 分发事件。如果当前分发的回调函数返回RET_REMOVE，该回调函数将被移出。
 * 禁用状态下，本函数不做任何事情。
 * @param {emitter_t*} emitter emitter对象。
 * @param {event_t*} e 事件对象。

 * @return {ret_t}
 如果当前分发的回调函数返回RET_STOP，dispatch中断分发，并返回RET_STOP，否则返回RET_OK。
 */
ret_t emitter_dispatch(emitter_t* emitter, event_t* e);

/**
 * @method emitter_on
 * 注册指定事件的处理函数。
 * @param {emitter_t*} emitter emitter对象。
 * @param {event_type_t} type 事件类型。
 * @param {event_func_t} on_event 事件处理函数。
 * @param {void*} ctx 事件处理函数上下文。
 *
 * @return {uint32_t} 返回id，用于emitter_off。
 */
uint32_t emitter_on(emitter_t* emitter, uint32_t etype, event_func_t handler, void* ctx);

/**
 * @method emitter_off
 * 注销指定事件的处理函数。
 * @param {emitter_t*} emitter emitter对象。
 * @param {uint32_t} id emitter_on返回的ID。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t emitter_off(emitter_t* emitter, uint32_t id);

/**
 * @method emitter_off_by_func
 * 注销指定事件的处理函数。
 * @param {emitter_t*} emitter emitter对象。
 * @param {event_type_t} type 事件类型。
 * @param {event_func_t} on_event 事件处理函数。
 * @param {void*} ctx 事件处理函数上下文。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t emitter_off_by_func(emitter_t* emitter, uint32_t etype, event_func_t handler, void* ctx);

/**
 * @method emitter_find
 * 通过ID查找emitter_item_t，主要用于辅助测试。
 * @param {emitter_t*} emitter emitter对象。
 * @param {uint32_t} id emitter_on返回的ID。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
emitter_item_t* emitter_find(emitter_t* emitter, uint32_t id);

/**
 * @method emitter_enable
 * 启用。
 * @param {emitter_t*} emitter emitter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t emitter_enable(emitter_t* emitter);

/**
 * @method emitter_disable
 * 禁用。禁用后emitter_dispatch无效，但可以注册和注销。
 * @param {emitter_t*} emitter emitter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t emitter_disable(emitter_t* emitter);

/**
 * @method emitter_size
 * 获取注册的回调函数个数，主要用于辅助测试。
 * @param {emitter_t*} emitter emitter对象。
 *
 * @return {uint32_t} 回调函数个数。
 */
uint32_t emitter_size(emitter_t* emitter);

/**
 * @method emitter_deinit
 * 析构。
 * @param {emitter_t*} emitter emitter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t emitter_deinit(emitter_t* emitter);

/**
 * @method emitter_destroy
 * 销毁。
 * @param {emitter_t*} emitter emitter对象。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t emitter_destroy(emitter_t* emitter);

END_C_DECLS

#endif /*TK_EMITTER_H*/
