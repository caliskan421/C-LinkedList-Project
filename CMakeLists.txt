cmake_minimum_required(VERSION 3.27)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_library(untitled1 STATIC DATA_STRUCT/1-DERS.c
        DATA_STRUCT/2-data_struct.c
        DATA_STRUCT/2-data_struct.c
        DATA_STRUCT/3-bagli_liste.c
        DATA_STRUCT/cift_yonlu_bagli_liste.c)
