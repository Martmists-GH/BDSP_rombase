#pragma once

#include "ui/base/element.h"
#include "ui/base/button.h"
#include "ui/base/child.h"
#include "ui/base/collapsing_header.h"
#include "ui/base/color_edit.h"
#include "ui/base/combo.h"
#include "ui/base/function_element.h"
#include "ui/base/menu.h"
#include "ui/base/menu_bar.h"
#include "ui/base/menu_item.h"
#include "ui/base/root_element.h"
#include "ui/base/selectable.h"
#include "ui/base/slider.h"
#include "ui/base/spacing.h"
#include "ui/base/text.h"
#include "ui/base/text_unformatted.h"
#include "ui/base/window.h"
#include "ui/components/file_selector.h"
#include "ui/components/string_view.h"
#include "ui/components/element_inspector.h"

ui::Root* getRootElement();
void exl_debug_menu_main();
void exl_imgui_main();
void setup_ui();

void ui_inspect(UnityEngine::Transform* transform);
void setArenaSettings(bool enabled, int id);
void showAreaName();
void setFlyOverride(bool enabled);

#define ROOT getRootElement()
