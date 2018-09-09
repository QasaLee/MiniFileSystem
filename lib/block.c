//
// Created by M78 on 9/9/18.
//

#include "../include/block.h"

int file_state = -1;//only open or load file system once*/
static int num_blocks = 0;
uint8_t block_map[NUMBER_OF_BLOCKS/SIZEOF_BYTE] = {0};
char file_system_path[100] = {0};