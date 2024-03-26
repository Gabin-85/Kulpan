/**
 * @file loader_utils.h
 * @brief This file contains resource loader utility functions.
 * @copyright Kulpan Game Engine
 */

#pragma once

#include "defines.h"
#include "core/kmemory.h"
#include "resources/resource_types.h"

struct resource_loader;

/**
 * @brief Unloads a resource using the appropriate registered loader.
 * @param self A pointer to the resource loader to be used.
 * @param resource A pointer to the resource to be unloaded.
 * @param tag The memory tag that was used by the resource loader, and should be used to unload the resource.
 * @return True on success; otherwise false.
 */
b8 resource_unload(struct resource_loader* self, resource* resource, memory_tag tag);
