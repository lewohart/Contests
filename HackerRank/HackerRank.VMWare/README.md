# Hierarchical Page Table Translation.

Write the code to traverse a simplified Hierarchical Page Table to convert a linear address into a physical address.

Our simplified architecture uses 32bit linear and 32bit physical addresses along with a two level hierarchical page table.

Page faults are generated for not-present entries, malformed entries, or permission violations.

###### Translation of linear address to physical address

To translate a linear address to physical address, the linear address is divided into a Paging Level 2 (PL2) index, a Paging Level 1 (PL1) index, and a 4KiB page offset.

Starting with a single Paging Level 3 Entry (PL3e) stored in a register, the CPU walks the page table structure to obtain a 4KiB physical page number (PPN). The final physical address translation is the PPN concatinated with the 4KiB offset from the linear address.

![alt text](https://s3.amazonaws.com/hr-challenge-images/12155/1441996608-e364e90e5a-ScreenShot2015-09-11at11.14.12AM.png "")

###### Translation using 4KiB pages

This section describes translation of linear address to physical address using 4KiB pages.

The 32bit PL3e register holds a 4KiB physical page number (PPN) for the Paging Level 2 (PL2) table. The physical address of the base of the PL2 table can be obtained by multiplying the PPN by the 4KiB page size.

The PL2 index from the linear address is the index into an array of 1024 32bit entries contained within the PL2 table. The CPU combines the PPN for the PL2 table with the index to generate the physical address of a 32bit Paging Level 2 Entry (PL2e).

The PL2e holds a 4KiB physical page number for the Paging Level 1 (PL1) table.

The PL1 index from the linear address is combined with the PL1 table address from the PL2e to generate the address of a 32bit Paging Level 1 Entry (PL1e).

And finally, the PL1e holds a 4KiB physical page number for the translation. Bits 31:12 from the PL1e are concatinated with the offset from bits 11:0 of the linear address to form the final physical address.

This final physical address is considered the translation from linear address to physical address.

###### Not Present

Each PL3e/PL2e/PL1e contains a Present (P) indication at bit 0.

If P is zero, the rest of the entry is ignored and a NOT-PRESENT fault is delivered.

No further entries are accessed by this translation.

####### 4GiB and 4MiB pages

Each present PL3e/PL2e/PL1e contains a Leaf (L) indication at bit 4.

If L is one, this is a leaf entry and provides a 4GiB, 4MiB, 4KiB physical page number depending on whether the L bit is set at in the PL3e, PL2e, or PL1e.

A 4GiB page is formed by setting L in the PL3e register. The physical address is identical to the linear address. In addition, bits 31:12 of the PL3e must be zero; if not, a MALFORMED fault is delivered.

A 4MiB page is formed by setting L in a PL2e. The physical address is formed by concatination of bits 31:22 of the PL2e with 21:0 of the linear address. In addition, bits 21:12 of the PL2e must be zero; if not a MALFORMED fault is delivered.

Every PL1e must have L set to indicate a 4KiB leaf. If not a MALFORMED fault is delivered.

######## Read (R), Write (W), Execute (X) Permisions

Each PL3e/PL2e/PL1e contains R/W/X permissions at bits 1/2/3.

If a present and well-formed translation is found for a linear address, the access type is checked against the permission bits.

For the access to occur, every PL3e/PL2e/PL1e used during translation must have the bit corresponding to the access type set to 1. If not, a VIOLATION fault is delivered.

![alt text](https://s3.amazonaws.com/hr-challenge-images/12155/1441996617-1fefdbf910-ScreenShot2015-09-11at11.22.51AM.png "")

#### Coding

For those who choose to use C, the template handles all input/output.
Populate the contents of linearToPhys().

```c
/*
 * linearToPhys() --
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
static enum fault
linearToPhys(uint32_t pl3e, uint32_t linearAddr, enum access access,
             uint32_t *physAddr /* OUT */);
```
Helper readPhys() can be used to read physical memory.

```c
/*
 * readPhys() --
 *   Read an aligned 32bit value from physical memory.
 */
static uint32_t readPhys(uint32_t physAddr);
```

In other languages, you will need to do your own input/output processing and remember the values in memory.

#### Input Format

The input contains a stream of lines with commands.

```
# Comment

    A line that starts with # is a comment and the entire line is ignored.

memory xxxxxxxx = yyyyyyyy

    Set the 32bit aligned physical memory location x (hex) to value y (hex).
    No test input will deliberately cause you to read an uninitialized memory.

pl3e xxxxxxxx

    Set the pl3e register to the 32bit hex value x provided.        

read xxxxxxxx

    Translate the 32bit linear address x (hex) to a physical address for read.
    The command and result (fault or physical address) is printed to output.

write xxxxxxxx

    Translate the 32bit linear address x (hex) to a physical address for write.
    The command and result (fault or physical address) is printed to output.

execute xxxxxxxx

    Translate the 32bit linear address x (hex) to a physical address for execute.
    The command and result (fault or physical address) is printed to output.
```

#### Output Format

The output contains a stream of lines, each of which is one of the following:

```
[read,write,execute] xxxxxxxx -> [NOT_PRESENT,MALFORMED,VIOLATION]

    The attempt to read/write/execute linear address x (hex) encounterd the specified fault.

[read,write,execute] xxxxxxxx -> yyyyyyyy

    read/write/execute of linear x (hex) was successfully translated to physical y (hex).
```

#### Sample Input

```
# successful 4KiB translations
pl3e 0000500f
memory 0000500c = 0000600f
memory 00006008 = 7777701f
memory 00006010 = 8888801f
memory 00006018 = 9999901f
#
# pl2 index 3, pl1 index 2, offset 1 -> 77777001
read 00c02001
#
# pl2 index 3, pl1 index 4, offset 5 -> 88888005
write 00c04005
#
# pl2 index 3, pl1 index 6, offset 9 -> 99999009
execute 00c06009
```

#### Sample Output

```
read 00c02001 -> 77777001
write 00c04005 -> 88888005
execute 00c06009 -> 99999009
```

#### Explanation

In this example all accesses encounter 4KiB pages that are present, well formed, and allow the access in question.