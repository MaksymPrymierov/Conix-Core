ENTRY(_start)
SECTIONS
{
  . = 1M;
  
  .text BLOCK(4K) : ALIGN(4K)
  {
    *(.multiboot)
    *(.text)
  }

  .rodata BLOCK(4K) : ALIGN(4K)
  {
    *(.rodata)
  }

  .data BLOCK(4K) : ALIGN(4K)
  {
    *(COMMON)
    *(.bss)
  }

  . = 0x01000000;
  heap_bottom = .;
  .heap         :
  {
    *(.heap)
  }
  . = ALIGN(50M);
  heap_top = .;

}
