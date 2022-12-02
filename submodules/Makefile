runner = $(shell whoami)

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

gtest: gtest_clean
	@echo Build gtest
	@cmake -S ./gtest/ -B build -DBUILD_SHARED_LIBS=ON -DINSTALL_GTEST=ON -DCMAKE_INSTALL_PREFIX:PATH=/usr
	@cmake --build build

gtest_install: check_runner
	@echo Install gtest
	@cmake -S ./gtest/ --install build

gtest_clean:
	@echo Clean gtest
	@rm -rf ./gtest/build