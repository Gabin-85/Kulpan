/**
 * @file identifier.h
 * @brief Contains a system for creating numeric identifiers.
 * @copyright Kulpan Game Engine
 */

#pragma once

#include "defines.h"

/**
 * @brief Acquires a new identifier for the given owner.
 *
 * @param owner The owner of the identifier.
 * @return The new identifier.
 */
u32 identifier_aquire_new_id(void* owner);

/**
 * @brief Releases the given identifier, which can then be used
 * again.
 *
 * @param id The identifier to be released.
 */
void identifier_release_id(u32 id);