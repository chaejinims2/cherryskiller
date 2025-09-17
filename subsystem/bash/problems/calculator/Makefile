REPO_ROOT := $(shell git -C $(shell dirname $(lastword $(MAKEFILE_LIST))) rev-parse --show-toplevel)
BATS := $(REPO_ROOT)/common/third-party/bats-core/bin/bats

.PHONY: test
test:
	@if [ ! -x "$(BATS)" ]; then \
		echo "[bash] bats not found at $(BATS)"; \
		echo "       run: git submodule update --init --recursive"; \
		exit 2; \
	fi
	"$(BATS)" -t test