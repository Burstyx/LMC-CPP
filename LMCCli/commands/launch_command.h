#pragma once
/**
 * Handle arguments
 *
 * @param args Command arguments
 * @throw command_invalid_arguments_exception If arguments are invalid
 */
void launch_command_handler(char* args[]);

/**
 * Print help message
 */
void launch_command_help();

/**
 * Launch Minecraft with default arguments
 */
void launch_command();

/**
 * Launch Minecraft from specific instance
 *
 * @param instance_name Instance name
 */
void launch_command(char* instance_name);