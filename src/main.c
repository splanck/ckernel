#include "monitor.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"

int main(struct multiboot *mboot_ptr)
{
    init_descriptor_tables();
    
    monitor_clear();
    monitor_write("Kernel starting...\n\n");

    asm volatile("int $0x3");
    asm volatile("int $0x4");
    monitor_write("Sending sti instruction...\n");

    asm volatile("sti");
    monitor_write("sti command sent...\n");

    init_timer(50); // Initialise timer to 50Hz 
    monitor_write("Timer initialised.\n\n");

    initialise_paging();
    monitor_write("Hello, paging world!\n");

    //u32int *ptr = (u32int*)0xA0000000;
    //u32int do_page_fault = *ptr;

    for(;;) 
    {
        asm("hlt");
    } 

    return 0;
}
