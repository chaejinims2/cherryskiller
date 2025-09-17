#!/usr/bin/env bats

function setup() {
	source "${BATS_TEST_DIRNAME}/../task.sh"
}

@test "Verification test - should add two numbers" {

	run add 5 6

	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "11" ]
}


@test "Verification test - should subtract two numbers" {

	run subtract 6 2

	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "4" ]
}

@test "Verification test - should multiply two numbers" {

	run multiply 2 3

	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "6" ]
}

@test "Verification test - should divide two numbers" {

	run divide 9 3

	[ "$status" -eq 0 ]
	[ "${lines[0]}" = "3" ]
}