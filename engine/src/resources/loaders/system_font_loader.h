/**
 * @file bitmap_font_loader.h
 * @brief The loader for bitmap fonts.
 * @copyright Kulpan Game Engine
 *
 */

#pragma once

#include "systems/resource_system.h"

/**
 * @brief Creates and returns a system font resource loader.
 *
 * @return The newly created resource loader.
 */
resource_loader system_font_resource_loader_create();