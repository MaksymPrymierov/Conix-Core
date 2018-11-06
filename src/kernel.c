#include "../headers/conix.h"
#include "../headers/multiboot.h"

void main(int bootloader_inf, multiboot_info_t* loader_struct_addr){
  textGraphickInit();
  timerPhase(100);

  gdtInit();
  idtInstall();  
  isrsInstall();
  irqInstall();

  timerInstall();
  keyboardInstall();

  printf("%s", "Conix Core version: 0.02\n ");
  printf("%s", "Load kernel...\n ");
  printf("%s", "/----------------------------------------\\\n ");
  setScreenTextColor(RED);
  printf("%s", "|    AVE SATAN, AVE CONNOR41, AVE GNU!   |\n");
  setScreenTextColor(LIGHT_GREY);
	printf("%s", "\\----------------------------------------/\n");

  initKernelShell();

  return;
}
