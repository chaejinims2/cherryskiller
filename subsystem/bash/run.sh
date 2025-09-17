#!/bin/bash
set -e

REPO_ROOT="$(git -C "$(dirname "$0")" rev-parse --show-toplevel)"
BATS="${REPO_ROOT}/common/third-party/bats-core/bin/bats"

if [[ ! -x "$BATS" ]]; then
  echo "[bash] bats not found at $BATS"
  echo "       run: git submodule update --init --recursive"
  exit 2
fi

TARGET_DIR="$1"
if [[ -z "$TARGET_DIR" ]]; then
  echo "Usage: $0 <problem-path>"
  exit 1
fi

if [[ ! -d "$TARGET_DIR/test" ]]; then
  echo "No test directory found in $TARGET_DIR"
  exit 1
fi

echo "[bash] running bats tests in $TARGET_DIR/test"
"$BATS" "$TARGET_DIR"/test/*.bats