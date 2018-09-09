//
// Created by M78 on 9/9/18.
//

#include "../include/block.h"

int file_state = -1;//only open or load file system once*/
static int num_blocks = 0;
uint8_t block_map[NUMBER_OF_BLOCKS/SIZEOF_BYTE] = {0};
char file_system_path[100] = {0};

void map_set(int ID) {
    block_map[ID>>3] |= 1ULL << (ID%SIZEOF_BYTE);
}

void map_clear(int ID) {
    block_map[ID>>3] &= ~(1ULL << ID%SIZEOF_BYTE);
}

/*
 * map check
 * read map from filesytem super block, this function will read from REAL filesystem not memory
 */
BOOL map_check(int ID)
{
    uint8_t map[NUMBER_OF_BLOCKS/SIZEOF_BYTE] = {0};

    if(lseek(file_state, strlen(FILE_SYSTEM_HEADER), SEEK_SET) < 0) {
        LOG_WARN("lseek fail, detail:  %s\n", strerror(errno));
        return FALSE;
    }

    if(read(file_state, map, NUMBER_OF_BLOCKS/SIZEOF_BYTE) != NUMBER_OF_BLOCKS/SIZEOF_BYTE) {
        LOG_WARN("Fail to write, detail: %s\n", strerror(errno));
        return FALSE;
    }

    return (BOOL)((map[ID>>3] & (1ULL << ID%SIZEOF_BYTE)) >> ID%SIZEOF_BYTE);
}