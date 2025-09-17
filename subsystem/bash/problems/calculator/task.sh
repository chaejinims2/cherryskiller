#!/bin/bash

function add() {
	local a="$1"
	local b="$2"
	echo "$((a + b))"
}

function subtract() {
	local a="$1"
	local b="$2"
	echo "$((a - b))"
}

function multiply() {
	local a="$1"
	local b="$2"
	echo "$((a * b))"
}

function divide() {
	local a="$1"
	local b="$2"
	echo "$((a / b))"
}