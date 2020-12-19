SOURCES=boot.o main.o monitor.o common.o gdt.o isr.o descriptor_tables.o interrupt.o timer.o kheap.o paging.o
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -m32

LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) kernel.iso 

clean:
	rm *.o
	rm *.bin
	rm -rf iso
	rm -rf out

kernel.bin:
	ld -m elf_i386 $(LDFLAGS) -o kernel.bin $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $< 

kernel.iso: kernel.bin
	mkdir -p ./iso/boot/grub
	mkdir ./out
	cp kernel.bin ./iso/boot/
	echo 'set timeout=0' >> ./iso/boot/grub/grub.cfg
	echo 'set default=0' >> ./iso/boot/grub/grub.cfg	
	echo 'menuentry "kernel" {' >> ./iso/boot/grub/grub.cfg
	echo '	multiboot /boot/kernel.bin' >> ./iso/boot/grub/grub.cfg
	echo '	boot' >> ./iso/boot/grub/grub.cfg
	echo '}' >> ./iso/boot/grub/grub.cfg
	grub-mkrescue --output=./out/kernel.iso iso

run: all
	(vboxmanage controlvm ckernel poweroff && sleep 1) || true
	(killall VirtualBox && sleep 1) || true
	vboxmanage startvm ckernel &
