// https://www.hackerrank.com/companies/vmware/challenges/hierarchical-page-table-translation
//

#include "pch.h"

#include "HierarchicalPageTableTranslation.h"

//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
#include <map>

using std::map;

map<uint32_t, uint32_t> memory;

/*
* linearToPhys()
*   Traverse the page tables rooted at pl3e for the linearAddr and access type.
*   Input:
*       pl3e - The contents of the PL3e register.
*       linearAddr - The linear address being accessed.
*       access - ACCESS_READ, ACCESS_WRITE, or ACCESS_EXECUTE.
*   Return:
*       FAULT_NONE on success.
*       Otherwise FAULT_NOT_PRESENT, FAULT_MALFORMED, or FAULT_VIOLATION.
*   Output:
*       On success, populate *physAddr.
*/
static enum fault linearToPhys(pl_entry pl3e, linear_address linearAddr, enum access access, uint32_t *physAddr /* OUT */) {
	uint32_t pl2 = pl3e.phys_page_no();
	pl_entry pl2e = pl2 + (linearAddr.pl2_index() * sizeof(pl2));

	uint32_t pl1 = pl2e.phys_page_no();
	pl_entry pl1e = linearAddr.pl1_index() * pl1;

	*physAddr = pl1e.phys_page_no() + linearAddr.offset();

	return fault::FAULT_NONE;
}

/*
* readPhys() --
*   Read an aligned 32bit value from physical memory.
*/
static uint32_t readPhys(uint32_t physAddr) {
	return memory[physAddr];
}