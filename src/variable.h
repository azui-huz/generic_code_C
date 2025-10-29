/**
 * @file variable.h
 * @brief Defines variable storage and access utilities.
 */

#ifndef VARIABLE_H
#define VARIABLE_H

/**
 * @brief Get the value of a variable or parse an integer literal.
 * @param name Variable name or numeric string.
 * @return The value of the variable or parsed number.
 */
int get_variable_value(const char* name);

/**
 * @brief Set or create a variable.
 * @param name Variable name.
 * @param value New value.
 */
void set_variable_value(const char* name, int value);

#endif
