runner = $(shell whoami)
MAKEFLAGS += --no-print-directory
.DEFAULT_GOAL=all

.PHONY: clean all \
	gtest gtest_install gtest_clean

all: gtest

install: check_runner \
	gtest_install

clean: \
	gtest_clean

check_runner: # check if make is executed by root user
ifneq ($(runner), root)
	$(error Some submodules require other module installation. Please, run make as root [now: $(runner)].)
else
	@echo 'Running as root. OK'
endif

# Gtest -----------------------------------

GTEST_DIR=gtest/
GTEST_BUILD_DIR=gtest/build/

gtest: gtest_clean
	@echo Build gtest
	@cmake -S ./$(GTEST_DIR) -B ./$(GTEST_BUILD_DIR) -DBUILD_SHARED_LIBS=ON -DINSTALL_GTEST=ON -DCMAKE_INSTALL_PREFIX:PATH=/usr
	@cmake --build ./$(GTEST_BUILD_DIR)

gtest_install: check_runner
	@echo Install gtest
	@cmake --install ./$(GTEST_BUILD_DIR)

gtest_clean:
	@echo Clean gtest
	@rm -rf ./$(GTEST_BUILD_DIR)
