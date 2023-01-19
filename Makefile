#* ******************************************************************************
#* Copyright (C) 2022 Sky group of companies, All Rights Reserved
#* * --------------------------------------------------------------------------
#* * THIS SOFTWARE CONTRIBUTION IS PROVIDED ON BEHALF OF SKY PLC. 
#* * BY THE CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
#* * BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
#* * A PARTICULAR PURPOSE ARE DISCLAIMED
#* ******************************************************************************
#*
#*   ** Project      : ut
#*   ** @addtogroup  : ut
#*   ** @file        : makefile
#*   ** @author      : gerald.weatherup@sky.uk
#*   ** @date        : 20/05/2022
#*   **
#*   ** @brief : Makefile for ut
#*   ** 
#*
#* ******************************************************************************
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
BIN_DIR := $(ROOT_DIR)/bin
TOP_DIR := $(ROOT_DIR)

SRC_DIRS = $(ROOT_DIR)/src
INC_DIRS := $(ROOT_DIR)/../include
HAL_LIB := iarmmgrs-pwrmgr-hal
CFLAGS = -DENABLE_THERMAL_PROTECTION
MOCK_SRCS := $(ROOT_DIR)/skeletons/src/plat_power.c

ifeq ($(TARGET),)
$(info TARGET NOT SET )
$(info TARGET FORCED TO Linux)
TARGET=linux
SRC_DIRS += $(ROOT_DIR)/skeletons/src
endif

$(info TARGET [$(TARGET)])

ifeq ($(TARGET),arm)
HAL_LIB_DIR := $(ROOT_DIR)/libs
YLDFLAGS = -Wl,-rpath,$(HAL_LIB_DIR) -L$(HAL_LIB_DIR) -l$(HAL_LIB) $(CFLAGS)
ifeq ("$(wildcard $(HAL_LIB_DIR)/lib$(HAL_LIB).so)","")
SETUP_SKELTON_LIBS := mock
endif
endif

.PHONY: clean list all

export YLDFLAGS
export BIN_DIR
export SRC_DIRS
export INC_DIRS
export TARGET
export TOP_DIR
export HAL_LIB_DIR

.PHONY: clean list build mock


build: $(SETUP_SKELTON_LIBS)
	echo "SETUP_SKELTON_LIBS $(SETUP_SKELTON_LIBS)"
	@echo UT [$@]
	make -C ./ut-core

mock:
	echo $(CC)
	$(CC) -fPIC -shared -I$(INC_DIRS)  $(MOCK_SRCS) -o lib$(HAL_LIB).so
	mkdir -p $(HAL_LIB_DIR)
	cp $(ROOT_DIR)/lib$(HAL_LIB).so $(HAL_LIB_DIR)

list:
	@echo UT [$@]
	make -C ./ut-core list

clean:
	@echo UT [$@]
	make -C ./ut-core clean
	rm -rf $(BIN_DIR)/hal_test 
	rm -rf `find ./ -iname *.o`
