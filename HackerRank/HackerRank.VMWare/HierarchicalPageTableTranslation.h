#pragma once

#include <cstdint>

const uint32_t _1KIB = 1024;
const uint32_t _4KIB = 4 * _1KIB;

enum access { ACCESS_READ, ACCESS_WRITE, ACCESS_EXECUTE };
enum fault { FAULT_NONE, FAULT_NOT_PRESENT, FAULT_MALFORMED, FAULT_VIOLATION };

struct linear_address {
	uint32_t value;

	linear_address(uint32_t v) : value{ v } {}

	const uint16_t offset() const { return value & 0x00000FFF; }
	const uint16_t pl1_index() const { return value & 0x003FF000; }
	const uint16_t pl2_index() const { return value & 0xFFC00000; };
};

struct pl_entry {
	uint32_t value;

	pl_entry(uint32_t v) : value{ v } {}

	const bool     present() const { return value & 0x00000001; }
	const bool     read() const { return value & 0x00000002; }
	const bool     write() const { return value & 0x00000004; }
	const bool     execute() const { return value & 0x00000008; }
	const bool     is_leaf() const { return value & 0x00000010; }
	const uint16_t ignored() const { return value & 0x00000FE0; }
	const int16_t  phys_page_no() const { return value & 0x7FFFF800; }
};
