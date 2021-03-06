﻿
#include "base/array.h"
#include "base/theme.h"
#include "base/widget.h"
#include "tools/theme_gen/xml_theme_gen.h"
#include "gtest/gtest.h"
#include <stdlib.h>

#include <string>
using std::string;

TEST(ThemeGen, basic) {
  uint8_t buff[1024];
  theme_t theme;
  style_t style;
  const char* str =
      "<widget><style><normal bg_color=\"yellow\" fg_color=\"#fafbfc\" font_name=\"sans\" font_size=\"12\" /></style></widget>\
       <progress_bar><style><normal bg_color=\"rgb(255,255,0)\" fg_color=\"rgba(255,255,0,0.5)\" border_color=\"#ff00ff\" /></style></progress_bar>";

  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;

  style.data = theme_find_style(&theme, WIDGET_TYPE_NONE, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style.data != NULL, true);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FONT_SIZE, 0), 12);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BG_COLOR, 0), 0xff00ffff);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FG_COLOR, 0), 0xfffcfbfa);
  ASSERT_EQ(style_get_str(&style, STYLE_ID_FONT_NAME, ""), string("sans"));

  style.data =
      theme_find_style(&theme, WIDGET_TYPE_PROGRESS_BAR, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style.data != NULL, true);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BG_COLOR, 0), 0xff00ffff);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FG_COLOR, 0), 0x7f00ffff);
}

TEST(ThemeGen, state) {
  uint8_t buff[1024];
  theme_t theme;
  style_t style;
  const char* str =
      "<button><style><over bg_color=\"yellow\" fg_color=\"#fafbfc\" font_name=\"sans\" font_size=\"12\" /></style></button>\
       <button><style><pressed bg_color=\"rgb(255,255,0)\" fg_color=\"rgba(255,255,0,0.5)\" border_color=\"#ff00ff\"/></style></button>";

  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_OVER);
  ASSERT_EQ(style.data != NULL, true);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FONT_SIZE, 0), 12);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BG_COLOR, 0), 0xff00ffff);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FG_COLOR, 0), 0xfffcfbfa);
  ASSERT_EQ(style_get_str(&style, STYLE_ID_FONT_NAME, ""), string("sans"));

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_PRESSED);
  ASSERT_EQ(style.data != NULL, true);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BG_COLOR, 0), 0xff00ffff);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FG_COLOR, 0), 0x7f00ffff);
}

TEST(ThemeGen, style_type) {
  uint8_t buff[1024];
  theme_t theme;
  style_t style;
  const char* str =
      "<button><style name=\"yellow\"><over bg_color=\"yellow\" fg_color=\"#fafbfc\" font_name=\"sans\" font_size=\"12\" /></style></button>\
       <button><style name=\"yellow\"><pressed bg_color=\"rgb(255,255,0)\" fg_color=\"rgba(255,255,0,0.5)\" border_color=\"#ff00ff\" /></style></button>";

  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, "yellow", WIDGET_STATE_OVER);
  ASSERT_EQ(style.data != NULL, true);

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, "yellow", WIDGET_STATE_PRESSED);
  ASSERT_EQ(style.data != NULL, true);
}

TEST(ThemeGen, inher) {
  uint8_t buff[1024];
  theme_t theme;
  style_t style;
  const char* str =
      "<button font_size=\"12\"><style name=\"yellow\" font_name=\"sans\"><over bg_color=\"yellow\" fg_color=\"#fafbfc\" /></style>\
       <style name=\"yellow\"><pressed bg_color=\"rgb(255,255,0)\" font_name=\"serif\" font_size=\"14\" /></style></button>";

  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, "yellow", WIDGET_STATE_OVER);
  ASSERT_EQ(style.data != NULL, true);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FONT_SIZE, 0), 12);
  ASSERT_EQ(style_get_str(&style, STYLE_ID_FONT_NAME, ""), string("sans"));

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, "yellow", WIDGET_STATE_PRESSED);
  ASSERT_EQ(style.data != NULL, true);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_FONT_SIZE, 0), 14);
  ASSERT_EQ(style_get_str(&style, STYLE_ID_FONT_NAME, ""), string("serif"));
}

TEST(ThemeGen, border) {
  uint8_t buff[1024];
  theme_t theme;
  style_t style;
  const char* str = "<button><style><normal border=\"left\" /></style></button>";
  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;

  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BORDER, 0), BORDER_LEFT);

  str = "<button><style><normal border=\"right\" /></style></button>";
  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;
  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BORDER, 0), BORDER_RIGHT);

  str = "<button><style><normal border=\"top\" /></style></button>";
  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;
  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BORDER, 0), BORDER_TOP);

  str = "<button><style><normal border=\"bottom\" /></style></button>";
  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;
  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BORDER, 0), BORDER_BOTTOM);

  str = "<button><style><normal border=\"all\" /></style></button>";
  xml_gen_buff(str, buff, sizeof(buff));
  theme.data = buff;
  style.data = theme_find_style(&theme, WIDGET_TYPE_BUTTON, TK_DEFAULT_STYLE, WIDGET_STATE_NORMAL);
  ASSERT_EQ(style_get_int(&style, STYLE_ID_BORDER, 0), BORDER_ALL);
}
