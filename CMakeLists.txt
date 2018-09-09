cmake_minimum_required(VERSION 3.12)
project(FileSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(FileSystem main.cpp include/block.h include/log.h include/file.h include/inode_entry.h lib/block.c lib/directory.c lib/file.c lib/inode_entry.c)